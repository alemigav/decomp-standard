/* FUN_8009f834
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f834  body 0x8009f834..0x8009f8a3  size 112 B
 * body sha256 8f7770b3577f91c9c5dbfb40164e5271010af71b7fa4fb9e9b3c7b5bfd3e05fa
 * provider record sha256 95096e355c3c70211b2e3a3a9e0a3d80e8d922f7b7c901c3f2cc8a5a1cded6b7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f834(void)

{
  if (DAT_801344f4 != 2) {
    if (DAT_801344f4 < 3) {
      if (DAT_801344f4 != 1) {
        return;
      }
      osSendMesg(&DAT_801344dc,0,0);
    }
    else if (DAT_801344f4 != 4) {
      return;
    }
  }
  DAT_801344f4 = 0;
  return;
}
