/* FUN_8017b4a4
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017b4a4  body 0x8017b4a4..0x8017b557  size 180 B
 * body sha256 e23b659ba56ff9fb6101bd8c799d697111529f8715bfd5997909cd1cbb9fdb3e
 * provider record sha256 023d83256d5985c4202f3f6bebfc0969cc3f6c75691f7b73f980f06b1b91d00f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b4a4(void)

{
  FUN_8017b89c();
  do {
    DAT_8017e5d8 = &UNK_8017e9e4 + (uint)DAT_800dfbe8 * 0xe10;
    (*(code *)(&PTR_FUN_8017e530)[DAT_8017e5c9])();
    FUN_8017d468();
    if (DAT_8017e5cc == '\x01') {
      FUN_8017bf9c();
    }
    else {
      FUN_8017d5c4();
    }
    func_0x8004cd88(1);
  } while( true );
}
