/* FUN_800566ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800566ec  body 0x800566ec..0x80056917  size 556 B
 * body sha256 ad27290bc0261ae4d8bef66d067374c3654d0e9aa35a3870e3bcad560bb137d6
 * provider record sha256 d5814fa0090bccc34643caddd2d9eb6922f80af4285e16fba8f9d482c6a917b0
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800566ec(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if (*(char *)(param_1 + 6) == '\0') {
    sVar1 = *(short *)(&DAT_8010dca0 + *(char *)(param_1 + 0x1ed) * 2);
    *(undefined1 *)(param_1 + 6) = 1;
    *(int *)(param_1 + 0x1e8) = sVar1 * 0x1000000 + 0x700;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
    DAT_800e112a = DAT_800e112a | 2;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_800568b8;
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0);
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
LAB_800568b8:
  if ((int)*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e) + -500) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - *(short *)(param_1 + 0x1e0) / 3;
  }
  FUN_80032b5c(param_1,0);
  return;
}
