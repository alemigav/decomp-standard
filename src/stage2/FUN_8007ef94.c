/* FUN_8007ef94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ef94  body 0x8007ef94..0x8007efe7  size 84 B
 * body sha256 03fa35c86110d838260944f373db4b2f8fd924fe465baa1acf53f974cc2235d9
 * provider record sha256 266ee2c131e59288a41a2630006c43cd46a3102e69da5e15a7a1bce75c7d4faa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ef94(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),0xa0);
  }
  return;
}
