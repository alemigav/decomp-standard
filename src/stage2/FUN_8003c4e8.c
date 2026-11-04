/* FUN_8003c4e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c4e8  body 0x8003c4e8..0x8003c567  size 128 B
 * body sha256 745631978c1d8908bc4d46fc2abf94c7bbbbbb9544dabf14bc4ab29e1a2fa17e
 * provider record sha256 a7e2f831747baca979b230eea5b4734f9240a7e710e0b712a7f897673b38ebfc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c4e8(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int local_18;
  int local_14;
  int iStack_10;
  
  *(undefined1 *)(DAT_800ebb94 + 3) = 0x23;
  *(short *)(DAT_800ebb94 + 0xc) = -*(short *)(DAT_800ebb94 + 0xc);
  uVar3 = FUN_80033604();
  iVar2 = DAT_800ebb94;
  puVar1 = (ushort *)(DAT_800ebb94 + 0x12);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  *(ushort *)(DAT_800ebb94 + 0x10) = (uVar3 & 3) * 3;
  local_14 = (int)*(short *)(iVar2 + 0x36);
  iStack_10 = (int)*(short *)(iVar2 + 0x38);
  FUN_80077adc((uint)*puVar1 << 0x10 | 1,&local_18);
  return;
}
