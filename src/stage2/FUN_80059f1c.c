/* FUN_80059f1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059f1c  body 0x80059f1c..0x8005a3c7  size 1196 B
 * body sha256 9d7bca7d2068a7ab8a3e3b5be87f63f658d53b7155c1d135a746ba7fd4555e9b
 * provider record sha256 57ebd51b60cd299585b119eee137d8974be114ca15cf2f293f2b8ba6b2c71379
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059f1c(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short local_60;
  short local_5e;
  short local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  int local_30;
  
  if ((DAT_800e1126 < 3) && ((byte)(&DAT_8010dd04)[*(ushort *)(param_1 + 0x1aa) & 0xfff] != 0)) {
    iVar6 = *(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20;
    local_48 = *(int *)(iVar6 + 4) - *(int *)(param_2 + 0x4c);
    iVar7 = (byte)(&DAT_8010dd04)[*(ushort *)(param_1 + 0x1aa) & 0xfff] - 1;
    local_44 = *(int *)(iVar6 + 8) - *(int *)(param_2 + 0x50);
    iVar5 = iVar7 * 8;
    local_40 = *(int *)(iVar6 + 0xc) - *(int *)(param_2 + 0x54);
    FUN_80040aa8(&local_48,&local_48);
    local_60 = *(short *)(&DAT_8010dd1a + iVar5);
    local_5e = *(short *)(&DAT_8010dd1c + iVar5);
    local_5c = 0;
    FUN_80042824(param_2 + 0x38,&local_60,&local_38);
    FUN_80040aa8(&local_38,&local_38);
    if (0xff069c < local_48 * local_38 + local_44 * local_34 + local_40 * local_30) {
      local_58 = *(int *)(iVar6 + 0x10) - *(int *)(iVar6 + 4);
      local_50 = *(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0xc);
      local_54 = *(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 8);
      FUN_80040aa8(&local_58,&local_58);
      uVar1 = FUN_80033604();
      local_60 = (*(short *)(iVar6 + 6) + (short)(local_58 >> 3)) - ((uVar1 & 0xff) - 0x80);
      uVar1 = FUN_80033604();
      local_5e = (*(short *)(iVar6 + 10) + (short)(local_54 >> 3)) - ((uVar1 & 0xff) - 0x80);
      uVar1 = FUN_80033604();
      local_5c = (*(short *)(iVar6 + 0xe) + (short)(local_50 >> 3)) - ((uVar1 & 0xff) - 0x80);
      FUN_80037780(0x70002c8,0,&DAT_800e9028,&local_60);
      if (iVar7 != 0) {
        sVar2 = *(short *)(iVar6 + 6) + (short)(local_58 >> 3);
        sVar3 = *(short *)(iVar6 + 10) + (short)(local_54 >> 3);
        sVar4 = *(short *)(iVar6 + 0xe) + (short)(local_50 >> 3);
        uVar1 = FUN_80033604();
        local_60 = sVar2 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5e = sVar3 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5c = sVar4 - ((uVar1 & 0xff) * 2 + -0x100);
        FUN_80037780(0x70002c8,0,&DAT_800e9028,&local_60);
        uVar1 = FUN_80033604();
        local_60 = sVar2 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5e = sVar3 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5c = sVar4 - ((uVar1 & 0xff) * 2 + -0x100);
        FUN_80037780(0x70002c8,0,&DAT_800e9028,&local_60);
        uVar1 = FUN_80033604();
        local_60 = sVar2 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5e = sVar3 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5c = sVar4 - ((uVar1 & 0xff) * 2 + -0x100);
        FUN_80037780(0x70002c8,0,&DAT_800e9028,&local_60);
        uVar1 = FUN_80033604();
        local_60 = sVar2 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5e = sVar3 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5c = sVar4 - ((uVar1 & 0xff) * 2 + -0x100);
        FUN_80037780(0x70002c8,0,&DAT_800e9028,&local_60);
        uVar1 = FUN_80033604();
        local_60 = sVar2 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5e = sVar3 - ((uVar1 & 0xff) * 2 + -0x100);
        uVar1 = FUN_80033604();
        local_5c = sVar4 - ((uVar1 & 0xff) * 2 + -0x100);
        FUN_80037780(0x70002c8,0,&DAT_800e9028,&local_60);
      }
    }
  }
  return;
}
