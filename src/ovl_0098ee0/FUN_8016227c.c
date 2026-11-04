/* FUN_8016227c
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x8016227c  body 0x8016227c..0x801623c7  size 332 B
 * body sha256 438b29dae809e60f8f03160a9b3c40e27914e3ea6c2ac166f231461964e10990
 * provider record sha256 ef1466a3066725a5e2e12ef2c973b053730b93ead26f78e57898da08ed3c6ff2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016227c(int param_1,short *param_2,int param_3)

{
  short sVar1;
  char cVar2;
  int iVar3;
  
  _DAT_800e1134 = 0x5000000;
  iVar3 = *(int *)(param_1 + 0x234) + param_3 * 0x178;
  sVar1 = func_0x80032d14((int)*param_2,(int)param_2[2],(int)_DAT_800e1164,(int)_DAT_800e1168);
  if ((((int)sVar1 - (int)_DAT_800e1196) + 0x400U & 0xfff) < 0x800) {
    func_0x80032ef4(0x800e1130,(int)*(short *)(param_1 + 0x66),0x200);
    *param_2 = _DAT_800e115a + (*(short *)(iVar3 + 0x4e) - *param_2);
    param_2[2] = _DAT_800e1162 + (*(short *)(iVar3 + 0x56) - param_2[2]);
    cVar2 = DAT_800e1135 + '\x01';
    _DAT_800e1135 = CONCAT12(cVar2,DAT_800e1134_1._1_2_);
  }
  else {
    func_0x80032ef4(0x800e1130,(int)((*(ushort *)(param_1 + 0x66) - 0x800) * 0x10000) >> 0x10,0x200)
    ;
    *param_2 = _DAT_800e115a - (*(short *)(iVar3 + 0x4e) - *param_2);
    param_2[2] = _DAT_800e1162 - (*(short *)(iVar3 + 0x56) - param_2[2]);
  }
  _DAT_800e1380 = param_1;
  _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
  _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
  return;
}
