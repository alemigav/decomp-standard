/* FUN_8005bea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005bea0  body 0x8005bea0..0x8005c03b  size 412 B
 * body sha256 a51c7aa3b9ba1d08295d6a463ee8f92dd52999be87255fd5c29076233237bb5f
 * provider record sha256 d66a0d7b4f9fbb528a1235ef174793311a0cb8c6f076d09378ceff87725f8bdf
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005bea0(int param_1)

{
  byte bVar1;
  char cVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  undefined1 auStack_48 [32];
  ushort local_28;
  short local_26;
  undefined2 local_24;
  undefined2 local_20 [2];
  undefined2 local_1c;
  
  if (((*(ushort *)(param_1 + 0x1aa) & 0xfff) != 0) &&
     (iVar4 = (byte)(&DAT_80110f13)[*(ushort *)(param_1 + 0x1aa) & 0xfff] - 1,
     (byte)(&DAT_80110f13)[*(ushort *)(param_1 + 0x1aa) & 0xfff] != 0)) {
    bVar1 = *(byte *)(param_1 + 8);
    puVar6 = (uint *)(*(int *)(param_1 + 0x234) + (uint)(byte)(&DAT_80110f2c)[iVar4 * 6] * 0x178);
    if ((bVar1 & 1) != 0) {
      puVar6 = puVar6 + 0x178;
    }
    if ((bVar1 == 0xe) || (puVar3 = puVar6 + 0x16, puVar7 = puVar6, bVar1 == 0x41)) {
      puVar7 = puVar6 + 0x5e;
      puVar3 = puVar6 + 0x74;
    }
    iVar4 = iVar4 * 6;
    iVar5 = *(int *)(param_1 + 0x234);
    *puVar7 = *puVar7 | 0x41;
    cVar2 = (&DAT_80110f2d)[iVar4];
    *(undefined1 *)((int)puVar7 + 0x111) = 1;
    *(undefined1 *)((int)puVar7 + 0x112) = 0;
    *(short *)(puVar7 + 0x47) = (short)cVar2;
    bVar1 = (&DAT_80110f2f)[iVar4];
    *(undefined2 *)(puVar7 + 0x16) = 0;
    *(undefined2 *)((int)puVar7 + 0x5a) = 0;
    *(undefined2 *)(puVar7 + 0x17) = 0;
    *(ushort *)((int)puVar7 + 0x11e) = (ushort)bVar1;
    FUN_80040e58(puVar3,puVar7 + 2);
    FUN_800424ec(iVar5 + 0x1060,puVar7 + 2,puVar7 + 0xe);
    *(undefined2 *)(puVar7 + 10) = *(undefined2 *)(param_1 + 0x25e);
    local_28 = 0;
    local_24 = 0;
    local_26 = *(short *)(&DAT_80110f30 + iVar4) + *(short *)(param_1 + 0x66);
    FUN_80040e58(&local_28,auStack_48);
    local_26 = 0;
    local_28 = (ushort)(byte)(&DAT_80110f2e)[iVar4];
    FUN_8004276c(auStack_48,&local_28,local_20);
    *(undefined2 *)((int)puVar7 + 0x2a) = local_20[0];
    *(undefined2 *)(puVar7 + 0xb) = local_1c;
  }
  return;
}
