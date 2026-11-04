/* FUN_80053994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053994  body 0x80053994..0x8005399f  size 12 B
 * body sha256 14113945b5fa3b9216f88d660a9a995256055988797d4061204e0ddf603fa2fa
 * provider record sha256 9ac66564524e10a0a05155ee7ec9922bc2201986fb5662443c73e566777be6cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80053994(uint param_1)

{
  return (param_1 & 0xff) + 0x3f;
}
