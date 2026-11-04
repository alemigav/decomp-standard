/* FUN_80010c70
 * image   boot (boot), base 0x80000480
 * address 0x80010c70  body 0x80010c70..0x80010eb3  size 580 B
 * body sha256 12270bab2dd8f72c6ed0bd80231182c1abe11bc447a4f99709ff241c86a44f92
 * provider record sha256 bc4c2278a9b5682f9fc6881710c13fdbe9a480e76372173fe0570590038f2890
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80010c70(int *param_1,char param_2)

{
  byte bVar1;
  int extraout_v1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 auStack_48 [23];
  undefined1 local_31;
  int local_30;
  int local_2c;
  int local_24;
  
  iVar7 = -0x7ffec7a0;
  if (param_2 == 'X') {
    iVar7 = -0x7ffec78c;
  }
  if (param_2 == 'o') {
    uVar4 = 8;
  }
  else {
    uVar4 = 0x10;
    if (param_2 != 'x' && param_2 != 'X') {
      uVar4 = 10;
    }
  }
  iVar5 = *param_1;
  iVar6 = param_1[1];
  iVar3 = 0x18;
  if ((param_2 == 'd' || param_2 == 'i') && (*param_1 < 0)) {
    iVar6 = -iVar6;
    iVar5 = -(uint)(iVar6 != 0) - iVar5;
  }
  if (((iVar5 != 0) || (iVar6 != 0)) || (param_1[9] != 0)) {
    iVar3 = 0x17;
    FUN_80010ec0(iVar5,iVar6,0,uVar4);
    local_31 = *(undefined1 *)(iVar7 + extraout_v1);
  }
  uVar8 = FUN_80006100(iVar5,iVar6,0,uVar4);
  *(undefined8 *)param_1 = uVar8;
  puVar2 = auStack_48 + iVar3;
  while( true ) {
    bVar1 = 0;
    if ((0 < *param_1) || ((*param_1 == 0 && (param_1[1] != 0)))) {
      bVar1 = 1;
    }
    if (!(bool)(bVar1 & 0 < iVar3)) break;
    FUN_80010584(&local_30);
    *param_1 = local_30;
    param_1[1] = local_2c;
    puVar2 = puVar2 + -1;
    iVar3 = iVar3 + -1;
    *puVar2 = *(undefined1 *)(iVar7 + local_24);
  }
  param_1[5] = 0x18 - iVar3;
  FUN_8000de9c(param_1[2],auStack_48 + iVar3);
  if (param_1[5] < param_1[9]) {
    param_1[4] = param_1[9] - param_1[5];
  }
  if (((param_1[9] < 0) && ((param_1[0xc] & 0x14U) == 0x10)) &&
     (iVar7 = ((param_1[10] - param_1[3]) - param_1[4]) - param_1[5], 0 < iVar7)) {
    param_1[4] = param_1[4] + iVar7;
  }
  return;
}
