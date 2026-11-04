/* FUN_8006e9d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e9d4  body 0x8006e9d4..0x8006e9db  size 8 B
 * body sha256 c028438457c6ee4e6e0fb199339eb60f2868b3060ec8a329ba83a91827ba3f0b
 * provider record sha256 915e5591fdbd5bed79b7adfc2d3639ac684bef854e5ecc2c3a75cf795131ac15
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_1(int param_1)

{
  undefined2 uVar1;
  int unaff_s0;
  undefined2 *unaff_s1;
  
  uVar1 = FUN_800844cc((param_1 - unaff_s0) * 0x10000 >> 0x10);
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
