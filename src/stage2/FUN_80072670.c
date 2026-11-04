/* FUN_80072670
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072670  body 0x80072670..0x8007272b  size 188 B
 * body sha256 44c847d4070ea65ed7c88d635afee0ff9928682214955cb26c93e3371d76bcb3
 * provider record sha256 70bd6c9c55cd02deb1485236bcc5edc2a27397398396f9b67f90e7e40385859f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072670(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_800e9250 * 0x28;
  iVar2 = (int)*(char *)(*(int *)(param_1 + 0x1c) + 1);
  iVar3 = (int)*(char *)(*(int *)(param_1 + 0x1c) + 2);
  FUN_8006cdf0(*(undefined4 *)(&DAT_800c4f80 + iVar1),*(undefined4 *)(&DAT_800c4f84 + iVar1),
               *(undefined4 *)(&DAT_800c4f88 + iVar1),*(undefined4 *)(&DAT_800c4f8c + iVar1),
               *(undefined4 *)(&DAT_800c4f90 + iVar1),*(undefined4 *)(&DAT_800c4f94 + iVar1),
               *(int *)(&DAT_800c4f98 + iVar1) - iVar2,*(int *)(&DAT_800c4f9c + iVar1) - iVar2,
               *(int *)(&DAT_800c4fa0 + iVar1) - iVar3,*(int *)(&DAT_800c4fa4 + iVar1) - iVar3,0,0);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 3;
  return 1;
}
