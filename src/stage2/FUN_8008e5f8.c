/* FUN_8008e5f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e5f8  body 0x8008e5f8..0x8008e6ff  size 264 B
 * body sha256 94a07cb85bf45717ee9fcd36986b3662daba7518343d60a88a53923753f15803
 * provider record sha256 72c47f7e1630eed7ece8be26d55095268f4db93800d654ec8baea4e0bebf5706
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e5f8(void)

{
  byte bVar3;
  uint uVar1;
  int iVar2;
  int iVar4;
  uint uVar5;
  int unaff_s2;
  int unaff_s3;
  int iVar6;
  
  bVar3 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar3;
  if (3 < bVar3) {
    uVar1 = FUN_8008c4b8(0);
    if (8 < uVar1) goto LAB_8008e6e8;
    iVar2 = FUN_8008c4b8(1);
    uVar5 = uVar1 + 1;
    if ((int)((uint)*(byte *)(unaff_s3 + 0x21488) - iVar2) <= (int)uVar1) goto LAB_8008e6e8;
    iVar6 = (int)uVar5 / 2 + 1 + uVar1;
    FUN_8008cb48(iVar6,(int)uVar1 / 2 + uVar1);
    iVar4 = unaff_s3 + uVar1 * 4;
    iVar2 = unaff_s3 + uVar5 * 4;
    *(undefined1 *)(iVar4 + 0x21818) = *(undefined1 *)(iVar2 + 0x21818);
    *(undefined1 *)(iVar4 + 0x21819) = *(undefined1 *)(iVar2 + 0x21819);
    *(undefined1 *)(iVar4 + 0x2181a) = *(undefined1 *)(iVar2 + 0x2181a);
    *(undefined1 *)(unaff_s2 + 5) = 0;
    if (*(byte *)(unaff_s2 + 8) == uVar5) {
      *(char *)(unaff_s2 + 8) = (char)uVar1;
    }
    FUN_8008cc1c(iVar6);
    FUN_8008c314(uVar5,0,0,0);
  }
  if (*(char *)(unaff_s2 + 6) == '\0') {
    return;
  }
LAB_8008e6e8:
  *(undefined1 *)(unaff_s2 + 2) = 4;
  *(undefined1 *)(unaff_s2 + 6) = 0;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  *(undefined1 *)(unaff_s2 + 4) = 0;
  *(undefined1 *)(unaff_s2 + 3) = 0;
  return;
}
