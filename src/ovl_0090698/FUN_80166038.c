/* FUN_80166038
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166038  body 0x80166038..0x801660b7  size 128 B
 * body sha256 5659bba6ec6c2edce15d69a774c5bd26b6ed2e13062eec5f9e70f4e2bb30e3c1
 * provider record sha256 8ca2f048999fc53709070ed1f8ab0a9d1a2314b3a35238c0deaadefe6a1f4799
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166038(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_8016703c(param_1,0x13,1);
    FUN_80166248(param_1);
    uVar1 = func_0x80033604();
    FUN_80167688(param_1,0x2004,(uVar1 & 3) + 6);
  }
  FUN_801658fc(param_1,param_2,param_3);
  return;
}
