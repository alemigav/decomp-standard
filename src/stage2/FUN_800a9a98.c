/* FUN_800a9a98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9a98  body 0x800a9a98..0x800a9ce3  size 588 B
 * body sha256 a22aab19238f6611582fd5aadf5c49eea5c5b48e65dc92a100a64eb8c115b9c9
 * provider record sha256 6a47253cee54e2f1955fb9cd49d18284a09384085f70636b19a11b9ddb473740
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9a98(int param_1,float param_2,float param_3,undefined4 param_4,float param_5,
                 float param_6)

{
  uint uVar1;
  undefined4 uVar2;
  float fVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 0x34);
  if ((*(uint *)(param_1 + 8) & 0x100000) == 0) {
    param_2 = param_2 * 127.0;
    if (2.1474836e+09 <= param_2) {
      param_2 = param_2 - 2.1474836e+09;
    }
    uVar1 = (uint)param_2;
    if ((int)(uVar1 << 0x18) < 0) {
      uVar1 = 0x7f;
    }
  }
  else {
    fVar3 = *(float *)(param_1 + 0x40) * param_2 * 127.0;
    if (2.1474836e+09 <= fVar3) {
      fVar3 = fVar3 - 2.1474836e+09;
    }
    uVar1 = (uint)fVar3;
    if ((int)(uVar1 << 0x18) < 0) {
      uVar1 = 0x7f;
    }
  }
  FUN_800a7a8c(uVar2,uVar1 & 0xff);
  fVar3 = (param_3 + 1.0) * 64.0;
  if (2.1474836e+09 <= fVar3) {
    fVar3 = fVar3 - 2.1474836e+09;
  }
  uVar1 = (uint)fVar3;
  if ((int)(uVar1 << 0x18) < 0) {
    uVar1 = 0x7f;
  }
  FUN_800a76a4(uVar2,uVar1 & 0xff);
  fVar3 = (1.0 - param_5) * 64.0;
  if (2.1474836e+09 <= fVar3) {
    fVar3 = fVar3 - 2.1474836e+09;
  }
  uVar1 = (uint)fVar3;
  if ((int)(uVar1 << 0x18) < 0) {
    uVar1 = 0x7f;
  }
  FUN_800a777c(uVar2,uVar1 & 0xff);
  param_6 = param_6 * 8192.0;
  if (param_6 < 2.1474836e+09) {
    uVar1 = (uint)param_6;
  }
  else {
    uVar1 = (int)(param_6 - 2.1474836e+09) | 0x80000000;
  }
  if (0x3fff < uVar1) {
    uVar1 = 0x3fff;
  }
  FUN_800a7854(uVar2,uVar1 & 0xffff);
  return;
}
