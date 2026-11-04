/* FUN_801637a8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801637a8  body 0x801637a8..0x801638a7  size 256 B
 * body sha256 02e2fcee61b108e52484b5f0f118876ea50b07d0cfea1caed97c076b6964942f
 * provider record sha256 31909fdfb5a6060e48baed2f64826ddbfa48d7767a7253be5c8054a8a7b26541
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801637a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  func_0x80089d54();
  if (*(char *)(param_1 + 7) == '\0') {
    if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
      *(undefined1 *)(param_1 + 7) = 1;
      local_14 = 0;
      local_16 = 0;
      local_18 = 0;
      func_0x80037780((uint)*(byte *)(param_1 + 0x2c0) << 0x10 | 0x1d000c00,
                      (int)(((int)*(short *)(param_1 + 0x66) +
                             (int)*(short *)(*(int *)(param_1 + 0x234) +
                                             (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x5a) +
                            (uint)*(byte *)(param_1 + 0x2cd) * 0x800) * 0x10000) >> 0x10,
                      *(int *)(param_1 + 0x234) + 0x1060,&local_18);
      func_0x80077d18(3,param_1);
    }
  }
  else if ((**(uint **)(param_1 + 0x214) & 0x20000) != 0) {
    FUN_801639d0(param_1,param_2,param_3);
  }
  return;
}
