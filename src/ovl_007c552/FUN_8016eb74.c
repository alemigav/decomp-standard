/* FUN_8016eb74
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016eb74  body 0x8016eb74..0x8016ebcf  size 92 B
 * body sha256 d45ab589e0ac33c6bdb31ca67e596bf073eef99eb641989d71b42a6edddb3eab
 * provider record sha256 c882b5349e381de17d651680af6439a3061913ba488ff82e9dce95a04d999172
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016eb74(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0x3b;
  do {
    func_0x800274e4(2,1);
    func_0x8004cd88(1);
    bVar1 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  func_0x80027874();
  func_0x800274e4(2,1);
  overlay_slot_reader_b(1);
  return;
}
