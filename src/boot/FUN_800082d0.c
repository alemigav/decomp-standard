/* FUN_800082d0
 * image   boot (boot), base 0x80000480
 * address 0x800082d0  body 0x800082d0..0x8000879b  size 1228 B
 * body sha256 8eab2356daec73c974a96fb430dfa3a58a2319d58be19ecba1978786b466316d
 * provider record sha256 b73749b81c8df794385f04a48b12e7594eff15e4fa50895f43538c15847414ae
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800082d0(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  undefined1 auStack_70 [31];
  char local_51;
  undefined4 local_50;
  ushort local_4c;
  undefined1 auStack_4a [26];
  undefined4 uStack_30;
  undefined1 local_2a [18];
  
  iVar3 = 0x1f;
  pcVar7 = &local_51;
  param_2[1] = param_1;
  param_2[2] = param_3;
  *param_2 = 0;
  *(undefined1 *)((int)param_2 + 0x65) = 0x80;
  do {
    *pcVar7 = -2;
    iVar3 = iVar3 + -1;
    pcVar7 = pcVar7 + -1;
  } while (-1 < iVar3);
  iVar3 = FUN_80008b70(param_1,param_3,0x400,auStack_70,0);
  if (iVar3 == 2) {
    iVar3 = FUN_80008b70(param_1,param_3,0x400,auStack_70,0);
  }
  if (iVar3 == 0) {
    iVar3 = FUN_800087a0(param_1,param_3,0x400,auStack_70);
    if (iVar3 == 2) {
      iVar3 = 4;
    }
    if (iVar3 == 0) {
      if (local_51 != -2) {
        iVar3 = 0x1f;
        pcVar7 = &local_51;
        do {
          *pcVar7 = -0x80;
          iVar3 = iVar3 + -1;
          pcVar7 = pcVar7 + -1;
        } while (-1 < iVar3);
        iVar3 = FUN_80008b70(param_1,param_3,0x400,auStack_70,0);
        if (iVar3 == 2) {
          iVar3 = FUN_80008b70(param_1,param_3,0x400,auStack_70,0);
        }
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = FUN_800087a0(param_1,param_3,0x400,auStack_70);
        if (iVar3 == 2) {
          iVar3 = 4;
        }
        if (iVar3 != 0) {
          return iVar3;
        }
        if (local_51 == -0x80) {
          if (*(int *)(param_3 * 4 + -0x7ffed720) != 0) {
            return 0;
          }
          iVar3 = 0;
          do {
            (&DAT_80016330)[iVar3] = 1;
            (&DAT_80016450)[iVar3] = 0;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x20);
          puVar12 = &DAT_80016330;
          iVar3 = param_3 * 0x40;
          puVar11 = (undefined4 *)(iVar3 + -0x7ffe9dd0);
          iVar4 = 0xe;
          puVar1 = (undefined4 *)(iVar3 + -0x7ffe9d98);
          do {
            *puVar1 = 0;
            iVar4 = iVar4 + -1;
            puVar1 = puVar1 + -1;
          } while (-1 < iVar4);
          *(undefined4 *)(iVar3 + -0x7ffe9d94) = 1;
          local_50._1_1_ = 0x23;
          local_50._2_1_ = 1;
          local_50._0_1_ = 0xff;
          local_50._3_1_ = 3;
          uVar2 = FUN_80008f30(0x600);
          puVar5 = auStack_4a;
          local_4c = uVar2 & 0xff | 0xc000;
          local_2a[0] = 0xff;
          do {
            *puVar5 = *puVar12;
            puVar5 = puVar5 + 1;
            puVar12 = puVar12 + 1;
          } while ((int)puVar5 < (int)local_2a);
          if ((param_3 != 0) && (iVar3 = 0, 0 < param_3)) {
            do {
              *(undefined1 *)puVar11 = 0;
              iVar3 = iVar3 + 1;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            } while (iVar3 < param_3);
          }
          puVar10 = &local_50;
          puVar1 = puVar11;
          if (((uint)puVar11 & 3) == 0) {
            do {
              uVar6 = puVar10[1];
              uVar8 = puVar10[2];
              uVar9 = puVar10[3];
              *puVar1 = *puVar10;
              puVar1[1] = uVar6;
              puVar1[2] = uVar8;
              puVar1[3] = uVar9;
              puVar10 = puVar10 + 4;
              puVar1 = puVar1 + 4;
            } while (puVar10 != &uStack_30);
          }
          else {
            do {
              uVar6 = puVar10[1];
              uVar8 = puVar10[2];
              uVar9 = puVar10[3];
              *puVar1 = *puVar10;
              puVar1[1] = uVar6;
              puVar1[2] = uVar8;
              puVar1[3] = uVar9;
              puVar10 = puVar10 + 4;
              puVar1 = puVar1 + 4;
            } while (puVar10 != &uStack_30);
          }
          uVar6 = puVar10[1];
          *puVar1 = *puVar10;
          puVar1[1] = uVar6;
          *(undefined1 *)(puVar11 + 10) = 0xfe;
          puVar12 = &DAT_80016450;
          iVar3 = param_3 * 0x40;
          puVar11 = (undefined4 *)(iVar3 + -0x7ffe9cb0);
          iVar4 = 0xe;
          puVar1 = (undefined4 *)(iVar3 + -0x7ffe9c78);
          do {
            *puVar1 = 0;
            iVar4 = iVar4 + -1;
            puVar1 = puVar1 + -1;
          } while (-1 < iVar4);
          *(undefined4 *)(iVar3 + -0x7ffe9c74) = 1;
          local_50._1_1_ = 0x23;
          local_50._2_1_ = 1;
          local_50._0_1_ = 0xff;
          local_50._3_1_ = 3;
          uVar2 = FUN_80008f30(0x600);
          puVar5 = auStack_4a;
          local_4c = uVar2 & 0xff | 0xc000;
          local_2a[0] = 0xff;
          do {
            *puVar5 = *puVar12;
            puVar5 = puVar5 + 1;
            puVar12 = puVar12 + 1;
          } while ((int)puVar5 < (int)local_2a);
          if ((param_3 != 0) && (iVar3 = 0, 0 < param_3)) {
            do {
              *(undefined1 *)puVar11 = 0;
              iVar3 = iVar3 + 1;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            } while (iVar3 < param_3);
          }
          puVar10 = &local_50;
          puVar1 = puVar11;
          if (((uint)puVar11 & 3) == 0) {
            do {
              uVar6 = puVar10[1];
              uVar8 = puVar10[2];
              uVar9 = puVar10[3];
              *puVar1 = *puVar10;
              puVar1[1] = uVar6;
              puVar1[2] = uVar8;
              puVar1[3] = uVar9;
              puVar10 = puVar10 + 4;
              puVar1 = puVar1 + 4;
            } while (puVar10 != &uStack_30);
          }
          else {
            do {
              uVar6 = puVar10[1];
              uVar8 = puVar10[2];
              uVar9 = puVar10[3];
              *puVar1 = *puVar10;
              puVar1[1] = uVar6;
              puVar1[2] = uVar8;
              puVar1[3] = uVar9;
              puVar10 = puVar10 + 4;
              puVar1 = puVar1 + 4;
            } while (puVar10 != &uStack_30);
          }
          uVar6 = puVar10[1];
          *puVar1 = *puVar10;
          puVar1[1] = uVar6;
          *(undefined1 *)(puVar11 + 10) = 0xfe;
          *(undefined4 *)(param_3 * 4 + -0x7ffed720) = 1;
          return 0;
        }
      }
      iVar3 = 0xb;
    }
  }
  return iVar3;
}
