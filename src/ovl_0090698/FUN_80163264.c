/* FUN_80163264
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163264  body 0x80163264..0x80163517  size 692 B
 * body sha256 e4b5d682504c5db58de2c63902602cf8f160c481a60d7e127f73727cd1cffda6
 * provider record sha256 24e4767a5be2bfd3bb8df3f46d53f1d04c0e57e6e5175957a98abd6a1da2e9de
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163264(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
  case 1:
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000300;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 0x1f) + 0x2d;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    sVar3 = FUN_80166b04(param_1,0x40);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar3;
    func_0x80089d54(param_1,param_2,param_3,0x400);
    if (sVar3 == 0) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000300;
    *(undefined1 *)(param_1 + 6) = 5;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 0x1f) + 10;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 300;
  case 5:
    sVar3 = FUN_80166b04(param_1,0x10);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar3;
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
    func_0x80089d54(param_1,param_2,param_3,0x400);
    cVar4 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar4 + -1;
    if (cVar4 == '\x01') {
      func_0x80077d18(3,param_1);
      FUN_801671ec(param_1,0x8a,(int)*(short *)(param_1 + 0x66));
      *(undefined1 *)(param_1 + 0x206) = 0xc;
    }
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    bVar1 = false;
    if ((sVar3 == -1) || (sVar3 = FUN_80166b04(param_1,0x200), sVar3 != 0)) {
      bVar1 = true;
    }
    if (((bVar1) || ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) || (*(char *)(param_1 + 0xd) != -1)) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000300;
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(undefined1 *)(param_1 + 6) = 7;
  case 7:
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    break;
  case 8:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined2 *)(param_1 + 0x2b4) = 0x3c;
  }
  FUN_80167938(param_1);
  return;
}
