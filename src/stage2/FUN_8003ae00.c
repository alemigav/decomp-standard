/* FUN_8003ae00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ae00  body 0x8003ae00..0x8003aef7  size 248 B
 * body sha256 16cd87ef17d39209582dc313362b673c45b242001f5c7fbdd9b5f5cfc96a585b
 * provider record sha256 8cd362de584082b5fdd748c0a8206659a99d704c0e5ba1d597d125a265a5b31d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ae00(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  DAT_800ebb94[0x1b] = (char)DAT_800e12da + -9;
  *DAT_800ebb94 = 0x16;
  DAT_800ebb94[1] = 0xf;
  puVar1 = DAT_800ebb94;
  *(undefined2 *)(DAT_800ebb94 + 0x18) = 0xb403;
  puVar1[0x21] = 0x12;
  puVar2 = DAT_800ebb94;
  *(ushort *)(puVar1 + 0x2a) = *(ushort *)(puVar1 + 0x2a) | 0x20;
  puVar2[0x20] = *(undefined1 *)(*(int *)(puVar2 + 0x70) + (uint)(byte)puVar2[0x21] * 8 + 2);
  if ((DAT_800e12da & 0x1f) == 9) {
    bVar3 = FUN_80033604();
    DAT_800ebb94[0xb] = bVar3 % 3 + 10;
  }
  else {
    DAT_800ebb94[0xb] = 0xf;
  }
  FUN_8003aa3c();
  return;
}
