/* FUN_80000f08
 * image   boot (boot), base 0x80000480
 * address 0x80000f08  body 0x80000f08..0x80000f4f  size 72 B
 * body sha256 b4041dd3fbfe3d38b6d05293b7247e8d2c813c5110070b0a1252a52402558348
 * provider record sha256 fd241059f9847db075c3adcf779465bfced17a5a5439b9bc8ec6a2d956a83bd6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80000f08(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = ((int *)*param_1)[1];
  piVar4 = (int *)*param_1;
  piVar2 = param_1;
  while (piVar1 = piVar4, param_2[1] <= iVar3) {
    piVar4 = (int *)*piVar1;
    iVar3 = piVar4[1];
    piVar2 = piVar1;
  }
  *param_2 = *piVar2;
  *piVar2 = (int)param_2;
  param_2[2] = (int)param_1;
  return;
}
