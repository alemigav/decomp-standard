/* FUN_80165ec4
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165ec4  body 0x80165ec4..0x80166057  size 404 B
 * body sha256 89de0ec72729bcfa12888856d2ac16108d6f192a352bbae893bc28f1f6a8b5f8
 * provider record sha256 acad18dde655b00480ebea841f49db94cd482bb768460732df89cdb7a98f1811
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ec4(int param_1)

{
  char cVar4;
  short sVar3;
  int iVar1;
  int iVar2;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80077adc(0x4020001,param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 500;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
  case 1:
    func_0x80032b5c(param_1,0);
    cVar4 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      sVar3 = *(short *)(param_1 + 0x1e0) + -0x3c;
    }
    else {
      sVar3 = *(short *)(param_1 + 0x1e0) + -0x1e;
    }
    *(short *)(param_1 + 0x1e0) = sVar3;
    if (*(short *)(param_1 + 0x1e0) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 2:
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000300;
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined1 *)(param_1 + 0x26f) = 0;
  case 5:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    iVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    if (iVar2 + iVar1 != 0) {
      *(undefined1 *)(param_1 + 6) = 6;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000300;
    }
    break;
  case 6:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                            *(undefined4 *)(param_1 + 0x218),0x10400);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(undefined1 *)(param_1 + 0x26f) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
    }
  }
  return;
}
