/* FUN_80088eec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088eec  body 0x80088eec..0x80088f1b  size 48 B
 * body sha256 a8c07db2378073a2c210c4708e2a9d8bf54517ed5310b7d065bf5fcd82dd37b8
 * provider record sha256 6d42a55fb8ead6bcd297a8d15ac5aa0162f01c0bd51932f188712e432e1ea11f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80088eec(int param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0xc4) + 7);
  *(int *)(param_1 + 0x234) = param_2;
  *(byte *)(param_1 + 0x1a3) = bVar1;
  return param_2 + (uint)bVar1 * 0x178;
}
