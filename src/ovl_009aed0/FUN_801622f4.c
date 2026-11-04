/* FUN_801622f4
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801622f4  body 0x801622f4..0x80162543  size 592 B
 * body sha256 01c345318f5989746045d32238c67e3057a45079a05eab3f933fbbde174b55fb
 * provider record sha256 7cb40696cb0f5fa1558f715b702a4e0ca32227fee3843a428895985f593bec9e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_801622f4(int param_1,int param_2,ushort param_3,ushort param_4,int param_5,int param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar5;
  uint uVar4;
  int iVar6;
  uint uVar7;
  int iVar8;
  short local_28;
  undefined2 local_26;
  short local_24;
  
  sVar5 = *(short *)(param_1 + 0x2c8);
  sVar1 = *(short *)(param_1 + 0x2ca);
  iVar8 = param_2 * 0x178 + *(int *)(param_1 + 0x234);
  *(undefined2 *)(param_1 + 0x2c8) = *(undefined2 *)(iVar8 + 0x4e);
  *(undefined2 *)(param_1 + 0x2ca) = *(undefined2 *)(iVar8 + 0x56);
  if (param_3 <= *(byte *)(param_1 + 0x1e9)) {
    if (param_4 < *(byte *)(param_1 + 0x1e9)) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x28) - *(int *)(iVar8 + 0x4c);
    iVar3 = *(int *)(param_1 + 0x30) - *(int *)(iVar8 + 0x54);
    iVar2 = func_0x80040bb4(iVar2 * iVar2 + iVar3 * iVar3);
    iVar3 = *(int *)(param_1 + 0x28) - (int)sVar5;
    iVar6 = *(int *)(param_1 + 0x30) - (int)sVar1;
    iVar3 = func_0x80040bb4(iVar3 * iVar3 + iVar6 * iVar6);
    if ((*(short *)(param_1 + 500) == 0) &&
       (*(uint *)(param_1 + 0x28c) < (uint)(iVar2 + iVar3 + 500 + param_6) >> 1)) {
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)sVar5,(int)sVar1);
      iVar3 = (int)sVar5;
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)*(short *)(iVar8 + 0x4e),(int)*(short *)(iVar8 + 0x56));
      iVar6 = (int)sVar5;
      iVar2 = iVar6;
      if (iVar6 < iVar3) {
        iVar2 = iVar3;
        iVar3 = iVar6;
      }
      uVar7 = iVar2 - iVar3 & 0xfff;
      if (uVar7 < 0x800) {
        iVar3 = iVar3 - param_5;
      }
      else {
        iVar3 = uVar7 + iVar3;
        uVar7 = 0x1000 - uVar7;
        iVar3 = (iVar3 + -0x1000) - param_5;
      }
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      uVar4 = sVar5 - iVar3 & 0xfff;
      if ((uVar4 != 0) && ((int)uVar4 < (int)(uVar7 + param_5 * 2))) {
        local_28 = _DAT_800e115a;
        local_26 = *(undefined2 *)(iVar8 + 0x52);
        local_24 = _DAT_800e1162;
        func_0x80037780(0x62800,(int)*(short *)(param_1 + 0x66),0x800e9028,&local_28);
        *(undefined2 *)(param_1 + 500) = 1;
        return 1;
      }
    }
  }
  return 0;
}
