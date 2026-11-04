/* FUN_800a5794
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5794  body 0x800a5794..0x800a57db  size 72 B
 * body sha256 daf62f988e110544dc7d5f143374b5d49c7006b794da805e92ac44bc14276363
 * provider record sha256 f6e9bb2fd56b9f5909a88ed8ed46369d0b171a4c1822ccc5c2486f9ce5d101b9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5794(void)

{
  osCreateMesgQueue(0x80143fb0,0x80143fc8,1);
  osSendMesg(0x80143fb0,0,0);
  return;
}
