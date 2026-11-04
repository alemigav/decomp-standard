/* FUN_800919a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800919a8  body 0x800919a8..0x80091a37  size 144 B
 * body sha256 58d8d916205d0b349cc9d24845f637829cad6ed78d72470a7ec65737173d1d50
 * provider record sha256 6a1b81c449710bc91c03b8f420d946b43f1f9dc795550e17dbd2823ece6ad850
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_5(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint unaff_s0;
  
  if (unaff_s0 == 1) {
    uVar1 = 0xd;
    if (DAT_800e8cae != 0x602) {
      uVar1 = 0x10;
    }
  }
  else if ((unaff_s0 != 3) || (uVar1 = 0xe, 2 < param_2)) {
    if ((unaff_s0 != 0xe) || (DAT_8012f528 != '\x01')) {
      if (unaff_s0 < 5) {
        return 0xd;
      }
      if (unaff_s0 == 5) {
        return 0xf;
      }
      if (unaff_s0 < 0x12) {
        return 0x10;
      }
    }
    uVar1 = 0x11;
  }
  return uVar1;
}
