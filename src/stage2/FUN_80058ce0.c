/* FUN_80058ce0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058ce0  body 0x80058ce0..0x80058e17  size 312 B
 * body sha256 41aa66e80d8f564a68378db7225d5aca035c1a30e65752cdab218fd1d3f5b570
 * provider record sha256 ece008ab4de2402d65c983cb1837a371968b638edb3550a6f5e686055c57f5dd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80058ce0(int param_1,uint param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  if (DAT_800e8b3e < 2) {
    iVar1 = (int)DAT_800df8c1;
  }
  else {
    fVar3 = (float)((int)DAT_800df8c0 * (int)DAT_800df8c0 + (int)DAT_800df8c1 * (int)DAT_800df8c1);
    fVar2 = (float)FUN_80048060(fVar3);
    iVar1 = (int)(fVar3 * fVar2);
    DAT_8010dd70 = iVar1;
  }
  if (((((param_2 & 0x10) == 0) && (iVar1 < 0x1a)) || ((DAT_800e110c & 0x2000) == 0)) &&
     (*(char *)(param_1 + 6) == '\x05')) {
    *(undefined1 *)(param_1 + 6) = 6;
    *(undefined1 *)(param_1 + 0x1e8) = 7;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    FUN_80077adc(0x2000001,param_1 + 0x28);
    FUN_80052df4();
  }
  return;
}
