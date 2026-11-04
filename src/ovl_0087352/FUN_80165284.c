/* FUN_80165284
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165284  body 0x80165284..0x8016543b  size 440 B
 * body sha256 79a54bc8b5beb502fbe5583d561d21fe14e38ba40cc15f84d58d9a7770576e13
 * provider record sha256 cf0bc110f1027c000480f7ba179ddd765a4af555d66503f3a3d6950038fb9ae3
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165284(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    func_0x80032dbc(param_1,0xffffcf2c,0xffffcdcc,0x60);
    func_0x80032bd8(param_1,0,0);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    cVar2 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar2;
    if (cVar2 == -1) {
      func_0x80077d18(1,param_1);
      *(undefined1 *)(param_1 + 0x2b5) = 0x3c;
      *(undefined1 *)(param_1 + 0x2b6) = 5;
      *(undefined1 *)(param_1 + 6) = 2;
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && ((*(ushort *)(param_1 + 0x270) & 2) != 0)) {
      *(undefined2 *)(param_1 + 0x270) = 0;
      FUN_80166294(param_1,0x32);
      *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
      *(undefined2 *)(param_1 + 0x1e0) = 300;
      *(undefined2 *)(param_1 + 0x1e2) = 0xffec;
      *(undefined1 *)(param_1 + 0x2b5) = 3;
      *(undefined1 *)(param_1 + 6) = 1;
      func_0x80077d18(1);
    }
  }
  else if (bVar1 == 2) {
    func_0x80032dbc(param_1,0xfffff0b1,0xffffd000,0x60);
    func_0x80032bd8(param_1,0,0);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    cVar2 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar2;
    if (cVar2 == -1) {
      *(undefined1 *)(param_1 + 700) = 0xff;
      *(undefined1 *)(param_1 + 699) = 0;
      FUN_80166294(param_1,0x15e);
      FUN_80165c58(param_1,1,4);
    }
  }
  return;
}
