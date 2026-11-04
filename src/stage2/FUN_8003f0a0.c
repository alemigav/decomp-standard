/* FUN_8003f0a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003f0a0  body 0x8003f0a0..0x8003f4fb  size 1116 B
 * body sha256 c28dbc4038a543de643eb5379bac17ca478c0796a6cb4a29ad3b3a9b11ce7f59
 * provider record sha256 c8e43933711c4bb5469d23199fece3da3e9a9e290f565fa1f8239a508848b931
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003f0a0(void)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 local_30;
  short local_2e;
  undefined2 local_2c;
  
  local_30 = *(undefined2 *)(DAT_800ebb94 + 0x2c);
  bVar1 = DAT_800ebb94[0x1e];
  local_2e = *(short *)(DAT_800ebb94 + 0x2e);
  local_2c = *(undefined2 *)(DAT_800ebb94 + 0x30);
  uVar4 = FUN_80033604();
  uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
  uVar6 = (bVar1 & 0xf8) << 0x10;
  uVar5 = FUN_80033604();
  FUN_80038a20(uVar6 | ((uint)uVar2 * 0x3c) / 100 + (uVar4 & 7) * 0x80 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) -
                     (((uVar5 & 0xff) % 10) * 0xc + -0x270)) * 0x10000) >> 0x10,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),&local_30);
  uVar4 = FUN_80033604();
  uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
  uVar5 = FUN_80033604();
  FUN_80038a20(uVar6 | ((uint)uVar2 * 0x3c) / 100 + (uVar4 & 7) * 0x80 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar5 & 0xff) % 10) * 0xc + 0xd90)
                    * 0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),&local_30);
  local_2e = local_2e + *(ushort *)(DAT_800ebb94 + 0x3a) / 0xf;
  uVar4 = FUN_80033604();
  uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
  uVar5 = FUN_80033604();
  FUN_80038a20(uVar6 | ((uint)uVar2 * 0x50) / 100 + (uVar4 & 7) * 0x80 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) -
                     (((uVar5 & 0xff) % 10) * 0xc + -0x270)) * 0x10000) >> 0x10,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),&local_30);
  uVar4 = FUN_80033604();
  uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
  uVar5 = FUN_80033604();
  FUN_80038a20(uVar6 | ((uint)uVar2 * 0x50) / 100 + (uVar4 & 7) * 0x80 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar5 & 0xff) % 10) * 0xc + 0xd90)
                    * 0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),&local_30);
  local_2e = local_2e + *(ushort *)(DAT_800ebb94 + 0x3a) / 0xf;
  uVar4 = FUN_80033604();
  uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
  uVar5 = FUN_80033604();
  FUN_80038a20(uVar6 | (uint)uVar2 + (uVar4 & 7) * 0x80 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) -
                     (((uVar5 & 0xff) % 10) * 0xc + -0x270)) * 0x10000) >> 0x10,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),&local_30);
  uVar4 = FUN_80033604();
  uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
  uVar5 = FUN_80033604();
  FUN_80038a20(uVar6 | (uint)uVar2 + (uVar4 & 7) * 0x80 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar5 & 0xff) % 10) * 0xc + 0xd90)
                    * 0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),&local_30);
  puVar3 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar3 = 0;
  *(undefined2 *)(puVar3 + 0x18) = 0;
  return;
}
