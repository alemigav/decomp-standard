/* FUN_8005d9c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d9c8  body 0x8005d9c8..0x8005da57  size 144 B
 * body sha256 01790bec6dcf94e9cdd3d1f712f847f4a429c91dfc7d83fe41c4c67b5029dd6b
 * provider record sha256 3fc4ab7887193140ffc73b6c4a6a2a9a028d6945ebadf3191c2afadd36ad2928
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d9c8(int param_1)

{
  DAT_800e112a = DAT_800e112a & 0xfffe;
  FUN_8005f808(param_1,0);
  FUN_8005f808(param_1,1);
  FUN_8005f808(param_1,2);
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
