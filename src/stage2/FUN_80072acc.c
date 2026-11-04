/* FUN_80072acc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072acc  body 0x80072acc..0x80072c3b  size 368 B
 * body sha256 3f20a7220d21a67612db1ad004c29792f3cfe5bd57402ff8812845331080c61a
 * provider record sha256 7d9eb35322d62e0b92f5040b6759b5f5b164359dfd00c471a0439aaaba422f17
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072acc(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined2 *unaff_s0;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x1c) + 1);
  if (bVar1 == 2) {
    iVar2 = DAT_800e13ec;
  }
  else if (bVar1 < 3) {
    if (bVar1 != 1) goto LAB_80072b90;
    iVar2 = 0;
  }
  else {
    if (bVar1 != 3) goto LAB_80072b90;
    iVar2 = (&DAT_800e13e8)[*(char *)(*(int *)(param_1 + 0x1c) + 2) + 2];
  }
  unaff_s0 = *(undefined2 **)(iVar2 + 0x208);
LAB_80072b90:
  iVar2 = *(int *)(param_1 + 0x1c);
  if (CONCAT12(*(byte *)(iVar2 + 5),CONCAT11(*(byte *)(iVar2 + 4),*(byte *)(iVar2 + 3))) ==
      -0x4040f0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)*(byte *)(iVar2 + 3) << 0x18 | (uint)*(byte *)(iVar2 + 4) << 0x10 |
            (uint)*(byte *)(iVar2 + 5) << 8;
  }
  FUN_800341dc(unaff_s0,uVar3);
  unaff_s0[2] = *(undefined2 *)(*(int *)(param_1 + 0x1c) + 6);
  unaff_s0[3] = *(undefined2 *)(*(int *)(param_1 + 0x1c) + 8);
  *unaff_s0 = *(undefined2 *)(*(int *)(param_1 + 0x1c) + 10);
  unaff_s0[1] = *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 0xe;
  return 1;
}
