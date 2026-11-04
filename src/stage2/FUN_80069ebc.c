/* FUN_80069ebc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069ebc  body 0x80069ebc..0x80069f1b  size 96 B
 * body sha256 5114948727ea4c87d5328a4311c0b837a7d74578c318d2ca76aa74a27b68365a
 * provider record sha256 90d843c5223c162e736e3f50919b47f76eaa3d685e2bcbdc87822a682516940f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80069ebc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(ushort *)(param_4 + 6) >> 1);
  iVar1 = ((int)*(short *)(param_4 + 2) + uVar2) - *(int *)(param_1 + 8);
  iVar1 = FUN_80040bb4(uVar2 * uVar2 - iVar1 * iVar1);
  return (param_2 - uVar2) + iVar1;
}
