/* FUN_8009f724
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f724  body 0x8009f724..0x8009f797  size 116 B
 * body sha256 194ed132e2edc813732474925192a64f4d5553abbf2caef121aaa77cc0bce863
 * provider record sha256 a5a164628a2d6829208a6d202583d40e08bb6b82321eda2e01f5e9c24069863c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009f724(void)

{
  int iVar1;
  
  DAT_801344cc = 0;
  if (DAT_801344d8 == 0) {
    DAT_801344c8 = 4;
  }
  else {
    iVar1 = func_0x80180c10();
    if (iVar1 == 0) {
      if ((DAT_801344d8 & 1) == 0) {
        DAT_801344d4 = DAT_801344d4 + 1;
      }
      DAT_801344d8 = DAT_801344d8 - 1;
    }
    else {
      _DAT_8018547c = 1;
      DAT_801344d8 = 0;
    }
  }
  DAT_801344f8 = DAT_801344f8 + 1;
  return;
}
