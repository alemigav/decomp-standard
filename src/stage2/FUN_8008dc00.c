/* FUN_8008dc00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008dc00  body 0x8008dc00..0x8008dd73  size 372 B
 * body sha256 bd0fc407f3182b5ae68630ea3c805c57691927c2aabb623032aa3751a6fab1b1
 * provider record sha256 5806a385d93aecbfaca4b991672f2a017244c02b1ec3e91411b4623f5382ba74
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008dc00(void)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int unaff_s1;
  int unaff_s2;
  
  bVar1 = DAT_800e10ec < 0;
  *(undefined1 *)(unaff_s1 + 0x16) = 1;
  if (bVar1) {
    if (DAT_8013a380 == '\0') {
      if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x4000) != 0) {
        cVar2 = *(char *)(unaff_s1 + 0xf) + -1;
        if (*(char *)(unaff_s1 + 0xf) == '\x01') {
          cVar2 = '\x03';
        }
        *(char *)(unaff_s1 + 0xf) = cVar2;
      }
      if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x1000) != 0) {
        cVar2 = *(char *)(unaff_s1 + 0xf) + '\x01';
        if (*(char *)(unaff_s1 + 0xf) == '\x03') {
          cVar2 = '\x01';
        }
LAB_8008dcd8:
        *(char *)(unaff_s1 + 0xf) = cVar2;
      }
    }
    else {
      if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x4000) != 0) {
        cVar2 = *(char *)(unaff_s1 + 0xf) + -1;
        if (*(char *)(unaff_s1 + 0xf) == '\0') {
          cVar2 = '\x03';
        }
        *(char *)(unaff_s1 + 0xf) = cVar2;
      }
      if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x1000) != 0) {
        cVar2 = *(char *)(unaff_s1 + 0xf) + '\x01';
        if (*(char *)(unaff_s1 + 0xf) != '\x03') goto LAB_8008dcd8;
        *(undefined1 *)(unaff_s1 + 0xf) = 0;
      }
    }
    if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x5000) != 0) {
      FUN_80077adc(0x4040000,0);
    }
  }
  uVar3 = 0x4060000;
  if ((*(uint *)(unaff_s2 + 0x18268) & 0x1000) == 0) {
    uVar3 = 0x4050000;
    if ((*(uint *)(unaff_s2 + 0x18268) & 0x2000) == 0) goto LAB_8008dd64;
    *(undefined1 *)(unaff_s1 + 2) = 4;
    *(undefined1 *)(unaff_s1 + 3) = 0;
  }
  else {
    *(undefined1 *)(unaff_s1 + 2) = 2;
    *(undefined1 *)(unaff_s1 + 4) = 0;
    *(undefined1 *)(unaff_s1 + 3) = *(undefined1 *)(unaff_s1 + 0xf);
    *(undefined1 *)(unaff_s1 + 0xd) = *(undefined1 *)(unaff_s1 + 0xc);
  }
  FUN_80077adc(uVar3,0);
LAB_8008dd64:
  FUN_80097578(DAT_8013a380);
  FUN_800962fc(*(undefined1 *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x2181a));
  return;
}
