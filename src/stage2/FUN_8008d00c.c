/* FUN_8008d00c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d00c  body 0x8008d00c..0x8008d08f  size 132 B
 * body sha256 1d535fddaaadadcc3592320219ed8acfe5d39419568d5f82cf2d99c845f3d641
 * provider record sha256 889198da9801377628b67dfaaa2b0b6a371bd035bba8b6e490140a08f753bff7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008d00c(void)

{
  uint uVar1;
  
  uVar1 = FUN_8008c51c(*(&PTR_DAT_8012ffac)[(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa0 * 4] * 2]
                      );
  if (DAT_8012bfa2 == '\x11') {
    uVar1 = 0;
  }
  else {
    uVar1 = ~uVar1 >> 0x1f;
  }
  return uVar1;
}
