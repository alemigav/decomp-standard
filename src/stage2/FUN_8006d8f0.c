/* FUN_8006d8f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d8f0  body 0x8006d8f0..0x8006d997  size 168 B
 * body sha256 5c895d61e3b43bb2864d593d1b9fde9947494671e01f32cba7d678840f9df2ca
 * provider record sha256 8b866065baf9871b9b4fc4d02aa8db485a5c316e0bdbcd5fdaf75fa7d2eacb91
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d8f0(void)

{
  FUN_8006d284();
  FUN_8006d334();
  FUN_8006d458();
  DAT_80114f34 = 0;
  DAT_80114f2c = *(undefined4 *)(DAT_800df92c + 0x48);
  FUN_8006d628(0,0);
  DAT_80114f2c = *(undefined4 *)(DAT_800df92c + 0x4c);
  FUN_8006d628(1,0);
  FUN_8006da14();
  FUN_8006d120();
  FUN_8006d718();
  FUN_8006d7a4();
  FUN_8006d7ac();
  return;
}
