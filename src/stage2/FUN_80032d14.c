/* FUN_80032d14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032d14  body 0x80032d14..0x80032dbb  size 168 B
 * body sha256 8bc72564269e54718d96e71895d73533ba5433badf6306c82279dc98d691cbcd
 * provider record sha256 f216fba10bd5bdfbb028fce1e32f1948ff898ad02a8ec9f7c50336232902b0d4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80032d14(short param_1,short param_2,short param_3,short param_4)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0x400;
  iVar4 = (int)param_3 - (int)param_1;
  if (0 < (int)param_4 - (int)param_2) {
    uVar1 = 0xc00;
  }
  iVar3 = ((int)param_4 - (int)param_2) * 0x1000;
  if (iVar4 != 0) {
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    sVar2 = FUN_80040a14(iVar3 / iVar4);
    iVar3 = 0;
    if (iVar4 < 0) {
      iVar3 = 0x800;
    }
    uVar1 = iVar3 - sVar2 & 0xfff;
  }
  return uVar1;
}
