/* FUN_80166338
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166338  body 0x80166338..0x8016636f  size 56 B
 * body sha256 1b0122f36dc6bca568104f243fbfa5b22255b4086cae2d5dc334e1e02e1c0652
 * provider record sha256 c95827deb5776ce57f1a44f1084cec01a523d7f5d489d16470dce0b1da70f087
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166338(uint *param_1)

{
  if (*(char *)((int)param_1 + 5) == '\0') {
    *(undefined1 *)((int)param_1 + 5) = 1;
    *param_1 = *param_1 | 2;
  }
  FUN_80166370();
  return;
}
