/* FUN_80163508
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80163508  body 0x80163508..0x8016367b  size 372 B
 * body sha256 7a3cccb9e8ee111d7a03b6b615442aa5a9825cad8bd02d259a5116f2e4ba7c10
 * provider record sha256 8daf1f488de53749afd04433ea108d8ac53649ea2128f9b89e53bc5ccfd22895
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163508(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  byte bVar4;
  char cVar5;
  int iVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar2 = func_0x80033604();
    if ((uVar2 & 7) == 0) {
      FUN_801661d8(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    bVar4 = func_0x80033604();
    *(byte *)(param_1 + 0x2b5) = bVar4 & 0x3f;
    *(undefined1 *)(param_1 + 0x2b6) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar5 = *(char *)(param_1 + 0x2b6) + -1;
  *(char *)(param_1 + 0x2b6) = cVar5;
  if (cVar5 == -1) {
    *(undefined1 *)(param_1 + 0x2b6) = 0xe;
  }
  bVar1 = false;
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x60);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)*(char *)(param_1 + 0x2b4);
  func_0x80032bd8(param_1,0,0);
  func_0x80089d54(param_1,param_2,param_3,0x200);
  iVar3 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x60);
  if (iVar3 == 0) {
    bVar1 = true;
  }
  else {
    cVar5 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar5;
    if (cVar5 == -1) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_80165c68(param_1,4);
  }
  return;
}
