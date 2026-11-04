/* FUN_8009ef50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ef50  body 0x8009ef50..0x8009f313  size 964 B
 * body sha256 e5ead78b85a7f8ba5f0887e20994c3ed483b4b26d566279e772c523394af90bd
 * provider record sha256 6ec12686894123522a7ba8230b9ea21dd71c9b92dd0c76ebdecaef6a6278f6f4
 * callees 4 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ef50(uint param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  
  fVar8 = (float)param_3;
  if (param_3 < 0) {
    fVar8 = fVar8 + 4.2949673e+09;
  }
  if (param_5 < 0) {
    fVar7 = (float)param_5 + 4.2949673e+09;
  }
  else {
    fVar7 = (float)param_5;
  }
  fVar8 = (fVar8 * 65536.0) / fVar7 + 1.0;
  if (fVar8 < 2.1474836e+09) {
    DAT_801343a8 = (uint)fVar8;
  }
  else {
    DAT_801343a8 = (int)(fVar8 - 2.1474836e+09) | 0x80000000;
  }
  fVar8 = (float)(param_4 + -1);
  if (param_4 + -1 < 0) {
    fVar8 = fVar8 + 4.2949673e+09;
  }
  if (param_6 < 0) {
    fVar7 = (float)param_6 + 4.2949673e+09;
  }
  else {
    fVar7 = (float)param_6;
  }
  fVar8 = (fVar8 * 65536.0) / fVar7 + 1.0;
  if (fVar8 < 2.1474836e+09) {
    uVar6 = (uint)fVar8;
  }
  else {
    uVar6 = (int)(fVar8 - 2.1474836e+09) | 0x80000000;
  }
  DAT_80134398 = param_1 & 0xfffffff;
  DAT_8013439c = param_2 & 0xfffffff;
  DAT_801343a0 = param_5;
  DAT_801343b8 = 0;
  DAT_801343bc = 0;
  DAT_801343d8 = 0xffff7fff;
  DAT_801343dc = 0x30004;
  DAT_801343e0 = 0x100f8;
  DAT_801343e4 = 0x40000008;
  DAT_801343e8 = 0x800007;
  DAT_801343ec = 0x800000ff;
  DAT_801343b0 = param_7 << 1;
  DAT_801343b4 = 0x133290;
  DAT_801343f0 = DAT_801343a8 << 3;
  DAT_801343ac = uVar6;
  DAT_801343f4 = uVar6;
  uVar1 = FUN_80031a20((DAT_800e8ca8 + 1) * 0x1000 + DAT_800e8caa * 0x10 + (int)DAT_800e8cac);
  DAT_801343f8 = uVar1 | 0x3c00000;
  func_0x8000f020();
  if (param_6 < 0) {
    fVar8 = (float)param_6 + 4.2949673e+09;
  }
  else {
    fVar8 = (float)param_6;
  }
  fVar8 = (fVar8 * 65536.0) / 6.0 + 1.0;
  if (fVar8 < 2.1474836e+09) {
    uVar2 = (uint)fVar8;
    uVar1 = uVar2;
  }
  else {
    uVar2 = (int)(fVar8 - 2.1474836e+09) | 0x80000000;
    uVar1 = (int)(fVar8 - 2.1474836e+09);
  }
  uVar4 = 0;
  uVar5 = 0;
  do {
    uVar4 = uVar4 + (uVar1 & 0xffff);
    uVar3 = uVar2 >> 0x10;
    if ((uVar4 & 0xffff0000) != 0) {
      uVar4 = uVar4 & 0xffff;
      uVar3 = (uVar2 >> 0x10) + 1;
    }
    DAT_801343a4 = uVar3;
    func_0x8000efa0(&DAT_80134398,0x80);
    DAT_801344f4 = 2;
    FUN_8006c044(&DAT_80133250,1);
    do {
    } while (DAT_801344f4 != 0);
    uVar5 = uVar5 + 1;
    DAT_8013439c = DAT_8013439c + param_7 * uVar3 * 2;
    DAT_801343bc = DAT_801343bc + uVar3 * uVar6;
  } while (uVar5 < 6);
  return;
}
