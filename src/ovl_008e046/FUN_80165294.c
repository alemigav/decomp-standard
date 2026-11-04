/* FUN_80165294
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80165294  body 0x80165294..0x80165527  size 660 B
 * body sha256 8bc8755e517a3516cfc8178c4eb16b05ed01327f84673697121401089f575cc1
 * provider record sha256 a497e9282f1cd6b7d3bfa691e0110f20baaa91543c8b86acedf307064b02ae4e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165294(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  char cVar3;
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    break;
  case 1:
    goto switchD_801652d4_caseD_1;
  case 2:
    sVar2 = *(short *)(param_1 + 0x1e2) + 0x48;
    *(short *)(param_1 + 0x1e2) = sVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar2;
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x1000);
    if (iVar1 == 0) goto switchD_801652d4_default;
    cVar3 = *(char *)(param_1 + 6);
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000000;
    goto LAB_801654cc;
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
    if (*(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2) + 0x48 < 0)
    goto switchD_801652d4_default;
    cVar3 = *(char *)(param_1 + 6);
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000000;
    goto LAB_801654cc;
  case 5:
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x1000);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1000000;
    }
  default:
    goto switchD_801652d4_default;
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0x3000000;
  *(undefined4 *)(param_1 + 700) = 0;
  *(undefined1 *)(param_1 + 0x2ce) = 0;
  *(undefined2 *)(param_1 + 0x1e2) = 0;
  *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
switchD_801652d4_caseD_1:
  func_0x8008a994(param_1,param_2,param_3,0x1000);
  if ((*(ushort *)(param_1 + 0x1aa) & 0xf) == 1) {
    if (*(short *)(param_1 + 0x270) == 0) goto switchD_801652d4_default;
    *(undefined1 *)(param_1 + 0x2ce) = 5;
    *(undefined4 *)(param_1 + 0x1e8) = 0xc000000;
    cVar3 = *(char *)(param_1 + 6);
    *(undefined2 *)(param_1 + 500) = 0xffff;
  }
  else {
    if (*(char *)(param_1 + 0x2b5) != '\x02') {
      iVar1 = FUN_80162768(param_1);
      *(int *)(param_1 + 0x2c4) = iVar1;
      if (iVar1 == 0) goto switchD_801652d4_default;
    }
    *(undefined1 *)(param_1 + 0x2ce) = 5;
    *(undefined4 *)(param_1 + 0x1e8) = 0xc000000;
    cVar3 = *(char *)(param_1 + 6);
    *(undefined2 *)(param_1 + 500) = 0xffff;
  }
LAB_801654cc:
  *(char *)(param_1 + 6) = cVar3 + '\x01';
switchD_801652d4_default:
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  return;
}
