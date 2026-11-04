/* FUN_80057c54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057c54  body 0x80057c54..0x80057e13  size 448 B
 * body sha256 52bc5d65fe901dd2683b642d39e92e3bb6dcfa1238eeffd5bffb0e661fb8b463
 * provider record sha256 d2546779c8e1731f4cc117d594093f2fa9bfa60b93b787c2788b7d7dd4686bf0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80057c54(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if (*(char *)(param_1 + 6) == '\0') {
    sVar1 = *(short *)(&DAT_8010dcb0 + *(char *)(param_1 + 0x1ed) * 2);
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(int *)(param_1 + 0x1e8) = sVar1 * 0x1000000 + 0x700;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 2;
  }
  if ((*(short *)(param_1 + 0x1a8) != 0) && ((*(byte *)(param_1 + 0x1e9) & 1) != 0)) {
    iVar3 = *(int *)(param_1 + 0x234);
    local_18 = 0;
    local_16 = 300;
    local_14 = 0;
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar3 + 0x1078) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar3 + 0x1060,&local_18);
    }
    iVar3 = *(int *)(param_1 + 0x234);
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar3 + 0x14e0) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar3 + 0x14c8,&local_18);
    }
  }
  return;
}
