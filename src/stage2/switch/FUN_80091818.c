/* FUN_80091818
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091818  body 0x80091818..0x80091837  size 32 B
 * body sha256 e22684a604457346eda595f8b96663d69009bde69ba32a8987883e63f8864736
 * provider record sha256 bd8359c0d2f4524c44c9c92a965fc4ceef9756e58104fbc2924b51fb9d174eee
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_2(void)

{
  undefined4 uVar1;
  uint unaff_s0;
  
  uVar1 = 5;
  if ((1 < unaff_s0) && (uVar1 = 6, unaff_s0 == 8)) {
    uVar1 = 5;
  }
  return uVar1;
}
