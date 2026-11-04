/* FUN_80048d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048d90  body 0x80048d90..0x800490eb  size 860 B
 * body sha256 55f3dbca66b707558f91f1cc587f734ac78ef361a7e25d3cef238251f27934a9
 * provider record sha256 3fcc033f389b69241b92a95f6442cd35dafbf6f45e9250f11cc82dcecbd97044
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80048d90(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar5 = *param_2;
  fVar3 = param_2[1];
  fVar4 = param_2[2];
  fVar2 = fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4;
  if (fVar2 < 1e-11) {
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    *param_1 = 1.0;
    param_1[4] = 1.0;
    param_1[5] = 0.0;
    param_1[6] = 0.0;
    param_1[7] = 0.0;
    param_1[8] = 1.0;
  }
  else {
    if ((1.000001 < fVar2) || (fVar2 < 0.99999)) {
      fVar2 = (float)FUN_80048060(fVar2);
      fVar5 = fVar5 * fVar2;
      fVar3 = fVar3 * fVar2;
      fVar4 = fVar4 * fVar2;
    }
    fVar2 = (float)func_0x80006be0(param_3);
    fVar1 = 1.0 - fVar2;
    if (fVar5 == 0.0) {
      fVar6 = fVar1 * fVar3;
      *param_1 = fVar2;
      param_1[4] = fVar6 * fVar3 + fVar2;
      param_1[8] = fVar1 * fVar4 * fVar4 + fVar2;
      fVar5 = (float)func_0x8000d050(param_3);
      param_1[1] = fVar5 * fVar4;
      param_1[3] = -fVar5 * fVar4;
      param_1[2] = -fVar5 * fVar3;
      param_1[6] = fVar5 * fVar3;
      param_1[5] = fVar6 * fVar4;
      param_1[7] = fVar6 * fVar4;
    }
    else {
      if (fVar3 == 0.0) {
        fVar6 = fVar1 * fVar5;
        param_1[4] = fVar2;
        *param_1 = fVar6 * fVar5 + fVar2;
        param_1[8] = fVar1 * fVar4 * fVar4 + fVar2;
        fVar3 = (float)func_0x8000d050(param_3);
        fVar2 = fVar3 * fVar5;
        fVar5 = -fVar3 * fVar5;
        param_1[1] = fVar3 * fVar4;
        param_1[3] = -fVar3 * fVar4;
        param_1[2] = fVar6 * fVar4;
        param_1[6] = fVar6 * fVar4;
      }
      else {
        if (fVar4 != 0.0) {
          fVar6 = fVar1 * fVar5;
          fVar7 = fVar1 * fVar3;
          *param_1 = fVar6 * fVar5 + fVar2;
          param_1[4] = fVar7 * fVar3 + fVar2;
          param_1[8] = fVar1 * fVar4 * fVar4 + fVar2;
          fVar2 = (float)func_0x8000d050(param_3);
          param_1[1] = fVar6 * fVar3 + fVar2 * fVar4;
          param_1[3] = fVar6 * fVar3 - fVar2 * fVar4;
          param_1[2] = fVar6 * fVar4 - fVar2 * fVar3;
          param_1[6] = fVar6 * fVar4 + fVar2 * fVar3;
          param_1[5] = fVar7 * fVar4 + fVar2 * fVar5;
          param_1[7] = fVar7 * fVar4 - fVar2 * fVar5;
          return;
        }
        fVar6 = fVar1 * fVar5;
        param_1[8] = fVar2;
        *param_1 = fVar6 * fVar5 + fVar2;
        param_1[4] = fVar1 * fVar3 * fVar3 + fVar2;
        fVar4 = (float)func_0x8000d050(param_3);
        fVar2 = fVar4 * fVar5;
        fVar5 = -fVar4 * fVar5;
        param_1[1] = fVar6 * fVar3;
        param_1[3] = fVar6 * fVar3;
        param_1[2] = -fVar4 * fVar3;
        param_1[6] = fVar4 * fVar3;
      }
      param_1[5] = fVar2;
      param_1[7] = fVar5;
    }
  }
  return;
}
