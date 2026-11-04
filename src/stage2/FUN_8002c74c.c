/* FUN_8002c74c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002c74c  body 0x8002c74c..0x8002c8bb  size 368 B
 * body sha256 bc76a88793de945d4fbf6a7ceb4813d67d272b2dc69897388c4286f81132159b
 * provider record sha256 f1313febd4a41db0f1b5a784bbdb26fd271d27252954e329bc2d987805575789
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002c74c(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)param_1[5];
  puVar5 = (undefined1 *)*puVar7;
  iVar3 = puVar7[1];
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar7[3])();
    if (iVar3 == 0) {
      return 0;
    }
    puVar5 = (undefined1 *)*puVar7;
    iVar3 = puVar7[1];
  }
  iVar3 = iVar3 + -1;
  uVar1 = *puVar5;
  puVar5 = puVar5 + 1;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar7[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar5 = (undefined1 *)*puVar7;
    iVar3 = puVar7[1];
  }
  puVar6 = puVar5 + 1;
  if (CONCAT11(uVar1,*puVar5) != 4) {
    *(undefined4 *)(*param_1 + 0x14) = 9;
    (**(code **)*param_1)(param_1);
  }
  iVar4 = iVar3 + -2;
  if (iVar3 == 1) {
    iVar3 = (*(code *)puVar7[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar7;
    iVar4 = puVar7[1] + -1;
  }
  uVar1 = *puVar6;
  puVar6 = puVar6 + 1;
  if (iVar4 == 0) {
    iVar3 = (*(code *)puVar7[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar7;
    iVar4 = puVar7[1];
  }
  uVar2 = *puVar6;
  *(undefined4 *)(*param_1 + 0x14) = 0x4a;
  *(uint *)(*param_1 + 0x18) = (uint)CONCAT11(uVar1,uVar2);
  (**(code **)(*param_1 + 4))(param_1,1);
  param_1[0x3a] = (uint)CONCAT11(uVar1,uVar2);
  *puVar7 = puVar6 + 1;
  puVar7[1] = iVar4 + -1;
  return 1;
}
