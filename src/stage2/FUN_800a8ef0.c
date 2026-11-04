/* FUN_800a8ef0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8ef0  body 0x800a8ef0..0x800a8f9f  size 176 B
 * body sha256 81dbd5a0fa34bc717552aeff2e20f9087b681c2262e1bb87b60f4bf05e39efae
 * provider record sha256 20300c16aa9a22736791672eca2ba7a097e6ce1d4b507c2ad44bb717fc33305f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a8ef0(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  sVar1 = *param_1;
  do {
    if (sVar1 == -1) {
      return;
    }
    piVar3 = (int *)(param_2 + *(int *)(param_2 + 8));
    iVar2 = *piVar3;
    while (iVar2 != -1) {
      if (*(short *)(piVar3 + 1) == sVar1) goto LAB_800a8f60;
      piVar3 = (int *)((int)piVar3 + *piVar3);
      iVar2 = *piVar3;
    }
    piVar3 = (int *)0x0;
LAB_800a8f60:
    if (piVar3 != (int *)0x0) {
      FUN_800acbc0(*param_1,piVar3 + 2);
    }
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  } while( true );
}
