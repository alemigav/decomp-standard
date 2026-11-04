/* FUN_8007ba00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ba00  body 0x8007ba00..0x8007bc0f  size 528 B
 * body sha256 5f7071379b24a021460d744abedac420a0349ca6017a6121e70d522bf44bea52
 * provider record sha256 237963cfd59652b84493e153893a25590c9dc5e102d363ec81c9c33870b9bc0d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ba00(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  char cVar6;
  int iVar4;
  undefined2 uVar5;
  ushort uVar7;
  int iVar8;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  short local_10;
  short local_e;
  short local_c;
  
  iVar8 = 0;
  if ((*(char *)(param_1 + 8) == 'E') || (*(char *)(param_1 + 8) == 'O')) {
    iVar8 = 1;
  }
  if (((DAT_800e110c & 0x10000000) == 0) || (param_1 != DAT_800e13ec)) {
    local_20 = (int)*(short *)(param_1 + 0x274);
    local_18 = (int)*(short *)(param_1 + 0x276);
    local_1c = 0;
    FUN_800653d0(param_1,&local_20,0,0);
    return;
  }
  uVar7 = *(ushort *)(param_1 + 0x2b8) & 3;
  if (uVar7 == 1) {
    local_20 = (int)*(short *)(param_1 + 0x2b4);
    local_1c = 0;
    local_18 = (int)*(short *)(param_1 + 0x2b6);
  }
  else {
    if (uVar7 < 2) {
      if ((*(ushort *)(param_1 + 0x2b8) & 3) != 0) goto LAB_8007bb58;
      iVar8 = iVar8 * 0xc;
      sVar1 = *(short *)(&UNK_8011af30 + iVar8);
      sVar2 = *(short *)(&UNK_8011af32 + iVar8);
      sVar3 = *(short *)(&UNK_8011af34 + iVar8);
    }
    else {
      if (uVar7 != 2) goto LAB_8007bb58;
      iVar8 = iVar8 * 0xc;
      sVar1 = *(short *)(&UNK_8011af36 + iVar8);
      sVar2 = *(short *)(&UNK_8011af38 + iVar8);
      sVar3 = *(short *)(&UNK_8011af3a + iVar8);
    }
    FUN_800805fc((int)sVar1,(int)sVar2,(int)sVar3,&local_10);
    local_20 = (int)local_10;
    *(short *)(param_1 + 0x2b4) = local_10;
    local_1c = (int)local_e;
    local_18 = (int)local_c;
    *(short *)(param_1 + 0x2b6) = local_c;
  }
LAB_8007bb58:
  cVar6 = FUN_8006568c((int)local_20._2_2_,(int)local_18._2_2_);
  if (cVar6 == -1) {
    *(undefined2 *)(param_1 + 0x2b4) = DAT_800e1158._2_2_;
    *(undefined2 *)(param_1 + 0x2b6) = DAT_800e1160._2_2_;
    local_20 = DAT_800e1158;
    local_18 = DAT_800e1160;
  }
  FUN_800653d0(param_1,&local_20,0,0);
  iVar8 = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x2b4);
  iVar4 = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x2b6);
  *(undefined4 **)(param_1 + 0x254) = &DAT_800e1130;
  uVar5 = FUN_80040bb4(iVar8 * iVar8 + iVar4 * iVar4);
  *(undefined2 *)(param_1 + 0x2ba) = uVar5;
  return;
}
