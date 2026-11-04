/* FUN_8003da98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003da98  body 0x8003da98..0x8003dadb  size 68 B
 * body sha256 9d377df65a6853fcc41b54805805facfeb7c404b3a19dd917ff3760589788e91
 * provider record sha256 16dd26a1929647406f2ba404e3bb64d1ffbee7a364925e81d216dad328421a3b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003da98(void)

{
  ushort uVar1;
  
  FUN_80039c34();
  *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
  uVar1 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0x42) = (uVar1 & 3) + 10;
  return;
}
