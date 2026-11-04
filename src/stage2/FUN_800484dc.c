/* FUN_800484dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800484dc  body 0x800484dc..0x8004858b  size 176 B
 * body sha256 18a205b32f756de63ca8361a7a7cc45324b774cf44a0744ca9dd26e05ef80246
 * provider record sha256 16a0b3a719e45793c5cee3ac4c30a7eaca97fea994f09799cfa82667047f1cf2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_800484dc(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (param_1 == 0.0) {
    fVar1 = 0.0;
    if (param_2 <= 0.0) {
      fVar1 = 3.1415927;
    }
  }
  else {
    fVar1 = (float)FUN_80048390(param_1 / param_2);
    if (param_2 < fVar2) {
      if (param_1 < fVar2) {
        fVar1 = fVar1 - 3.1415927;
      }
      else {
        fVar1 = fVar1 + 3.1415927;
      }
    }
  }
  return fVar1;
}
