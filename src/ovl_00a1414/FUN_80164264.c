/* FUN_80164264
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80164264  body 0x80164264..0x80164353  size 240 B
 * body sha256 f35987d30c784f396f8dfcd1247776688c453b9565d0c1b71893762f2dbe5ec7
 * provider record sha256 8d7963408eb3e3a25b89fc741871a16613d0b50a9d105e27c0cbb723cb6ed071
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164264(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x11000700;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 10;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 1;
  }
  func_0x80032b5c(param_1,0);
  return;
}
