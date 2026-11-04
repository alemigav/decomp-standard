/* FUN_801627d8
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x801627d8  body 0x801627d8..0x801629e3  size 524 B
 * body sha256 8afab1d0da30187733fb992e1e5ed272055475ef7adf0e62f12bc469dc1eff19
 * provider record sha256 69d3bc4b9c47dc9375b0af7b94e9da2edd96971d851a5b88d51fba3c53020e30
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801627d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    if (*(char *)(param_1 + 0x1e9) == '\0') {
      func_0x80052bd0(2,0);
      func_0x80052c6c(1,0xb4,0);
      func_0x80052c6c(2,0xfa,1);
      uVar2 = func_0x80033604();
      uVar4 = 7;
      if ((uVar2 & 1) != 0) {
        uVar4 = 5;
      }
      func_0x80077d18(uVar4,param_1);
    }
    func_0x80089d54(param_1,param_2,param_3,0x100);
    iVar3 = func_0x800331b8();
    iVar3 = (uint)*(ushort *)(param_1 + 0x1f6) - (iVar3 * 2 + 1);
    *(short *)(param_1 + 0x1f6) = (short)iVar3;
    if (iVar3 * 0x10000 < 0) {
      *(undefined1 *)(param_1 + 6) = 2;
      _DAT_800e1136 = CONCAT11(2,(undefined1)DAT_800e1134_2);
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
      iVar3 = *(int *)(param_1 + 0x234) +
              (uint)(byte)(&DAT_80163022)[(*(ushort *)(param_1 + 0x1aa) & 1) * 7] * 0x178;
      _DAT_800e1158 = *(undefined4 *)(iVar3 + 0x4c);
      _DAT_800e1160 = *(undefined4 *)(iVar3 + 0x54);
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1134 = 0x5000000;
      _DAT_800e1380 = param_1;
      func_0x80052bd0(4,0);
      func_0x80052c6c(4,0xfa,0);
      func_0x80052d10(100,0x32,0x96,0);
      *(undefined2 *)(param_1 + 0x1f6) = 0x96;
    }
  }
  else if (bVar1 == 2) {
    _DAT_800e1128 = 0x78;
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  return;
}
