/* FUN_8002fef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fef4  body 0x8002fef4..0x8002ffeb  size 248 B
 * body sha256 91d207efc5ea8a4b590ffb77638c74cdc35fd0c6c3c00d53c8d41a31fd7090c3
 * provider record sha256 23086ed1f4a0dff5801989ff9e38daad57ee0676aa87e4ebea9cf6357950bcbe
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_8002fef4(int *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1[1];
  if (0x3b9ac9f0 < param_3) {
    FUN_8002fd00(param_1,3);
  }
  if ((param_3 & 7) != 0) {
    param_3 = (param_3 + 8) - (param_3 & 7);
  }
  if (1 < param_2) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    *(uint *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar1 = (undefined4 *)FUN_8002fc9c(param_1,param_3 + 0x10);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_8002fd00(param_1,4);
  }
  iVar2 = iVar4 + param_2 * 4;
  *(uint *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 0x10 + param_3;
  uVar3 = *(undefined4 *)(iVar2 + 0x38);
  puVar1[1] = param_3;
  puVar1[2] = 0;
  *puVar1 = uVar3;
  *(undefined4 **)(iVar2 + 0x38) = puVar1;
  return puVar1 + 4;
}
