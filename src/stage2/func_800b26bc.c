/* func_800b26bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b26bc  body 0x800b26bc..0x800b26f3  size 56 B
 * body sha256 4e041e97efe93e182ecf0685c3bd2cd1fe6f895407b5a3da4ba2747a657bb8b0
 * provider record sha256 eb62919ce63a0455046ed84b2a74432c1ceaaede420051190a324662c9f9dcc4
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800b26bc(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a5bc0();
    FUN_800a56c0();
  }
  return;
}
