/* FUN_8006bc40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bc40  body 0x8006bc40..0x8006bccb  size 140 B
 * body sha256 b40ff52b125b870a1cff5479c31d03745b976d98b02d6e3b00aeec0e28e197e7
 * provider record sha256 bedaf65b3d57690f714ea47db07963514313fd8642d0e8c1a52903cd7c13d8c1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006bc40(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
    if (DAT_801127e0 != 0) {
      while (DAT_801127e0 != 0) {
        osRecvMesg(0x80139f90,&DAT_801127e8,1);
      }
      uVar1 = 1;
      DAT_801127e0 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
