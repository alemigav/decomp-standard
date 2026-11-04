/* FUN_80164e34
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80164e34  body 0x80164e34..0x80164fab  size 376 B
 * body sha256 ec24e5d375439149d26559d1c589cb43125e85f785438b3f50316dd72fe0ce63
 * provider record sha256 f38cd6ee5de272ef0c429b84345be31ab5292fa1b6c10a96d5af7ec7e235ae1d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e34(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      iVar2 = FUN_80164d04(param_1,1);
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x2d0) = 0;
        *(undefined4 *)(param_1 + 4) = 0x1070000;
      }
      else {
        *(undefined2 *)(param_1 + 6) = 0x200;
      }
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_1 + 6) = 1;
        *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
        func_0x800334c8(param_1,param_2,param_3,0);
        func_0x80089d54(param_1,param_2,param_3,0x100);
        func_0x80077d18(10,param_1);
        return;
      }
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      *(undefined1 *)(param_1 + 0x2d0) = 0;
    }
  }
  func_0x80032b5c(param_1,0);
  return;
}
