/* FUN_80048390
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048390  body 0x80048390..0x8004842b  size 156 B
 * body sha256 c120cccc91af5f50c5786f22bcd39db19b0c9dc888728971abfea56407d15d4e
 * provider record sha256 f246ce17bbdf2b19437e4c9d3e154fb5881695297d844fd17d0ce8fe14f39553
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80048390(float param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(int)(param_1 * 20.0);
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
  }
  if ((int)fVar1 < 0x191) {
    fVar2 = 1.0;
    if (param_1 < 0.0) {
      fVar2 = -1.0;
    }
    fVar2 = fVar2 * *(float *)(&DAT_800f57ec + (int)fVar1 * 4);
  }
  else {
    fVar2 = (float)FUN_80048294();
  }
  return fVar2;
}
