/* FUN_80072978
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072978  body 0x80072978..0x80072a23  size 172 B
 * body sha256 42d361b77ee2bc172fbbc915fd6d0e4b7092135a4bedd249d6770315d57e886a
 * provider record sha256 f05bb3381e636538db567357350fb4b8a473863a0438c3da2f247c4fa44fb361
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072978(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x1c) + 1);
  DAT_800e12da = DAT_800e12da & 0xf000 | (ushort)bVar1;
  if (bVar1 == 0) {
    DAT_8012bfa0 = 0x80;
    DAT_8012bfa2 = 0;
  }
  else {
    DAT_8012bfa0 = FUN_8008c51c(bVar1);
    DAT_8012bfa2 = bVar1;
  }
  FUN_8005aaf8(&DAT_800e1130);
  FUN_8005a3d0(&DAT_800e1130);
  FUN_80026a88();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
