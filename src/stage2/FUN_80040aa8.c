/* FUN_80040aa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040aa8  body 0x80040aa8..0x80040bb3  size 268 B
 * body sha256 af27ae4bfc9b03a488b71c58d525501b50299cacf43f3bb0535d6f611dd13ae6
 * provider record sha256 796c7128f329139b4c2f1bcdc8d1f99064131a177f84e98ef6527089f1a2c69b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040aa8(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_80040bb4(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (*param_1 << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  *param_2 = (*param_1 << 0xc) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (param_1[1] << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  param_2[1] = (param_1[1] << 0xc) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (param_1[2] << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  param_2[2] = (param_1[2] << 0xc) / iVar1;
  return;
}
