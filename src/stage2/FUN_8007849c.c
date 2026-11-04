/* FUN_8007849c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007849c  body 0x8007849c..0x800787db  size 832 B
 * body sha256 67c59b341bec55dc0cfce5befa694c98e05b9251d510dcea9aa1dab98c030e6c
 * provider record sha256 6c750c19ba137e6f35fa67814dbc1e53548037394b3798ceccd36c6c3c5bfa59
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007849c(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  short *psVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  pbVar7 = &UNK_8011a28c;
  puVar11 = &DAT_8011a2a0;
  psVar6 = &DAT_8011a288;
  puVar8 = &DAT_80119f2c;
  do {
    pbVar7 = pbVar7 + -0x24;
    puVar9 = puVar8 + -2;
    uVar10 = (uint)(byte)puVar8[-1];
    puVar11 = puVar11 + -9;
    if (*pbVar7 != 0) {
      if (DAT_80119e73 != 0) {
        if ((&DAT_8011a294)[psVar6[-0xe]] == 0) goto LAB_80078754;
        uVar2 = *(undefined2 *)
                 ((uint)*(byte *)((int)psVar6 + -0x1f) * 2 + (&DAT_8011a294)[psVar6[-0xe]]);
        if (uVar10 < 0x10) {
          if (psVar6[-7] == 0) {
            uVar3 = FUN_800b2298(uVar2,0xff,0x3f);
          }
          else {
            uVar3 = FUN_800aa940(0,puVar11,puVar11,0x471c4000,0,0,uVar2,0x7f,
                                 ((uint)DAT_80119e73 * 0x1f) / 100);
          }
          *(undefined4 *)(&DAT_8011a2b0 + uVar10 * 4) = uVar3;
        }
        else {
          if ((psVar6[-0xe] == 2) && (*(byte *)((int)psVar6 + -0x1f) == 0)) {
            FUN_800b2528(*(undefined4 *)(&DAT_8011a2b0 + uVar10 * 4),
                         ((0x10 - (uint)*pbVar7) * 0x2fa) / 100 & 0xff);
            bVar1 = *pbVar7;
            *pbVar7 = bVar1 + 1;
            if ((byte)(bVar1 + 1) == 0x10) {
              *pbVar7 = 0;
            }
            *puVar9 = 0;
            goto LAB_80078754;
          }
          puVar5 = (undefined4 *)(&DAT_8011a2b0 + uVar10 * 4);
          iVar4 = FUN_800b230c(*puVar5);
          if (iVar4 != -1) {
            FUN_800b2344(*puVar5);
          }
          if (psVar6[-7] == 0) {
            uVar3 = FUN_800b2298(uVar2,0xff,0x3f);
            *puVar5 = uVar3;
          }
          else {
            uVar3 = FUN_800aa940(0,puVar11,puVar11,0x471c4000,0,0,uVar2,0x7f,
                                 ((uint)DAT_80119e73 * 0x1f) / 100);
            *puVar5 = uVar3;
          }
        }
        if ((psVar6[-0xe] != 0) && (psVar6[-0xe] != 4)) {
          if (*(int *)(&DAT_8011a2b0 + uVar10 * 4) == -1) {
            *pbVar7 = 0;
            goto LAB_80078754;
          }
          if (*psVar6 != 0) {
            FUN_800b1db8(*(int *)(&DAT_8011a2b0 + uVar10 * 4),0x6c);
          }
        }
      }
      *pbVar7 = 0;
    }
LAB_80078754:
    if (&UNK_80119f27 < puVar9) {
      iVar4 = FUN_800b230c(*(undefined4 *)(&DAT_8011a2b0 + uVar10 * 4));
      if (iVar4 == -1) {
        *puVar9 = 0;
      }
    }
    else {
      *puVar9 = 0;
    }
    psVar6 = psVar6 + -0x12;
    puVar8 = puVar9;
    if (puVar9 == &DAT_80119efc) {
      FUN_800774f4();
      return;
    }
  } while( true );
}
