/* func_800092c0
 * image   boot (boot), base 0x80000480
 * address 0x800092c0  body 0x800092c0..0x8000946f  size 432 B
 * body sha256 e447b99da329a2f793202042f40f895ce9566b4d9ebeb1a14948f542247eeb46
 * provider record sha256 d3fc69ab5614585fc3b1ad1766539ce7b74fdf8cf73ae79e1670441727f5ad37
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_800092c0(float *param_1,undefined2 *param_2,float param_3,float param_4,float param_5,
                  float param_6,float param_7)

{
  undefined2 uVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  FUN_80009120();
  dVar5 = (double)param_3 * _DAT_80011b30;
  fVar7 = (float)dVar5 / 2.0;
  FUN_80006be0(fVar7);
  fVar6 = SUB84(dVar5,0);
  fVar8 = fVar6;
  FUN_8000d050(fVar7);
  iVar4 = 0;
  param_1[0xf] = 0.0;
  param_1[0xb] = -1.0;
  param_1[5] = fVar8 / fVar6;
  param_1[10] = (param_5 + param_6) / (param_5 - param_6);
  param_1[0xe] = ((param_5 + param_5) * param_6) / (param_5 - param_6);
  *param_1 = (fVar8 / fVar6) / param_4;
  do {
    iVar3 = 0;
    pfVar2 = param_1;
    do {
      iVar3 = iVar3 + 1;
      *pfVar2 = *pfVar2 * param_7;
      pfVar2 = pfVar2 + 1;
    } while (iVar3 < 4);
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 4;
  } while (iVar4 < 4);
  if (param_2 != (undefined2 *)0x0) {
    uVar1 = 0xffff;
    if (_DAT_80011b38 < (double)(param_5 + param_6)) {
      dVar5 = _DAT_80011b40 / (double)(param_5 + param_6);
      if (_DAT_80011b48 <= dVar5) {
        dVar5 = dVar5 - _DAT_80011b48;
      }
      *param_2 = (short)(int)dVar5;
      uVar1 = 1;
      if (((int)dVar5 & 0xffffU) != 0) {
        return;
      }
    }
    *param_2 = uVar1;
  }
  return;
}
