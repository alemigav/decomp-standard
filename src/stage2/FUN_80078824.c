/* FUN_80078824
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078824  body 0x80078824..0x800788ab  size 136 B
 * body sha256 5c054ead28f930bf0f5e57538ad552c6866d5bb70fd93aa55409ce67072df9c0
 * provider record sha256 bf64c772f23f0333c4cff4e340e62d6145b7cd2697994c5b421c12a055e9a6b9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80078824(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  param_3 = param_3 - param_1;
  if (param_3 == 0) {
    uVar2 = 0x400;
    if (0 < param_4 - param_2) {
      uVar2 = 0xc00;
    }
  }
  else {
    iVar3 = (param_4 - param_2) * 0x1000;
    if (param_3 == 0) {
      trap(0x1c00);
    }
    if ((param_3 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = FUN_80040a14(iVar3 / param_3);
    iVar3 = 0;
    if (param_3 < 0) {
      iVar3 = 0x800;
    }
    uVar2 = iVar3 - iVar1 & 0xfff;
  }
  return uVar2;
}
