/* FUN_80162e2c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162e2c  body 0x80162e2c..0x80162f53  size 296 B
 * body sha256 dc5f8ab99f68eda42853c99bd5633feda9a4c99eb22fdcd59b13ca1ce2803f06
 * provider record sha256 3d652c9be081f2b39cfcb48d0c6e1921dc96a8eaf1a59bc5e8f02bc4e62f644b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162e2c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    FUN_80162f54(param_1,0x41,0xfffffee8);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    if (*(char *)(param_1 + 0x7a) == '\f') {
      sVar1 = *(short *)((int)param_1 + 0x66) + -0x20;
    }
    else {
      if (*(char *)(param_1 + 0x7a) != '\r') goto LAB_80162ea8;
      sVar1 = *(short *)((int)param_1 + 0x66) + 0x20;
    }
    *(short *)((int)param_1 + 0x66) = sVar1;
  }
LAB_80162ea8:
  func_0x80032b5c(param_1,0);
  func_0x80089d54(param_1,param_2,param_3,0x200);
  sVar1 = *(short *)(param_1 + 0x7d);
  *(short *)(param_1 + 0x7d) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
    *(undefined2 *)(param_1 + 0x78) = 0x118;
    *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    *(undefined1 *)((int)param_1 + 0x2be) = 1;
    *param_1 = *param_1 & 0xfbffffff | 0x10000000;
    func_0x80077d18(3);
    _DAT_800e1128 = _DAT_800e1128 | 0x20;
  }
  return;
}
