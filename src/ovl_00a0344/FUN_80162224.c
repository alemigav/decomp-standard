/* FUN_80162224
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162224  body 0x80162224..0x80162297  size 116 B
 * body sha256 bf1a9b78371e4aa1af694fd9f519dc5c784416089c4ae588b7f38c1a0a8675f1
 * provider record sha256 3e4dcd9f422c28b71f6c47c02501bc4d505bd94ac75112e2ce8a1c8262b9be4a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162224(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  uVar1 = func_0x80033604();
  *(ushort *)(param_1 + 500) = (ushort)*(byte *)(param_1 + 0x2b4) * 2 + (uVar1 & 3) + 1;
  func_0x80089d54(param_1,param_2,param_3,0x200);
  return;
}
