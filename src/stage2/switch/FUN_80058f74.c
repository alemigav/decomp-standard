/* FUN_80058f74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058f74  body 0x80058f74..0x8005903f  size 204 B
 * body sha256 c9184e0fdff292939a1c0f0567bdb89a4958a463a4373ec3359e371a34339e4a
 * provider record sha256 968bbd3912f967cecc3db8d5fae5c8341507c0c414f9559aa02852e36057360b
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_5(void)

{
  int unaff_s0;
  
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
