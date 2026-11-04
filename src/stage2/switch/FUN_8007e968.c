/* FUN_8007e968
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e968  body 0x8007e968..0x8007e98b  size 36 B
 * body sha256 8ee8b94c29615091a7dd2aecfdc168792f9ae691527779ff0bd9e9b840ec0226
 * provider record sha256 a7ffb3a6b93ada8b8a143f2db460851640ce9abf9453b99d28e3bbddd61baa06
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_0(void)

{
  char cVar1;
  char cVar2;
  uint *unaff_s1;
  
  *(undefined1 *)((int)unaff_s1 + 7) = 1;
  *(undefined1 *)(unaff_s1 + 0x7a) = 7;
  *(undefined1 *)((int)unaff_s1 + 0x1ea) = 7;
  *(undefined1 *)((int)unaff_s1 + 0x1e9) = 0;
  *unaff_s1 = *unaff_s1 | 4;
  FUN_80089d54();
  if ((*(char *)(unaff_s1 + 2) == 'E') || (cVar2 = '\x0e', *(char *)(unaff_s1 + 2) == 'O')) {
    cVar1 = *(char *)((int)unaff_s1 + 0x1e9);
    cVar2 = '\x1d';
  }
  else {
    cVar1 = *(char *)((int)unaff_s1 + 0x1e9);
  }
  if (cVar1 == cVar2) {
    *(undefined1 *)((int)unaff_s1 + 7) = 2;
  }
  return;
}
