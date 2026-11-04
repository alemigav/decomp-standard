/* FUN_800ab580
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab580  body 0x800ab580..0x800ab657  size 216 B
 * body sha256 a5070c6cae89f138c06eacf9bfbed201d20295259a6ca3f79e88dea216c8873f
 * provider record sha256 c34607babad2d72ba2a08133c1e431ef4f061fc3f97b845ace6a4d6647335a36
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800ab580(undefined4 param_1,byte param_2,undefined1 param_3,undefined1 param_4,
                undefined2 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_res0 [4];
  
  DAT_80136310 = 0;
  if (param_2 < 0x21) {
    DAT_80147a58 = param_2;
  }
  else {
    DAT_80147a58 = 0x20;
  }
  DAT_80144440 = param_4;
  DAT_80147a59 = param_3;
  local_res0[0] = param_1;
  iVar2 = FUN_800a5018(local_res0,DAT_80147a58,param_5,param_6);
  uVar1 = local_res0[0];
  if (iVar2 == 0) {
    FUN_800a8ce8();
    FUN_800ae0d4();
    FUN_800a1ecc();
    DAT_80147fa8 = 0;
    FUN_800a80c8(uVar1);
    FUN_800a9540();
    FUN_800aaf70();
    DAT_80136310 = 1;
  }
  return iVar2;
}
