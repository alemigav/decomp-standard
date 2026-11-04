/* FUN_8007aa2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007aa2c  body 0x8007aa2c..0x8007aaa7  size 124 B
 * body sha256 bbc85d2619d23070c7436ab96b51db382c63875bb386391758c21fe66fd48858
 * provider record sha256 2e4172990a22cce507fe97813a015a6d82cf74139d5f0a7e9d8fc423483df4ee
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007aa2c(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
  }
  return;
}
