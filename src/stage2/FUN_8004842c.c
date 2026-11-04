/* FUN_8004842c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004842c  body 0x8004842c..0x800484db  size 176 B
 * body sha256 2a8fada0096df40a6ae3c09a7d92c0f0b34f89da141b8fba97041a1e302b6dc1
 * provider record sha256 695f645ae109072e78e4153593a6c46fbdbbc097177f3431b3ed2237b0ec43fa
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_8004842c(float param_1,float param_2)

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
    fVar1 = (float)FUN_800482e0(param_1 / param_2);
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
