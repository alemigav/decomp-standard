/* FUN_80162c1c
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162c1c  body 0x80162c1c..0x80162d6b  size 336 B
 * body sha256 f9b696c9513b576fddb2161863e57a4f887d622a41573d7ca2d2b993038c35a1
 * provider record sha256 23146733da2177fc01f2fd9215287dc4b07d2034abfb2364c3fc2c180a07ee8e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c1c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(param_1 + 0x26f) & 0x7f) != 0) {
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) - 1;
    }
    (*(code *)(&PTR_FUN_8016682c)[*(byte *)(param_1 + 4)])
              (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
    if (*(char *)(param_1 + 0x2c6) != '\0') {
      *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + -1;
    }
    if (*(char *)(param_1 + 0x2c7) != '\0') {
      *(char *)(param_1 + 0x2c7) = *(char *)(param_1 + 0x2c7) + -1;
    }
    if (*(char *)(param_1 + 0x2c8) != '\0') {
      *(char *)(param_1 + 0x2c8) = *(char *)(param_1 + 0x2c8) + -1;
    }
    if (*(char *)(param_1 + 0x2c9) != '\0') {
      *(char *)(param_1 + 0x2c9) = *(char *)(param_1 + 0x2c9) + -1;
    }
    if (*(code **)(param_1 + 700) != (code *)0x0) {
      (**(code **)(param_1 + 700))(param_1);
    }
    if ((*(ushort *)(param_1 + 0x2c0) & 0x80) == 0) {
      func_0x80033648(param_1);
    }
    func_0x8004db5c(param_1);
    func_0x8004dcb8(param_1,0x400);
    iVar1 = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x34);
    iVar2 = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x38);
    uVar3 = func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
    *(undefined2 *)(param_1 + 0x2c2) = uVar3;
  }
  return;
}
