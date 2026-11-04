/* FUN_80079418
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079418  body 0x80079418..0x80079467  size 80 B
 * body sha256 53a523079ea0eee0a9ac9042ed700479da653a689991e739003ceef8d3e94722
 * provider record sha256 7bcd7618d700926befe6bd869c65449b37ebc1e96618385a6fb98d1b09ecf111
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_80079418(short param_1)

{
  undefined1 uVar1;
  
  if ((&DAT_8011a3a4)[param_1 * 0x3c] == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_800a21a8((&DAT_8011a380)[param_1 * 0xf]);
  }
  return uVar1;
}
