/* FUN_80032e74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032e74  body 0x80032e74..0x80032ef3  size 128 B
 * body sha256 586711a6474f90790cf81eb86578bb8b10efc9808e305029a54778c8a2d897af
 * provider record sha256 1240aff29f57ad6b7674753e94869cef2847e260a4479813c08888dac3ea1df2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80032e74(int param_1,short param_2,short param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),(int)param_2,
                       (int)param_3);
  uVar2 = param_4 + (iVar1 - (uint)*(ushort *)(param_1 + 0x66)) & 0xfff;
  iVar3 = (int)(short)param_4;
  iVar1 = 0;
  if ((iVar3 << 1 <= (int)uVar2) && (iVar1 = iVar3, 0x800 < uVar2)) {
    iVar1 = -iVar3;
  }
  return iVar1;
}
