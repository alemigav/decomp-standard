/* FUN_801677b0
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801677b0  body 0x801677b0..0x80167893  size 228 B
 * body sha256 81832bcd7b64ecb40f954bbcc5784c64f1a4abd75c8c91fd4d9a5a1830e4c359
 * provider record sha256 f6bbdf0463dd2688b01a4d2eae3dbf5d3d2a88b8e64c678ed0895400b277b2e5
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801677b0(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_8016760c();
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x14;
    if ((param_2 & 2) != 0) {
      uVar4 = 10;
    }
    iVar1 = func_0x80059e00(uVar4,0);
    if (iVar1 == 2) {
      FUN_801675ec();
      uVar4 = 0xffffffff;
    }
    else {
      if (param_2 == 0) {
        cVar3 = func_0x80033144(param_1,&DAT_800e1130);
        FUN_80167598(cVar3 + '\x02');
      }
      else {
        uVar2 = func_0x80033144(param_1,&DAT_800e1130);
        FUN_801675bc(param_1,2,uVar2);
      }
      func_0x80052bd0(8,0);
      func_0x80052c6c(8,0xfa,4);
      _DAT_800e1324 = (ushort)param_2 & 1;
      uVar4 = 1;
    }
  }
  return uVar4;
}
