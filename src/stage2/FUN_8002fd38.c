/* FUN_8002fd38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fd38  body 0x8002fd38..0x8002fef3  size 444 B
 * body sha256 ba9a6f72e122aa2ed3488f59fea2644c7c1129b2c52c1aca9c7409f793c0080a
 * provider record sha256 c3fa569a47b34668bedb72277fc5dc98e0baaac9a2071c2b8d7bbc59c47f34b3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8002fd38(int *param_1,uint param_2,uint param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = param_1[1];
  if (0x3b9ac9f0 < param_3) {
    FUN_8002fd00(param_1,1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = (param_3 + 8) - (param_3 & 7);
  }
  if (1 < param_2) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    *(uint *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar2 = *(undefined4 **)(iVar7 + param_2 * 4 + 0x30);
  puVar6 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3;
      if (param_3 <= (uint)puVar3[2]) break;
      puVar2 = (undefined4 *)*puVar3;
      puVar6 = puVar3;
    } while (puVar2 != (undefined4 *)0x0);
    if (puVar2 != (undefined4 *)0x0) goto LAB_8002feb0;
  }
  iVar5 = param_3 + 0x10;
  if (puVar6 == (undefined4 *)0x0) {
    puVar1 = &DAT_800b8040;
  }
  else {
    puVar1 = &DAT_800b8048;
  }
  uVar4 = *(uint *)(puVar1 + param_2 * 4);
  if (1000000000U - iVar5 < *(uint *)(puVar1 + param_2 * 4)) {
    uVar4 = 1000000000U - iVar5;
  }
  while( true ) {
    puVar2 = (undefined4 *)FUN_8002fc78(param_1,iVar5 + uVar4);
    if (puVar2 != (undefined4 *)0x0) break;
    uVar4 = uVar4 >> 1;
    if (uVar4 < 0x32) {
      FUN_8002fd00(param_1,2);
    }
  }
  *(uint *)(iVar7 + 0x48) = *(int *)(iVar7 + 0x48) + iVar5 + uVar4;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = param_3 + uVar4;
  if (puVar6 == (undefined4 *)0x0) {
    *(undefined4 **)(iVar7 + param_2 * 4 + 0x30) = puVar2;
  }
  else {
    *puVar6 = puVar2;
  }
LAB_8002feb0:
  iVar7 = puVar2[1];
  puVar2[1] = iVar7 + param_3;
  puVar2[2] = puVar2[2] - param_3;
  return (int)puVar2 + iVar7 + 0x10;
}
