/* FUN_80164544
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164544  body 0x80164544..0x801645ef  size 172 B
 * body sha256 0807d0874ea867f581d3c09f5415c0c8e882f3f235ddd92d703207d7fd090310
 * provider record sha256 3a8a51e9d774fa987926783f2522b296c648ba62104f0f451f3256fb688db527
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164544(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x2c5) != '\0') {
    *(undefined1 *)(param_1 + 0x2c3) = 1;
  }
  iVar1 = 0xfa;
  if ((_DAT_800e10ec & 0x20) != 0) {
    iVar1 = 200;
  }
  if ((((*(char *)(param_1 + 0x2c9) != '\0') && (*(char *)(param_1 + 0x2c3) == '\0')) &&
      ((*(byte *)(param_1 + 0x2bd) & 1) != 0)) &&
     ((uint)(int)*(short *)(param_1 + 0x1f2) < ((uint)*(byte *)(param_1 + 0x2c9) * iVar1) / 3)) {
    *(undefined1 *)(param_1 + 0x2c3) = 1;
    *(char *)(param_1 + 0x2c9) = *(char *)(param_1 + 0x2c9) + -1;
  }
  return;
}
