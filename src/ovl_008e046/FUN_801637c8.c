/* FUN_801637c8
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801637c8  body 0x801637c8..0x801638d3  size 268 B
 * body sha256 98fe545894481efdef20d8dd13f6ec494fe47f1f3ad159f1abc2cab7ee4c0ab1
 * provider record sha256 898e2a7841ad04529c3f68849431f2f57bdf931916ec5bb1f4d70eead1089a7f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801637c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if ((*(char *)(param_1 + 0x2ca) == '\0') && (*(uint *)(param_1 + 0x28c) < 2000)) {
    iVar1 = func_0x80032e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                            *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x300);
    uVar2 = 0x1020000;
    if (iVar1 == 0) {
      uVar2 = 0x1090000;
    }
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,1);
    func_0x80032b5c(param_1,0);
    func_0x8008a994(param_1,param_2,param_3,0x10100);
    if (*(char *)(param_1 + 0x1e9) != '.') {
      return;
    }
    uVar2 = 0x10f0000;
  }
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
