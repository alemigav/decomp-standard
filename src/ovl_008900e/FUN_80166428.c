/* FUN_80166428
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166428  body 0x80166428..0x80166683  size 604 B
 * body sha256 fb5d95de5e3fc9d1f256548b71c5f0eecba37ac09fb5453042250d517dfaecd2
 * provider record sha256 09fd129417633a0ea13be6d9e908f8ab7c52a2a224274f5c1c0c983a89939a5f
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166428(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    func_0x80036dc4(param_1,3,0,0);
    if (*(short *)(param_1 + 0x9c) != 0) {
      *(undefined2 *)(param_1 + 0x9c) = 0;
      *(undefined2 *)((int)param_1 + 0x1e2) = 0;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
    break;
  case 1:
    uVar3 = 0x12;
    sVar1 = *(short *)((int)param_1 + 0x1e2) + 0x48;
    *(short *)((int)param_1 + 0x1e2) = sVar1;
    param_1[0xb] = param_1[0xb] + (int)sVar1;
    goto LAB_8016661c;
  case 2:
    local_18 = 0x8980000;
    local_14 = 0;
    param_1[0xb] = param_1[0xb] + 0xa8c;
    func_0x8008383c((int)*(short *)((int)param_1 + 0x66),param_1[0x1c],&local_18,&local_18);
    sVar1 = func_0x80032d14(0,0,(int)local_18._0_2_,(int)local_14._0_2_);
    *(ushort *)(_DAT_800df938 + 0x66) = sVar1 + 0x100U & 0xc00;
    func_0x80036e70(param_1);
    param_1[0x7a] = 0x13000000;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 3:
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    sVar1 = *(short *)((int)param_1 + 0x1e2) + 0x48;
    *(short *)((int)param_1 + 0x1e2) = sVar1;
    param_1[0xb] = param_1[0xb] + (int)sVar1;
    func_0x8008a994(param_1,param_2,param_3,0x100);
    if (-1 < (int)(param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2) + 0x48)) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      FUN_801629c0(param_1);
      *(undefined1 *)(param_1 + 0x7a) = 0;
      *param_1 = *param_1 & 0xfffffff7;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
    break;
  case 4:
    uVar3 = 0x13;
    param_1[0xb] = 0;
LAB_8016661c:
    cVar2 = func_0x80036be4(param_1,uVar3,0,0);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    break;
  case 5:
    func_0x80036dc4(param_1,3,3,0);
    *(undefined1 *)((int)param_1 + 0x2ce) = 4;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
    if (*(short *)(param_1 + 0x9c) != 0) {
      param_1[1] = 0x10e0000;
    }
  }
  return;
}
