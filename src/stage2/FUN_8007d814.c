/* FUN_8007d814
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d814  body 0x8007d814..0x8007d96f  size 348 B
 * body sha256 7cbb9144bbc3bb4976a2d52c268c3281b0d6715dbcedba473d3ba85a0f510dd6
 * provider record sha256 27c0af8423dc27be8896ddc4357010030a496b27ed7a479c9b7fe50bccae5a98
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d814(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  byte local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 9;
  local_18[2] = 9;
  if (*(char *)(param_1 + 6) == '\0') {
    bVar1 = local_18[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x700;
    uVar2 = FUN_80032e74(&DAT_800e1130,*(undefined4 *)(param_1 + 0x28),
                         *(undefined4 *)(param_1 + 0x30));
    *(ushort *)(param_1 + 0x1f6) = uVar2 << 7;
    if ((uVar2 & 0x1ff) == 0) {
      *(undefined2 *)(param_1 + 0x1f6) = 0x80;
    }
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_8007d934;
  FUN_800334c8(param_1,param_2,param_3,0);
  FUN_80089d54(param_1,param_2,param_3,0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
  }
  *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + '\x01';
LAB_8007d934:
  if (*(char *)(param_1 + 0x1ea) != '\0') {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  FUN_80032b5c(param_1,0);
  return;
}
