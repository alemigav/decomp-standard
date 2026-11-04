/* FUN_80167024
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80167024  body 0x80167024..0x801672f3  size 720 B
 * body sha256 ff28648aa032eced5c06cf30b0a997bbd8701664576656bf29c78f238dc87151
 * provider record sha256 aa66e04cf68d6562126958abbf28bdf4681fbb9db142bba0bfdd16b68df376ea
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167024(uint *param_1,undefined4 param_2,undefined4 param_3)

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
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    bVar1 = *(byte *)((int)param_1 + 0x207);
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    if (bVar1 == 1) {
      uVar3 = 0xff6a;
LAB_80167110:
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
      if (bVar1 == 3) goto LAB_80167110;
    }
    uVar6 = 4;
    if (*(byte *)((int)param_1 + 0x206) != 0) {
      uVar6 = (uint)*(byte *)((int)param_1 + 0x206);
    }
    uVar2 = 0x18000000;
    if ((int)(*(byte *)((int)param_1 + 0x207) - uVar6) < 0) {
      uVar2 = 0x17000000;
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
    param_1[0x7a] = 0x19000000;
    func_0x8008a994(param_1,param_2,param_3,0x400);
    if ((int)param_1[0xb] < 0) goto switchD_80167068_default;
    param_1[0xaf] = 0;
    FUN_801629c0(param_1);
    param_1[0x7a] = 0x19000000;
    *param_1 = *param_1 & 0xfffffff7;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    break;
  case 5:
    if (*(short *)((int)param_1 + 0x1f2) < 0) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      *param_1 = *param_1 & 0xfffffff3;
      goto switchD_80167068_default;
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
    goto switchD_80167068_default;
  }
  cVar5 = func_0x8008a994(param_1,param_2,param_3,0x1000);
  *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar5;
switchD_80167068_default:
  if ((int)(param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2) + 0x48) < 0) {
    sVar4 = *(short *)((int)param_1 + 0x1e2) + 0x30;
    *(short *)((int)param_1 + 0x1e2) = sVar4;
    param_1[0xb] = param_1[0xb] + (int)sVar4;
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
  }
  else {
    param_1[0xb] = 0;
  }
  return;
}
