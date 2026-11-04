/* FUN_8008dfa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008dfa4  body 0x8008dfa4..0x8008e17f  size 476 B
 * body sha256 3ac0d5bfc5276bb299a0adc540990d049db676e6b3798a490197cf7be6e6d65d
 * provider record sha256 496e2f3b9113f4d688252aacd6cdc655b3efd9a7549e5335592cc0d13a6436a7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008dfa4(undefined4 param_1,int param_2)

{
  int iVar1;
  short sVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int unaff_s0;
  
  iVar1 = param_2 + (uint)*(byte *)(unaff_s0 + 0xc) * 4;
  if (*(byte *)(iVar1 + 0x21818) < 0x1e) {
    uVar4 = 5;
LAB_8008e16c:
    FUN_8004ac04(0xaf0010,0xe400,uVar4,0);
    *(undefined1 *)(unaff_s0 + 4) = 1;
    return;
  }
  switch(*(undefined1 *)(iVar1 + 0x21818)) {
  case 0x23:
    *(short *)(param_2 + 0x2149e) = *(short *)(param_2 + 0x2149e) + 1;
    sVar2 = *(short *)(param_2 + 0x19c7e);
    break;
  default:
    iVar1 = FUN_800837ac(&DAT_800e1114,
                         *(undefined1 *)(param_2 + (uint)*(byte *)(unaff_s0 + 0xc) * 4 + 0x21818));
    if (iVar1 != 0) {
      *(undefined1 *)(unaff_s0 + 4) = 3;
      return;
    }
    uVar4 = 7;
    goto LAB_8008e16c;
  case 0x26:
    sVar2 = *(short *)(param_2 + 0x19c7e) >> 2;
    break;
  case 0x28:
    *(undefined2 *)(unaff_s0 + 0x3588) = 0;
    *(undefined2 *)(param_2 + 0x19d34) = 0;
    uVar3 = 2;
    goto LAB_8008e118;
  case 0x29:
    sVar2 = *(short *)(param_2 + 0x19c7e) >> 1;
    break;
  case 0x2a:
    *(undefined2 *)(unaff_s0 + 0x3588) = *(undefined2 *)(param_2 + 0x19c7e);
    goto LAB_8008e02c;
  case 0x2b:
    sVar2 = *(short *)(param_2 + 0x19c7e) >> 2;
    goto LAB_8008e100;
  case 0x2c:
    *(undefined2 *)(unaff_s0 + 0x3588) = *(undefined2 *)(param_2 + 0x19c7e);
    goto LAB_8008e02c;
  case 0x2d:
    sVar2 = *(short *)(param_2 + 0x19c7e) >> 1;
    goto LAB_8008e100;
  case 0x2e:
    sVar2 = *(short *)(param_2 + 0x19c7e);
LAB_8008e100:
    *(short *)(unaff_s0 + 0x3588) = sVar2;
    *(undefined2 *)(param_2 + 0x19d34) = 0;
    uVar3 = 3;
    goto LAB_8008e118;
  }
  *(short *)(unaff_s0 + 0x3588) = sVar2;
LAB_8008e02c:
  uVar3 = 1;
LAB_8008e118:
  *(undefined1 *)(unaff_s0 + 0x62) = uVar3;
  *(undefined1 *)(unaff_s0 + 4) = 4;
  return;
}
