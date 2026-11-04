/* FUN_800311d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800311d0  body 0x800311d0..0x8003128f  size 192 B
 * body sha256 4f5de1275a570223ee690667348370ec2bc0a4561046ffd5344dcf60b8e1bc0f
 * provider record sha256 8a38c68d0772357728c33e57d1d427a6aed3356a2d4586deb3baf3828e4ecd6a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800311d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  puVar1 = (undefined4 *)
           (**(code **)(*(int *)(param_1 + 4) + 0x1c))
                     (param_1,*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x2c),1);
  *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + 1;
  puVar3 = (undefined1 *)**(undefined4 **)(param_2 + 0x10);
  iVar5 = *(int *)(param_1 + 0x5c);
  puVar6 = (undefined1 *)*puVar1;
  if (iVar5 != 0) {
    puVar2 = puVar6 + 1;
    do {
      iVar5 = iVar5 + -1;
      puVar2[1] = *puVar3;
      puVar4 = puVar3 + 2;
      *puVar2 = puVar3[1];
      puVar3 = puVar3 + 3;
      puVar2 = puVar2 + 3;
      *puVar6 = *puVar4;
      puVar6 = puVar6 + 3;
    } while (iVar5 != 0);
  }
  iVar5 = *(int *)(param_2 + 0x28);
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  return;
}
