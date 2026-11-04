/* FUN_801647ac
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801647ac  body 0x801647ac..0x801648ab  size 256 B
 * body sha256 27da89c57f6249dc6e7fa40268a2822985bba485d75b74c6e6f672b8722d252a
 * provider record sha256 2662d8699d49f71ca4a092b0352c66474304c2f94028f016f4b3ca8394aed4dd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801647ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar1 = &DAT_800e1130;
  }
  else {
    puVar1 = _DAT_800e13ec;
  }
  *(undefined2 *)(param_1 + 0x1e0) = 0;
  *(undefined2 *)(param_1 + 0x1e2) = *(undefined2 *)(param_1 + 0x2d2);
  *(undefined2 *)(param_1 + 0x1e4) = *(undefined2 *)(param_1 + 0x2d4);
  if (*(short *)(param_1 + 0x1e2) < 0) {
    *(undefined2 *)(param_1 + 0x1e2) = 0x28;
  }
  *(undefined2 *)(param_1 + 500) = 0x28;
  func_0x80032dbc(param_1,*(undefined4 *)(puVar1 + 0x28),*(undefined4 *)(puVar1 + 0x30),0xffffff00);
  *(undefined1 *)(param_1 + 0x2c7) = 0;
  *(undefined1 *)(param_1 + 0x2c6) = 0;
  *(undefined1 *)(param_1 + 0x2c4) = 0;
  FUN_80164544(param_1);
  *(undefined1 *)(param_1 + 0x2d6) = *(undefined1 *)(param_1 + 5);
  if (*(char *)(param_1 + 0x1e8) != '\x04') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *(undefined1 *)(param_1 + 0x2d7) = 0;
  return;
}
