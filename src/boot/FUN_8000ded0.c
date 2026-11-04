/* FUN_8000ded0
 * image   boot (boot), base 0x80000480
 * address 0x8000ded0  body 0x8000ded0..0x8000df03  size 52 B
 * body sha256 a09531b99b4e7097f146b82d8cc2fcad0374cce1159ffd461e3ee5db4ab0beb1
 * provider record sha256 c6fd17decb9712e9199e2a8f7510e06aa630ab5485127099fb154238fd9c3c93
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000ded0(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while( true ) {
    piVar1 = piVar2;
    if (piVar1 == (int *)0x0) {
      return;
    }
    if (piVar1 == (int *)param_2) break;
    piVar2 = (int *)*piVar1;
    param_1 = piVar1;
  }
  *param_1 = *piVar1;
  return;
}
