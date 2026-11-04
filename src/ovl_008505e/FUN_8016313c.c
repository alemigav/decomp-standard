/* FUN_8016313c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016313c  body 0x8016313c..0x80163247  size 268 B
 * body sha256 ae2a195522c4e3f5dfa90e3559fbbe5452c08a89859c0dc99b8b39621858b62d
 * provider record sha256 6f90f26ce27bcce986e2c1b75e86a127b0524575016a2c005bf7a6951ce19e74
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8016313c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    func_0x80032bd8(param_1,0,0);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
    if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 7) = 1;
      *(undefined1 *)((int)param_1 + 0x2b5) = 0;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
      *param_1 = *param_1 & 0xefffffff | 0x4000000;
      func_0x80077d18(10,param_1);
    }
    if (*(char *)((int)param_1 + 0x1e9) != '\b') {
      func_0x80089d54(param_1,param_2,param_3,0x100);
      return 0;
    }
  }
  else {
    func_0x80032b5c(param_1,0);
    FUN_8016655c(param_1,0x40,0xf0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
