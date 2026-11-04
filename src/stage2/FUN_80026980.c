/* FUN_80026980
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026980  body 0x80026980..0x80026a87  size 264 B
 * body sha256 d335259471b8d9665f01c80f85b141b6c3424ff4d03f6f69a2ea388ec4d081ca
 * provider record sha256 8610de4062cb1cd33d61c2b953f1cb4333a4d924f6ebc01b4f948b61281376ba
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80026980(int param_1)

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
  DAT_800e910c = param_1;
  while ((uint)(DAT_801137f0 * DAT_801137f4) < uVar1) {
    DAT_800e910c = DAT_800e910c + -1;
    uVar1 = ((piVar2[-10] - piVar2[-7]) - piVar2[-8]) * ((piVar2[-9] - piVar2[-5]) - piVar2[-6]);
    piVar2 = piVar2 + -10;
  }
  iVar3 = DAT_800e910c * 0x28;
  FUN_8002691c(*(undefined4 *)(&DAT_800c4f80 + iVar3),*(undefined4 *)(&DAT_800c4f84 + iVar3),
               *(undefined4 *)(&DAT_800c4f88 + iVar3),*(undefined4 *)(&DAT_800c4f8c + iVar3),
               *(undefined4 *)(&DAT_800c4f90 + iVar3),*(undefined4 *)(&DAT_800c4f94 + iVar3));
  return;
}
