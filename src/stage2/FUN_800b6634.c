/* FUN_800b6634
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b6634  body 0x800b6634..0x800b6787  size 340 B
 * body sha256 d3ea61a13aa26f8ba417dd30be6b8a77ae25595bb5f039c6c361657a6e53f304
 * provider record sha256 98149da4b45c9f2724a3aafb8069e0c18ef6f1a4cd90f4f160945742bfafeee7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b6634(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar2 = *(undefined4 *)(param_1 + 0x140);
  uVar3 = *(undefined4 *)(param_1 + 0x144);
  uVar4 = *(undefined4 *)(param_1 + 0x148);
  uVar5 = *(undefined4 *)(param_1 + 0x14c);
  uVar6 = *(undefined4 *)(param_1 + 0x150);
  uVar7 = *(undefined4 *)(param_1 + 0x154);
  uVar8 = *(undefined4 *)(param_1 + 0x158);
  uVar9 = *(undefined4 *)(param_1 + 0x15c);
  uVar1 = *(undefined2 *)(param_1 + 0x164);
  FUN_800b6788();
  FUN_800b6470();
  FUN_800b6788();
  FUN_800b6470();
  FUN_800b6788();
  FUN_800b6470();
  FUN_800b6788();
  FUN_800b6470();
  *(undefined4 *)(param_1 + 0x140) = uVar2;
  *(undefined4 *)(param_1 + 0x144) = uVar3;
  *(undefined4 *)(param_1 + 0x148) = uVar4;
  *(undefined4 *)(param_1 + 0x14c) = uVar5;
  *(undefined4 *)(param_1 + 0x150) = uVar6;
  *(undefined4 *)(param_1 + 0x154) = uVar7;
  *(undefined4 *)(param_1 + 0x158) = uVar8;
  *(undefined4 *)(param_1 + 0x15c) = uVar9;
  *(undefined2 *)(param_1 + 0x164) = uVar1;
  return;
}
