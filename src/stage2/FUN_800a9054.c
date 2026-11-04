/* FUN_800a9054
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9054  body 0x800a9054..0x800a90cf  size 124 B
 * body sha256 d587c7fb25d92e37af2c741416025ba366ccb4b2029fcd07c810fa204954242b
 * provider record sha256 233c8dc7d2a2ba2d97f74edb4a63ca7f42274a75aca9aecfb18f01f93b708052
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9054(short *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  char cVar3;
  
  uVar2 = FUN_800a5c98(param_2);
  cVar3 = FUN_800ad330(param_3,uVar2);
  if (cVar3 != '\0') {
    sVar1 = *param_1;
    while (sVar1 != -1) {
      sVar1 = *param_1;
      param_1 = param_1 + 1;
      FUN_800add28(sVar1,param_3);
      sVar1 = *param_1;
    }
  }
  return;
}
