/* FUN_80164194
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80164194  body 0x80164194..0x80164293  size 256 B
 * body sha256 9aef0370b8afc91ca5fd53ba634837306a52fa3de797cdde1be5d1c3e81d2053
 * provider record sha256 acf1c4eee9764b7d5c3d99f210debdea730cc556de79d7f4e3a0de41c0663fdf
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164194(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                  *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x10);
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80032b5c(param_1,0);
  iVar1 = func_0x8008a994(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x10f0000;
  }
  uVar2 = 0x1140000;
  if ((4000 < *(uint *)(param_1 + 0x28c)) ||
     ((*(char *)(param_1 + 0x2ca) == '\0' && (uVar2 = 0x1090000, *(uint *)(param_1 + 0x28c) < 2000))
     )) {
    *(undefined4 *)(param_1 + 4) = uVar2;
  }
  return;
}
