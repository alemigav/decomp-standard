/* FUN_80162f58
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162f58  body 0x80162f58..0x801630bb  size 356 B
 * body sha256 315ac0e1e164a2bd55931e8ed7a0a517b4c1fd736722980840982f7b046e83a0
 * provider record sha256 6fa82a2200dbf11918ef38e9b3e064835704293ec3bdf4ea6b7a1e27daa4459d
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80162f58(int param_1,char param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [2];
  int local_18;
  
  local_28 = 0x7080000;
  local_24 = 0;
  func_0x8008383c((int)*(short *)(param_1 + 0x66),*(undefined4 *)(param_1 + 0x70),&local_28,
                  &local_28);
  local_20[0] = *(int *)(param_1 + 0x28) + (int)local_28._0_2_;
  local_18 = *(int *)(param_1 + 0x30) + (int)local_24._0_2_;
  func_0x800667d4(local_20,400,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x400);
  if (_DAT_800e1068 == 0) {
    *(undefined1 *)(param_1 + 0x2cc) = 0;
    uVar3 = 0;
  }
  else {
    if (*(char *)(param_1 + 0x2cc) == '\0') {
      uVar1 = func_0x8006a42c(param_1 + 0x28);
      iVar4 = (*(ushort *)(param_1 + 0x66) & 0xfff) - ((uVar1 & 0xffff) * 0x400 + 0x800 & 0xfff);
      iVar2 = iVar4;
      if (iVar4 < 0) {
        iVar2 = -iVar4;
      }
      if (0x800 < iVar2) {
        iVar4 = iVar4 + -0x1000;
      }
      if (iVar4 == 0) {
        *(char *)(param_1 + 0x2cc) = -param_2;
      }
      else {
        *(char *)(param_1 + 0x2cc) = param_2;
      }
      if (param_3 != 0) {
        *(char *)(param_1 + 0x2cc) = -*(char *)(param_1 + 0x2cc);
      }
    }
    uVar3 = 1;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)*(char *)(param_1 + 0x2cc);
  }
  return uVar3;
}
