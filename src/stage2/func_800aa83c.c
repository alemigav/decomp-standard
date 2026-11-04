/* func_800aa83c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa83c  body 0x800aa83c..0x800aa8b7  size 124 B
 * body sha256 aca05b48490a26fc00399650c44a13a13802839e0b14e93dc1c9b3cfc71c56d7
 * provider record sha256 63afa14deca300460e9eed0f9c34627ef6d3b063a2989a9e6bc5a019cffe45ea
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_800aa83c(int *param_1)

{
  undefined4 uVar1;
  
  if (DAT_80136310 == '\0') {
    uVar1 = 0;
  }
  else {
    FUN_800a5678();
    if (*param_1 != 0) {
      *(int *)(*param_1 + 4) = param_1[1];
    }
    if ((int *)param_1[1] == (int *)0x0) {
      _DAT_80148bd8 = *param_1;
    }
    else {
      *(int *)param_1[1] = *param_1;
    }
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
