/* FUN_8017f3bc
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f3bc  body 0x8017f3bc..0x8017f42f  size 116 B
 * body sha256 56c0c43f5089cf3acd34ecb5db2a2d1e96fd4177e483dd3f7e345261de58f45c
 * provider record sha256 54c067c6e16116cd32e420171c095a4a39baf2812ef9c320a088fc33bc4ef349
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017f3bc(void)

{
  short sVar3;
  uint uVar1;
  uint uVar2;
  
  sVar3 = FUN_8017b4c8(7);
  func_0x8004c21c((int)sVar3,0xc0,&DAT_80180458,0x4002);
  func_0x8004cd88(2);
  uVar1 = FUN_8017fdbc(0);
  uVar2 = FUN_8017fdbc(1);
  return uVar1 & 1 | (uVar2 & 1) << 1;
}
