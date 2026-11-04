/* FUN_80076b70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80076b70  body 0x80076b70..0x80076c83  size 276 B
 * body sha256 ee6726687c8fb035710e71f30aa3a7ab031192624a4c5b9e5ad4b04e1a409e10
 * provider record sha256 76c9811dcc1b85e3882d147e81089bb995a3f97bae387570efa65adcd4bcfda9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80076b70(void)

{
  if ((DAT_800e10ec & 0x2000) == 0) {
    if (((DAT_80119ee5 != -1) && (DAT_80119ee5 == '\0')) && (-1 < DAT_80119ee6)) {
      FUN_80078fc0();
      DAT_80119ee4 = 1;
    }
    if (((DAT_80119eed != -1) && (DAT_80119eed == '\0')) && (-1 < DAT_80119eee)) {
      FUN_80078fc0();
      DAT_80119eec = 1;
    }
    if (((DAT_80119ef5 != -1) && (DAT_80119ef5 == '\0')) && (-1 < DAT_80119ef6)) {
      FUN_80078fc0();
      DAT_80119ef4 = 1;
    }
  }
  return;
}
