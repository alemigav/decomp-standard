/* FUN_8007ec60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ec60  body 0x8007ec60..0x8007ecc7  size 104 B
 * body sha256 1bdd537ea2b1b8a764edb94104de9944f9617ee2a081b990db585e4a9a64f98f
 * provider record sha256 5f276806700df0da0b9fd3ead720029f0b4b61ed81a8f8a83c0b73f7f720b346
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_6(void)

{
  undefined1 uVar1;
  int unaff_s1;
  
  if (((DAT_800e110c & 0x10000000) == 0) || (unaff_s1 != DAT_800e13ec)) {
    uVar1 = 5;
    if (*(char *)(unaff_s1 + 5) == '\x17') {
      uVar1 = 4;
    }
    *(undefined1 *)(unaff_s1 + 5) = uVar1;
  }
  else {
    *(undefined1 *)(unaff_s1 + 5) = 0;
  }
  *(undefined1 *)(unaff_s1 + 6) = 0;
  *(undefined1 *)(unaff_s1 + 7) = 0;
  return;
}
