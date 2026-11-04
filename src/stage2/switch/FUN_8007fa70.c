/* FUN_8007fa70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fa70  body 0x8007fa70..0x8007fac3  size 84 B
 * body sha256 3ffcdf1623d3622eea882eaa5f7be028fbead4054d701287e9d7ad3e7d871ca0
 * provider record sha256 d8ad4e732cece9a95f98d68ba7a3c70e2ccb1f0263e8fa818ba37ef515ad900f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_2(void)

{
  int iVar1;
  int unaff_s0;
  
  iVar1 = FUN_80032e74();
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x9000700;
  if (iVar1 << 0x10 < 0) {
    *(undefined4 *)(unaff_s0 + 0x1e8) = 0xb000700;
  }
  *(undefined1 *)(unaff_s0 + 6) = 3;
  *(undefined1 *)(unaff_s0 + 0x207) = 0;
  iVar1 = FUN_80089d54();
  if ((iVar1 != 0) && (*(char *)(unaff_s0 + 0x207) == '\0')) {
    *(undefined1 *)(unaff_s0 + 0x207) = 1;
    *(char *)(unaff_s0 + 0x1e8) = *(char *)(unaff_s0 + 0x1e8) + '\x01';
  }
  return;
}
