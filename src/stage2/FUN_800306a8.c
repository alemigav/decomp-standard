/* FUN_800306a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800306a8  body 0x800306a8..0x800307c7  size 288 B
 * body sha256 051b1a1755d64e20c5b000ed19504d92910b328547cf5b2beb7563348c9087e9
 * provider record sha256 d4be56de08bd2e69eb407b4f642cfea3c247e756ab7df0bb776a4d95fdc5b44b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800306a8(undefined4 param_1,int *param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = param_2[2];
  iVar6 = param_2[6] * iVar7;
  iVar2 = param_2[4];
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = iVar2 - iVar5;
      if (param_2[5] < iVar2 - iVar5) {
        iVar3 = param_2[5];
      }
      iVar2 = param_2[1] - (param_2[6] + iVar5);
      if (iVar3 < iVar2) {
        iVar2 = iVar3;
      }
      iVar3 = iVar2 * iVar7;
      if (iVar2 < 1) {
        return;
      }
      if (param_3 == 0) {
        uVar4 = *(undefined4 *)(iVar5 * 4 + *param_2);
        pcVar1 = (code *)param_2[10];
      }
      else {
        uVar4 = *(undefined4 *)(iVar5 * 4 + *param_2);
        pcVar1 = (code *)param_2[0xb];
      }
      (*pcVar1)(param_1,param_2 + 10,uVar4,iVar6,iVar3);
      iVar2 = param_2[4];
      iVar5 = iVar5 + param_2[5];
      iVar6 = iVar6 + iVar3;
    } while (iVar5 < iVar2);
  }
  return;
}
