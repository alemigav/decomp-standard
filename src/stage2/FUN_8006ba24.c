/* FUN_8006ba24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ba24  body 0x8006ba24..0x8006baf3  size 208 B
 * body sha256 506edb027fd70ef8c47a0cb5ef42f9b07d13a04238c6a06400b83af67bf19e1f
 * provider record sha256 50a6398e479008268e078079a0d254d5944705abc645dcf6c7c695658c91711c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006ba24(void)

{
  osRecvMesg(&DAT_80112a24,0,1);
  if (DAT_8011296c == '\0') {
    DAT_801137d4 = 0;
    FUN_8006b3dc(4,0,1);
    DAT_80112781 = 4;
    DAT_8011296c = 1;
    if (DAT_801127d8 != (code *)0x0) {
      (*DAT_801127d8)();
    }
    DAT_8011296c = '\x04';
    if (DAT_801137d4 == 0) {
      DAT_8011296c = '\b';
    }
    DAT_80112781 = 10;
    FUN_8006b6b4();
    FUN_8006b8a0();
    FUN_8006b3dc(4,0,2);
  }
  return;
}
