/* FUN_80162678
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162678  body 0x80162678..0x801626ab  size 52 B
 * body sha256 ba58151553fb5fed06ee9da65c89cbc3d74daeaab68ebc274eb126bd1b6ed180
 * provider record sha256 ff64a4a3dfe40fad38b65d1417790aa984e58dd7e0f9156ebc6ac0cd6b18927c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162678(int param_1)

{
  if (*(short *)(param_1 + 0x2d4) == -0x8000) {
    if (*(char *)(param_1 + 0x2d9) == '\0') {
      *(undefined4 *)(param_1 + 4) = 0x30a0000;
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  }
  return;
}
