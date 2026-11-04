/* FUN_8008940c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008940c  body 0x8008940c..0x800896bf  size 692 B
 * body sha256 d07195a42cb6026dd2c6877f420b9ab89542841f457721668d67ceac5592c777
 * provider record sha256 b916ba0a54a650a125850dd8c4e9b62fd17e2d44c6d541ba77be2e46c47c7d26
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008940c(int param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  char cVar18;
  uint uVar19;
  
  cVar18 = '\0';
  uVar14 = 0;
  puVar12 = *(undefined4 **)(param_1 + 0x234);
  uVar19 = (uint)*(ushort *)(param_2 + 6);
  puVar16 = (uint *)(param_2 + (*(ushort *)(param_2 + 2) & 0xfffc));
  iVar15 = *(byte *)(param_1 + 0x1a3) - 1;
  puVar12[0x19] = param_1 + 0x14;
  param_2 = param_2 + 8;
  puVar12[0x4b] = param_1;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined2 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0x10000000;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0x10000000;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0x10000000;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(int *)(param_1 + 0x70) = param_1 + 0x1b8;
  if (iVar15 != -1) {
    puVar7 = puVar12 + 0x4b;
    puVar13 = puVar12;
    puVar17 = puVar16;
    do {
      puVar7[-0x3d] = 0x10000000;
      puVar7[-0x3c] = 0;
      puVar7[-0x3b] = 0x10000000;
      puVar7[-0x3a] = 0;
      puVar7[-0x39] = 0x10000000;
      puVar7[-0x38] = 0;
      puVar7[-0x37] = 0;
      puVar7[-0x36] = 0;
      puVar11 = puVar13 + 2;
      iVar10 = 2;
      puVar8 = &DAT_800e9048;
      do {
        iVar4 = 2;
        puVar3 = puVar8;
        puVar6 = puVar11;
        do {
          uVar2 = *puVar3;
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
          *(undefined2 *)puVar6 = uVar2;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        } while (iVar4 != -1);
        puVar11 = (undefined4 *)((int)puVar11 + 6);
        iVar10 = iVar10 + -1;
        puVar8 = puVar8 + 3;
      } while (iVar10 != -1);
      puVar7[-0x33] = 0x808080;
      puVar7[-0x4a] = 0;
      puVar7[-0x35] = 0;
      *(undefined2 *)(puVar7 + -0x34) = 0;
      *(undefined2 *)(puVar7 + 1) = 0;
      *(undefined2 *)((int)puVar7 + 6) = 0;
      *(undefined2 *)(puVar7 + 2) = 0;
      *(undefined2 *)((int)puVar7 + 10) = 0;
      *(undefined2 *)(puVar7 + 3) = 0;
      *(undefined2 *)((int)puVar7 + 0xe) = 0;
      *puVar13 = 1;
      *(undefined2 *)(puVar7 + -0x38) = 0;
      *(char *)(puVar7 + -7) = cVar18;
      sVar1 = *(short *)((uVar14 ^ 1) * 2 + param_2);
      puVar7[-0x44] = (int)sVar1;
      *(short *)(puVar7 + -0x41) = sVar1;
      sVar1 = *(short *)((uVar14 + 1 ^ 1) * 2 + param_2);
      puVar7[-0x43] = (int)sVar1;
      *(short *)((int)puVar7 + -0x102) = sVar1;
      sVar1 = *(short *)((uVar14 + 2 ^ 1) * 2 + param_2);
      uVar14 = uVar14 + 3;
      puVar7[-0x42] = (int)sVar1;
      *(short *)(puVar7 + -0x40) = sVar1;
      if (uVar19 == 0) {
        puVar7[-0x32] = &DAT_800e9028;
        *puVar7 = 0;
      }
      else {
        iVar10 = (*puVar17 & 0xffff) - 1;
        uVar9 = (int)puVar16 + (*puVar17 >> 0x10);
        if (iVar10 != -1) {
          do {
            pbVar5 = (byte *)(uVar9 ^ 3);
            uVar9 = uVar9 + 1;
            puVar12[(uint)*pbVar5 * 0x5e + 0x19] = puVar13 + 0xe;
            iVar10 = iVar10 + -1;
            puVar12[(uint)*pbVar5 * 0x5e + 0x4b] = puVar13;
          } while (iVar10 != -1);
        }
        puVar17 = puVar17 + 1;
        uVar19 = uVar19 - 1;
      }
      puVar7 = puVar7 + 0x5e;
      puVar13 = puVar13 + 0x5e;
      iVar15 = iVar15 + -1;
      cVar18 = cVar18 + '\x01';
    } while (iVar15 != -1);
  }
  return;
}
