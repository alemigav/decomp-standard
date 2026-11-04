/* FUN_80162d54
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80162d54  body 0x80162d54..0x8016301f  size 716 B
 * body sha256 222fcd9dec04f9d7d1401df8f660b2b229fe3627bee995a9d7822c1c7016c998
 * provider record sha256 bb8bcbcd8dc0c6b11b2a34b63b02bbc9571050be4a7bbb08e5a197af9b879071
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162d54(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_70 [20];
  int local_5c;
  int local_58;
  int local_54;
  undefined1 auStack_50 [20];
  uint local_3c;
  uint local_38;
  uint local_34;
  
  uVar4 = param_1[0x8d];
  if (*(char *)((int)param_1 + 6) == '\0') {
    iVar3 = (uint)*(byte *)((int)param_1 + 0x2c2) * 0xe;
    *param_1 = *param_1 & 0xfeffffff;
    iVar2 = _DAT_800e1364;
    func_0x80040e58(&DAT_80163944 + iVar3,auStack_70,0x18000,param_4,0x140000,0);
    local_5c = (int)*(short *)(&DAT_8016393e + iVar3);
    local_58 = (int)*(short *)(&DAT_80163940 + iVar3);
    local_54 = (int)*(short *)(&DAT_80163942 + iVar3);
    func_0x800424ec(iVar2 + (uint)*(ushort *)(&DAT_8016393c + iVar3) * 0x178 + 0x38,auStack_70,
                    auStack_50);
    param_1[10] = local_3c;
    param_1[0xb] = local_38;
    param_1[0xc] = local_34;
    sVar1 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,
                            (int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32));
    *(undefined2 *)(param_1 + 0x78) = 0x32;
    *(undefined2 *)(param_1 + 0x79) = 0;
    func_0x800837d0((int)sVar1,param_1 + 0x78,param_1 + 0x78);
    *(undefined2 *)(param_1 + 0x19) = 0;
    *(undefined2 *)((int)param_1 + 0x66) = 0;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    param_1[0x1c] = (uint)(param_1 + 0x6e);
    func_0x80036e70(param_1);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0x14;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  else if (*(char *)((int)param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032b5c(param_1,0);
  sVar1 = *(short *)((int)param_1 + 0x1e2) + *(short *)(param_1 + 0x7d) + 2;
  *(short *)((int)param_1 + 0x1e2) = sVar1;
  *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 2;
  iVar2 = *(short *)(param_1 + 0x77) + -0xc00;
  param_1[0xb] = param_1[0xb] + (int)sVar1;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (0x10 < iVar2) {
    sVar1 = *(short *)(param_1 + 0x77) + -0x10;
    if (0xbff < *(short *)(param_1 + 0x77)) {
      sVar1 = *(short *)(param_1 + 0x77) + 0x10;
    }
    *(short *)(param_1 + 0x77) = sVar1;
    func_0x80040e58(param_1 + 0x76,param_1[0x1c]);
  }
  sVar1 = func_0x80069f1c(param_1 + 10,1,0x400,0);
  if (_DAT_80112710 < sVar1) {
    sVar1 = _DAT_80112712;
  }
  if ((int)sVar1 <= (int)param_1[0xb]) {
    func_0x80077d18(1,param_1);
    param_1[0xb] = (int)sVar1;
    FUN_801634c8(param_1);
    *(undefined4 *)(uVar4 + 0x2f0) = 0;
    *(undefined4 *)(uVar4 + 0x468) = 0;
    *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) & 0xfffe;
    DAT_80163b00 = DAT_80163b00 & ~(1 << (*(byte *)((int)param_1 + 0x2c2) & 0x1f));
    param_1[1] = 0x1000000;
  }
  return;
}
