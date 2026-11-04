/* FUN_80163740
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80163740  body 0x80163740..0x801638df  size 416 B
 * body sha256 24b3b23f96cd1a96487a488221ef9cfeee3591a00d1f5b9a6a9d23bf630d78a7
 * provider record sha256 102a4ee56e7b20da41940d35da9418d5b7c90c8a8c739a8e61a3fc6651793a2b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163740(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  byte bVar3;
  char cVar4;
  int iVar1;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80077d18(3,param_1);
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  case 1:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
  case 2:
    sVar2 = *(short *)(param_1 + 0x2c0) + 0x14;
    *(short *)(param_1 + 0x2c0) = sVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar2;
    iVar1 = *(short *)(param_1 + 0x25e) + -0xfa;
    if (iVar1 < *(int *)(param_1 + 0x2c)) {
      func_0x80077d18(5,param_1);
      *(int *)(param_1 + 0x2c) = iVar1;
      *(undefined4 *)(param_1 + 0x1e8) = 0xb000700;
      bVar3 = func_0x80033604();
      *(byte *)(param_1 + 0x2b5) = bVar3 & 0xf;
      *(undefined2 *)(param_1 + 0x68) = 0;
      *(undefined1 *)(param_1 + 6) = 3;
    }
    break;
  case 3:
    cVar4 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 0x1e9) = *(char *)(param_1 + 0x1e9) + -1;
    break;
  case 4:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      FUN_80165c58(param_1,1,9);
    }
  }
  return;
}
