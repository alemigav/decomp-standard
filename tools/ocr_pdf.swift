// OCR a scanned PDF with macOS Vision, without installing anything.
//
//   swiftc -O tools/ocr_pdf.swift -o /tmp/ocr_pdf
//   /tmp/ocr_pdf docs/Some_Scanned_Guide.pdf > build/ocr/guide.txt
//
// Pages are rendered with CoreGraphics at `scale` x 72 dpi (default 4x, i.e. 288 dpi: enough for the
// 6-8 pt body text in these SDK manuals) and recognised with VNRecognizeTextRequest. Lines come out in
// reading order — Vision's origin is bottom-left, so rows are sorted by descending midY and then by x.
//
// Deliberately a standalone renderer+recogniser rather than a wrapper around tesseract/pdftoppm: neither
// is installed here, and Vision ships with the OS.

import CoreGraphics
import Foundation
import Vision

func die(_ message: String) -> Never {
    FileHandle.standardError.write((message + "\n").data(using: .utf8)!)
    exit(2)
}

var args = CommandLine.arguments
guard args.count >= 2 else {
    die("usage: ocr_pdf <file.pdf> [--scale N] [--first N] [--last N]")
}
let path = args[1]
var scale: CGFloat = 4
var first = 1
var last = Int.max
var i = 2
while i < args.count {
    switch args[i] {
    case "--scale" where i + 1 < args.count: scale = CGFloat(Double(args[i + 1]) ?? 4); i += 2
    case "--first" where i + 1 < args.count: first = Int(args[i + 1]) ?? 1; i += 2
    case "--last"  where i + 1 < args.count: last = Int(args[i + 1]) ?? last; i += 2
    default: die("unknown argument: \(args[i])")
    }
}

guard let doc = CGPDFDocument(URL(fileURLWithPath: path) as CFURL) else {
    die("not a readable PDF: \(path)")
}
let pages = doc.numberOfPages
guard pages > 0 else { die("PDF has no pages: \(path)") }
FileHandle.standardError.write("\(path): \(pages) page(s), scale \(scale)x\n".data(using: .utf8)!)

let upper = min(last, pages)
for pageNo in max(1, first)...upper {
    guard let page = doc.page(at: pageNo) else { continue }
    let box = page.getBoxRect(.mediaBox)
    let width = Int(box.width * scale)
    let height = Int(box.height * scale)
    guard width > 0, height > 0,
          let ctx = CGContext(data: nil, width: width, height: height, bitsPerComponent: 8,
                              bytesPerRow: 0, space: CGColorSpaceCreateDeviceGray(),
                              bitmapInfo: CGImageAlphaInfo.none.rawValue)
    else { die("could not create a \(width)x\(height) context for page \(pageNo)") }
    ctx.setFillColor(gray: 1, alpha: 1)
    ctx.fill(CGRect(x: 0, y: 0, width: width, height: height))
    ctx.scaleBy(x: scale, y: scale)
    ctx.drawPDFPage(page)
    guard let image = ctx.makeImage() else { die("page \(pageNo) produced no image") }

    let request = VNRecognizeTextRequest()
    request.recognitionLevel = .accurate
    request.usesLanguageCorrection = true
    request.recognitionLanguages = ["en-US"]
    do {
        try VNImageRequestHandler(cgImage: image, options: [:]).perform([request])
    } catch {
        die("page \(pageNo): recognition failed: \(error)")
    }

    print("=== page \(pageNo) ===")
    let observations: [VNRecognizedTextObservation] = request.results ?? []
    // Vision's bounding boxes are normalised with a bottom-left origin; group into rows within a
    // tolerance so a run of small labels on one baseline is not interleaved with the next.
    let sorted = observations.sorted { a, b in
        let dy = abs(a.boundingBox.midY - b.boundingBox.midY)
        if dy > 0.008 { return a.boundingBox.midY > b.boundingBox.midY }
        return a.boundingBox.minX < b.boundingBox.minX
    }
    for observation in sorted {
        if let candidate = observation.topCandidates(1).first {
            print(candidate.string)
        }
    }
}
