/* FUN_8005f808
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005f808  body 0x8005f808..0x8005fa53  size 588 B
 * body sha256 98dca7dcafb896dd59af89d84591a20b1d00637aaf7efb9f8c83b3acff8b3a61
 * provider record sha256 fa486e9e16d267c798765dfd1a4e1e5972ad11b7b6d7b137e2f73b453fdd0dd4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8005f808(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  short sVar11;
  
  iVar3 = 6;
  sVar11 = 0;
  iVar2 = *(int *)(param_1 + 0x234);
  puVar9 = (undefined4 *)(iVar2 + 0x1d60);
  piVar8 = (int *)(iVar2 + 0x1e8c);
  do {
    if (*(char *)(piVar8 + 1) == -1) {
      *(undefined1 *)(piVar8 + 1) = 0;
      *puVar9 = 1;
      piVar8[-0x44] = 200;
      piVar8[0x13] = 1;
      piVar8[-0x43] = 0x390;
      piVar8[-0x42] = 0;
      if (param_2 == 1) {
        piVar8[-0x42] = 100;
      }
      puVar10 = puVar9 + 2;
      if (param_2 == 2) {
        piVar8[-0x42] = -100;
      }
      iVar3 = 2;
      puVar7 = &DAT_800e9048;
      do {
        iVar5 = 2;
        puVar4 = puVar7;
        puVar6 = puVar10;
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          iVar5 = iVar5 + -1;
          *(undefined2 *)puVar6 = uVar1;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        } while (iVar5 != -1);
        puVar10 = (undefined4 *)((int)puVar10 + 6);
        iVar3 = iVar3 + -1;
        puVar7 = puVar7 + 3;
      } while (iVar3 != -1);
      FUN_800424ec(piVar8[-0x32],puVar9 + 2,puVar9 + 0xe);
      *(undefined2 *)((int)piVar8 + -0x16) = *(undefined2 *)(param_1 + 0x66);
      iVar3 = *(int *)(param_1 + 0x234);
      *puVar9 = 1;
      piVar8[-0x32] = iVar3 + 0x1060;
      *piVar8 = iVar3 + 0x1028;
      *(short *)(iVar2 + 0x1144) = sVar11;
      return 1;
    }
    piVar8 = piVar8 + 0xbc;
    puVar9 = puVar9 + 0xbc;
    iVar3 = iVar3 + -1;
    sVar11 = sVar11 + 1;
  } while (iVar3 != 0);
  sVar11 = *(short *)(iVar2 + 0x1144) + 1;
  *(short *)(iVar2 + 0x1144) = sVar11;
  if (2 < sVar11) {
    *(undefined2 *)(iVar2 + 0x1144) = 0;
  }
  iVar3 = 2;
  puVar7 = &DAT_800e9048;
  puVar10 = (undefined4 *)(*(int *)(param_1 + 0x234) + *(short *)(iVar2 + 0x1144) * 0x2f0 + 0x1d60);
  *(undefined1 *)(puVar10 + 0x4c) = 0;
  *puVar10 = 1;
  puVar10[0x5e] = 1;
  puVar9 = puVar10 + 2;
  *(undefined2 *)((int)puVar10 + 0x116) = *(undefined2 *)(param_1 + 0x66);
  iVar2 = *(int *)(param_1 + 0x234);
  *puVar10 = 0x41;
  puVar10[0x19] = iVar2 + 0x1060;
  puVar10[0x4b] = iVar2 + 0x1028;
  do {
    iVar2 = 2;
    puVar4 = puVar7;
    puVar6 = puVar9;
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
      *(undefined2 *)puVar6 = uVar1;
      puVar6 = (undefined4 *)((int)puVar6 + 2);
    } while (iVar2 != -1);
    puVar9 = (undefined4 *)((int)puVar9 + 6);
    iVar3 = iVar3 + -1;
    puVar7 = puVar7 + 3;
  } while (iVar3 != -1);
  puVar10[7] = 200;
  puVar10[8] = 0x390;
  puVar10[9] = 0;
  if (param_2 == 1) {
    puVar10[9] = 100;
  }
  if (param_2 == 2) {
    puVar10[9] = 0xffffff9c;
  }
  FUN_800424ec(puVar10[0x19],puVar10 + 2,puVar10 + 0xe);
  return 0;
}
