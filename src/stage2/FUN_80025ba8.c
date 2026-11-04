/* FUN_80025ba8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025ba8  body 0x80025ba8..0x80025d5f  size 440 B
 * body sha256 f807d18b6cf804f223e6bb1bfe4afccc32d34f0627722ba142988a493765c252
 * provider record sha256 b31466614185bf9e871719b325a65d56bb0251af17660e6dc05b972ebd7c21c2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025ba8(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x28;
  uVar1 = ((*(int *)(&DAT_800c4f80 + iVar3) - *(int *)(&DAT_800c4f8c + iVar3)) -
          *(int *)(&DAT_800c4f88 + iVar3)) *
          ((*(int *)(&DAT_800c4f84 + iVar3) - *(int *)(&DAT_800c4f94 + iVar3)) -
          *(int *)(&DAT_800c4f90 + iVar3));
  piVar2 = (int *)(&DAT_800c4f80 + iVar3);
  DAT_800c7640 = param_1;
  while ((uint)(DAT_801137f0 * DAT_801137f4) < uVar1) {
    DAT_800c7640 = DAT_800c7640 + -1;
    uVar1 = ((piVar2[-10] - piVar2[-7]) - piVar2[-8]) * ((piVar2[-9] - piVar2[-5]) - piVar2[-6]);
    piVar2 = piVar2 + -10;
  }
  FUN_80025b1c(DAT_800c7640);
  FUN_80042a90();
  DAT_800c4f60 = 1;
  DAT_800c4eb4 = DAT_801137d8 * DAT_801137dc + 0x1ffU >> 9;
  FUN_80025a60();
  DAT_800c56e0 = DAT_800c7640;
  iVar3 = DAT_800c7640 * 0x28;
  DAT_800c764c = *(undefined4 *)(&DAT_800c4f80 + iVar3);
  DAT_800c7650 = *(undefined4 *)(&DAT_800c4f84 + iVar3);
  DAT_800c7654 = *(undefined4 *)(&DAT_800c4f88 + iVar3);
  DAT_800c7658 = *(undefined4 *)(&DAT_800c4f8c + iVar3);
  DAT_800c765c = *(undefined4 *)(&DAT_800c4f90 + iVar3);
  DAT_800c7660 = *(undefined4 *)(&DAT_800c4f94 + iVar3);
  DAT_800c7664 = *(undefined4 *)(&DAT_800c4f98 + iVar3);
  DAT_800c7668 = *(undefined4 *)(&DAT_800c4f9c + iVar3);
  DAT_800c766c = *(undefined4 *)(&DAT_800c4fa0 + iVar3);
  DAT_800c7670 = *(undefined4 *)(&DAT_800c4fa4 + iVar3);
  return;
}
