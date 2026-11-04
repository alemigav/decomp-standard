/* FUN_80163204
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163204  body 0x80163204..0x8016329f  size 156 B
 * body sha256 de133bd2189c61ccae6b688729e3f08216dc6d021067cbd6565e35abca5b3f4f
 * provider record sha256 33b8e2633136818dde9d6db9335edb3a828dde06a61969299d4aedcdf1814cdd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163204(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x2c2) = 0x400;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x80000 + 0xf00;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_8016327c;
  uVar1 = *(short *)(param_1 + 0x2c2) - 0x20;
  *(ushort *)(param_1 + 0x2c2) = uVar1;
  if ((int)((uint)uVar1 << 0x10) < 0) {
    *(undefined2 *)(param_1 + 0x2c2) = 0;
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
LAB_8016327c:
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_8016375c(param_1,0);
  return;
}
