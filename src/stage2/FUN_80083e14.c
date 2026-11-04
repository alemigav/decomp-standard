/* FUN_80083e14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083e14  body 0x80083e14..0x80083e5f  size 76 B
 * body sha256 584ab00df8d89062f39d1bc50e26375f2d567b170e5950e10c0be88fb1d5d6b9
 * provider record sha256 b4b1fe1ce60d239f1c66db233e64e65a9637d8c158fdcad7a94a38334e8b2347
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80083e14(int *param_1,short *param_2)

{
  if (((uint)(ushort)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(ushort)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}
