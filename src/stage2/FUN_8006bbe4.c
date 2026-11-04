/* FUN_8006bbe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bbe4  body 0x8006bbe4..0x8006bc3f  size 92 B
 * body sha256 4909888b5b38b198aca6b426852d897b64baebe3fe1d8cb7465075a6a2f2cc3b
 * provider record sha256 1404e6c0da7c219b9ce6350e64d81a354fdcb07b03f64a8b428cc9690a2c5f5d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bbe4(void)

{
  while (DAT_801127e0 != 0) {
    osRecvMesg(0x80139f70,&DAT_801127e4,1);
  }
  return;
}
