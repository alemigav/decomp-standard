/* FUN_80165e80
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165e80  body 0x80165e80..0x80165f9b  size 284 B
 * body sha256 31870388ad7aaa86de84fbc7916ea7c0e9f795e4774515eb5756061f5dbdcb31
 * provider record sha256 f61304ec3f6177604f3a86927bc105102eb228e97bb1e35102b9978906be7c3e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e80(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  func_0x80032bd8(param_1,0,0);
  if (*(char *)(param_1 + 0x2b5) == '\0') {
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      if (*(char *)(param_1 + 7) == '\0') {
        *(undefined1 *)(param_1 + 7) = 1;
        *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
      }
      else {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
      }
    }
  }
  else {
    if ((*(char *)(param_1 + 7) == '\0') && (*(uint *)(param_1 + 0x28c) < 0x578)) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
      *(undefined1 *)(param_1 + 7) = 1;
    }
    *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
    if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined1 *)(param_1 + 0x2b5) = 0;
      *(undefined1 *)(param_1 + 7) = 0;
    }
    if (*(char *)(param_1 + 0x1e9) != '\x03') {
      func_0x80089d54(param_1,param_2,param_3,0x200);
    }
  }
  return;
}
