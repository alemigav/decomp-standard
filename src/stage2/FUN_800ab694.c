/* FUN_800ab694
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab694  body 0x800ab694..0x800ab76b  size 216 B
 * body sha256 901f7fa2123694c1d69d94b671b83f311e1a0be6025eab8169342332c7ec551d
 * provider record sha256 8db0fbfef1ee203c73edbfb08f05a871d5e5288cf14af2fdfdc63870a2b1c151
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800ab694(undefined4 param_1,byte param_2,undefined1 param_3,undefined1 param_4,
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
  iVar2 = FUN_800a57dc(local_res0,DAT_80147a58,param_5,param_6);
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
