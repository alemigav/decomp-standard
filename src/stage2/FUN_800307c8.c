/* FUN_800307c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800307c8  body 0x800307c8..0x800308eb  size 292 B
 * body sha256 c331f1dc11c324c715900a844e7595908281f213699512536da0d446e5ab46b9
 * provider record sha256 ae3f4068b0a0a9fa7711f990f3b0d63c30fe635364baeacee070ab524b347f26
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800307c8(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = param_2[2];
  iVar7 = param_2[6] * iVar1 * 0x80;
  iVar3 = param_2[4];
  iVar6 = 0;
  if (0 < iVar3) {
    do {
      iVar4 = iVar3 - iVar6;
      if (param_2[5] < iVar3 - iVar6) {
        iVar4 = param_2[5];
      }
      iVar3 = param_2[1] - (param_2[6] + iVar6);
      if (iVar4 < iVar3) {
        iVar3 = iVar4;
      }
      iVar4 = iVar3 * iVar1 * 0x80;
      if (iVar3 < 1) {
        return;
      }
      if (param_3 == 0) {
        uVar5 = *(undefined4 *)(iVar6 * 4 + *param_2);
        pcVar2 = (code *)param_2[10];
      }
      else {
        uVar5 = *(undefined4 *)(iVar6 * 4 + *param_2);
        pcVar2 = (code *)param_2[0xb];
      }
      (*pcVar2)(param_1,param_2 + 10,uVar5,iVar7,iVar4);
      iVar3 = param_2[4];
      iVar6 = iVar6 + param_2[5];
      iVar7 = iVar7 + iVar4;
    } while (iVar6 < iVar3);
  }
  return;
}
