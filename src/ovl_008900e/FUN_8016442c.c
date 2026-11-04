/* FUN_8016442c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016442c  body 0x8016442c..0x80164693  size 616 B
 * body sha256 b5eaabdfba364121ce7ca51704684fc86ea80e5827b2a80da0af299ab296dc8f
 * provider record sha256 72c5c1fb7e24de84d8ad470e4f68e84975439fd86a1acd1c9fdf969c2265fa93
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016442c(int param_1,undefined4 param_2,undefined4 param_3)

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
      *(undefined4 *)(param_1 + 0x1e8) = 0x12000000;
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
    *(undefined4 *)(param_1 + 0x1e8) = 0x13000000;
    goto LAB_80164638;
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
    *(undefined4 *)(param_1 + 0x1e8) = 0x13000000;
    sVar2 = *(short *)(param_1 + 0x1e2) + 0x48;
    *(short *)(param_1 + 0x1e2) = sVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar2;
    func_0x8008a994(param_1,param_2,param_3,0x1000);
    if (-1 < *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2) + 0x48) {
      cVar3 = *(char *)(param_1 + 6);
      *(undefined4 *)(param_1 + 0x1e8) = 0x13000000;
LAB_80164638:
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
