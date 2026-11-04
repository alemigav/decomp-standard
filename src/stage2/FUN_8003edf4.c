/* FUN_8003edf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003edf4  body 0x8003edf4..0x8003efbb  size 456 B
 * body sha256 db8dd8bd95458b6138454a50232047d3beb6cba403c8560d33738acf91c38e0a
 * provider record sha256 5b9dfa3ad028ff6f1a5f0ff3342fbe9ba628be058136664a206b1f6e7f9b8ce9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003edf4(void)

{
  ushort *puVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = FUN_800837ac(&DAT_800e8ce0,0x76);
  puVar3 = DAT_800ebb94;
  if (iVar4 == 0) {
    puVar1 = (ushort *)(DAT_800ebb94 + 0x12);
    *(undefined2 *)(DAT_800ebb94 + 0x18) = 0x8000;
    if ((uint)*puVar1 % 5 == 0) {
      uVar5 = FUN_80038a20((uint)(byte)puVar3[0x1c] << 0x18 | *(ushort *)(puVar3 + 0x3a) | 0x10000,
                           (int)*(short *)(puVar3 + 0x22),*(undefined4 *)(puVar3 + 0x6c),
                           puVar3 + 0x2c);
      if ((uVar5 & 0xff) < 0xff) {
        (&DAT_800ebdc0)[(uVar5 & 0xff) * 0x3e] = 0xb803;
      }
    }
  }
  else {
    sVar2 = *(short *)(DAT_800ebb94 + 0x14);
    *(ushort *)(DAT_800ebb94 + 0x14) = sVar2 + 1U;
    if ((ushort)(sVar2 + 1U) < 0x5b) {
      if ((uint)*(ushort *)(puVar3 + 0x12) % 5 == 0) {
        *(short *)(puVar3 + 4) = (short)(((uint)*(ushort *)(puVar3 + 4) * 0x50) / 100);
        uVar5 = FUN_80038a20((uint)(byte)puVar3[0x1c] << 0x18 | *(ushort *)(puVar3 + 0x3a) | 0x10000
                             ,(int)*(short *)(puVar3 + 0x22),*(undefined4 *)(puVar3 + 0x6c),
                             puVar3 + 0x2c);
        puVar3 = DAT_800ebb94;
        uVar5 = uVar5 & 0xff;
        if (uVar5 < 0xff) {
          (&DAT_800ebdc0)[uVar5 * 0x3e] = 0xb803;
          *(undefined2 *)(&DAT_800ebdac + uVar5 * 0x7c) = *(undefined2 *)(puVar3 + 4);
        }
      }
    }
    else {
      puVar3[1] = 0;
      *puVar3 = 0;
      *(undefined2 *)(puVar3 + 0x18) = 0;
    }
  }
  *(short *)(DAT_800ebb94 + 0x12) = *(short *)(DAT_800ebb94 + 0x12) + 1;
  return;
}
