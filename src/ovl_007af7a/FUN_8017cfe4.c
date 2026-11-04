/* FUN_8017cfe4
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017cfe4  body 0x8017cfe4..0x8017d07b  size 152 B
 * body sha256 24601eba43ed47e27468d79162c7670a683f5483f392bb55785937f1a82216f8
 * provider record sha256 ecef944ad56aca2c48ae583800b6d722410435e38dc4c5e7ca6a7f9dbb79713d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017cfe4(void)

{
  undefined4 uVar1;
  
  if ((_DAT_800df918 & 0x3000) != 0) {
    DAT_8017e5c9 = 2;
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    DAT_8017e5cd = 0;
    DAT_8017e5bf = DAT_8017e5bf | 8;
    uVar1 = 0x4050000;
    if ((_DAT_800df918 & 0x1000) != 0) {
      uVar1 = 0x4060000;
    }
    func_0x80077adc(uVar1,0);
  }
  return;
}
