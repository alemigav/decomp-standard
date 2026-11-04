/* FUN_80039fc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039fc4  body 0x80039fc4..0x8003a127  size 356 B
 * body sha256 063ef5e3add3ffe2f957973ed91993163f657446545648e87df4815670c86b20
 * provider record sha256 b7a847bfb2238a232912b150db65d780ee9a15e5dfdba4b06494c32c7bb37a46
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039fc4(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  FUN_80039ba8();
  uVar4 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 4) =
       *(short *)(DAT_800ebb94 + 4) +
       ((short)(uVar4 & 0xff) + (short)((uVar4 & 0xff) / 5) * -5) * 0x200;
  bVar5 = FUN_80033604();
  *(byte *)(DAT_800ebb94 + 0x21) = *(char *)(DAT_800ebb94 + 0x21) + (bVar5 & 1);
  *(undefined1 *)(DAT_800ebb94 + 0x20) =
       *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)*(byte *)(DAT_800ebb94 + 0x21) * 8 + 2)
  ;
  iVar3 = DAT_800ebb94;
  pcVar1 = (char *)(DAT_800ebb94 + 3);
  cVar2 = *(char *)(DAT_800ebb94 + 0xb);
  *(short *)(DAT_800ebb94 + 0x2c) =
       *(short *)(DAT_800ebb94 + 0x2c) + (short)*(char *)(DAT_800ebb94 + 2);
  *(short *)(iVar3 + 0x2e) = *(short *)(iVar3 + 0x2e) + (short)*pcVar1;
  *(short *)(iVar3 + 0x30) = *(short *)(iVar3 + 0x30) + (short)cVar2;
  uVar4 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 0x44) =
       *(short *)(DAT_800ebb94 + 0x12) + (short)((uVar4 & 0xff) % 5) * 3;
  uVar4 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 0x46) =
       *(short *)(DAT_800ebb94 + 0x14) + (short)((uVar4 & 0xff) % 5) * 3;
  return;
}
