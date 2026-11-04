/* FUN_80162ac8
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162ac8  body 0x80162ac8..0x80162b87  size 192 B
 * body sha256 cd8e109b87ca6104a278f23c4edad41ebab97cec3309ae9515df76e208ffc5b9
 * provider record sha256 1f317714d5bab5fb629e57ac184174fc6623af5d6d9204185fcbea2988956ffc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162ac8(int param_1,short param_2,short param_3,int param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)param_2,(int)param_3);
  uVar3 = iVar1 + 0x800U & 0xfff;
  if (((int)(short)param_4 & 0x8000U) != 0) {
    param_4 = -(int)(short)param_4;
    uVar3 = uVar3 + 0x800 & 0xfff;
  }
  uVar4 = param_4 + (uVar3 - *(ushort *)(param_1 + 0x66)) & 0xfff;
  if ((int)uVar4 < (param_4 << 0x10) >> 0xf) {
    *(short *)(param_1 + 0x66) = (short)uVar3;
  }
  else {
    sVar2 = *(ushort *)(param_1 + 0x66) - (short)param_4;
    *(short *)(param_1 + 0x66) = sVar2;
    if (uVar4 < 0x801) {
      *(short *)(param_1 + 0x66) = sVar2 + (short)param_4 * 2;
    }
  }
  return;
}
