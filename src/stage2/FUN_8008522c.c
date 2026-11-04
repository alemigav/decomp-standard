/* FUN_8008522c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008522c  body 0x8008522c..0x800852ff  size 212 B
 * body sha256 15d7dd1b31768e21185c530bd68bac1f72e440fdcd301db0b53d834a67d37e60
 * provider record sha256 948396844953cad975801102796ce2a980d9275fd8c00a27e87320453817fb8b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8008522c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = func_0x800072e0();
  uVar1 = DAT_8012485c;
  if (-1 < (int)DAT_8012485c) {
    DAT_8012485c = (&DAT_80124880)[DAT_8012485c * 4];
  }
  func_0x80007300(uVar2);
  (&DAT_8012486c)[(int)uVar1 >> 5] = (&DAT_8012486c)[(int)uVar1 >> 5] | 1 << (uVar1 & 0x1f);
  (&DAT_80124880)[uVar1 * 4] = param_1;
  *(undefined4 *)(&DAT_80124888 + uVar1 * 0x10) = param_2;
  (&DAT_80124884)[uVar1 * 4] = 0;
  (&DAT_8012487c)[uVar1 * 4] = uVar1 | DAT_80124858 << 8;
  DAT_80124858 = DAT_80124858 + 1;
  DAT_80124868 = DAT_80124868 + 1;
  return (&DAT_8012487c)[uVar1 * 4];
}
