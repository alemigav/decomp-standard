/* FUN_8006a6c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a6c8  body 0x8006a6c8..0x8006a75b  size 148 B
 * body sha256 f1073925a98d753396ef67ff371ab1314d6392a9d0ad9c422bae71d84a15e29a
 * provider record sha256 b9d5fac941a20eec0d6f7354b204e0dcbc6246eb64f347418a3eceb9ad00e9a3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006a6c8(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = param_6 * (param_1 - param_3);
  iVar3 = iVar1 / param_5;
  if (param_5 == 0) {
    trap(0x1c00);
  }
  if ((param_5 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  uVar2 = 0;
  if (iVar3 < param_2 - param_4) {
    uVar2 = 2;
    if (-iVar3 < param_2 - (param_4 + param_6)) {
      uVar2 = 3;
    }
  }
  else if (param_2 - (param_4 + param_6) < -iVar3) {
    uVar2 = 1;
  }
  return uVar2;
}
