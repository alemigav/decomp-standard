/* FUN_8007a904
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a904  body 0x8007a904..0x8007aa2b  size 296 B
 * body sha256 8dfe75ada01647b17dc3cf1dce5c0f5e1959075239c531219d937c47fbd34688
 * provider record sha256 45171fdab21f99687cdbe0b2ca68144bf3198daa13f50b151a2ade595f300ea2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a904(int param_1)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    *(undefined4 *)(iVar1 + 0x220) = *(undefined4 *)(iVar1 + 0x1828);
    *(undefined4 *)(iVar1 + 0x224) = *(undefined4 *)(iVar1 + 0x182c);
    *(undefined4 *)(iVar1 + 0x228) = *(undefined4 *)(iVar1 + 0x1830);
    *(undefined4 *)(iVar1 + 0x22c) = *(undefined4 *)(iVar1 + 0x1834);
    *(undefined2 *)(iVar1 + 0x23c) = *(undefined2 *)(iVar1 + 0x1844);
    *(undefined2 *)(iVar1 + 0x23e) = *(undefined2 *)(iVar1 + 0x1846);
    *(undefined4 *)(iVar1 + 0x244) = *(undefined4 *)(iVar1 + 0x184c);
    *(undefined4 *)(iVar1 + 0x240) = *(undefined4 *)(iVar1 + 0x1848);
    *(undefined4 *)(iVar1 + 0x1780) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x2f0) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x468) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x5e0) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x758) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x8d0) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xa48) = 0;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,1);
  }
  return;
}
