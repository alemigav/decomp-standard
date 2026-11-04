/* FUN_800af130
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af130  body 0x800af130..0x800af1ab  size 124 B
 * body sha256 da26b9616c5ddbd9d64296f6a04e00f74498da7aef0fd04d4a819a7256045c49
 * provider record sha256 4b031376c18e66ab1873667c737bec92ba0dd2f0e8d60afb2f10b174ed0cdd70
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800af130(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (param_1 != -1) {
    cVar1 = FUN_800a5890();
    if (cVar1 != '\0') {
      FUN_800a5acc(param_1);
    }
    iVar2 = param_1 * 0x1a0;
    *(int *)(&DAT_801444a8 + iVar2) = param_1;
    FUN_800aebfc(&DAT_80144448 + iVar2);
    (&DAT_80144505)[iVar2] = 0;
  }
  return;
}
