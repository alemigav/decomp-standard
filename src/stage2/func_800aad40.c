/* func_800aad40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aad40  body 0x800aad40..0x800aaddb  size 156 B
 * body sha256 d916cd8461dec08106d2cacb94997684247393e75481a2fe35dea71a95deca4e
 * provider record sha256 aba7144cd1024196d3decac7b3bd8bb62a7e9ad916b00b97095d83f8cb51260a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_800aad40(int *param_1)

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
      _DAT_80148bd4 = *param_1;
    }
    else {
      *(int *)param_1[1] = *param_1;
    }
    param_1[2] = (uint)*(ushort *)((int)param_1 + 10);
    if (param_1[0xd] != -1) {
      FUN_800a8248();
    }
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
