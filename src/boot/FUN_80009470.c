/* FUN_80009470
 * image   boot (boot), base 0x80000480
 * address 0x80009470  body 0x80009470..0x80009637  size 456 B
 * body sha256 a28338e418ae8b07f13e75aedf82be43e7f2330cfe05a11ddf7ea692d430bdf6
 * provider record sha256 2cd601432a23bdc558772ce5621e33cd2aefad15127b9911b7315b4f5f291cdb
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80009470(undefined4 param_1,undefined2 *param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7)

{
  undefined2 uVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float fVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  float local_78 [5];
  float local_64;
  float local_50;
  undefined4 local_4c;
  float local_40;
  undefined4 local_3c;
  
  pfVar5 = local_78;
  FUN_80009120(pfVar5);
  fVar6 = 2.0;
  fVar8 = (float)((double)param_3 * _DAT_80011b50) / 2.0;
  FUN_80006be0(fVar8);
  fVar9 = fVar6;
  FUN_8000d050(fVar8);
  iVar4 = 0;
  local_3c = 0;
  local_4c = 0xbf800000;
  local_64 = fVar9 / fVar6;
  local_50 = (param_5 + param_6) / (param_5 - param_6);
  local_40 = ((param_5 + param_5) * param_6) / (param_5 - param_6);
  local_78[0] = (fVar9 / fVar6) / param_4;
  do {
    iVar3 = 0;
    pfVar2 = pfVar5;
    do {
      iVar3 = iVar3 + 1;
      *pfVar2 = *pfVar2 * param_7;
      pfVar2 = pfVar2 + 1;
    } while (iVar3 < 4);
    iVar4 = iVar4 + 1;
    pfVar5 = pfVar5 + 4;
  } while (iVar4 < 4);
  if (param_2 != (undefined2 *)0x0) {
    uVar1 = 0xffff;
    if (_DAT_80011b58 < (double)(param_5 + param_6)) {
      dVar7 = _DAT_80011b60 / (double)(param_5 + param_6);
      if (_DAT_80011b68 <= dVar7) {
        dVar7 = dVar7 - _DAT_80011b68;
      }
      *param_2 = (short)(int)dVar7;
      if (((int)dVar7 & 0xffffU) != 0) goto LAB_80009604;
      uVar1 = 1;
    }
    *param_2 = uVar1;
  }
LAB_80009604:
  FUN_80008fe0(local_78,param_1);
  return;
}
