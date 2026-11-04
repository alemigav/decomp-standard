/* FUN_80058f60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058f60  body 0x80058f60..0x80058f73  size 20 B
 * body sha256 bb4903f3aeeddad1b2c017626e86e0b23cf77d355e7a1cefa18af5da06283b74
 * provider record sha256 e12c5b4f86fb842b21b6001524ba4303529082828814e1f23d29e33e013f50a3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_4(void)

{
  int unaff_s0;
  
  *(undefined1 *)(unaff_s0 + 6) = 5;
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x8000700;
  if (*(char *)(unaff_s0 + 0x1e9) == '\x01') {
    FUN_80077adc(0x2040001,unaff_s0 + 0x28);
    FUN_80052bd0(2,0);
    FUN_80052c6c(3,0x96,0);
    FUN_80052d10(0x14,0x96,0,3);
  }
  FUN_80089d54();
  if (*(char *)(unaff_s0 + 8) == '\x0f') {
    *(undefined2 *)(unaff_s0 + 0x1e0) = 5;
  }
  if ((**(uint **)(unaff_s0 + 0x214) & 0x2000) == 0) {
    *(undefined2 *)(unaff_s0 + 0x1e4) = 0;
  }
  else {
    FUN_80033680();
    *(undefined2 *)(unaff_s0 + 0x1e4) = 0;
  }
  FUN_80032b5c();
  return;
}
