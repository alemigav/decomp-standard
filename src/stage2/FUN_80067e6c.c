/* FUN_80067e6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067e6c  body 0x80067e6c..0x80067edf  size 116 B
 * body sha256 3e8b2da26ef14e46e099b6d357acbd9bff3e4a169447d87d60193a2fa129d845
 * provider record sha256 9215e9ce38cec751a1cc8308c914f4151fe48a7730a2b8719e525761bd9bd251
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80067e6c(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*param_1 - (*param_3 - param_2)) * ((uint)(ushort)param_3[3] + param_2 * 2);
  iVar2 = (uint)(ushort)param_3[2] + param_2 * 2;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return param_1[2] - (param_3[1] - param_2) < iVar1 / iVar2;
}
