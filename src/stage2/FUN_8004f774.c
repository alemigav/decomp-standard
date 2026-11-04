/* FUN_8004f774
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f774  body 0x8004f774..0x8004f813  size 160 B
 * body sha256 92c2f8a5860586d2cf2d7b53677045a9d8f8b50fbfff8159e3a918227352175b
 * provider record sha256 57cbab600128e81bf4cf206fb8cc1fed186f22202a780f71710d6fc955dabafb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004f774(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (uint)*(ushort *)(param_2 + 300) + param_3;
  param_3 = (uint)*(ushort *)(param_2 + 0x12e) + param_3;
  if (((uint)(iVar1 * 2) < (uint)((*param_1 - *(int *)(param_2 + 0x120)) + iVar1)) ||
     ((uint)(param_3 * 2) < (uint)((param_1[2] - *(int *)(param_2 + 0x128)) + param_3))) {
    return 0;
  }
  uVar2 = 1;
  if (param_4 != 0) {
    iVar1 = *(ushort *)(param_2 + 0x13a) - 1;
    if (iVar1 < 0) {
      return 0;
    }
    uVar2 = 0;
    if ((uint)((param_1[1] - *(int *)(param_2 + 0x124)) + iVar1) <= iVar1 * 2 + 1U) {
      uVar2 = 1;
    }
  }
  return uVar2;
}
