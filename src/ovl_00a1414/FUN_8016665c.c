/* FUN_8016665c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016665c  body 0x8016665c..0x8016676b  size 272 B
 * body sha256 a5e66687a8840245c6e445f706f3282d8a46a7adaff2bcdaeb622535b185deb4
 * provider record sha256 5bcf64d40b9ecdb9ef0d0bf096ef0fc331f6fd76175d047294b6f4eaa1c00b57
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016665c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033144(param_1,0x800e1130);
    *(uint *)(param_1 + 0x1e8) = (10 - (uVar1 & 0xff)) * 0x1000000 + 0x300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x80;
    if (*(char *)(param_1 + 5) == '\v') {
      func_0x80077d18(0,param_1);
    }
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1080000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xff7f;
    func_0x80077d18(7,param_1);
  }
  func_0x80032b5c(param_1,0);
  return;
}
