/* func_80011510
 * image   boot (boot), base 0x80000480
 * address 0x80011510  body 0x80011510..0x800115a3  size 148 B
 * body sha256 87bf093466bcba6736df73abfdb8dbf68ca73aab4496548f1b5b76b541aff924
 * provider record sha256 8b5d2f1ada5ebb456ae5837ebb4928188231bdeebc8165fb4554ff64a2669401
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_80011510(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1;
  if (DAT_80013890 != '\0') {
    iVar3 = param_1 + -0x2000;
  }
  DAT_80013890 = (param_1 + param_2 & 0x1fffU) == 0;
  iVar1 = FUN_800115b0();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    _DAT_a4500000 = FUN_8000e800(iVar3);
    uVar2 = 0;
    _DAT_a4500004 = param_2;
  }
  return uVar2;
}
