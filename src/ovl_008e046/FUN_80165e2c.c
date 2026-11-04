/* FUN_80165e2c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80165e2c  body 0x80165e2c..0x80166103  size 728 B
 * body sha256 ef20eb3b23e48e7f2c65031508857cc0f941171b9d868699e7e4a7b499e6cea0
 * provider record sha256 af3f34e527b650baf49f57696f456fd5903fd4978d3ed12a864d1f8f362514f0
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e2c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar3;
  uint uVar2;
  char cVar5;
  short sVar4;
  uint uVar6;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    bVar1 = *(byte *)((int)param_1 + 0x207);
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    if (bVar1 == 1) {
      uVar3 = 0xff6a;
LAB_80165f18:
      *(undefined2 *)(param_1 + 0x79) = uVar3;
    }
    else if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined2 *)(param_1 + 0x78) = 0x96;
      }
    }
    else if (bVar1 == 2) {
      *(undefined2 *)(param_1 + 0x78) = 0xff6a;
    }
    else {
      uVar3 = 0x96;
      if (bVar1 == 3) goto LAB_80165f18;
    }
    uVar6 = 4;
    if (*(byte *)((int)param_1 + 0x206) != 0) {
      uVar6 = (uint)*(byte *)((int)param_1 + 0x206);
    }
    uVar2 = 0x12000000;
    if ((int)(*(byte *)((int)param_1 + 0x207) - uVar6) < 0) {
      uVar2 = 0x11000000;
    }
    param_1[0x7a] = uVar2;
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 4;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
    break;
  case 1:
  case 4:
  case 6:
    break;
  case 2:
    param_1[0xb] = param_1[0xb] + 0x4f5;
    *(ushort *)((int)param_1 + 0x66) = (ushort)*(byte *)((int)param_1 + 0x206) * 0x400 + -0x800;
    func_0x80036e70(param_1);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
  case 3:
    param_1[0x7a] = 0x13000000;
    func_0x8008a994(param_1,param_2,param_3,0x400);
    if ((int)param_1[0xb] < 0) goto switchD_80165e70_default;
    param_1[0xaf] = 0;
    FUN_801629c0(param_1);
    param_1[0x7a] = 0x13000000;
    *param_1 = *param_1 & 0xfffffff7;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    break;
  case 5:
    if (*(short *)((int)param_1 + 0x1f2) < 0) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      *param_1 = *param_1 & 0xfffffff3;
      goto switchD_80165e70_default;
    }
    param_1[0x7a] = 0x10000000;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    break;
  case 7:
    *(undefined1 *)((int)param_1 + 0x2ce) = 3;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 & 0xfffffff3;
    FUN_80165a84(param_1);
  default:
    goto switchD_80165e70_default;
  }
  cVar5 = func_0x8008a994(param_1,param_2,param_3,0x1000);
  *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar5;
switchD_80165e70_default:
  sVar4 = *(short *)((int)param_1 + 0x1e2) + 0x30;
  if ((int)(param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2) + 0x48) < 0) {
    *(short *)((int)param_1 + 0x1e2) = sVar4;
    param_1[0xb] = param_1[0xb] + (int)sVar4;
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
  }
  else {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
  }
  return;
}
