/* FUN_801623c4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801623c4  body 0x801623c4..0x801624a3  size 224 B
 * body sha256 8808a23faf3d76b9fca43bfe9f371577f062305925fbab7fef6900fe9eb2c667
 * provider record sha256 dbc5e0caea7ea9c9e825ba9a9a48d4c9e5c37fc7ac94e864064f2a07283b02ea
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801623c4(int param_1)

{
  int iVar1;
  undefined1 uVar3;
  short sVar2;
  uint uVar4;
  
  *(short *)(param_1 + 700) =
       *(short *)(param_1 + 0x1f6) - *(short *)(*(int *)(param_1 + 0x250) + 0x66);
  iVar1 = func_0x80089d54();
  func_0x80033648(param_1);
  uVar4 = **(uint **)(param_1 + 0x214);
  if (((uVar4 & 0x20000) != 0) && (*(char *)(param_1 + 0x2c5) == '\0')) {
    uVar3 = FUN_80163a30(param_1,5);
    *(undefined1 *)(param_1 + 0x2c5) = uVar3;
  }
  if ((uVar4 & 0x10000) == 0) {
    sVar2 = *(short *)(param_1 + 0x2c2) + -0x14;
    if ((*(byte *)(param_1 + 0x2b5) & 1) == 0) {
      sVar2 = *(short *)(param_1 + 0x2c2) + 0x14;
    }
  }
  else {
    sVar2 = *(short *)(param_1 + 0x2c2) + 0x14;
    if ((*(byte *)(param_1 + 0x2b5) & 1) == 0) {
      sVar2 = *(short *)(param_1 + 0x2c2) + -0x14;
    }
  }
  *(short *)(param_1 + 0x2c2) = sVar2;
  if (iVar1 != 0) {
    FUN_801624a4(param_1);
  }
  return;
}
