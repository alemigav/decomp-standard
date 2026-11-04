/* FUN_800a3094
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a3094  body 0x800a3094..0x800a3263  size 464 B
 * body sha256 d61eaa9d930bd41f4ed3685b00c488f2877206232d2a55338f1106dd38d2fec6
 * provider record sha256 7dbfd95ba7e709f6d85770716124b2c74f178f35da7d56a0244447406e9536f7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a3094(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar3 = 0.000244140625;
  dVar6 = (double)(int)((uint)*(ushort *)(param_1 + 4) * (param_2 & 0xffff)) * 0.000244140625;
  if ((*(int *)(param_1 + 0x38) != 0) &&
     ((*(char *)(param_1 + 1) != '\0' || (*(int *)(param_1 + 0x3c) == 0)))) {
    iVar1 = *(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x38);
    dVar5 = (double)iVar1;
    if (iVar1 < 0) {
      dVar3 = 4294967296.0;
      dVar5 = dVar5 + 4294967296.0;
    }
    FUN_800a6258(*(undefined8 *)(param_1 + 8));
    if (dVar3 <= dVar5) {
      iVar2 = *(int *)(param_1 + 0x38);
      iVar1 = *(int *)(param_1 + 0x34) + iVar2;
      dVar3 = (double)iVar1;
      if (iVar1 < 0) {
        dVar3 = dVar3 + 4294967296.0;
      }
      dVar5 = *(double *)(param_1 + 8) + dVar6;
      if (dVar3 <= dVar5) {
        dVar3 = dVar3 - *(double *)(param_1 + 8);
        dVar5 = (double)iVar2;
        dVar6 = dVar6 - dVar3;
        if (iVar2 < 0) {
          dVar3 = 4294967296.0;
          dVar5 = dVar5 + 4294967296.0;
        }
        FUN_800a6258(dVar6 / dVar5);
        dVar5 = (double)*(int *)(param_1 + 0x38);
        if (*(int *)(param_1 + 0x38) < 0) {
          dVar5 = dVar5 + 4294967296.0;
        }
        dVar4 = (double)*(int *)(param_1 + 0x34);
        if (*(int *)(param_1 + 0x34) < 0) {
          dVar4 = dVar4 + 4294967296.0;
        }
        *(double *)(param_1 + 8) = dVar4 + (dVar6 - dVar3 * dVar5);
        return;
      }
      *(double *)(param_1 + 8) = dVar5;
      return;
    }
  }
  iVar1 = *(int *)(param_1 + 0x30);
  dVar3 = (double)iVar1;
  dVar6 = *(double *)(param_1 + 8) + dVar6;
  if (iVar1 < 0) {
    dVar3 = dVar3 + 4294967296.0;
  }
  if ((dVar3 <= dVar6) && (dVar6 = (double)(iVar1 + -1), iVar1 + -1 < 0)) {
    dVar6 = dVar6 + 4294967296.0;
  }
  *(double *)(param_1 + 8) = dVar6;
  return;
}
