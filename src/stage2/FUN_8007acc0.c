/* FUN_8007acc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007acc0  body 0x8007acc0..0x8007ad13  size 84 B
 * body sha256 0aefee0ced164575a487cd09044a6f5519c0f4c0c0d266bc74fef00163e20d77
 * provider record sha256 0a7755a819a61dcbc8884906a4a8fca29a9fa0d8fa7142e077c5499ee97af74c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007acc0(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
