/* FUN_8008457c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008457c  body 0x8008457c..0x80084a83  size 1288 B
 * body sha256 b3dc8afcd8b433b1129da3ac0465a0bf0100317fc11f525b7011527f78e12606
 * provider record sha256 931ee6cfad2a5f27fbd487f9454e5c6174804f20e126baac35fadc8905d8a708
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008457c(void)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  char cVar7;
  short sVar6;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined1 auStack_a8 [32];
  undefined1 auStack_88 [20];
  int local_74;
  int local_70;
  int local_6c;
  undefined1 auStack_68 [32];
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  int local_2c;
  
  FUN_80043620();
  puVar12 = &DAT_8011c924;
  local_30 = (uint)(*(ushort *)(DAT_800df92c + DAT_800e8cac * 0x20 + 0x6a) >> 7);
  local_38 = DAT_800df940;
  FUN_80042d60(&DAT_800e9134);
  puVar8 = &DAT_800eebac;
  FUN_80042dac(&DAT_800e9134);
  do {
    local_74 = (int)*(short *)(puVar8 + 0x34);
    local_70 = (int)*(short *)(puVar8 + 0x36);
    local_6c = (int)*(short *)(puVar8 + 0x38);
    uVar4 = *(ushort *)(puVar8 + 0x18);
    if (uVar4 != 0) {
      puVar9 = (undefined1 *)(*(int *)(puVar8 + 0x70) + (uint)(byte)puVar8[0x21] * 8);
      uVar10 = (uint)(byte)puVar9[1];
      if ((uVar4 & 0xa000) == 0xa000) {
        iVar5 = FUN_80083d2c(&local_74,local_38);
        if ((iVar5 != 0) && (uVar10 != 0)) {
          uVar11 = 0x2c;
          if ((uVar4 & 0x1000) != 0) {
            uVar11 = 0x2e;
          }
          uVar2 = puVar9[3];
          uVar3 = *puVar9;
          if ((uVar4 & 0x200) == 0) {
            if (local_2c != 0) {
              FUN_80042d60(&DAT_800e9134);
              FUN_80042dac(&DAT_800e9134);
              local_2c = 0;
            }
            if ((DAT_800e110c & 0x10000) == 0) {
              if (&UNK_80120524 <= puVar12 + uVar10 * 0x28) goto LAB_800849d8;
              sVar6 = FUN_80084a84(puVar12,puVar8,uVar2,uVar10,local_30,local_34,uVar11,uVar3);
              if (sVar6 != 0) {
                puVar12 = puVar12 + uVar10 * 0x28;
              }
            }
            else {
              iVar5 = uVar10 * 0x28;
              if (&UNK_80120524 <= puVar12 + iVar5 + iVar5) goto LAB_800849d8;
              sVar6 = FUN_80084a84(puVar12,puVar8,uVar2,uVar10,local_30,local_34,uVar11,uVar3);
              if (sVar6 != 0) {
                puVar12 = puVar12 + iVar5;
              }
              local_48 = (int)*(short *)(puVar8 + 0x34);
              local_44 = (int)*(short *)(puVar8 + 0x36);
              local_40 = (int)*(short *)(puVar8 + 0x38);
              cVar7 = FUN_8004a328(*(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20,DAT_800e10f1,
                                   &local_48);
              if (cVar7 != '\0') {
                FUN_80042d60(&DAT_800e9154);
                FUN_80042dac(&DAT_800e9154);
                sVar6 = FUN_80084a84(puVar12,puVar8,uVar2,uVar10,local_30,local_34,uVar11,uVar3);
                if (sVar6 != 0) {
                  puVar12 = puVar12 + iVar5;
                }
                goto LAB_800849b0;
              }
            }
          }
          else {
            local_74 = (int)*(short *)(puVar8 + 0x2c) + (int)*(short *)(puVar8 + 0x24);
            local_70 = (int)*(short *)(puVar8 + 0x2e) + (int)*(short *)(puVar8 + 0x26);
            local_6c = (int)*(short *)(puVar8 + 0x30) + (int)*(short *)(puVar8 + 0x28);
            FUN_80040e58(puVar8 + 0x44,auStack_88);
            FUN_800424ec(puVar8 + 0x4c,auStack_88,auStack_68);
            FUN_800424ec(&DAT_800e9134,auStack_68,auStack_a8);
            FUN_80042d60(auStack_a8);
            FUN_80042dac(auStack_a8);
            if ((DAT_800e110c & 0x10000) == 0) {
              if (&UNK_80120523 < puVar12 + uVar10 * 0x28) goto LAB_800849d8;
LAB_80084820:
              FUN_80084e04(puVar8,uVar2,uVar10,local_30,local_34,uVar11,uVar3);
            }
            else {
              if (&UNK_80120523 < puVar12 + uVar10 * 0x50) {
LAB_800849d8:
                *(undefined2 *)(puVar8 + 0x18) = 0;
                goto LAB_80084a18;
              }
              FUN_80084e04(puVar8,uVar2,uVar10,local_30,local_34,uVar11,uVar3);
              local_48 = (int)*(short *)(puVar8 + 0x34);
              local_44 = (int)*(short *)(puVar8 + 0x36);
              local_40 = (int)*(short *)(puVar8 + 0x38);
              cVar7 = FUN_8004a328(*(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20,DAT_800e10f1,
                                   &local_48);
              if (cVar7 != '\0') {
                FUN_800424ec(&DAT_800e9154,auStack_68,auStack_a8);
                FUN_80042d60(auStack_a8);
                FUN_80042dac(auStack_a8);
                goto LAB_80084820;
              }
            }
LAB_800849b0:
            local_2c = 1;
          }
        }
      }
    }
LAB_80084a18:
    bVar1 = puVar8 == &DAT_800ebda8;
    puVar8 = puVar8 + -0x7c;
    if (bVar1) {
      DAT_80124124 = puVar12;
      DAT_800df8b4 = FUN_80043648(DAT_800df8b4);
      return;
    }
  } while( true );
}
