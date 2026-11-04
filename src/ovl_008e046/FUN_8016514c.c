/* FUN_8016514c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x8016514c  body 0x8016514c..0x80165293  size 328 B
 * body sha256 47d5750729ea7e8b30e7d63613e9e4cc4f4c0bd5bfecf689f9c20b194a387394
 * provider record sha256 6ddaafb1209c88fe3eab0cd9a0b0cc4aeee3174c04b0e064e966b81f72bd5bfa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016514c(int param_1)

{
  char cVar1;
  undefined4 local_30 [8];
  
  local_30[0] = 0x15efe70;
  local_30[1] = 0x1900000;
  local_30[2] = 0x15efed4;
  local_30[3] = 0xfa0000;
  local_30[4] = 0x15eff38;
  local_30[5] = 0x640000;
  local_30[6] = 0x15eff9c;
  local_30[7] = 0xffce0000;
  if ((*(byte *)(param_1 + 0x2cf) & 1) == 0) {
    func_0x800837d0(((int)_DAT_800e1324 << 0x1b) >> 0x10,
                    local_30 + (uint)(*(byte *)(param_1 + 0x2cf) >> 1) * 2,
                    local_30 + (uint)(*(byte *)(param_1 + 0x2cf) >> 1) * 2);
    FUN_80166e8c(0x800e1130,0,2,0x2400,0,0,local_30 + (uint)(*(byte *)(param_1 + 0x2cf) >> 1) * 2);
  }
  cVar1 = *(char *)(param_1 + 0x2cf) + '\x01';
  *(char *)(param_1 + 0x2cf) = cVar1;
  if (cVar1 == '\a') {
    *(undefined4 *)(param_1 + 0x2d8) = 0;
  }
  return;
}
