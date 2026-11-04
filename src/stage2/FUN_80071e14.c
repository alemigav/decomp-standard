/* FUN_80071e14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071e14  body 0x80071e14..0x800722cb  size 1208 B
 * body sha256 efea946eb22a6f70b7df1fad700ec83d29273bbb59f33e89d7ef30f12cc4e8eb
 * provider record sha256 222b2c3e7c05a3b958063dff12d171adfdf958a07c83ff0bda86859713742137
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071e14(int param_1)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 uVar11;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar12;
  undefined *puVar13;
  
  DAT_80115284 = *(int *)(param_1 + 0x1c);
  if ((DAT_800e8ca8 < 3) && ((DAT_800e110c & 0x2000000) == 0)) {
    puVar13 = &DAT_800e8d08;
  }
  else {
    puVar13 = &DAT_800e8d28;
  }
  if ((*(char *)(DAT_80115284 + 9) == -1) ||
     (iVar7 = FUN_800837ac(puVar13,*(char *)(DAT_80115284 + 9)), iVar7 == 0)) {
    FUN_8003287c(*(undefined1 *)(DAT_80115284 + 3));
    iVar7 = *(char *)(DAT_80115284 + 2) + 2;
    if (iVar7 != 1) {
      DAT_800e1126 = DAT_800e1126 + '\x01';
    }
    puVar12 = (undefined4 *)((int)DAT_800df934 + 7U & 0xfffffff8);
    DAT_800df934 = puVar12;
    (&DAT_800e13e8)[iVar7] = puVar12;
    *(byte *)(puVar12 + 3) = (byte)iVar7;
    iVar5 = DAT_80115284;
    puVar8 = DAT_800df934 + 0xc0;
    if (DAT_800df93c < &DAT_800e13ec + iVar7) {
      DAT_800df93c = &DAT_800e13ec + iVar7;
    }
    DAT_800df934 = puVar8;
    *puVar12 = 1;
    *(undefined1 *)((int)puVar12 + 0x296) = *(undefined1 *)(iVar5 + 7);
    iVar5 = DAT_80115284;
    cVar1 = *(char *)(DAT_80115284 + 7);
    cVar6 = DAT_80114f3d;
    if ((DAT_80114f3c != cVar1) && (cVar6 = cVar1, DAT_80114f3c == '\0')) {
      DAT_80114f3c = cVar1;
      cVar6 = DAT_80114f3d;
    }
    DAT_80114f3d = cVar6;
    sVar2 = *(short *)(DAT_80115284 + 10);
    *(short *)(puVar12 + 0xd) = sVar2;
    puVar12[10] = (int)sVar2;
    sVar2 = *(short *)(iVar5 + 0xc);
    *(short *)((int)puVar12 + 0x36) = sVar2;
    puVar12[0xb] = (int)sVar2;
    sVar2 = *(short *)(iVar5 + 0xe);
    *(short *)(puVar12 + 0xe) = sVar2;
    puVar12[0xc] = (int)sVar2;
    *(undefined2 *)(puVar12 + 0x6d) = *(undefined2 *)(iVar5 + 10);
    uVar3 = *(undefined2 *)(iVar5 + 0xe);
    *(undefined2 *)(puVar12 + 0x19) = 0;
    *(undefined2 *)((int)puVar12 + 0x1b6) = uVar3;
    uVar3 = *(undefined2 *)(iVar5 + 0x10);
    *(undefined2 *)(puVar12 + 0x1a) = 0;
    *(undefined2 *)((int)puVar12 + 0x66) = uVar3;
    *(undefined1 *)(puVar12 + 2) = *(undefined1 *)(iVar5 + 3);
    iVar5 = DAT_80115284;
    *(undefined2 *)((int)puVar12 + 0x1aa) = *(undefined2 *)(DAT_80115284 + 4);
    *(undefined1 *)((int)puVar12 + 0x26a) = *(undefined1 *)(iVar5 + 9);
    *(undefined1 *)((int)puVar12 + 0x26b) = *(undefined1 *)(DAT_80115284 + 8);
    *(undefined1 *)((int)puVar12 + 0x1a2) = *(undefined1 *)(DAT_80115284 + 6);
    *(ushort *)((int)puVar12 + 0x25e) = (ushort)*(byte *)(DAT_80115284 + 6) * -0x708;
    puVar12[1] = 0;
    *(undefined2 *)(puVar12 + 0x9b) = 0;
    *(undefined1 *)((int)puVar12 + 0x26f) = 0;
    *(undefined2 *)(puVar12 + 0x7c) = 0;
    *(undefined1 *)((int)puVar12 + 0x1e6) = 0;
    *(undefined2 *)(puVar12 + 0x9a) = 0;
    *(undefined2 *)((int)puVar12 + 0x27a) = 0x1000;
    *(undefined2 *)(puVar12 + 0x9c) = 0;
    *(undefined2 *)((int)puVar12 + 0x272) = 0;
    *(undefined2 *)(puVar12 + 0x9d) = 0;
    *(undefined2 *)((int)puVar12 + 0x276) = 0;
    puVar12[0xa8] = 0;
    puVar12[0xa9] = 0;
    puVar12[0xa0] = 0;
    *(undefined2 *)((int)puVar12 + 0x2ae) = 0;
    *(undefined2 *)(puVar12 + 0x6a) = 0;
    puVar12[0xa3] = 0;
    puVar12[0xa4] = 0;
    if (*(byte *)(puVar12 + 2) < 0x40) {
      uVar11 = 4;
    }
    else {
      uVar11 = 0x80;
    }
    *(undefined1 *)((int)puVar12 + 9) = uVar11;
    *(undefined2 *)(puVar12 + 0x4d) = 0xfa06;
    *(undefined2 *)((int)puVar12 + 0x13a) = 0x5fa;
    *(byte *)(puVar12 + 0x7b) = (byte)iVar7 & 7;
    *(undefined2 *)((int)puVar12 + 0x136) = 0x1c2;
    *(undefined2 *)(puVar12 + 0x4e) = 0x1c2;
    *(undefined2 *)(puVar12 + 0x4b) = 0x1c2;
    *(undefined2 *)((int)puVar12 + 0x12e) = 0x1c2;
    puVar12[0xa1] = 0;
    *(undefined2 *)(puVar12 + 0x4c) = 0;
    *(undefined2 *)((int)puVar12 + 0x132) = 0;
    puVar4 = DAT_80114f30;
    if (*(char *)(puVar12 + 2) == DAT_80114f36) {
      puVar12[0x69] = DAT_80114f30[0x69];
      puVar12[0x86] = DAT_80114f30[0x86];
      puVar12[0x87] = DAT_80114f30[0x87];
      puVar12[0x88] = DAT_80114f30[0x88];
      puVar12[0x89] = DAT_80114f30[0x89];
      puVar12[0x8a] = DAT_80114f30[0x8a];
      puVar12[0x96] = DAT_80114f30[0x96];
      uVar10 = FUN_80082674(DAT_80114f30,puVar12,puVar8);
      *(undefined1 *)(puVar12 + 0x68) = *(undefined1 *)(DAT_80114f30 + 0x68);
      *(undefined1 *)((int)puVar12 + 0x1a1) = *(undefined1 *)((int)DAT_80114f30 + 0x1a1);
    }
    else {
      DAT_80114f37 = *(undefined1 *)((int)puVar12 + 0x26b);
      DAT_80114f30 = puVar12;
      DAT_80114f36 = *(char *)(puVar12 + 2);
      uVar9 = FUN_8006d108(*(undefined1 *)(puVar12 + 2));
      if (uVar9 != DAT_80114f38) {
        *(byte *)((int)puVar12 + 0x26b) = *(byte *)((int)puVar12 + 0x26b) & 0x7f;
      }
      DAT_80114f38 = (byte)uVar9;
      uVar10 = FUN_80031c14(DAT_80114f36,puVar12,puVar8);
      DAT_80114f34 = 0;
      DAT_80114f2c = *(undefined4 *)(DAT_800df92c + 0x4c);
      if ((*(byte *)((int)puVar12 + 0x26b) & 0x80) != 0) {
        puVar12[0x87] = puVar4[0x87];
        puVar12[0x88] = puVar4[0x88];
        puVar12[0x89] = puVar4[0x89];
        puVar12[0x8a] = puVar4[0x8a];
      }
    }
    uVar10 = FUN_80088eec(puVar12,uVar10);
    iVar7 = FUN_80088f1c(puVar12,uVar10,puVar12[0x69],0);
    FUN_800661e4(puVar12,puVar12[0x96]);
    DAT_800df934 = (undefined4 *)iVar7;
    *(undefined1 *)(puVar12 + 0x7a) = 0;
    iVar7 = DAT_80115284;
    *(undefined2 *)(puVar12 + 0x7d) = *(undefined2 *)(DAT_80115284 + 0x12);
    *(undefined2 *)((int)puVar12 + 0x1f6) = *(undefined2 *)(iVar7 + 0x14);
    if ((*(ushort *)((int)puVar12 + 0x1aa) & 0x4000) != 0) {
      *(undefined1 *)(puVar12 + 0x97) = 0x92;
    }
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 0x16;
  return 1;
}
