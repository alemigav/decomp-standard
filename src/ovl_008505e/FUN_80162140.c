/* FUN_80162140
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162140  body 0x80162140..0x8016219f  size 96 B
 * body sha256 464bcfd22513c5c87f3347c1dd1aa575c22ef1be74f361d4be8f9aadd8070c82
 * provider record sha256 946a2fd53f1955ee7749870a96616ebdb37f627d97bfb65b256c2a79e1d1fb17
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162140(int param_1)

{
  (*(code *)(&PTR_FUN_80166d34)[*(byte *)(param_1 + 5)])();
  if ((**(uint **)(param_1 + 0x214) & 0x40000) != 0) {
    func_0x80077d18(8,param_1);
  }
  return;
}
