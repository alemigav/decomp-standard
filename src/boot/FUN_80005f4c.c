/* FUN_80005f4c
 * image   boot (boot), base 0x80000480
 * address 0x80005f4c  body 0x80005f4c..0x800060fb  size 432 B
 * body sha256 fda26ed3da4065fbe652f7f30ba959e1d073a4dca926bda1a4098072035e492b
 * provider record sha256 69e8e2ce34b5ff7504a82088aa7db29c59ed50c92ebf7a5e97aa1346c85096ef
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_80005f4c(short param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int local_58 [6];
  int local_40 [6];
  
  if (param_1 != -1) {
    piVar8 = local_58;
    piVar7 = local_40;
    _DAT_800128ac = (int *)(_DAT_800c52d8 + 0xaf800);
    FUN_800051b8();
    piVar4 = _DAT_800128ac;
    iVar9 = *_DAT_800128ac;
    param_2[1] = iVar9;
    piVar2 = param_2 + 2;
    iVar6 = iVar9;
    piVar3 = piVar4;
    while( true ) {
      iVar6 = iVar6 + -1;
      if (iVar6 == -1) break;
      uVar5 = piVar3[1];
      piVar3 = piVar3 + 2;
      iVar1 = *piVar3;
      *piVar7 = (int)piVar2;
      piVar7 = piVar7 + 1;
      _DAT_800128ac = piVar4;
      *piVar2 = iVar1;
      iVar1 = FUN_8000521c((uVar5 >> 0x10) + 0x49b & 0xffff,piVar2 + 1);
      *piVar8 = iVar1;
      piVar2 = (int *)FUN_80005438((uVar5 & 0xffff) + 0x49b & 0xffff);
      piVar8 = piVar8 + 1;
    }
    *param_2 = ((int)piVar2 - (int)param_2 >> 2) << 2;
    iVar6 = 0;
    if (0 < iVar9) {
      piVar4 = local_58;
      piVar3 = local_40;
      do {
        iVar1 = *piVar3;
        piVar3 = piVar3 + 1;
        iVar6 = iVar6 + 1;
        *piVar2 = (iVar1 - (int)param_2 >> 2) << 2;
        iVar1 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar2[1] = (iVar1 - (int)param_2 >> 2) << 2;
        piVar2 = piVar2 + 2;
      } while (iVar6 < iVar9);
    }
    param_2 = piVar2;
    if (_DAT_800128ac < param_2) {
      trap(0);
    }
  }
  return param_2;
}
