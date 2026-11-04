/* FUN_800917f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800917f4  body 0x800917f4..0x80091817  size 36 B
 * body sha256 4e4044e5b3170c3d110c72006f342ca1c4af192f73dd7cb43b1ac3e696914d96
 * provider record sha256 a6abb54aa0e1e521dc9071ab52b972b12cd105b4a54ecb842e8763e5b886ca86
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_1(void)

{
  undefined4 uVar1;
  uint unaff_s0;
  
  if (unaff_s0 == 0x1b) {
    uVar1 = 3;
  }
  else {
    uVar1 = 5;
    if (unaff_s0 < 0x11) {
      uVar1 = 2;
    }
  }
  return uVar1;
}
