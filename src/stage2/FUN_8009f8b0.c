/* FUN_8009f8b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f8b0  body 0x8009f8b0..0x8009feb7  size 1544 B
 * body sha256 296b3ad4b36dbe64f75d72d084f4cb8b260f01df496fae3e5102a445321f9271
 * provider record sha256 0b041c20958d0b9d7a3e8a9ce7c318a964f164c9cad179d415855ae52b36167a
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8009f8b0(int param_1,undefined4 param_2,int param_3,int *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  uint *puVar7;
  undefined1 *puVar8;
  ushort *puVar9;
  int *piVar10;
  undefined1 *puVar11;
  uint uVar12;
  char cVar14;
  int iVar13;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  uVar17 = 0;
  puVar11 = &DAT_8013bc90;
  do {
    if (puVar11[0xfc1] != '\0') break;
    uVar17 = uVar17 + 1;
    puVar11 = puVar11 + 0xff8;
  } while (uVar17 < 8);
  if (uVar17 == 8) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = uVar17 * 0xff8;
    puVar11 = &DAT_8013bc90 + iVar1;
    uVar12 = 0;
    *(int *)(iVar1 + -0x7fec436c) = param_1;
    *(undefined1 *)(iVar1 + -0x7fec337c) = 0;
    *(undefined4 *)(iVar1 + -0x7fec42e8) = param_2;
    *(int **)(iVar1 + -0x7fec4264) = param_4;
    uVar2 = 0;
    do {
      *(undefined1 *)(iVar1 + -0x7fec4368 + uVar2) = 0xff;
      uVar12 = uVar12 + 1;
      uVar2 = uVar12 & 0xff;
    } while (-1 < (int)(uVar12 * 0x1000000));
    cVar14 = '\0';
    if (*(char *)(param_1 + 5) != -1) {
      pbVar5 = (byte *)(param_1 + 5);
      uVar2 = (uint)*pbVar5;
      do {
        pbVar5 = pbVar5 + 8;
        *(char *)(iVar1 + -0x7fec4368 + uVar2) = cVar14;
        uVar2 = (uint)*pbVar5;
        cVar14 = cVar14 + '\x01';
      } while (uVar2 != 0xff);
    }
    iVar13 = *(int *)(iVar1 + -0x7fec42e8);
    uVar12 = 0;
    uVar2 = 0;
    do {
      *(undefined1 *)(iVar1 + -0x7fec42e4 + uVar2) = 0xff;
      uVar12 = uVar12 + 1;
      uVar2 = uVar12 & 0xff;
    } while (-1 < (int)(uVar12 * 0x1000000));
    cVar14 = '\0';
    if (*(char *)(iVar13 + 5) != -1) {
      pbVar5 = (byte *)(iVar13 + 5);
      uVar2 = (uint)*pbVar5;
      do {
        pbVar5 = pbVar5 + 8;
        *(char *)(iVar1 + -0x7fec42e4 + uVar2) = cVar14;
        uVar2 = (uint)*pbVar5;
        cVar14 = cVar14 + '\x01';
      } while (uVar2 != 0xff);
    }
    (&DAT_8013cc54)[iVar1] = (char)uVar17 + '\x17';
    iVar13 = 0;
    puVar6 = puVar11;
    do {
      iVar13 = iVar13 + 1;
      puVar6[0x528] = (&DAT_8013cc54)[iVar1];
      puVar6 = puVar11 + iVar13;
    } while (iVar13 < 0x40);
    if (param_5 == (uint *)0x0) {
      *(undefined4 *)(iVar1 + -0x7fec4260) = 0xffffffff;
      *(undefined4 *)(iVar1 + -0x7fec425c) = 0xffffffff;
      *(undefined2 *)(&DAT_8013cc52 + iVar1) = 0x100;
    }
    else {
      if ((*param_5 & 1) == 0) {
        *(undefined4 *)(iVar1 + -0x7fec4260) = 0xffffffff;
        *(undefined4 *)(iVar1 + -0x7fec425c) = 0xffffffff;
      }
      else {
        *(uint *)(iVar1 + -0x7fec4260) = param_5[1];
        *(uint *)(iVar1 + -0x7fec425c) = param_5[2];
      }
      if ((*param_5 & 2) == 0) {
        *(undefined2 *)(&DAT_8013cc52 + iVar1) = 0x100;
      }
      else {
        *(undefined2 *)(&DAT_8013cc52 + iVar1) = *(undefined2 *)(param_5 + 3);
      }
      if (((*param_5 & 8) != 0) && (iVar13 = 0, *(char *)((int)param_5 + 0x12) != '\0')) {
        do {
          pbVar5 = (byte *)(iVar13 * 2 + param_5[5]);
          puVar11[*pbVar5 + 0x528] = pbVar5[1];
          FUN_800a832c(*(undefined1 *)(iVar13 * 2 + param_5[5] + 1),0);
          iVar13 = iVar13 + 1;
        } while (iVar13 < (int)(uint)*(byte *)((int)param_5 + 0x12));
      }
      if ((*param_5 & 4) != 0) {
        FUN_800a7b64(*(undefined1 *)(param_5 + 4),*(undefined2 *)((int)param_5 + 0xe),
                     (&DAT_8013cc54)[iVar1],0,0);
        iVar13 = 0;
        if (*(char *)(param_5 + 6) != '\0') {
          do {
            FUN_800a7b64(*(undefined1 *)(param_5 + 4),*(undefined2 *)((int)param_5 + 0xe),
                         *(undefined1 *)(param_5[7] + iVar13),0,0);
            iVar13 = iVar13 + 1;
          } while (iVar13 < (int)(uint)*(byte *)(param_5 + 6));
        }
      }
    }
    iVar13 = param_4[4];
    *(int *)(&DAT_8013bdb4 + iVar1) = iVar13;
    FUN_800a82d8(iVar13,uVar17 & 0xff);
    iVar13 = param_4[3] + (int)param_4;
    if (param_4[3] == 0) {
      *(undefined4 *)(&DAT_8013cbf8 + iVar1) = 0;
    }
    else {
      *(int *)(&DAT_8013cbf8 + iVar1) = iVar13;
      *(int *)(&DAT_8013cbfc + iVar1) = iVar13;
      *(undefined4 *)(&DAT_8013cc00 + iVar1) = 0;
      *(undefined4 *)(&DAT_8013cc04 + iVar1) = 0;
    }
    iVar13 = 0;
    *(undefined1 *)(iVar1 + -0x7fec33ab) = 0;
    piVar10 = (int *)(*param_4 + (int)param_4);
    puVar6 = puVar11;
    puVar8 = puVar11;
    do {
      *(undefined1 *)(iVar13 + -0x7feb85a0) = 0x7f;
      *(undefined4 *)(puVar6 + 0x130) = 0;
      *(undefined4 *)(puVar6 + 0x134) = 0;
      *(undefined4 *)(puVar8 + 0x574) = 0;
      *(undefined4 *)(puVar8 + 0x578) = 0;
      *(undefined4 *)(puVar8 + 0x57c) = 0;
      iVar3 = *piVar10 + (int)param_4;
      if (*piVar10 == 0) {
        *(undefined4 *)(puVar6 + 0x128) = 0;
        *(undefined4 *)(puVar6 + 300) = 0;
      }
      else {
        *(int *)(puVar6 + 0x128) = iVar3;
        *(int *)(puVar6 + 300) = iVar3;
      }
      piVar10 = piVar10 + 1;
      puVar8 = puVar8 + 0x28;
      iVar13 = iVar13 + 1;
      puVar6 = puVar6 + 0x10;
    } while (iVar13 < 0x40);
    uVar12 = 0;
    *(undefined4 *)(iVar1 + -0x7fec33f8) = 0;
    *(undefined4 *)(&DAT_8013cc0c + iVar1) = 0;
    uVar2 = 0;
    do {
      FUN_800abad4(uVar2,uVar17 & 0xff);
      uVar12 = uVar12 + 1;
      uVar2 = uVar12 & 0xff;
    } while ((int)uVar12 < 0x10);
    iVar3 = 0xf;
    iVar13 = iVar1 + -0x7fec4334;
    do {
      *(undefined4 *)(iVar13 + 0xf80) = 0xffffffff;
      iVar3 = iVar3 + -1;
      iVar13 = iVar13 + -4;
    } while (-1 < iVar3);
    iVar3 = *(int *)(iVar1 + -0x7fec436c);
    pbVar5 = (byte *)(iVar1 + -0x7fec4368);
    iVar13 = 0;
    do {
      iVar16 = 0;
      pbVar4 = pbVar5;
      do {
        iVar16 = iVar16 + 1;
        if (*pbVar4 != 0xff) {
          puVar9 = (ushort *)((uint)*pbVar4 * 8 + iVar3);
          if (*(byte *)(puVar9 + 2) != 0xff) {
            *(uint *)(puVar11 + (uint)*(byte *)(puVar9 + 2) * 4 + 0xf80) =
                 (uint)*puVar9 << 0x10 | (uint)*(byte *)(puVar9 + 1) << 8 |
                 (uint)*(byte *)((int)puVar9 + 3);
          }
        }
        pbVar4 = pbVar5 + iVar16;
      } while (iVar16 < 0x80);
      iVar3 = *(int *)(iVar1 + -0x7fec42e8);
      iVar13 = iVar13 + 1;
      pbVar5 = (byte *)(iVar1 + -0x7fec42e4);
    } while (iVar13 < 2);
    if (param_3 != 0) {
      uVar2 = 0;
      uVar12 = uVar17 & 0xff;
      do {
        if ((uVar2 & 0xff) == 9) {
          if ((byte)puVar11[*(byte *)(param_3 + 4) + 0x8c] != 0xff) {
            puVar9 = (ushort *)
                     ((uint)(byte)puVar11[*(byte *)(param_3 + 4) + 0x8c] * 8 +
                     *(int *)(iVar1 + -0x7fec42e8));
            *(uint *)(iVar1 + -0x7fec33cc) =
                 (uint)*puVar9 << 0x10 | (uint)*(byte *)(puVar9 + 1) << 8 |
                 (uint)*(byte *)((int)puVar9 + 3);
          }
        }
        else if ((byte)puVar11[*(byte *)(param_3 + 4) + 8] != 0xff) {
          puVar9 = (ushort *)
                   ((uint)(byte)puVar11[*(byte *)(param_3 + 4) + 8] * 8 +
                   *(int *)(iVar1 + -0x7fec436c));
          *(uint *)(puVar11 + (uVar2 & 0xff) * 4 + 0xf80) =
               (uint)*puVar9 << 0x10 | (uint)*(byte *)(puVar9 + 1) << 8 |
               (uint)*(byte *)((int)puVar9 + 3);
        }
        uVar15 = uVar2 & 0xff;
        uVar2 = uVar2 + 1;
        FUN_800ac614(7,uVar15,uVar12,*(undefined1 *)(param_3 + 5));
        FUN_800ac614(10,uVar15,uVar12,*(undefined1 *)(param_3 + 6));
        FUN_800ac614(0x5b,uVar15,uVar12,*(undefined1 *)(param_3 + 7));
        puVar6 = (undefined1 *)(param_3 + 8);
        param_3 = param_3 + 8;
        FUN_800ac614(0x5d,uVar15,uVar12,*puVar6);
      } while ((int)uVar2 < 0x10);
    }
    *(undefined2 *)(iVar1 + -0x7fec33aa) = 0;
    if ((param_5 == (uint *)0x0) || ((*param_5 & 0x10) == 0)) {
      (&DAT_8013cc50)[iVar1] = 1;
    }
    do {
      uVar15 = 0;
      puVar7 = (uint *)&DAT_8013bc90;
      uVar12 = _DAT_80143c5c + 1 & 0x7fffffff;
      do {
        uVar15 = uVar15 + 1;
        if ((*(char *)((int)puVar7 + 0xfc1) == '\0') && (*puVar7 == _DAT_80143c5c)) {
          uVar2 = 0xffffffff;
          break;
        }
        puVar7 = puVar7 + 0x3fe;
        uVar2 = _DAT_80143c5c;
      } while (uVar15 < 8);
      _DAT_80143c5c = uVar12;
    } while (uVar2 == 0xffffffff);
    *(uint *)(&DAT_8013bc90 + uVar17 * 0xff8) = uVar2;
    (&DAT_8013cc51)[iVar1] = 0;
  }
  return uVar2;
}
