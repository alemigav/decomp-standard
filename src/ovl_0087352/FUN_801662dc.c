/* FUN_801662dc
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801662dc  body 0x801662dc..0x801663e7  size 268 B
 * body sha256 38b86b969fb10be4bfd778840c458f4a09111ef1c8b3300f5739e896e42ed045
 * provider record sha256 6193b01dfca7e28a54d44591fb25febdfc1f533c1e20578480bae6363ac22a3e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801662dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
  case 1:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    break;
  case 3:
    if (_DAT_800e1322 < 0) {
      DAT_800e1134 = 3;
      DAT_800e1135 = 0;
      DAT_800e1136 = 0;
      DAT_800e1137 = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000700;
    *(undefined1 *)(param_1 + 6) = 4;
  case 4:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
      FUN_80165c58(0x800e1130,1,0);
    }
  }
  return;
}
