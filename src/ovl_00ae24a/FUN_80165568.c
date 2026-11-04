/* FUN_80165568
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165568  body 0x80165568..0x801655b3  size 76 B
 * body sha256 88abfdaac3caf50567a64b34be0b63ae274fb9f104341f702e1927fae6ad3171
 * provider record sha256 2918f719a8fad18416fbc548c291599def4f73e6bb151e1d09965ac667c22c9f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165568(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_8016731c,param_2);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167388,uVar1);
  return;
}
