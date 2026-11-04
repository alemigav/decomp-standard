/* FUN_800a8e40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8e40  body 0x800a8e40..0x800a8eef  size 176 B
 * body sha256 0c3f6fe6175002d5d04a0f6087c6edf89b9814cabf60685d2390ba6b5f035e22
 * provider record sha256 442b5c279d75839458afc8b41bcb7b7af012b5bbc91a071a8ec86f9cf0139e56
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a8e40(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  sVar1 = *param_1;
  do {
    if (sVar1 == -1) {
      return;
    }
    piVar3 = (int *)(param_2 + *(int *)(param_2 + 4));
    iVar2 = *piVar3;
    while (iVar2 != -1) {
      if (*(short *)(piVar3 + 1) == sVar1) goto LAB_800a8eb0;
      piVar3 = (int *)((int)piVar3 + *piVar3);
      iVar2 = *piVar3;
    }
    piVar3 = (int *)0x0;
LAB_800a8eb0:
    if (piVar3 != (int *)0x0) {
      FUN_800ad0c0(*param_1,piVar3 + 2);
    }
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  } while( true );
}
