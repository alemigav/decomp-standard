/* FUN_80166a34
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80166a34  body 0x80166a34..0x80166dff  size 972 B
 * body sha256 14cfbab9d10f8987e7036186dd60165fbcf95e97280f61eee7c0dc14ec50e842
 * provider record sha256 8f55a84ffae3ce9c991399af65b02d8acd204b047e3e2cb31daa39e733a7b229
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_80166a34(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  
  puVar2 = _DAT_800df934;
  puVar5 = (undefined4 *)&DAT_800e13f0;
  iVar13 = 0x20;
  if ((*_DAT_800e13f0 & 1) != 0) {
    iVar13 = 0x1f;
    while ((puVar5 = puVar5 + 1, iVar13 != 0 && ((*(uint *)*puVar5 & 1) != 0))) {
      iVar13 = iVar13 + -1;
    }
  }
  if (_DAT_800df93c <= puVar5) {
    _DAT_800df93c = puVar5 + 1;
  }
  *puVar5 = _DAT_800df934;
  DAT_800e1126 = DAT_800e1126 + 1;
  puVar2[0x96] = *(undefined4 *)(param_2 + 600);
  puVar2[0x86] = *(undefined4 *)(param_2 + 0x218);
  puVar2[0x69] = *(undefined4 *)(param_2 + 0x1a4);
  puVar2[0x88] = *(undefined4 *)(param_2 + 0x220);
  puVar2[0x87] = *(undefined4 *)(param_2 + 0x21c);
  puVar2[0x8a] = *(undefined4 *)(param_2 + 0x228);
  puVar2[0x89] = *(undefined4 *)(param_2 + 0x224);
  puVar2[0x8c] = *(undefined4 *)(param_2 + 0x230);
  puVar2[0x8b] = *(undefined4 *)(param_2 + 0x22c);
  uVar4 = *(undefined4 *)(param_2 + 0xc4);
  puVar2[0x1b] = 0x808080;
  puVar2[0x37] = 0x808080ff;
  puVar2[0x31] = uVar4;
  *(undefined1 *)((int)puVar2 + 0x26b) = *(undefined1 *)(param_2 + 0x26b);
  *(undefined1 *)((int)puVar2 + 0x1a1) = *(undefined1 *)(param_2 + 0x1a1);
  *(undefined1 *)(puVar2 + 0x68) = *(undefined1 *)(param_2 + 0x1a0);
  puVar2[0x33] = puVar2[0x31] + 0x1c;
  *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(param_2 + 8);
  *(undefined2 *)((int)puVar2 + 0x1aa) = *(undefined2 *)(param_2 + 0x1aa);
  *(undefined1 *)((int)puVar2 + 0x1a2) = *(undefined1 *)(param_2 + 0x1a2);
  *(undefined2 *)((int)puVar2 + 0x25e) = *(undefined2 *)(param_2 + 0x25e);
  puVar2[0xa8] = *(undefined4 *)(param_2 + 0x2a0);
  puVar2[0xa9] = *(undefined4 *)(param_2 + 0x2a4);
  *(undefined1 *)((int)puVar2 + 9) = *(undefined1 *)(param_2 + 9);
  uVar4 = *(undefined4 *)(param_2 + 0x124);
  uVar11 = *(undefined4 *)(param_2 + 0x128);
  uVar12 = *(undefined4 *)(param_2 + 300);
  puVar2[0x48] = *(undefined4 *)(param_2 + 0x120);
  puVar2[0x49] = uVar4;
  puVar2[0x4a] = uVar11;
  puVar2[0x4b] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x134);
  uVar11 = *(undefined4 *)(param_2 + 0x138);
  uVar12 = *(undefined4 *)(param_2 + 0x13c);
  puVar2[0x4c] = *(undefined4 *)(param_2 + 0x130);
  puVar2[0x4d] = uVar4;
  puVar2[0x4e] = uVar11;
  puVar2[0x4f] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x144);
  uVar11 = *(undefined4 *)(param_2 + 0x148);
  uVar12 = *(undefined4 *)(param_2 + 0x14c);
  puVar2[0x50] = *(undefined4 *)(param_2 + 0x140);
  puVar2[0x51] = uVar4;
  puVar2[0x52] = uVar11;
  puVar2[0x53] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x154);
  uVar11 = *(undefined4 *)(param_2 + 0x158);
  uVar12 = *(undefined4 *)(param_2 + 0x15c);
  puVar2[0x54] = *(undefined4 *)(param_2 + 0x150);
  puVar2[0x55] = uVar4;
  puVar2[0x56] = uVar11;
  puVar2[0x57] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x164);
  uVar11 = *(undefined4 *)(param_2 + 0x168);
  uVar12 = *(undefined4 *)(param_2 + 0x16c);
  puVar2[0x58] = *(undefined4 *)(param_2 + 0x160);
  puVar2[0x59] = uVar4;
  puVar2[0x5a] = uVar11;
  puVar2[0x5b] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x174);
  uVar11 = *(undefined4 *)(param_2 + 0x178);
  uVar12 = *(undefined4 *)(param_2 + 0x17c);
  puVar2[0x5c] = *(undefined4 *)(param_2 + 0x170);
  puVar2[0x5d] = uVar4;
  puVar2[0x5e] = uVar11;
  puVar2[0x5f] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x1bc);
  uVar11 = *(undefined4 *)(param_2 + 0x1c0);
  uVar12 = *(undefined4 *)(param_2 + 0x1c4);
  puVar2[0x6e] = *(undefined4 *)(param_2 + 0x1b8);
  puVar2[0x6f] = uVar4;
  puVar2[0x70] = uVar11;
  puVar2[0x71] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x1cc);
  uVar11 = *(undefined4 *)(param_2 + 0x1d0);
  uVar12 = *(undefined4 *)(param_2 + 0x1d4);
  puVar2[0x72] = *(undefined4 *)(param_2 + 0x1c8);
  puVar2[0x73] = uVar4;
  puVar2[0x74] = uVar11;
  puVar2[0x75] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x1dc);
  puVar2[0x76] = *(undefined4 *)(param_2 + 0x1d8);
  puVar2[0x77] = uVar4;
  puVar2[0x1c] = *(undefined4 *)(param_2 + 0x70);
  *(undefined2 *)(puVar2 + 0xd) = *(undefined2 *)(param_2 + 0x34);
  *(undefined2 *)((int)puVar2 + 0x36) = *(undefined2 *)(param_2 + 0x36);
  *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_2 + 0x38);
  *(undefined2 *)((int)puVar2 + 0x212) = *(undefined2 *)(param_2 + 0x212);
  *(undefined1 *)((int)puVar2 + 0x26a) = *(undefined1 *)(param_2 + 0x26a);
  puVar2[0xa1] = *(undefined4 *)(param_2 + 0x284);
  uVar4 = func_0x80082674(param_2,puVar2,puVar2 + 0xc0);
  puVar5 = puVar2 + 5;
  iVar10 = 2;
  puVar2[10] = *(undefined4 *)(param_2 + 0x28);
  puVar9 = (undefined2 *)&DAT_800e9048;
  puVar2[0xb] = *(undefined4 *)(param_2 + 0x2c);
  uVar11 = *(undefined4 *)(param_2 + 0x30);
  *(undefined2 *)(puVar2 + 0x19) = 0;
  *(undefined2 *)((int)puVar2 + 0x66) = 0;
  *(undefined2 *)(puVar2 + 0x1a) = 0;
  puVar2[0xc] = uVar11;
  do {
    iVar7 = 2;
    puVar6 = puVar9;
    puVar8 = puVar5;
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      iVar7 = iVar7 + -1;
      *(undefined2 *)puVar8 = uVar1;
      puVar8 = (undefined4 *)((int)puVar8 + 2);
    } while (iVar7 != -1);
    puVar5 = (undefined4 *)((int)puVar5 + 6);
    iVar10 = iVar10 + -1;
    puVar9 = puVar9 + 3;
  } while (iVar10 != -1);
  *puVar2 = 1;
  *(char *)(puVar2 + 3) = (char)iVar13;
  puVar2[1] = 0;
  *(undefined2 *)(puVar2 + 0x9b) = 0;
  *(undefined1 *)((int)puVar2 + 0x26f) = 0;
  *(undefined2 *)(puVar2 + 0x7c) = 0;
  *(undefined1 *)((int)puVar2 + 0x1e6) = 0;
  *(undefined2 *)(puVar2 + 0x9a) = 0;
  *(undefined2 *)(puVar2 + 0x9e) = 0;
  *(undefined2 *)((int)puVar2 + 0x27a) = 0x1000;
  *(undefined2 *)(puVar2 + 0x9c) = 0;
  *(undefined2 *)((int)puVar2 + 0x272) = 0;
  *(undefined2 *)(puVar2 + 0x9d) = 0;
  *(undefined2 *)((int)puVar2 + 0x276) = 0;
  *(undefined2 *)(puVar2 + 0x7d) = 0;
  *(undefined2 *)((int)puVar2 + 0x1f6) = 0;
  bVar3 = DAT_800e1126;
  puVar2[0xa8] = 0;
  puVar2[0xa9] = 0;
  puVar2[0xa0] = 0;
  *(byte *)(puVar2 + 0x7b) = bVar3 & 7;
  _DAT_800df934 = (undefined4 *)func_0x80088eec(puVar2,uVar4);
  return puVar2;
}
