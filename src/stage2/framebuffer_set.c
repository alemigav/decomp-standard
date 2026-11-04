/* framebuffer_set
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008af6c  body 0x8008af6c..0x8008af7f  size 20 B
 * body sha256 bc43f76767ff41174d24814e461e4a3a844a14065a67a242d4e2941e1147f54c
 * provider record sha256 39648148f9d3ac9c95957e5b4a8a7ef730c4ebf06fd65d6fbef419f6a8e97fa8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void framebuffer_set(void)

{
  DAT_8012bd84 = DAT_8010b6f0;
  return;
}
