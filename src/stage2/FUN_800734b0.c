/* FUN_800734b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800734b0  body 0x800734b0..0x80073563  size 180 B
 * body sha256 67a4c5834593971f827c28aaeb94bf36c8046ff32aa75e061d0d0b0eb0b9c45c
 * provider record sha256 dcfffd5be34c67dcfc42411cba0760934a7c8ce5126fa91f0083c5ad50220304
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800734b0(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  bVar1 = *(byte *)(iVar3 + 1);
  bVar2 = *(byte *)(iVar3 + 2);
  local_28 = *(undefined4 *)((&DAT_800e13e8)[bVar1] + 0x28);
  local_24 = *(undefined4 *)((&DAT_800e13e8)[bVar1] + 0x2c);
  local_20 = *(undefined4 *)((&DAT_800e13e8)[bVar1] + 0x30);
  local_18 = *(undefined4 *)((&DAT_800e13e8)[bVar2] + 0x28);
  local_14 = *(undefined4 *)((&DAT_800e13e8)[bVar2] + 0x2c);
  local_10 = *(undefined4 *)((&DAT_800e13e8)[bVar2] + 0x30);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 6;
  iVar3 = FUN_8006ab40(&local_28,&local_18,*(undefined2 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 3));
  return iVar3 == 0;
}
