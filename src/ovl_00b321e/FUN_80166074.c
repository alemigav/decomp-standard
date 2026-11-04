/* FUN_80166074
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80166074  body 0x80166074..0x801661d7  size 356 B
 * body sha256 0726aca3e91df6e2e652041d11b98b09b14788d14d772d1ff7d012557caa2e66
 * provider record sha256 3da3f2ed5183ff1c6ee1e0fa254c58d7908e992bdff1303a4d9533815e8123c5
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80166074(undefined4 param_1)

{
  int iVar1;
  undefined1 uVar3;
  undefined4 uVar2;
  
  iVar1 = FUN_80165fb4(param_1,0,0x73a,0x180);
  if (iVar1 == 0) {
    if (((_DAT_800e110c & 0x10000000) == 0) ||
       (iVar1 = FUN_80165fb4(param_1,1,0x73a,0x180), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      func_0x80077d18(4,param_1);
      iVar1 = func_0x80080e00(0x14,0,0);
      if (iVar1 == 2) {
        FUN_8016622c(1);
        uVar2 = 2;
      }
      else {
        uVar3 = func_0x80033144(param_1,_DAT_800e13ec);
        FUN_801661d8(1,uVar3);
        uVar2 = 1;
      }
    }
  }
  else {
    func_0x80077d18(4,param_1);
    iVar1 = func_0x80059e00(0x14,0);
    if (iVar1 == 2) {
      FUN_8016622c(0);
      uVar2 = 2;
      _DAT_800e1130 = _DAT_800e1130 | 2;
    }
    else {
      uVar3 = func_0x80033144(param_1,&DAT_800e1130);
      FUN_801661d8(0,uVar3);
      func_0x80052bd0(3,0);
      func_0x80052c6c(8,0xfa,0);
      uVar2 = 1;
    }
  }
  return uVar2;
}
