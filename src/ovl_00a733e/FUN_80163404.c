/* FUN_80163404
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163404  body 0x80163404..0x8016361f  size 540 B
 * body sha256 302620b2d7bc750571141539b7f05a85e25cc0e0f4b0bc210422040a46537914
 * provider record sha256 3975c843437347f7da2eee6c97bfcbcde1b68368c86dc8dc136de7c1ac191f78
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163404(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar4;
  uint uVar3;
  uint uVar5;
  
  func_0x800334c8();
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 == 0) {
    uVar5 = **(uint **)(param_1 + 0x214);
    if (((*(char *)(param_1 + 7) == '\0') && (*(short *)(param_1 + 0x1f6) != 0)) &&
       (bVar1 = false, (uVar5 & 0x20000) != 0)) {
      iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x440);
      if (iVar2 != 0) {
        uVar3 = func_0x80033604();
        bVar1 = (0x5a0 >> (uVar3 & 0xf) & 1U) == 0;
      }
      if (bVar1) {
        *(undefined1 *)(param_1 + 7) = 1;
        *(undefined1 *)(param_1 + 0x2c0) = 1;
      }
      else {
        func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
        *(undefined2 *)(param_1 + 6) = 1;
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) ^ 1;
      }
    }
  }
  else {
    uVar5 = **(uint **)(param_1 + 0x214);
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    if (*(char *)(param_1 + 0x2c0) == '\0') {
      bVar4 = func_0x80033604();
      *(byte *)(param_1 + *(short *)(param_1 + 0x2b6) + 0x2b8) =
           *(char *)(param_1 + 0x206) + '\n' + (bVar4 & 7);
    }
    FUN_801631d4(param_1);
    FUN_80163824(param_1);
    *(undefined1 *)(param_1 + 0x2c0) = 0;
    *(char *)(param_1 + 0x2c7) = *(char *)(param_1 + 0x206) * '\x04' + '<';
  }
  func_0x80032b5c(param_1,0);
  func_0x80033648(param_1);
  if ((((uVar5 & 0x10000) != 0) && (*(char *)(param_1 + 0x206) == '\0')) &&
     (iVar2 = FUN_801676cc(param_1,(int)*(short *)(param_1 + 0x2b6)), iVar2 != 0)) {
    func_0x80077d18(3,param_1);
    *(undefined1 *)(param_1 + 0x206) = 0xf;
    *(undefined1 *)(param_1 + 0x207) = 3;
    FUN_80167374(&DAT_800e1130,8,0);
  }
  FUN_80163620(param_1,(int)(short)(&DAT_80167d6c)[*(short *)(param_1 + 0x2b6) * 2] + 1U & 0xff);
  return;
}
