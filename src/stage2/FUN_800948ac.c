/* FUN_800948ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800948ac  body 0x800948ac..0x80094b67  size 700 B
 * body sha256 c9d1ba3e25b67fa46067e34b2da800dbc85b3fb9f8df2dcf2e0108004f0ed935
 * provider record sha256 a16273393b6782391dc77537ff27dfc50085dafeed6280cbaa08513dc905f46e
 * callees 24 direct (24 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800948ac(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_800e8605 < 0x68) {
    DAT_8012bf98 = 1;
    DAT_8012bf99 = 2;
    DAT_8012bfb1 = 0;
    _DAT_8013a390 =
         FUN_800479c8(DAT_800c52dc + 0x44800,&DAT_8012fa38,
                      *(undefined2 *)(&DAT_8012f5e0 + (uint)DAT_800e8605 * 2));
    func_0x80004cfc((&DAT_8012bec0)[DAT_800e8605],_DAT_8013a390,0,&DAT_800ba0fc);
    if (DAT_800e8605 - 0xe < 6) {
      func_0x80004cfc((&DAT_8012bec0)[DAT_800e8605 + 0x56],_DAT_8013a390 + 0x4b0,0,&DAT_800ba0fc);
    }
    FUN_800986a4(1);
    FUN_80096e74(0);
    FUN_800274f8(0x200,0xffffe800,7,1);
    do {
      FUN_8004cd88(1);
      FUN_80096d90();
      FUN_800978a4();
      FUN_80097c4c();
      uVar1 = FUN_8008c3a0();
      FUN_800981d8(uVar1);
      FUN_800969a4();
      FUN_80096f68(0);
      FUN_80097174();
      FUN_80095c34();
      FUN_800988a4(1);
      iVar2 = FUN_8002767c(0);
    } while (iVar2 == 0);
  }
  else {
    uVar3 = FUN_8008c05c(DAT_800e8605 - 0x68);
    DAT_8012bfa9 = (undefined1)(uVar3 >> 3);
    DAT_8012bfaa = (byte)uVar3 & 7;
    DAT_8012bfab = 0;
    DAT_8012fe04 = (byte)(DAT_800e8605 + 0x7f) < 0x10;
    DAT_8012bfb1 = 1;
    if ((bool)DAT_8012fe04) {
      DAT_8012bfa9 = 3;
      DAT_8012bfaa = (byte)uVar3;
    }
    FUN_800946f0();
    FUN_800274e4(2,1);
    uVar3 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar3 = DAT_800c52dc + 0x3c004U;
    }
    FUN_80098c08(uVar3 + 0xa64);
    DAT_8012bff4 = 0x138;
    DAT_8012bf98 = 1;
    DAT_8012bf99 = 4;
    DAT_8012bf9a = 3;
    FUN_800274f8(0x200,0xffffe800,7);
    do {
      FUN_8004cd88(1);
      FUN_80098f08();
      iVar2 = FUN_8002767c(0);
    } while (iVar2 == 0);
    FUN_80077adc(0x4080000,0);
  }
  FUN_8006c070(1);
  return;
}
