/* FUN_80162d54
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162d54  body 0x80162d54..0x80162e83  size 304 B
 * body sha256 570d6e8b1dfb2092ceedacd6dfd4526c236c7b868bcec8de23a28d1a537f1f5e
 * provider record sha256 b4501839371170962cd4b876c925b2110ea8b9e7fc17c064c0f61d65d00a1ec1
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162d54(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
      uVar1 = func_0x80033604();
      uVar2 = 3;
      if ((uVar1 & 7) == 0) {
        FUN_801661d8(param_1,1);
        uVar2 = 3;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1e8) = 0x3000700;
      uVar2 = 2;
    }
    *(undefined1 *)(param_1 + 0x2b4) = uVar2;
    bVar3 = func_0x80033604();
    *(byte *)(param_1 + 0x2b5) = bVar3 & 0x1f;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  func_0x80032bd8(param_1,0,0);
  if (*(short *)(param_1 + 0x1e0) < 300) {
    *(ushort *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + (ushort)*(byte *)(param_1 + 0x2b4);
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  cVar4 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar4;
  if (cVar4 == -1) {
    *(undefined1 *)(param_1 + 6) = 0;
  }
  return;
}
