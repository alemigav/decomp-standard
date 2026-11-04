/* FUN_8007d4b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d4b0  body 0x8007d4b0..0x8007d607  size 344 B
 * body sha256 c81ec245cf99a1de002a8a3ede918d502a5435e364c9be365f8498dea1bab0aa
 * provider record sha256 b38278504634dd34a109f63b2b7aa89fbf78fa91700daf4315edbd3c7bc96599
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d4b0(int param_1)

{
  short sVar3;
  uint uVar1;
  uint uVar2;
  
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
LAB_8007d55c:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
      goto LAB_8007d570;
    }
  }
  else {
    if (((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) &&
       (sVar3 = *(short *)(param_1 + 0x2c0) + 1, *(short *)(param_1 + 0x2c0) = sVar3, 0x3c < sVar3))
    {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x1000;
      uVar1 = FUN_80033604();
      uVar2 = FUN_80033604();
      *(undefined2 *)(param_1 + 0x2c0) = 0xf;
      *(ushort *)(param_1 + 700) =
           *(short *)(param_1 + 0x66) -
           (((ushort)((int)(uVar1 & 0xff) >> (uVar2 & 3)) & 1) * 0x100 + -0x880);
      return;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_8007d55c;
LAB_8007d570:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) goto LAB_8007d5c0;
  }
  if (*(short *)(param_1 + 0x2c0) != 0) {
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 700),0x50);
    sVar3 = *(short *)(param_1 + 0x2c0);
    *(short *)(param_1 + 0x2c0) = sVar3 + -1;
    if (sVar3 == 1) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xefff;
      return;
    }
    return;
  }
LAB_8007d5c0:
  if (*(ushort *)(param_1 + 0x2ba) < 3000) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x38);
    FUN_8004e774(param_1);
  }
  return;
}
