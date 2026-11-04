/* FUN_8006e9dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e9dc  body 0x8006e9dc..0x8006e9f3  size 24 B
 * body sha256 ff1f3c0c7653ced3c068748c72da74934307931f953733e53d6c7a3502e9a916
 * provider record sha256 e5264a2582a4b27a8421c696be6da3185835fbcea966074f2e1a7a38fc0b5f68
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_2(short param_1)

{
  undefined2 uVar1;
  int unaff_s0;
  undefined2 *unaff_s1;
  
  uVar1 = FUN_800844cc(param_1 * unaff_s0 * 0x10000 >> 0x10);
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
