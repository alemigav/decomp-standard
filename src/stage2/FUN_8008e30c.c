/* FUN_8008e30c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e30c  body 0x8008e30c..0x8008e53f  size 564 B
 * body sha256 a8a31abaaae608c8dc18bad9d3c3300cb1fe135095053f0c269665285504c354
 * provider record sha256 1011e7bebc7a714c935361446953aec36a6f8e597e818e72240828dbb8eb2201
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e30c(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int unaff_s2;
  int unaff_s3;
  
  uVar5 = (uint)*(byte *)(unaff_s2 + 0xd);
  if (-1 < DAT_800e10ec) goto LAB_8008e490;
  if (((*(ushort *)(unaff_s3 + 0x1825c) & 0x2000) != 0) &&
     ((int)uVar5 < (int)(*(byte *)(unaff_s3 + 0x21488) - 1))) {
    if (*(char *)(unaff_s3 + uVar5 * 4 + 0x2181a) == '\x01') {
      *(byte *)(unaff_s2 + 0xd) = *(byte *)(unaff_s2 + 0xd) + 1;
    }
    *(char *)(unaff_s2 + 0xd) = *(char *)(unaff_s2 + 0xd) + '\x01';
  }
  if ((*(ushort *)(unaff_s3 + 0x1825c) & 0x8000) != 0) {
    bVar1 = *(byte *)(unaff_s2 + 0xd);
    uVar3 = (uint)bVar1;
    if ((uVar3 != 0) && (uVar3 != 10)) {
      if (*(char *)(unaff_s3 + uVar3 * 4 + 0x2181a) == '\x02') {
        if (uVar3 == 1) {
          cVar2 = bVar1 + 1;
        }
        else {
          cVar2 = bVar1 - 1;
        }
        *(char *)(unaff_s2 + 0xd) = cVar2;
      }
      *(char *)(unaff_s2 + 0xd) = *(char *)(unaff_s2 + 0xd) + -1;
    }
  }
  if ((*(ushort *)(unaff_s3 + 0x1825c) & 0x4000) != 0) {
    bVar1 = *(byte *)(unaff_s2 + 0xd);
    cVar2 = bVar1 + 2;
    if ((int)(*(byte *)(unaff_s3 + 0x21488) - 2) <= (int)(uint)bVar1) {
      if (bVar1 != 10) goto LAB_8008e440;
      cVar2 = '\x01';
    }
    *(char *)(unaff_s2 + 0xd) = cVar2;
  }
LAB_8008e440:
  if ((*(ushort *)(unaff_s3 + 0x1825c) & 0x1000) != 0) {
    bVar1 = *(byte *)(unaff_s2 + 0xd);
    if (bVar1 != 10) {
      if (bVar1 < 2) {
        *(undefined1 *)(unaff_s2 + 0xd) = 10;
      }
      else {
        *(byte *)(unaff_s2 + 0xd) = bVar1 - 2;
      }
    }
  }
  if (uVar5 != *(byte *)(unaff_s2 + 0xd)) {
    FUN_80077adc(0x4040000,0);
  }
LAB_8008e490:
  if ((*(uint *)(unaff_s3 + 0x18268) & 0x1000) == 0) {
    if ((*(uint *)(unaff_s3 + 0x18268) & 0x2000) != 0) {
      FUN_80077adc(0x4050000,0);
      *(undefined1 *)(unaff_s2 + 2) = 1;
      *(undefined1 *)(unaff_s2 + 3) = 0;
      *(undefined1 *)(unaff_s2 + 4) = 0;
    }
  }
  else {
    cVar2 = FUN_8008c414();
    *(char *)(unaff_s2 + 4) = cVar2;
    uVar4 = 0x4070000;
    if (cVar2 != '\0') {
      uVar4 = 0x4060000;
    }
    FUN_80077adc(uVar4,0);
  }
  FUN_800965e4(*(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x2181a));
  FUN_8008c25c(0x10,0xaf,2,*(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21818)
              );
  return;
}
