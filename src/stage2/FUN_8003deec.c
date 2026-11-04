/* FUN_8003deec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003deec  body 0x8003deec..0x8003dfe3  size 248 B
 * body sha256 278e068b3446dfa4031e67e60cca5fe4797b82e4fa8dec1642e70e7a315c9cfe
 * provider record sha256 60a12afc3e647aa5a0182c6c6a7428040ffbd89c3401afea6642fd81b11ee9ef
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003deec(void)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = DAT_800ebb94;
  if (DAT_800e115c + -1000 < (int)*(short *)(DAT_800ebb94 + 0x36)) {
    (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 2)])();
  }
  else {
    if (*(char *)(DAT_800ebb94 + 0x1b) < '\x14') {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      *(char *)(DAT_800ebb94 + 0x1b) = *(char *)(DAT_800ebb94 + 0x1b) + '\x01';
      *(ushort *)(iVar2 + 4) = *puVar1 + (short)(((uint)*puVar1 * 0x26) / 1000);
    }
    *(short *)(DAT_800ebb94 + 6) =
         (short)((longlong)(int)(uint)*(ushort *)(DAT_800ebb94 + 6) * 0x4051eb851f >> 0x26);
  }
  return;
}
