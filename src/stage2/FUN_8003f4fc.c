/* FUN_8003f4fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003f4fc  body 0x8003f4fc..0x8003f643  size 328 B
 * body sha256 f952b3e11ecba7f42692bec204daef7c2893c7da852e621215c7ce0786c50887
 * provider record sha256 b5dc6b44ba0c2f92eb6c00d95c6f511f95df4a7f86ea9870ed1216af0e101fba
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003f4fc(void)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  FUN_80039c34();
  *(char *)(DAT_800ebb94 + 8) =
       (char)((int)((int)*(char *)(DAT_800ebb94 + 8) * (uint)*(ushort *)(DAT_800ebb94 + 0x3a)) /
             3000);
  *(char *)(DAT_800ebb94 + 9) =
       (char)((int)((int)*(char *)(DAT_800ebb94 + 9) * (uint)*(ushort *)(DAT_800ebb94 + 0x3a)) /
             3000);
  *(char *)(DAT_800ebb94 + 10) =
       (char)((int)((int)*(char *)(DAT_800ebb94 + 10) * (uint)*(ushort *)(DAT_800ebb94 + 0x3a)) /
             3000);
  iVar3 = DAT_800ebb94;
  uVar4 = (uint)*(ushort *)(DAT_800ebb94 + 0x3a);
  psVar1 = (short *)(DAT_800ebb94 + 0xe);
  sVar2 = *(short *)(DAT_800ebb94 + 0x10);
  *(short *)(DAT_800ebb94 + 0xc) =
       (short)((int)((int)*(short *)(DAT_800ebb94 + 0xc) * uVar4) / 3000);
  *(short *)(iVar3 + 0xe) = (short)((int)((int)*psVar1 * uVar4) / 3000);
  *(short *)(iVar3 + 0x10) = (short)((int)((int)sVar2 * uVar4) / 3000);
  return;
}
