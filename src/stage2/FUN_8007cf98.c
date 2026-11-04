/* FUN_8007cf98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007cf98  body 0x8007cf98..0x8007d153  size 444 B
 * body sha256 4330a8f6a16e55b930d7f9cb4180d07e95e7d168750884f30987c524f2c74f37
 * provider record sha256 33951ed25aebfabb519b7e67e8004c8051437b1b02f4779a0f21f110b15be1b2
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007cf98(int param_1)

{
  ushort uVar1;
  short sVar4;
  uint uVar2;
  uint uVar3;
  char cVar5;
  
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
LAB_8007d044:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
      goto LAB_8007d058;
    }
  }
  else {
    if (((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) &&
       (sVar4 = *(short *)(param_1 + 0x2c0) + 1, *(short *)(param_1 + 0x2c0) = sVar4, 0x3c < sVar4))
    {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x1000;
      uVar2 = FUN_80033604();
      uVar3 = FUN_80033604();
      *(undefined2 *)(param_1 + 0x2c0) = 0x1e;
      *(ushort *)(param_1 + 700) =
           *(short *)(param_1 + 0x66) -
           (((ushort)((int)(uVar2 & 0xff) >> (uVar3 & 3)) & 1) * 0x100 + -0x880);
      return;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_8007d044;
LAB_8007d058:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) goto LAB_8007d0a8;
  }
  if (*(short *)(param_1 + 0x2c0) != 0) {
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 700),0x28);
    sVar4 = *(short *)(param_1 + 0x2c0);
    *(short *)(param_1 + 0x2c0) = sVar4 + -1;
    if (sVar4 == 1) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xefff;
      return;
    }
    return;
  }
LAB_8007d0a8:
  uVar1 = *(ushort *)(param_1 + 0x2ba);
  if (uVar1 < 300) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
  }
  else if (uVar1 < 0x1389) {
    if (((uVar1 < 2000) && (DAT_800e1134._1_1_ == '\x02')) &&
       (cVar5 = FUN_80033160(param_1,&DAT_800e1130), cVar5 == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
    }
    else {
      FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x28);
      FUN_8004e774(param_1);
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
