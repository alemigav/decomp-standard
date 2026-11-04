/* FUN_800023d8
 * image   boot (boot), base 0x80000480
 * address 0x800023d8  body 0x800023d8..0x80002b8b  size 260 B
 * body sha256 7da21b72473cbbff629b0ca2c67eb5d8d4f0b998d8f33e5d3ec8c4d626f0677b
 * provider record sha256 55b48412759c53bf4936302820935d9a38ddc0d127e5215ceea12a385d8ae52f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800023d8(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_2;
  iVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  if (**(uint **)(param_1 + 0xc) < 10) {
                    /* WARNING: Could not emulate address calculation at 0x80002468 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(uint **)(param_1 + 0xc) * 4 + -0x7ffee948))();
    return;
  }
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  iVar1 = *param_2;
  param_2[1] = iVar4;
  *param_2 = iVar3;
  param_2[2] = param_2[2] + (iVar3 - iVar1);
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  FUN_80004370(param_1,param_2,0xfffffffe);
  return;
}
