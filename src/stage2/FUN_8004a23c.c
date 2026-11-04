/* FUN_8004a23c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a23c  body 0x8004a23c..0x8004a327  size 236 B
 * body sha256 0bf4f4380f811cd5ecb9a1bbc28ca53a63aa89f3b1203235ab134aaa6b2e9e21
 * provider record sha256 9621cbe73e7f42f1725e56041de273b0073cf86c0ff5f21f8d5c638f2dbd20a0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a23c(undefined4 *param_1,undefined4 *param_2,char param_3,short param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *param_2 = *param_1;
  param_2[1] = uVar2;
  param_2[2] = uVar3;
  param_2[3] = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  param_2[4] = param_1[4];
  param_2[5] = uVar2;
  param_2[6] = uVar3;
  param_2[7] = uVar4;
  if (param_3 == '\x01') {
    param_2[1] = param_4 * 2 - param_1[1];
    param_2[4] = param_4 * 2 - param_1[4];
    return;
  }
  iVar1 = (int)param_4;
  if (param_3 == '\0') {
    param_2[3] = iVar1 * 2 - param_1[3];
    param_2[6] = iVar1 * 2 - param_1[6];
    return;
  }
  param_2[2] = iVar1 * 2 - param_1[2];
  param_2[5] = iVar1 * 2 - param_1[5];
  return;
}
