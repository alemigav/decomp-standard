/* FUN_8017bb98
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017bb98  body 0x8017bb98..0x8017bc1b  size 132 B
 * body sha256 60fab3215c4ac1caf9fc3e9da424c46f5abb297ce50af64818d9f4bcf79f59b6
 * provider record sha256 8f07dfbe1cccc5559e6f093699088acf938242a02588a2326c9fd11e577d3a11
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017bb98(void)

{
  if ((DAT_8017e5bf & 0xc) == 0) {
    if ((_DAT_800df90e & 0x100) == 0) {
      (*(code *)(&PTR_FUN_8017e548)[DAT_8017e5cc])(0x4050000);
    }
    else {
      func_0x80077adc(0x4050000,0);
      DAT_8017e5c9 = 2;
    }
  }
  return;
}
