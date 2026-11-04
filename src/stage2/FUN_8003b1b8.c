/* FUN_8003b1b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b1b8  body 0x8003b1b8..0x8003b237  size 128 B
 * body sha256 bdbd4e2fb342bc48eedddea94d4c9baa282469641c038b5b94cc10bdef937ddb
 * provider record sha256 65219a02f9eb50d3b2442342440e9c8b27f7ddb250c01205a63928ff3087974e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b1b8(void)

{
  if (*(byte *)(DAT_800ebb94 + 2) != 0) {
    if (((*(byte *)(DAT_800ebb94 + 2) & 1) == 0) &&
       ((int)*(short *)(DAT_800ebb94 + 0x34) + (int)*(short *)(DAT_800ebb94 + 0x36) +
        (int)*(short *)(DAT_800ebb94 + 0x38) != 0)) {
      FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) + 0xb00 | 0x3090000,0,&DAT_800e9028,
                   DAT_800ebb94 + 0x34);
    }
    *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + -1;
  }
  return;
}
