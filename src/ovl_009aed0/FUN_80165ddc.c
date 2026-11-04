/* FUN_80165ddc
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80165ddc  body 0x80165ddc..0x80165fdf  size 516 B
 * body sha256 79e71888744328e4a72d8d995d49db8db3388a7bd1bd6be01b89431061b56df5
 * provider record sha256 b8028f6de1d162ccc5a55d84ad29361b0a009feb2f35344a69dbcd4a6f2e3280
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ddc(int param_1)

{
  short sVar1;
  char cVar5;
  short sVar4;
  int iVar2;
  int iVar3;
  ushort uVar6;
  
  sVar1 = *(short *)(*(int *)(param_1 + 0x250) + 0x66);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80077adc(0x4020001,param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000300;
    *(undefined2 *)(param_1 + 0x1f6) = 10;
    *(undefined2 *)(param_1 + 0x1e0) = 300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
  case 1:
    FUN_80163154(param_1,(int)sVar1);
    cVar5 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    uVar6 = *(short *)(param_1 + 0x1f6) - 1;
    *(ushort *)(param_1 + 0x1f6) = uVar6;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
    if ((int)((uint)uVar6 << 0x10) < 1) {
      sVar4 = *(short *)(param_1 + 0x1e0) + -0x19;
    }
    else {
      sVar4 = *(short *)(param_1 + 0x1e0) + -0xf;
    }
    *(short *)(param_1 + 0x1e0) = sVar4;
    if (*(short *)(param_1 + 0x1e0) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined1 *)(param_1 + 0x26f) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 3:
    iVar3 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    if (iVar3 + iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000300;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    break;
  case 4:
    iVar3 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                            *(undefined4 *)(param_1 + 0x218),0x10400);
    if ((iVar3 != 0) ||
       (iVar3 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                                *(undefined4 *)(param_1 + 0x218),0x10400), iVar3 != 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(undefined1 *)(param_1 + 0x26f) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
    }
  }
  if (*(char *)(param_1 + 0x206) != '\0') {
    func_0x80032ef4(param_1,(int)sVar1,0x20);
  }
  return;
}
