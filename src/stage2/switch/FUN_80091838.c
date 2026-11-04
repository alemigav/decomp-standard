/* FUN_80091838
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091838  body 0x80091838..0x8009189b  size 100 B
 * body sha256 caaebaa2332cb869d4b006b5b1a2749e0a5b276540662aec206a04db5b37a726
 * provider record sha256 ca8883fc7266e0cdb1ad96e59995a9ecca34b4af6bbf4da15f89396c1ef70ffa
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_3(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int unaff_s0;
  
  if ((((unaff_s0 == 0) && (3 < param_2)) || ((unaff_s0 == 1 && (3 < param_2)))) ||
     ((((unaff_s0 == 3 && (3 < param_2)) || (unaff_s0 == 0xb)) ||
      ((unaff_s0 == 2 || (uVar1 = 8, unaff_s0 == 9)))))) {
    uVar1 = 7;
  }
  return uVar1;
}
