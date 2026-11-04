/* FUN_8002c8bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002c8bc  body 0x8002c8bc..0x8002c9bf  size 260 B
 * body sha256 709dd3690cf6046f9d0fdb68128b1bcd5cbc2f56105e7e1e62b6fa9a04218dce
 * provider record sha256 3b251df452f763edc28d2e4e1b5fefd25b9216212ac61dafcda89f0bd99ffb8a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002c8bc(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)param_1[5];
  puVar4 = (undefined1 *)*puVar5;
  iVar3 = puVar5[1];
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar5[3])();
    if (iVar3 == 0) {
      return 0;
    }
    puVar4 = (undefined1 *)*puVar5;
    iVar3 = puVar5[1];
  }
  iVar3 = iVar3 + -1;
  uVar1 = *puVar4;
  puVar4 = puVar4 + 1;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar5[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar4 = (undefined1 *)*puVar5;
    iVar3 = puVar5[1];
  }
  uVar2 = *puVar4;
  *(undefined4 *)(*param_1 + 0x14) = 0x53;
  *(int *)(*param_1 + 0x18) = param_1[0x58];
  *(uint *)(*param_1 + 0x1c) = (uint)CONCAT11(uVar1,uVar2);
  (**(code **)(*param_1 + 4))(param_1,1);
  *puVar5 = puVar4 + 1;
  puVar5[1] = iVar3 + -1;
  (**(code **)(param_1[5] + 0x10))(param_1,CONCAT11(uVar1,uVar2) - 2);
  return 1;
}
