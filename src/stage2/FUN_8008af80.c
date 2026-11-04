/* FUN_8008af80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008af80  body 0x8008af80..0x8008b027  size 168 B
 * body sha256 7115dea087eee46f30386844e1f22f080013923c4c3a0eb029f5535670aea7f3
 * provider record sha256 a344c5638cc6a1f7958e5191b454b2193d84e1676785ac33c679ed52cf90d43b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008af80(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = func_0x800072e0();
  DAT_8012bd84 = DAT_8012bd84 - param_1;
  if (DAT_8012bd80 == 2) {
    uVar2 = 0xfffffff8;
  }
  else if (DAT_8012bd80 < 3) {
    if (DAT_8012bd80 != 1) goto LAB_8008b008;
    uVar2 = 0xfffffffc;
  }
  else {
    if (DAT_8012bd80 != 3) goto LAB_8008b008;
    uVar2 = 0xfffffff1;
  }
  DAT_8012bd84 = DAT_8012bd84 & uVar2;
LAB_8008b008:
  uVar2 = DAT_8012bd84;
  func_0x80007300(uVar1);
  return uVar2;
}
