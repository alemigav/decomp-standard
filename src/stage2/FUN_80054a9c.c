/* FUN_80054a9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054a9c  body 0x80054a9c..0x80054b67  size 204 B
 * body sha256 8c3f3846e54c05724ca4520d5ef1bf411a886dc2e1f74274290041bf60480904
 * provider record sha256 ceb9a27f4f5acabe929dcb03fccab915e9bfcf8e636e03ee63bc038eacada127
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054a9c(void)

{
  int iVar1;
  uint unaff_s3;
  
  iVar1 = DAT_800df934;
  DAT_8010d940 = DAT_800df934;
  DAT_800df934 = DAT_800df934 + 0x5320;
  if ((DAT_800e110c & 0x200) == 0) {
    FUN_80054f98(DAT_800e10f0 >> 4,1);
  }
  else {
    FUN_80054f98(DAT_800e10f0 >> 4,0);
    FUN_800539a0(0,"Register your fingerprint.]",&DAT_8010da24);
  }
  DAT_8010da24 = 0;
  DAT_8010da20 = 0;
  if ((DAT_800e110c & 0x200) == 0) {
    DAT_800e8609 = 1;
    FUN_800539a0(1,"UMBRELLA \"RODEM\" SYSTEM]                      Ver 5.0]",&DAT_8010da24);
    if (DAT_8010da24 != 0) {
      DAT_800e8609 = 2;
    }
  }
  else {
    DAT_800e8609 = 8;
  }
  if (*(char *)(iVar1 + 0x2d9) == '\x01') {
    *(undefined1 *)(iVar1 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da20 & DAT_8010da24) != 0) || (unaff_s3 != DAT_800e8609)) {
    DAT_80139bef = 0;
    DAT_8010da24 = 0;
    DAT_8010da20 = 0;
    DAT_80139bee = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
