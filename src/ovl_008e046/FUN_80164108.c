/* FUN_80164108
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80164108  body 0x80164108..0x80164207  size 256 B
 * body sha256 78d606c09914ccca6d4c27a73abc1458b5867e3ef98bb963e7a4f1420e5c2f1b
 * provider record sha256 c4f90e2419553468b059d98cb6f572c1b7e9186590e98eb88f7ebab9b69db63c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164108(int param_1,undefined4 param_2,undefined4 param_3)

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
