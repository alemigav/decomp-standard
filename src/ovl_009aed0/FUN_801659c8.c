/* FUN_801659c8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801659c8  body 0x801659c8..0x80165ddb  size 1044 B
 * body sha256 b23caa7152d729c83b495877bd2a71882d47233d6edc813b7813cc8a4f2a81cf
 * provider record sha256 da1cf0b1802b2bf440fb42e72e892cdf011e3fa6e06c91463e3cec311d14ba09
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801659c8(int param_1)

{
  short sVar3;
  undefined2 uVar4;
  char cVar6;
  char cVar7;
  ushort uVar5;
  int iVar1;
  int iVar2;
  int iVar8;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar8 = *(int *)(param_1 + 0x250);
  sVar3 = *(short *)(iVar8 + 0x66);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000300;
    func_0x80077adc(0x4010001,param_1 + 0x28);
    *(undefined2 *)(param_1 + 500) = 5;
    *(undefined2 *)(param_1 + 0x1e0) = 700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
  case 1:
    FUN_80163154(param_1,(int)sVar3);
    if (*(short *)(param_1 + 0x1f6) == 0) {
      sVar3 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                              *(undefined4 *)(param_1 + 0x228),0x400);
      *(short *)(param_1 + 0x1f6) = sVar3;
      if (sVar3 == 0) {
        uVar4 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                                *(undefined4 *)(param_1 + 0x228),0x400);
        *(undefined2 *)(param_1 + 0x1f6) = uVar4;
      }
    }
    sVar3 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar3 + -1;
    if (sVar3 == 1) {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -100;
    if ((*(uint *)(param_1 + 0x1ac) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 5;
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000300;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    func_0x80077adc(0x22a0001,param_1 + 0x28);
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    FUN_80163154(param_1,(int)sVar3);
    cVar6 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    cVar7 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6 + cVar7;
    local_14 = 0;
    local_18 = 0;
    local_16 = 100;
    sVar3 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar3 + 1;
    if ((ushort)(sVar3 - 5U) < 8) {
      FUN_801628f0(param_1,4,0x55,0x448,0,4,&local_18);
      FUN_801628f0(param_1,4,0x55,0x448,0,7,&local_18);
    }
    uVar5 = *(short *)(param_1 + 0x1e0) - 10;
    *(ushort *)(param_1 + 0x1e0) = uVar5;
    if ((int)((uint)uVar5 << 0x10) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x26f) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
    break;
  case 5:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000300;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    func_0x80077adc(0x4020001,param_1 + 0x28);
    func_0x80077adc(0x2290001,param_1 + 0x28);
  case 6:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    iVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    if (iVar2 + iVar1 != 0) {
      cVar6 = *(char *)(param_1 + 6) + '\x01';
LAB_80165da4:
      *(char *)(param_1 + 6) = cVar6;
    }
    break;
  case 7:
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000300;
    *(undefined2 *)(param_1 + 500) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 8:
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228),
                    0x10400);
    iVar2 = func_0x800331b8();
    iVar2 = (uint)*(ushort *)(param_1 + 500) - (iVar2 * 5 + 1);
    *(short *)(param_1 + 500) = (short)iVar2;
    if (iVar2 * 0x10000 < 0) {
      *(undefined1 *)(param_1 + 6) = 9;
    }
    break;
  case 9:
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 0x26f) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 10:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 0xb;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000300;
    }
    break;
  case 0xb:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                            *(undefined4 *)(param_1 + 0x218),0x10400);
    cVar6 = '\x04';
    if (iVar2 == 0) {
      iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                              *(undefined4 *)(param_1 + 0x218),0x10400);
      cVar6 = '\x04';
      if (iVar2 == 0) break;
    }
    goto LAB_80165da4;
  }
  if (*(char *)(param_1 + 0x206) != '\0') {
    func_0x80032dbc(param_1,*(undefined4 *)(iVar8 + 0x28),*(undefined4 *)(iVar8 + 0x30),0x20);
  }
  return;
}
