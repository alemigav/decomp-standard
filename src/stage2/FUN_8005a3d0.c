/* FUN_8005a3d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005a3d0  body 0x8005a3d0..0x8005a767  size 920 B
 * body sha256 b4f9b7e2827b4ed59e72c308180875f2c532b7cd684c6ba4651f33db00b0cfe7
 * provider record sha256 5c8f28ebda494aef26d8de486a204fd133337e489546ed3a36b430459d5d4b89
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005a3d0(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined1 auStack_e0 [76];
  undefined4 *local_94;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  
  puVar3 = DAT_800df924;
  puVar4 = DAT_800df924 + 0x758;
  uVar11 = *(ushort *)(param_1 + 0x1aa) & 0xfff;
  bVar1 = *(byte *)(param_1 + 8);
  if (0x13 < uVar11) {
    uVar11 = 0;
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xf000;
  }
  local_30 = puVar4;
  FUN_80085398(puVar4,puVar3 + 0xf58,"weapon");
  iVar15 = uVar11 * 4;
  iVar13 = *(int *)((&PTR_DAT_80110d10)[bVar1] + iVar15);
  local_38 = 0;
  local_34 = 0;
  if (-1 < iVar13) {
    puVar4 = (undefined4 *)FUN_800874d4(puVar4,&local_38,&local_34,iVar13,0);
  }
  if ((uint)((int)puVar4 - (int)local_30) < 0x2000) {
    puVar4 = puVar3 + 0xf58;
  }
  iVar5 = func_0x80004cfc(*(undefined4 *)((&PTR_DAT_80110cd0)[bVar1] + iVar15),puVar4,0,"WEP TM3");
  uVar11 = (int)puVar4 + iVar5 + 7 & 0xfffffff8;
  FUN_800824b8(puVar4);
  local_94 = puVar4;
  FUN_80087868(auStack_e0,iVar13);
  iVar5 = puVar4[1];
  iVar14 = puVar4[2];
  cVar12 = *(char *)(param_1 + 0x1a3);
  *(uint *)(param_1 + 0x220) = uVar11;
  *(char *)(param_1 + 0x1a3) = cVar12 + (char)iVar5;
  DAT_80111160 = iVar5;
  iVar13 = func_0x80005e84(*(undefined2 *)((&PTR_DAT_80110d50)[bVar1] + iVar15 + 2),uVar11);
  uVar11 = iVar13 + 7U & 0xfffffff8;
  *(uint *)(param_1 + 0x21c) = uVar11;
  iVar13 = func_0x80005ee8(*(undefined2 *)((&PTR_DAT_80110d90)[bVar1] + iVar15 + 2),uVar11);
  uVar11 = iVar13 + 7U & 0xfffffff8;
  puVar8 = puVar3 + 0x2b;
  puVar4 = puVar3;
  do {
    puVar10 = puVar4 + 2;
    iVar13 = 2;
    puVar9 = &DAT_800e9048;
    puVar8[-0x12] = &DAT_800e9028;
    puVar8[0x20] = 0;
    *(undefined2 *)(puVar8 + -0x21) = 0;
    puVar8[-0x24] = 0;
    *(undefined2 *)((int)puVar8 + -0x82) = 0;
    puVar8[-0x23] = 0;
    *(undefined2 *)(puVar8 + -0x20) = 0;
    puVar8[-0x22] = 0;
    puVar8[-0x1d] = 0x10000000;
    puVar8[-0x1c] = 0;
    puVar8[-0x1b] = 0x10000000;
    puVar8[-0x1a] = 0;
    puVar8[-0x19] = 0x10000000;
    puVar8[-0x18] = 0;
    puVar8[-0x17] = 0;
    puVar8[-0x16] = 0;
    do {
      iVar15 = 2;
      puVar6 = puVar9;
      puVar7 = puVar10;
      do {
        uVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        iVar15 = iVar15 + -1;
        *(undefined2 *)puVar7 = uVar2;
        puVar7 = (undefined4 *)((int)puVar7 + 2);
      } while (iVar15 != -1);
      puVar10 = (undefined4 *)((int)puVar10 + 6);
      iVar13 = iVar13 + -1;
      puVar9 = puVar9 + 3;
    } while (iVar13 != -1);
    puVar8[8] = 0xffffffff;
    puVar8[-0x2a] = 0;
    puVar8[-0x13] = 0x808080;
    puVar8[-0x15] = 0;
    *(undefined2 *)(puVar8 + -0x14) = 0;
    *puVar4 = 0;
    puVar8[7] = iVar14;
    iVar14 = iVar14 + 0x10;
    *(char *)(puVar8 + 0x19) = cVar12;
    cVar12 = cVar12 + '\x01';
    puVar4 = puVar4 + 0x5e;
    iVar5 = iVar5 + -1;
    *(undefined2 *)(puVar8 + -0x18) = 0;
    puVar8[2] = 0;
    puVar8[4] = 0;
    puVar8[-1] = local_38;
    *puVar8 = local_34;
    puVar8 = puVar8 + 0x5e;
  } while (iVar5 != 0);
  iVar13 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar13 + 0x10d0) = puVar3[0x2a];
  *(undefined4 *)(iVar13 + 0x10f0) = puVar3[0x32];
  *(undefined4 *)(iVar13 + 0x10dc) = puVar3[0x2d];
  *(undefined4 *)(iVar13 + 0x10e4) = puVar3[0x2f];
  *(undefined4 *)(iVar13 + 0x10d0) = puVar3[0x2a];
  *(undefined4 *)(iVar13 + 0x10d4) = puVar3[0x2b];
  (*(code *)(&PTR_LAB_80110dd0)[*(ushort *)(param_1 + 0x1aa) & 0xfff])(param_1);
  if (DAT_800c52dc + 0x3b800U < uVar11) {
    DAT_80110e20 = (uVar11 - 0x3b800) - DAT_800c52dc;
  }
  return;
}
