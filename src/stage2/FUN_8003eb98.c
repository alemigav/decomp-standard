/* FUN_8003eb98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003eb98  body 0x8003eb98..0x8003ecb7  size 288 B
 * body sha256 15120af91c7b1a0dfb70d754a8e940ad1d086123df64df7afe5355a5f0487d05
 * provider record sha256 70cfdbbcf9d776b3d8e3701b8e4769efcd86339c3de80da42bd93206a83f6fb9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003eb98(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  FUN_80039ba8();
  uVar2 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 4) =
       *(short *)(DAT_800ebb94 + 4) +
       ((short)(uVar2 & 0xff) + (short)((uVar2 & 0xff) / 5) * -5) * 0x200;
  bVar3 = FUN_80033604();
  *(byte *)(DAT_800ebb94 + 0x21) = *(char *)(DAT_800ebb94 + 0x21) + (bVar3 & 1);
  *(undefined1 *)(DAT_800ebb94 + 0x20) =
       *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)*(byte *)(DAT_800ebb94 + 0x21) * 8 + 2)
  ;
  uVar2 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 0x44) =
       *(short *)(DAT_800ebb94 + 0x12) + (short)((uVar2 & 0xff) % 5) * 3;
  uVar2 = FUN_80033604();
  iVar1 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 2) = 4;
  *(short *)(iVar1 + 0x46) = *(short *)(iVar1 + 0x14) + (short)((uVar2 & 0xff) % 5) * 3;
  return;
}
