/* FUN_8004a554
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a554  body 0x8004a554..0x8004a5b3  size 96 B
 * body sha256 fd67b61b61d4b28a73bc2a61542ca5bed0d5577fc6718265aec27cb8d68cc83d
 * provider record sha256 a4ecd6b47c1a6e424f49de3bcaf203d7c7e61620b149070bff9b3ac3bda4c136
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a554(void)

{
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [16];
  
  FUN_8004a23c(*(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20,auStack_28,DAT_800e10f1,
               (int)DAT_800e10f2);
  FUN_80082d4c(auStack_24,auStack_18);
  return;
}
