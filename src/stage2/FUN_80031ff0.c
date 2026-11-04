/* FUN_80031ff0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031ff0  body 0x80031ff0..0x8003247b  size 1164 B
 * body sha256 28ed3dcca81d961756c5e2169388f2c12e6d1e74934573a2750e28cc5d8176e0
 * provider record sha256 ccc46e341095d84331a30fd8b7d3a1659d7bc5d82c50d1ace46d8bd0955f0e1f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_80031ff0(char param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  int iVar16;
  
  puVar3 = DAT_800df934;
  puVar14 = (uint *)0x0;
  puVar9 = &DAT_800e13e8;
  do {
    puVar15 = (uint *)*puVar9;
    if ((*(char *)(puVar15 + 2) == param_1) && (puVar14 = puVar15, (*puVar15 & 1) == 0)) {
      puVar15[1] = 0;
      FUN_80089230(puVar15);
      *puVar15 = *puVar15 | 1;
      DAT_800e1126 = DAT_800e1126 + 1;
      return puVar15;
    }
    puVar9 = puVar9 + 1;
  } while (puVar9 != DAT_800df93c);
  puVar15 = (uint *)0x0;
  if (puVar14 != (uint *)0x0) {
    puVar9 = &DAT_800e13f0;
    iVar16 = 0x20;
    uVar5 = *DAT_800e13f0;
    puVar15 = DAT_800e13f0;
    while ((uVar5 & 1) != 0) {
      iVar16 = iVar16 + -1;
      puVar9 = puVar9 + 1;
      puVar15 = (uint *)0x0;
      if (iVar16 == 0) break;
      puVar15 = (uint *)*puVar9;
      uVar5 = *puVar15;
    }
    if (puVar15 == (uint *)0x0) {
      puVar15 = (uint *)0x0;
    }
    else {
      if (DAT_800df93c <= puVar9) {
        DAT_800df93c = puVar9 + 1;
      }
      *puVar9 = DAT_800df934;
      DAT_800e1126 = DAT_800e1126 + 1;
      puVar3[0x96] = puVar14[0x96];
      puVar3[0x86] = puVar14[0x86];
      puVar3[0x69] = puVar14[0x69];
      puVar3[0x88] = puVar14[0x88];
      puVar3[0x87] = puVar14[0x87];
      puVar3[0x8a] = puVar14[0x8a];
      puVar3[0x89] = puVar14[0x89];
      puVar3[0x8c] = puVar14[0x8c];
      puVar3[0x8b] = puVar14[0x8b];
      uVar5 = puVar14[0x31];
      puVar3[0x1b] = 0x808080;
      puVar3[0x31] = uVar5;
      *(undefined1 *)((int)puVar3 + 0x26b) = *(undefined1 *)((int)puVar14 + 0x26b);
      *(undefined1 *)((int)puVar3 + 0x1a1) = *(undefined1 *)((int)puVar14 + 0x1a1);
      uVar1 = *(undefined1 *)(puVar14 + 0x68);
      puVar3[0x33] = puVar3[0x31] + 0x1c;
      *(undefined1 *)(puVar3 + 0x68) = uVar1;
      *(undefined1 *)(puVar3 + 2) = *(undefined1 *)(puVar14 + 2);
      *(undefined2 *)((int)puVar3 + 0x1aa) = *(undefined2 *)((int)puVar14 + 0x1aa);
      *(undefined1 *)((int)puVar3 + 0x1a2) = *(undefined1 *)((int)puVar14 + 0x1a2);
      *(undefined2 *)((int)puVar3 + 0x25e) = *(undefined2 *)((int)puVar14 + 0x25e);
      puVar3[0xa8] = puVar14[0xa8];
      puVar3[0xa9] = puVar14[0xa9];
      *(undefined1 *)((int)puVar3 + 9) = *(undefined1 *)((int)puVar14 + 9);
      uVar5 = puVar14[0x49];
      uVar12 = puVar14[0x4a];
      uVar13 = puVar14[0x4b];
      puVar3[0x48] = puVar14[0x48];
      puVar3[0x49] = uVar5;
      puVar3[0x4a] = uVar12;
      puVar3[0x4b] = uVar13;
      uVar5 = puVar14[0x4d];
      uVar12 = puVar14[0x4e];
      uVar13 = puVar14[0x4f];
      puVar3[0x4c] = puVar14[0x4c];
      puVar3[0x4d] = uVar5;
      puVar3[0x4e] = uVar12;
      puVar3[0x4f] = uVar13;
      uVar5 = puVar14[0x51];
      uVar12 = puVar14[0x52];
      uVar13 = puVar14[0x53];
      puVar3[0x50] = puVar14[0x50];
      puVar3[0x51] = uVar5;
      puVar3[0x52] = uVar12;
      puVar3[0x53] = uVar13;
      uVar5 = puVar14[0x55];
      uVar12 = puVar14[0x56];
      uVar13 = puVar14[0x57];
      puVar3[0x54] = puVar14[0x54];
      puVar3[0x55] = uVar5;
      puVar3[0x56] = uVar12;
      puVar3[0x57] = uVar13;
      uVar5 = puVar14[0x59];
      uVar12 = puVar14[0x5a];
      uVar13 = puVar14[0x5b];
      puVar3[0x58] = puVar14[0x58];
      puVar3[0x59] = uVar5;
      puVar3[0x5a] = uVar12;
      puVar3[0x5b] = uVar13;
      uVar5 = puVar14[0x5d];
      uVar12 = puVar14[0x5e];
      uVar13 = puVar14[0x5f];
      puVar3[0x5c] = puVar14[0x5c];
      puVar3[0x5d] = uVar5;
      puVar3[0x5e] = uVar12;
      puVar3[0x5f] = uVar13;
      uVar5 = puVar14[0x6f];
      uVar12 = puVar14[0x70];
      uVar13 = puVar14[0x71];
      puVar3[0x6e] = puVar14[0x6e];
      puVar3[0x6f] = uVar5;
      puVar3[0x70] = uVar12;
      puVar3[0x71] = uVar13;
      uVar5 = puVar14[0x73];
      uVar12 = puVar14[0x74];
      uVar13 = puVar14[0x75];
      puVar3[0x72] = puVar14[0x72];
      puVar3[0x73] = uVar5;
      puVar3[0x74] = uVar12;
      puVar3[0x75] = uVar13;
      uVar5 = puVar14[0x77];
      puVar3[0x76] = puVar14[0x76];
      puVar3[0x77] = uVar5;
      puVar3[0x1c] = puVar14[0x1c];
      *(undefined2 *)(puVar3 + 0xd) = *(undefined2 *)(puVar14 + 0xd);
      *(undefined2 *)((int)puVar3 + 0x36) = *(undefined2 *)((int)puVar14 + 0x36);
      *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(puVar14 + 0xe);
      *(undefined2 *)((int)puVar3 + 0x212) = *(undefined2 *)((int)puVar14 + 0x212);
      *(undefined1 *)((int)puVar3 + 0x26a) = *(undefined1 *)((int)puVar14 + 0x26a);
      puVar3[0xa1] = puVar14[0xa1];
      uVar6 = FUN_80082674(puVar14,puVar3,puVar3 + 0xc0);
      puVar15 = puVar3 + 5;
      iVar11 = 2;
      puVar3[10] = puVar14[10];
      puVar10 = &DAT_800e9048;
      puVar3[0xb] = puVar14[0xb];
      uVar5 = puVar14[0xc];
      *(undefined2 *)(puVar3 + 0x19) = 0;
      *(undefined2 *)((int)puVar3 + 0x66) = 0;
      *(undefined2 *)(puVar3 + 0x1a) = 0;
      puVar3[0xc] = uVar5;
      do {
        iVar8 = 2;
        puVar7 = puVar10;
        puVar14 = puVar15;
        do {
          uVar2 = *puVar7;
          puVar7 = puVar7 + 1;
          iVar8 = iVar8 + -1;
          *(undefined2 *)puVar14 = uVar2;
          puVar14 = (uint *)((int)puVar14 + 2);
        } while (iVar8 != -1);
        puVar15 = (uint *)((int)puVar15 + 6);
        iVar11 = iVar11 + -1;
        puVar10 = puVar10 + 3;
      } while (iVar11 != -1);
      *puVar3 = 1;
      *(char *)(puVar3 + 3) = (char)iVar16;
      puVar3[1] = 0;
      *(undefined2 *)(puVar3 + 0x9b) = 0;
      *(undefined1 *)((int)puVar3 + 0x26f) = 0;
      *(undefined2 *)(puVar3 + 0x7c) = 0;
      *(undefined1 *)((int)puVar3 + 0x1e6) = 0;
      *(undefined2 *)(puVar3 + 0x9a) = 0;
      *(undefined2 *)(puVar3 + 0x9e) = 0;
      *(undefined2 *)((int)puVar3 + 0x27a) = 0x1000;
      *(undefined2 *)(puVar3 + 0x9c) = 0;
      *(undefined2 *)((int)puVar3 + 0x272) = 0;
      *(undefined2 *)(puVar3 + 0x9d) = 0;
      *(undefined2 *)((int)puVar3 + 0x276) = 0;
      *(undefined2 *)(puVar3 + 0x7d) = 0;
      *(undefined2 *)((int)puVar3 + 0x1f6) = 0;
      bVar4 = DAT_800e1126;
      puVar3[0xa8] = 0;
      puVar3[0xa9] = 0;
      puVar3[0xa0] = 0;
      *(byte *)(puVar3 + 0x7b) = bVar4 & 7;
      uVar6 = FUN_80088eec(puVar3,uVar6);
      puVar14 = (uint *)FUN_80088f1c(puVar3,uVar6,puVar3[0x69],0);
      FUN_800661e4(puVar3,puVar3[0x96]);
      puVar15 = puVar3;
      DAT_800df934 = puVar14;
    }
  }
  return puVar15;
}
