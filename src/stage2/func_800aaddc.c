/* func_800aaddc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aaddc  body 0x800aaddc..0x800aaea7  size 204 B
 * body sha256 e44a754ddae95a510fc54a33b0176ac32eb3a6683807033617b4b827164fca18
 * provider record sha256 4f6ed8cd980b2c860047bb19f2567e7615db5de3810723d6f932a7de77f61646
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800aaddc(int param_1,undefined4 *param_2,undefined4 *param_3,byte param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  
  if (DAT_80136310 == '\0') {
    uVar1 = 0;
  }
  else {
    FUN_800a5678();
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    *(undefined4 *)(param_1 + 0xc) = *param_2;
    *(undefined4 *)(param_1 + 0x10) = uVar1;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    *(undefined4 *)(param_1 + 0x18) = *param_3;
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    fVar3 = (float)param_4 / 127.0;
    *(float *)(param_1 + 0x28) = fVar3;
    if (fVar3 < *(float *)(param_1 + 0x2c)) {
      *(float *)(param_1 + 0x2c) = fVar3;
    }
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
