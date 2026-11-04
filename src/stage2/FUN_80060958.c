/* FUN_80060958
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80060958  body 0x80060958..0x800609df  size 136 B
 * body sha256 197e6e90f9a4d9f6b94194738774a0d0b42d7c4d85745261145094c8ded24204
 * provider record sha256 7ad6333d3954259beba79f0dcff59ee30997d2f16f1c3e682941465cf31d16e6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80060958(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0x400;
  if (0 < param_2) {
    uVar3 = 0xc00;
  }
  if (param_1 != 0) {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if ((param_1 == -1) && (param_2 << 0xc == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = FUN_80040a14((param_2 << 0xc) / param_1);
    iVar2 = 0;
    if (param_1 < 0) {
      iVar2 = 0x800;
    }
    uVar3 = iVar2 - iVar1 & 0xfff;
  }
  return uVar3;
}
