/* FUN_80056c88
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80056c88  body 0x80056c88..0x80056f6f  size 744 B
 * body sha256 93ce46d22e8a93fb5a8e8ea84889151cfb48868cd9d50d6bd877652909b0310a
 * provider record sha256 e505939a2edd5476d2745299874586dc2a333e1d325baf6e39d01df5cd936aa2
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80056c88(int param_1)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  short local_18;
  short local_16;
  short local_14;
  
  if (*(char *)(param_1 + 6) == '\0') {
    bVar1 = (&DAT_8010dca8)[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x700;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
    DAT_800e112a = DAT_800e112a | 4;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_80056ef0;
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0);
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 4;
  }
  if ((*(short *)(param_1 + 0x1a8) != 0) && ((*(byte *)(param_1 + 0x1e9) & 1) != 0)) {
    iVar4 = *(int *)(param_1 + 0x234);
    local_18 = 0;
    local_16 = 300;
    local_14 = 0;
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar4 + 0x1078) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar4 + 0x1060,&local_18);
    }
    iVar4 = *(int *)(param_1 + 0x234);
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar4 + 0x14e0) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar4 + 0x14c8,&local_18);
    }
  }
  if ((*(char *)(param_1 + 8) == '\r') && ((*(byte *)(param_1 + 0x1e9) & 7) == 7)) {
    iVar4 = *(int *)(param_1 + 0x234);
    uVar3 = FUN_80033604();
    local_18 = (uVar3 & 0xff) * -2 + 0x100;
    uVar3 = FUN_80033604();
    local_16 = (uVar3 & 0xff) * -2 + -0x2e8;
    uVar3 = FUN_80033604();
    local_14 = (uVar3 & 0xff) * -2 + 0x100;
    uVar2 = FUN_80033604();
    FUN_80037780(0x1262000,
                 (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 2 + -0x900)) * 0x10000
                      ) >> 0x10,iVar4 + 0x38,&local_18);
  }
LAB_80056ef0:
  if (*(char *)(param_1 + 0x1ed) < '\x02') {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -0x11;
  }
  if ((int)*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e) + -500) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - *(short *)(param_1 + 0x1e0) / 3;
  }
  FUN_80032b5c(param_1,0);
  return;
}
