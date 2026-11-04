/* FUN_80072a24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072a24  body 0x80072a24..0x80072acb  size 168 B
 * body sha256 ed3118da239515a3db218beee9c53401feb6cf78765875f7a22a3e5143d270ef
 * provider record sha256 2b844e865f20a63e319aaf2aab1bb34525c875db7a6fcdcd9390710de222b2b7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072a24(int param_1)

{
  uint uVar1;
  
  DAT_800df934 = DAT_800df934 + 7 & 0xfffffff8;
  uVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x1c) + 1);
  func_0x80004cfc((&DAT_8012bec0)[uVar1],DAT_800df934,0,&DAT_800b99cc);
  FUN_8008c8a8(uVar1,*(undefined1 *)(*(int *)(param_1 + 0x1c) + 2),DAT_800df934);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 3;
  return 1;
}
