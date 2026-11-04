/* FUN_801667a8
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801667a8  body 0x801667a8..0x801669e3  size 572 B
 * body sha256 5dc02dbbc447d0e2c85222e9af4cdff331b9df160f8242296474d5a994522672
 * provider record sha256 2e71af9fe4a2dadfb04a1c7b4511a54d94dea9d60c0afe157360a2533259cb8b
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801667a8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar2;
  short sVar1;
  undefined4 uVar3;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    param_1[0x7a] = 0x13000000;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    param_1[0xb] = param_1[0xb] + 0x546;
switchD_801667e8_caseD_1:
    func_0x8008a994(param_1,param_2,param_3,0x1000);
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    if (-1 < (int)param_1[0xb]) {
      param_1[0xaf] = 0;
      FUN_801629c0(param_1);
      param_1[0x7a] = 0x13000000;
      *param_1 = *param_1 & 0xfffffff7;
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
switchD_801667e8_caseD_2:
      uVar3 = 0x400;
LAB_80166924:
      cVar2 = func_0x8008a994(param_1,param_2,param_3,uVar3);
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar2;
    }
switchD_801667e8_default:
    sVar1 = *(short *)((int)param_1 + 0x1e2) + 0x30;
    if ((int)(param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2) + 0x48) <
        (int)*(short *)(param_1 + 0xb8)) {
      *(short *)((int)param_1 + 0x1e2) = sVar1;
      param_1[0xb] = param_1[0xb] + (int)sVar1;
      param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
      param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    }
    else {
      param_1[0xb] = (int)*(short *)(param_1 + 0xb8);
    }
    return;
  case 1:
    goto switchD_801667e8_caseD_1;
  case 2:
    goto switchD_801667e8_caseD_2;
  case 3:
    if (*(short *)((int)param_1 + 0x1f2) < 0) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      *param_1 = *param_1 & 0xfffffff3;
      goto switchD_801667e8_default;
    }
    param_1[0x7a] = 0x10000000;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
  case 4:
    uVar3 = 0x1000;
    goto LAB_80166924;
  case 5:
    *(undefined1 *)((int)param_1 + 0x2ce) = 3;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 & 0xfffffff3;
    FUN_80165a84(param_1);
  default:
    goto switchD_801667e8_default;
  }
}
