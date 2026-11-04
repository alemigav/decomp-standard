/* FUN_8000d6a0
 * image   boot (boot), base 0x80000480
 * address 0x8000d6a0  body 0x8000d6a0..0x8000d9bb  size 796 B
 * body sha256 0a9596b6250a72033adb582524daffd5ca548a4197ac731f4c9795c8032b5c5a
 * provider record sha256 731d62d5728e9cd91dc893fbbd65eeefbf24d84a2c7cee4385fd57318a473734
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_8000d6a0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  if ((param_3 != 0) && (param_1 != param_2)) {
    if (((int)param_2 < (int)param_1) || ((int)((int)param_1 + param_3) <= (int)param_2)) {
      puVar9 = param_2;
      if ((0xf < param_3) && (uVar4 = (uint)param_1 & 3, uVar4 == ((uint)param_2 & 3))) {
        if (uVar4 != 0) {
          if (uVar4 == 1) {
            uVar2 = *(undefined1 *)param_1;
            uVar3 = *(undefined2 *)((int)param_1 + 1);
            param_1 = (undefined4 *)((int)param_1 + 3);
            *(undefined1 *)param_2 = uVar2;
            *(undefined2 *)((int)param_2 + 1) = uVar3;
            puVar9 = (undefined4 *)((int)param_2 + 3);
            param_3 = param_3 + -3;
          }
          else if (uVar4 == 2) {
            uVar3 = *(undefined2 *)param_1;
            param_1 = (undefined4 *)((int)param_1 + 2);
            *(undefined2 *)param_2 = uVar3;
            puVar9 = (undefined4 *)((int)param_2 + 2);
            param_3 = param_3 + -2;
          }
          else {
            uVar2 = *(undefined1 *)param_1;
            param_1 = (undefined4 *)((int)param_1 + 1);
            *(undefined1 *)param_2 = uVar2;
            puVar9 = (undefined4 *)((int)param_2 + 1);
            param_3 = param_3 + -1;
          }
        }
        for (; 0x1f < param_3; param_3 = param_3 + -0x20) {
          uVar7 = *param_1;
          uVar11 = param_1[1];
          uVar12 = param_1[2];
          uVar13 = param_1[3];
          uVar14 = param_1[4];
          uVar15 = param_1[5];
          uVar17 = param_1[6];
          uVar16 = param_1[7];
          param_1 = param_1 + 8;
          *puVar9 = uVar7;
          puVar9[1] = uVar11;
          puVar9[2] = uVar12;
          puVar9[3] = uVar13;
          puVar9[4] = uVar14;
          puVar9[5] = uVar15;
          puVar9[6] = uVar17;
          puVar9[7] = uVar16;
          puVar9 = puVar9 + 8;
        }
        for (; 0xf < param_3; param_3 = param_3 + -0x10) {
          uVar7 = *param_1;
          uVar11 = param_1[1];
          uVar12 = param_1[2];
          uVar13 = param_1[3];
          param_1 = param_1 + 4;
          *puVar9 = uVar7;
          puVar9[1] = uVar11;
          puVar9[2] = uVar12;
          puVar9[3] = uVar13;
          puVar9 = puVar9 + 4;
        }
        for (; 3 < param_3; param_3 = param_3 + -4) {
          uVar7 = *param_1;
          param_1 = param_1 + 1;
          *puVar9 = uVar7;
          puVar9 = puVar9 + 1;
        }
      }
      if (param_3 != 0) {
        puVar5 = (undefined4 *)((int)param_1 + param_3);
        do {
          uVar2 = *(undefined1 *)param_1;
          param_1 = (undefined4 *)((int)param_1 + 1);
          *(undefined1 *)puVar9 = uVar2;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        } while (param_1 != puVar5);
      }
    }
    else {
      puVar8 = (undefined1 *)((int)param_1 + param_3);
      puVar10 = (undefined1 *)((int)param_2 + param_3);
      if ((0xf < param_3) && (uVar4 = (uint)puVar8 & 3, uVar4 == ((uint)puVar10 & 3))) {
        if (uVar4 != 0) {
          if (uVar4 == 3) {
            puVar6 = puVar8 + -1;
            uVar3 = *(undefined2 *)(puVar8 + -3);
            puVar8 = puVar8 + -3;
            puVar10[-1] = *puVar6;
            *(undefined2 *)(puVar10 + -3) = uVar3;
            puVar10 = puVar10 + -3;
            param_3 = param_3 + -3;
          }
          else if (uVar4 == 2) {
            puVar1 = (undefined2 *)(puVar8 + -2);
            puVar8 = puVar8 + -2;
            *(undefined2 *)(puVar10 + -2) = *puVar1;
            puVar10 = puVar10 + -2;
            param_3 = param_3 + -2;
          }
          else {
            puVar6 = puVar8 + -1;
            puVar8 = puVar8 + -1;
            puVar10[-1] = *puVar6;
            puVar10 = puVar10 + -1;
            param_3 = param_3 + -1;
          }
        }
        for (; 0x1f < param_3; param_3 = param_3 + -0x20) {
          puVar9 = (undefined4 *)(puVar8 + -4);
          uVar7 = *(undefined4 *)(puVar8 + -8);
          uVar11 = *(undefined4 *)(puVar8 + -0xc);
          uVar12 = *(undefined4 *)(puVar8 + -0x10);
          uVar13 = *(undefined4 *)(puVar8 + -0x14);
          uVar14 = *(undefined4 *)(puVar8 + -0x18);
          uVar15 = *(undefined4 *)(puVar8 + -0x1c);
          uVar17 = *(undefined4 *)(puVar8 + -0x20);
          puVar8 = puVar8 + -0x20;
          *(undefined4 *)(puVar10 + -4) = *puVar9;
          *(undefined4 *)(puVar10 + -8) = uVar7;
          *(undefined4 *)(puVar10 + -0xc) = uVar11;
          *(undefined4 *)(puVar10 + -0x10) = uVar12;
          *(undefined4 *)(puVar10 + -0x14) = uVar13;
          *(undefined4 *)(puVar10 + -0x18) = uVar14;
          *(undefined4 *)(puVar10 + -0x1c) = uVar15;
          *(undefined4 *)(puVar10 + -0x20) = uVar17;
          puVar10 = puVar10 + -0x20;
        }
        for (; 0xf < param_3; param_3 = param_3 + -0x10) {
          puVar9 = (undefined4 *)(puVar8 + -4);
          uVar7 = *(undefined4 *)(puVar8 + -8);
          uVar11 = *(undefined4 *)(puVar8 + -0xc);
          uVar12 = *(undefined4 *)(puVar8 + -0x10);
          puVar8 = puVar8 + -0x10;
          *(undefined4 *)(puVar10 + -4) = *puVar9;
          *(undefined4 *)(puVar10 + -8) = uVar7;
          *(undefined4 *)(puVar10 + -0xc) = uVar11;
          *(undefined4 *)(puVar10 + -0x10) = uVar12;
          puVar10 = puVar10 + -0x10;
        }
        for (; 3 < param_3; param_3 = param_3 + -4) {
          puVar9 = (undefined4 *)(puVar8 + -4);
          puVar8 = puVar8 + -4;
          *(undefined4 *)(puVar10 + -4) = *puVar9;
          puVar10 = puVar10 + -4;
        }
      }
      if (param_3 != 0) {
        puVar8 = puVar8 + -1;
        puVar6 = puVar8 + -param_3;
        do {
          puVar10 = puVar10 + -1;
          uVar2 = *puVar8;
          puVar8 = puVar8 + -1;
          *puVar10 = uVar2;
        } while (puVar8 != puVar6);
        return param_2;
      }
    }
  }
  return param_2;
}
