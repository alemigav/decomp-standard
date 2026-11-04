/* FUN_8005e530
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005e530  body 0x8005e530..0x8005e8cf  size 928 B
 * body sha256 2b519edec5b7d4028b4583a3ecf732c033a54c82205083ba969ab94f9447b1b1
 * provider record sha256 e89df390bec215170782f4f2d5bf43d61104d5656e59fac47f2211b7cecc13d8
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005e530(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = 0xff88;
  local_24 = 0xff1000fa;
  local_20 = 0xc80096;
  cVar4 = *(char *)(param_1 + 0x1e9);
  if (cVar4 == '\x01') {
    local_30 = 0x78;
    local_2e = 0x4b0;
    local_2c = 0;
    uVar6 = (uint)(DAT_800e1320 >> 0xf);
    iVar5 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1002000,0,iVar5,&local_30);
    uVar2 = FUN_80037780(0x20c0a00,(int)*(short *)(param_1 + 0x66),iVar5,&local_30);
    if ((uVar2 & 0xff) < 0xff) {
      iVar3 = (uVar2 & 0xff) * 0x7c;
      (&DAT_800ebdb0)[iVar3] = 0xf6;
      uVar1 = *(undefined2 *)((int)&local_28 + uVar6 * 6);
      *(undefined2 *)(&DAT_800ebdb6 + iVar3) = 600;
      *(undefined2 *)(&DAT_800ebdb8 + iVar3) = 0;
      *(undefined2 *)(&DAT_800ebdb4 + iVar3) = uVar1;
    }
    uVar2 = FUN_80037780(0x20c0a00,(int)*(short *)(param_1 + 0x66),iVar5,&local_30);
    if ((uVar2 & 0xff) < 0xff) {
      iVar3 = (uVar2 & 0xff) * 0x7c;
      (&DAT_800ebdb0)[iVar3] = 0xec;
      uVar1 = *(undefined2 *)((int)&local_28 + uVar6 * 6 + 2);
      *(undefined2 *)(&DAT_800ebdb6 + iVar3) = 400;
      *(undefined2 *)(&DAT_800ebdb8 + iVar3) = 100;
      *(undefined2 *)(&DAT_800ebdb4 + iVar3) = uVar1;
    }
    uVar2 = FUN_80037780(0x20c0a00,(int)*(short *)(param_1 + 0x66),iVar5,&local_30);
    if ((uVar2 & 0xff) < 0xff) {
      iVar3 = (uVar2 & 0xff) * 0x7c;
      (&DAT_800ebdb0)[iVar3] = 0xec;
      uVar1 = *(undefined2 *)((int)&local_28 + uVar6 * 6 + 2);
      *(undefined2 *)(&DAT_800ebdb6 + iVar3) = 400;
      *(undefined2 *)(&DAT_800ebdb8 + iVar3) = 0xff9c;
      *(undefined2 *)(&DAT_800ebdb4 + iVar3) = uVar1;
    }
    uVar2 = FUN_80037780(0x20c0a00,(int)*(short *)(param_1 + 0x66),iVar5,&local_30);
    if ((uVar2 & 0xff) < 0xff) {
      iVar3 = (uVar2 & 0xff) * 0x7c;
      (&DAT_800ebdb0)[iVar3] = 0xd8;
      uVar1 = *(undefined2 *)((int)&local_24 + uVar6 * 6);
      *(undefined2 *)(&DAT_800ebdb6 + iVar3) = 0xfa;
      *(undefined2 *)(&DAT_800ebdb8 + iVar3) = 0x32;
      *(undefined2 *)(&DAT_800ebdb4 + iVar3) = uVar1;
    }
    uVar2 = FUN_80037780(0x20c0a00,(int)*(short *)(param_1 + 0x66),iVar5,&local_30);
    if ((uVar2 & 0xff) < 0xff) {
      iVar5 = (uVar2 & 0xff) * 0x7c;
      (&DAT_800ebdb0)[iVar5] = 0xd8;
      uVar1 = *(undefined2 *)((int)&local_24 + uVar6 * 6);
      *(undefined2 *)(&DAT_800ebdb6 + iVar5) = 0xfa;
      *(undefined2 *)(&DAT_800ebdb8 + iVar5) = 0xffce;
      *(undefined2 *)(&DAT_800ebdb4 + iVar5) = uVar1;
    }
    cVar4 = *(char *)(param_1 + 0x1e9);
  }
  if ((cVar4 == '\b') && (iVar5 = FUN_8008cce4(*(ushort *)(param_1 + 0x1aa) & 0xfff), iVar5 == 0)) {
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
  }
  cVar4 = '\n';
  if (*(char *)(param_1 + 0x1e8) == '\f') {
    cVar4 = '\t';
  }
  if (*(char *)(param_1 + 0x1e9) == cVar4) {
    FUN_8005c264(param_1);
    FUN_80052bd0(3,0);
    FUN_80052c6c(5,0x96,0x11);
  }
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
