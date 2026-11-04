/* FUN_80069c60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069c60  body 0x80069c60..0x80069dab  size 332 B
 * body sha256 b5b5d94e5a04a8bf37c24c1c7e85c09a8cae944673b6795a703ac64bdd94c2d7
 * provider record sha256 526f0074d2dbeb1ff6c0b69d290000ce1d6361461524f9ea2726025e8456c5eb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80069c60(int param_1,int param_2,int param_3,short *param_4)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = ((ushort)param_4[5] & 0x30) >> 4;
  if (uVar3 == 1) {
    param_2 = *param_4 - param_1;
    uVar1 = param_4[2];
LAB_80069d60:
    uVar3 = (uint)uVar1;
    param_3 = (param_2 * -0x708) / (int)uVar3;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (param_2 * -0x708 == -0x80000000)) {
      trap(0x1800);
    }
    bVar2 = param_3 < 0x709;
  }
  else {
    if (uVar3 < 2) {
      bVar2 = param_3 < 0x709;
      if (uVar3 != 0) goto LAB_80069d94;
      uVar3 = (uint)(ushort)param_4[2];
      param_1 = param_1 - ((int)*param_4 + uVar3);
    }
    else {
      if (uVar3 != 2) {
        bVar2 = param_3 < 0x709;
        if (uVar3 != 3) goto LAB_80069d94;
        param_2 = param_4[1] - param_2;
        uVar1 = param_4[3];
        goto LAB_80069d60;
      }
      uVar3 = (uint)(ushort)param_4[3];
      param_1 = param_2 - ((int)param_4[1] + uVar3);
    }
    param_3 = (param_1 * -0x708) / (int)uVar3;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (param_1 * -0x708 == -0x80000000)) {
      trap(0x1800);
    }
    bVar2 = param_3 < 0x709;
  }
LAB_80069d94:
  if (!bVar2) {
    param_3 = 0x708;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  return param_3;
}
