/* FUN_80162114
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162114  body 0x80162114..0x80162143  size 48 B
 * body sha256 17babe1e28940cc8531d5a96186fb8b45a0500a395ba4e2bebea06d4b0796d91
 * provider record sha256 eaab08e1d6cfe06bff495910cbe6a5e591d027127e13a8fd0d49555547a337ff
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162114(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = func_0x80059e00(param_1,0);
  if ((uVar1 & 2) != 0) {
    _DAT_800e1134 = 0x3000000;
  }
  return;
}
