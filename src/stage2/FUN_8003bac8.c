/* FUN_8003bac8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bac8  body 0x8003bac8..0x8003bbd3  size 268 B
 * body sha256 6efcf0cfe075bbd713126749b88671d599c2e9ca053b7eb4752caedcb9fb3a1f
 * provider record sha256 93788a1c9c540625a2141a93c4ac1f0e1080618d01e91823ae678f6e85622609
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003bac8(void)

{
  uint uVar1;
  int iVar2;
  
  if (*(short *)(DAT_800ebb94 + 0x42) < 4) {
    *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + 1;
  }
  else {
    if (*(char *)(DAT_800ebb94 + 0x1b) == '\0') {
      uVar1 = FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0xa000000,
                           (int)*(short *)(DAT_800ebb94 + 0x22),*(undefined4 *)(DAT_800ebb94 + 0x6c)
                           ,DAT_800ebb94 + 0x2c);
      if ((uVar1 & 0xff) < 0xff) {
        iVar2 = (uVar1 & 0xff) * 0x7c;
        (&DAT_800ebdc3)[iVar2] = 1;
        *(undefined2 *)(&DAT_800ebdea + iVar2) = 1;
      }
    }
    else if (*(char *)(DAT_800ebb94 + 0x1b) < '\x03') {
      uVar1 = FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0xa000000,
                           (int)*(short *)(DAT_800ebb94 + 0x22),*(undefined4 *)(DAT_800ebb94 + 0x6c)
                           ,DAT_800ebb94 + 0x2c);
      if ((uVar1 & 0xff) < 0xff) {
        (&DAT_800ebdc3)[(uVar1 & 0xff) * 0x7c] = *(char *)(DAT_800ebb94 + 0x1b) + '\x01';
      }
    }
    FUN_8003ad94();
    *(undefined1 *)(DAT_800ebb94 + 1) = 0x35;
  }
  return;
}
