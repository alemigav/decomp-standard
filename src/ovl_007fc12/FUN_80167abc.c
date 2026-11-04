/* FUN_80167abc
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80167abc  body 0x80167abc..0x80167ba3  size 232 B
 * body sha256 2e665f2dee951cd20b630fc073207495bbbbaa2e8bba5ecb3bbdbc24be1b947b
 * provider record sha256 a49048356299197b3c965b1bb6cb77d9adae6c5106021a84de1f343a2d610374
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167abc(int param_1)

{
  int iVar1;
  
  *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x1800;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x60) = 0x304040;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1d8) = 0x304040;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x350) = 0x405050;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x7b8) = 0x405050;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xc20) = 0x304040;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xd98) = 0x506060;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1200) = 0x506060;
  func_0x80037780(0x40f1770,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,0);
  iVar1 = *(int *)(param_1 + 0x234);
  if ((*(uint *)(iVar1 + 0x11a0) & 1) != 0) {
    func_0x80037780(0x40f0fa0,(int)*(short *)(param_1 + 0x66),iVar1 + 0x11d8,0);
    iVar1 = *(int *)(param_1 + 0x234);
  }
  if ((*(uint *)(iVar1 + 0x468) & 1) != 0) {
    func_0x80037780(0x40f0fa0,(int)*(short *)(param_1 + 0x66),iVar1 + 0x4a0,0);
  }
  return;
}
