/* FUN_80025474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025474  body 0x80025474..0x800254f3  size 128 B
 * body sha256 f702bee02d838a327037342d8bb47753e9b006eb12e8d8b25d757b4c49a33854
 * provider record sha256 3a7f5c74f9037753811610c67fcaec047d1bcd410a92a5bf744982afcac5de6f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025474(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_800c56ec = param_1;
  *param_1 = 1;
  param_1[3] = 0xd0;
  param_1[5] = 0x1000;
  param_1[7] = 0x800;
  param_1[8] = &DAT_800c52e0;
  param_1[2] = entry;
  param_1[9] = 0x400;
  uVar2 = DAT_800c56e4;
  uVar1 = DAT_800c4ea0;
  param_1[0xc] = &DAT_800c56f8;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[10] = uVar1;
  param_1[0xb] = uVar2;
  return;
}
