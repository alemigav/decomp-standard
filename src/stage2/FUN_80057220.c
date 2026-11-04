/* FUN_80057220
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057220  body 0x80057220..0x80057553  size 820 B
 * body sha256 e38677f71ed5ced7a5ccc37e07e3b86c45af7a6f40cbb3975a6b8364bbc252ac
 * provider record sha256 046bea9907cc396b760779761933f9f3152148ed0050b8610ce1c7a6530e9c2e
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80057220(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  char cVar4;
  uint uVar3;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  if (*(char *)(param_1 + 6) == '\0') {
    bVar1 = (&DAT_8010dcac)[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x700;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    DAT_800e112a = DAT_800e112a | 2;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_800574ec;
  if ((*(char *)(param_1 + 0x207) == '\0') && (*(char *)(param_1 + 0x1ed) == '\0')) {
    iVar2 = FUN_80057554(param_1,5000,800);
    if (iVar2 == 0) {
      if (*(char *)(param_1 + 0x206) != '\0') {
        uVar3 = *(byte *)(param_1 + 0x1e9) / 7;
        *(undefined1 *)(param_1 + 0x1e8) = 0;
        *(undefined1 *)(param_1 + 0x206) = 0;
        cVar4 = (char)(uVar3 + (*(byte *)(param_1 + 0x1e9) - uVar3 >> 1) >> 2);
        *(char *)(param_1 + 0x1e9) = cVar4;
        cVar4 = cVar4 * '\a';
        goto LAB_80057384;
      }
    }
    else if (*(char *)(param_1 + 0x206) == '\0') {
      cVar4 = *(char *)(param_1 + 0x1e9);
      *(undefined1 *)(param_1 + 0x1e8) = 1;
      *(undefined1 *)(param_1 + 0x206) = 1;
LAB_80057384:
      *(undefined1 *)(param_1 + 0x1ea) = 7;
      *(undefined1 *)(param_1 + 0x1e9) = 0;
      FUN_800334c8(param_1,param_2,param_3,0);
      *(char *)(param_1 + 0x1e9) = cVar4;
      FUN_800334c8(param_1,param_2,param_3,0);
    }
    *(undefined1 *)(param_1 + 0x207) = 0xf;
  }
  *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
  FUN_800334c8(param_1,param_2,param_3,0);
  FUN_80089d54(param_1,param_2,param_3,0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 2;
  }
  if ((*(short *)(param_1 + 0x1a8) != 0) && ((*(byte *)(param_1 + 0x1e9) & 1) != 0)) {
    iVar2 = *(int *)(param_1 + 0x234);
    local_20 = 0;
    local_1e = 300;
    local_1c = 0;
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar2 + 0x1078) + 300) {
      uVar3 = FUN_80033604();
      FUN_80037780((uVar3 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar2 + 0x1060,&local_20);
    }
    iVar2 = *(int *)(param_1 + 0x234);
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar2 + 0x14e0) + 300) {
      uVar3 = FUN_80033604();
      FUN_80037780((uVar3 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar2 + 0x14c8,&local_20);
    }
  }
LAB_800574ec:
  if ((int)*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e) + -500) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - *(short *)(param_1 + 0x1e0) / 3;
  }
  FUN_80032b5c(param_1,0);
  return;
}
