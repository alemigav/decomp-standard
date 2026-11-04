/* FUN_80162308
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162308  body 0x80162308..0x80162427  size 288 B
 * body sha256 3c5048d4392f992d8c22788d8fbc4a726a514cc75578f8f90c056f268011abd0
 * provider record sha256 770a43fb00b9394dcf40a602d35e294e2888bf75ccabde863b3100c1380d836b
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162308(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x2b4);
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 0x1e0) = (uVar1 & 0x3f) + 0x5a;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = uVar1 & 0x4e;
  }
  else if (*(char *)(param_1 + 7) != '\x01') goto LAB_801623bc;
  func_0x80032dbc(param_1,*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x30),
                  (int)*(char *)(param_1 + 0x2bf));
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)*(char *)(param_1 + 0x2ba);
  sVar2 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar2;
  *(char *)(param_1 + 0x2ba) = -*(char *)(param_1 + 0x2ba);
  if (sVar2 == -1) {
    *(undefined2 *)(param_1 + 6) = 0;
  }
LAB_801623bc:
  func_0x80032b5c(param_1,(int)*(char *)(param_1 + 0x2ba));
  iVar3 = func_0x80074d64(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
  if (iVar3 == 0) {
    iVar3 = FUN_80162c90(param_1);
    if (iVar3 == 0) {
      *(undefined1 *)(param_1 + 5) = 2;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  else {
    *(int *)(param_1 + 0x28) = (int)*(short *)(param_1 + 0x34);
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x36);
    *(int *)(param_1 + 0x30) = (int)*(short *)(param_1 + 0x38);
  }
  return;
}
