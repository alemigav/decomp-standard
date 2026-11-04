/* FUN_8016464c
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x8016464c  body 0x8016464c..0x80164733  size 232 B
 * body sha256 daab99d97f259f1952705602054083ff0c33737f392b29d9a4d3400bce20c185
 * provider record sha256 ba140e4f0ad8e846fa01b2a627850b0be94dbca814b9a2d83f59b036e7e3ffa2
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016464c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) | 2;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x8001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x80077d18(0xc,param_1);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (*(char *)(param_1 + 0x1e9) == '\x0f') {
    func_0x80077d18(9,param_1);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) & 0xfffd;
  }
  func_0x80032b5c(param_1,0);
  return;
}
