/* FUN_8016ecb8
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016ecb8  body 0x8016ecb8..0x8016edb3  size 252 B
 * body sha256 45eb5540c3c32a1d08178b021c254813c50191cc8ced2cdd65a2195e056a0460
 * provider record sha256 19bf45167c18451440bd78b252a9e5c63783734bd0523fa7f1952e3e69348aaa
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016ecb8(void)

{
  ushort uVar1;
  
  if ((DAT_80171df4 & 2) == 0) {
    func_0x800274f8(0x200,0x100,7,1);
    DAT_80171dd9 = 2;
    DAT_80171df4 = DAT_80171df4 | 2;
  }
  else if ((_DAT_800e9184 < 0) || (_DAT_800e9184 == 0x7fff)) {
    uVar1 = DAT_80171df4 ^ 2;
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) {
        DAT_80171dd9 = 0;
        DAT_80171df4 = uVar1;
      }
      else {
        DAT_80171dd9 = 1;
        DAT_80171df4 = DAT_80171df4 ^ 10;
      }
    }
    else {
      DAT_80171dd9 = 3;
      DAT_80171df4 = DAT_80171df4 ^ 6;
    }
    if ((DAT_80171df4 & 0x2000) != 0) {
      DAT_80171df4 = DAT_80171df4 ^ 0x2000;
      FUN_801700ac(0xffffffff,0,1);
    }
    func_0x800274e4(2,1);
  }
  return;
}
