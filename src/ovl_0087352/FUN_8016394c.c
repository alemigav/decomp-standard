/* FUN_8016394c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016394c  body 0x8016394c..0x80163b43  size 504 B
 * body sha256 d373caa860c67448a8313c56017dc97e1f9f783c04cc0482135395d7e465aaed
 * provider record sha256 e0545058f45c4c6d31f84f0f31ee2ad2f9145b2590a4eb5e6df94cf918806f96
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016394c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  short sVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    sVar4 = _DAT_800e138e + -0xa8c;
    *(short *)(param_1 + 0x2c0) = sVar4;
    if ((int)sVar4 - *(int *)(param_1 + 0x2c) < 0) {
      *(undefined1 *)(param_1 + 0x2b4) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x2b4) = 1;
    }
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar1 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar1;
  if (cVar1 == -1) {
    func_0x80077d18(1,param_1);
    *(undefined1 *)(param_1 + 0x2b6) = 0xe;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x60);
  if (*(short *)(param_1 + 0x1e0) < 300) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 5;
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    if ((int)*(short *)(param_1 + 0x2c0) < *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x28;
    }
  }
  else if (*(int *)(param_1 + 0x2c) < (int)*(short *)(param_1 + 0x2c0)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x28;
  }
  if (*(char *)(param_1 + 0xd) == '\0') {
    if (((int)*(short *)(param_1 + 0x2c0) - *(int *)(param_1 + 0x2c)) + 0x167U < 0x2cf) {
      if (*(short *)(param_1 + 0x1e0) < 0xe7) {
        bVar2 = func_0x80033604();
        *(byte *)(param_1 + 700) = bVar2 & 0x7f;
        uVar3 = func_0x80065628();
        *(undefined1 *)(param_1 + 699) = uVar3;
        FUN_80165c68(param_1,8);
      }
      else {
        FUN_80165c68(param_1,0xc);
      }
    }
  }
  else {
    func_0x80032bd8(param_1,0,0);
  }
  return;
}
