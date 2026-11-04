# M139 — S2DEX is searchable: OCR with the OS, no installs

The S2DEX microcode guide is a **38-page scan with no text layer**, so until now it was the one SDK manual
that could not be searched — the programming manual (534 pp) and the EXEGCC guide (126 pp) both carry text.
This milestone makes it searchable without adding a dependency.

## 1. The tool, and why it is written from scratch

Nothing usable was installed: no `tesseract`, no `ocrmypdf`, no `pdftoppm`/`pdfimages`, no Ghostscript, no
ImageMagick, and no Python imaging (`PIL`, `fitz`, `pytesseract`) either. The single candidate was `sips`,
which rasterises one page at a time and cannot OCR at all.

What **is** present is the toolchain that ships with the OS: `swiftc` 6.2 and the Vision framework. So
`tools/ocr_pdf.swift` is a standalone renderer + recogniser:

* **render** — `CGPDFDocument` + `CGContext` (8-bit grey), each page drawn at `--scale` × 72 dpi,
  default 4× (288 dpi), which resolves the 6–8 pt body text in these manuals;
* **recognise** — `VNRecognizeTextRequest`, `.accurate`, language correction on, `en-US`;
* **order** — Vision's boxes are normalised with a **bottom-left** origin, so rows are sorted by
  descending `midY` and then by `minX`, with a `0.008` row tolerance so labels on one baseline are not
  interleaved with the next line.

```
swiftc -O tools/ocr_pdf.swift -o /tmp/ocr_pdf
/tmp/ocr_pdf docs/Nintendo_64_S2DEX_Microcode_Users_Guide_NU6-06-0136-001A.pdf > build/ocr/s2dex.txt
```

Output goes to **`build/ocr/s2dex.txt`** — `build/` is gitignored, and it must stay that way: the extracted
text is the same copyrighted Nintendo document, so it is local reference exactly like the PDF itself.

## 2. What came out

* **38 of 38 pages** recognised, **1 840 lines**, in about a minute.
* Five pages carry almost no text — 1, 32, 34, 36, 38 — which are the cover and figure/diagram pages. The
  OCR reports them as empty rather than inventing content, which is the behaviour to want.
* **86 distinct GBI names** recovered, e.g. `gDPFillRectangle`, `gDPLoadTextureBlock`,
  `gDPSetRenderMode`, `gDPSetOtherMode`-family setters, `gDPNoOp`, `gDPScisFillRectangle`,
  `gDPLoadTLUT_pal16`/`_pal256`.
* The structure and mode vocabulary is legible too: `ObjMtx`, `uObjSubMtx`, and the render-mode flags
  `G_OBJRM_BILERP`, `G_OBJRM_NOTXCLAMP`, `G_OBJRM_SHRINKSIZE_1/2`, `G_OBJRM_WIDEN`, plus texture types
  `G_OBJIT_TLUT`, `G_OBJIT_TXTRBLOCK`, `G_OBJLT_IXTRTILE`.
* The table of contents names the two chapters that matter for compatibility work: **"GBIs Supported by
  Both S2DEX and F3DEX"** and **"GBIs Not Supported in S2DEX"**.

Known OCR damage: odd glyphs run together (`ObjMtx/uObjSubMt×`, `HilitelTile`, `G_OBJRM_BILERE`). Search
works; quoting does not — treat every string above as an index entry and re-read the page image before
citing it.

## 3. What this enables — and the test it enables is not yet run

S2DEX is the **2D sprite microcode**: an object/sprite command set layered on top of the RDP setters, with
its own matrix ("ObjMtx") and its own render modes. Whether **this game uses it at all** is a separate,
testable question, and the test is cheap: S2DEX's sprite commands live in the GBI opcode space that F3DEX2
does not use, so a display list scan for those opcodes answers it directly. That scan is the next step;
nothing in this milestone claims RE2 N64 uses S2DEX, and the 1 227 JPEG frames the owner's plan mentions
are a *texture* concern, which the RDP setters in `gDPLoadTexture*` cover regardless of microcode.

## 4. Limit stated: this tool is not in the gate

`tools/ocr_pdf.swift` is **not** wired into `acceptance.py` or `ci.sh`, deliberately: it needs a macOS-only
framework, and its input (the PDF) is gitignored, so a suite for it would report SKIP everywhere it ran. The
consequence is stated rather than hidden — **the tool is untested by the gate**, and its correctness
evidence is this run: 38/38 pages, the GBI vocabulary above, and the empty-page behaviour. If it is ever
made part of the gate, it needs a committed synthetic one-page PDF as its fixture, not this manual.
