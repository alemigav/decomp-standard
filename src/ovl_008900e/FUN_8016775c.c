/* FUN_8016775c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016775c  body 0x8016775c..0x80167a2f  size 724 B
 * body sha256 a38a75087fdd95584f977deb8610c97b838c48c3e6c759a16af818fc7491ae13
 * provider record sha256 e557fdc5e51c34ff8ea384576654f0fda5fca6e43abbe99ec6e44d7685322be7
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016775c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    param_1[0x7a] = 0x22000000;
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 4;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
  case 1:
    cVar2 = func_0x8008a994(param_1,param_2,param_3,0x1000);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar2;
    if (*(byte *)((int)param_1 + 0x1e9) < 6) {
      *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    }
    goto switchD_801677a0_default;
  case 2:
    param_1[0xb] = param_1[0xb] + 0x4f5;
    uVar1 = func_0x8006a7ec(param_1[0x1c]);
    switch(uVar1) {
    case 2:
      param_1[10] = param_1[10] - 600;
      break;
    case 3:
      param_1[10] = param_1[10] + 600;
      break;
    case 4:
      uVar3 = param_1[0xc] - 600;
      goto LAB_801678b4;
    case 5:
      uVar3 = param_1[0xc] + 600;
LAB_801678b4:
      param_1[0xc] = uVar3;
    }
    func_0x80036e70(param_1);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
switchD_801677a0_caseD_3:
    param_1[0x7a] = 0x19000000;
    func_0x8008a994(param_1,param_2,param_3,0x400);
    if ((int)param_1[0xb] < 0) goto switchD_801677a0_default;
    param_1[0xaf] = 0;
    FUN_801629c0(param_1);
    param_1[0x7a] = 0x19000000;
    *param_1 = *param_1 & 0xfffffff7;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    break;
  case 3:
    goto switchD_801677a0_caseD_3;
  case 4:
  case 6:
    break;
  case 5:
    if (*(short *)((int)param_1 + 0x1f2) < 0) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      *param_1 = *param_1 & 0xfffffff3;
      goto switchD_801677a0_default;
    }
    param_1[0x7a] = 0x16000000;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    break;
  case 7:
    *(undefined1 *)((int)param_1 + 0x2ce) = 3;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 & 0xfffffff3;
    FUN_80166c7c(param_1);
  default:
    goto switchD_801677a0_default;
  }
  cVar2 = func_0x8008a994(param_1,param_2,param_3,0x1000);
  *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar2;
switchD_801677a0_default:
  uVar3 = param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2);
  if ((int)(uVar3 + 0x48) < 0) {
    param_1[0xb] = uVar3;
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x30;
  }
  else {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
  }
  return;
}
