/* FUN_801643a0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801643a0  body 0x801643a0..0x80164607  size 616 B
 * body sha256 db4dedb04145422cd018ee8070ac1006cb8a3009ba69c114deb7a72da2a1887b
 * provider record sha256 18ad9b974e26b80d8251e7ae6e665417501a939e86a0d612a62902b149eb9b4f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801643a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  char cVar3;
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 700) = 0;
    *(undefined2 *)(param_1 + 0x270) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000000;
    func_0x8008a994(param_1,param_2,param_3,0x1000);
    *(undefined1 *)(param_1 + 0x2ce) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
  case 1:
    if (*(short *)(param_1 + 0x270) != 0) {
      *(undefined1 *)(param_1 + 0x2ce) = 5;
      *(undefined4 *)(param_1 + 0x1e8) = 0xc000000;
      *(undefined2 *)(param_1 + 500) = 0xffff;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    break;
  case 2:
    sVar2 = *(short *)(param_1 + 0x1e2) + 0x48;
    *(short *)(param_1 + 0x1e2) = sVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar2;
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x1000);
    if (iVar1 == 0) break;
    cVar3 = *(char *)(param_1 + 6);
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000000;
    goto LAB_801645ac;
  case 3:
    local_18 = 0x8980000;
    local_14 = 0;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0xa8c;
    func_0x8008383c((int)*(short *)(param_1 + 0x66),*(undefined4 *)(param_1 + 0x70),&local_18,
                    &local_18);
    sVar2 = func_0x80032d14(0,0,(int)local_18._0_2_,(int)local_14._0_2_);
    *(ushort *)(_DAT_800df938 + 0x66) = sVar2 + 0x100U & 0xc00;
    func_0x80036e70(param_1);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000000;
    sVar2 = *(short *)(param_1 + 0x1e2) + 0x48;
    *(short *)(param_1 + 0x1e2) = sVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar2;
    func_0x8008a994(param_1,param_2,param_3,0x1000);
    if (-1 < *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2) + 0x48) {
      cVar3 = *(char *)(param_1 + 6);
      *(undefined4 *)(param_1 + 0x1e8) = 0xd000000;
LAB_801645ac:
      *(char *)(param_1 + 6) = cVar3 + '\x01';
    }
    break;
  case 5:
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x1000);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1000000;
    }
  }
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  return;
}
