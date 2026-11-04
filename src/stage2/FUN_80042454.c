/* FUN_80042454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042454  body 0x80042454..0x8004249b  size 72 B
 * body sha256 f3bedd1809d75e2b8c05272e7cbf72eaa55065a92a1b8e6b025815448eb5a105
 * provider record sha256 473b3683907edbbfed30fe42f9cb70a4c29138470858c07a6b3f3bdf4acf2f8c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80042454(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  return param_2;
}
