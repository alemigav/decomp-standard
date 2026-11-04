/* FUN_8016ad10
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016ad10  body 0x8016ad10..0x8016b07f  size 880 B
 * body sha256 cfbda93d1bb2fb6cf4250211f450f761418c9c1c702c6a35cf168197525b3dd6
 * provider record sha256 05d510b275ca02ead0727c916832352fcf378753b6926f86904fb4cd96d61aca
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016ad10(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  
  switch(*(undefined1 *)(param_1 + 0x2c5)) {
  case 0:
    *(undefined1 *)(param_1 + 0x2c5) = 1;
    *(undefined2 *)(param_1 + 0x2c6) = 0;
  case 1:
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) + *(short *)(param_1 + 0x2c6);
    iVar5 = (int)*(short *)(param_1 + 0x2c6);
    if (iVar5 < 0) {
      iVar5 = iVar5 + 3;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0x14) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x14) + (short)(iVar5 >> 2);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + 4;
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) = *(short *)(*(int *)(param_2 + 0x120) + 0x18) >> 1
    ;
    if (0x400 < *(short *)(*(int *)(param_2 + 0x120) + 0x14)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x14) = 0x400;
    }
    if (0xc00 < *(short *)(*(int *)(param_2 + 0x120) + 0x10)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x10) = 0xc00;
      *(undefined1 *)(param_1 + 0x2c5) = 2;
    }
    break;
  case 2:
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) - *(short *)(param_1 + 0x2c6);
    *(short *)(*(int *)(param_2 + 0x120) + 0x14) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x14) + *(short *)(param_1 + 0x2c6);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + 8;
    if (0x1000 < *(short *)(*(int *)(param_2 + 0x120) + 0x14)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x14) = 0x1000;
      *(undefined1 *)(param_1 + 0x2c5) = 3;
      *(undefined2 *)(param_1 + 0x2c6) = 0;
      *(undefined1 *)(param_1 + 0x2ca) = 10;
      uVar4 = func_0x80033604();
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      *(ushort *)(param_1 + 0x2c8) = (uVar2 & 0xff) + (uVar1 & 0xff) + (uVar4 & 0xff) * 2 + 0x400;
    }
    break;
  case 3:
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) = *(short *)(*(int *)(param_2 + 0x120) + 0x10) >> 1
    ;
    *(short *)(*(int *)(param_2 + 0x120) + 0x14) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x14) - *(short *)(param_1 + 0x2c6);
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) + *(short *)(param_1 + 0x2c6);
    sVar3 = *(short *)(param_1 + 0x2c6) + 0x20;
    *(short *)(param_1 + 0x2c6) = sVar3;
    if (0x100 < sVar3) {
      *(undefined2 *)(param_1 + 0x2c6) = 0x100;
    }
    if (*(short *)(param_1 + 0x2c8) < *(short *)(*(int *)(param_2 + 0x120) + 0x18)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x18) = *(undefined2 *)(param_1 + 0x2c8);
      *(short *)(*(int *)(param_2 + 0x120) + 0x14) = 0x1000 - *(short *)(param_1 + 0x2c8);
      *(undefined1 *)(param_1 + 0x2c5) = 4;
      *(undefined2 *)(param_1 + 0x2c6) = 0;
      uVar4 = func_0x80033604();
      cVar6 = *(char *)(param_1 + 0x2ca) + -1;
      *(char *)(param_1 + 0x2ca) = cVar6;
      *(ushort *)(param_1 + 0x2c8) = *(short *)(param_1 + 0x2c8) - ((uVar4 & 0xff) + 0x264);
      if (cVar6 == -1) {
        *(undefined1 *)(param_1 + 0x2c5) = 5;
      }
    }
    break;
  case 4:
    *(short *)(*(int *)(param_2 + 0x120) + 0x14) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x14) + *(short *)(param_1 + 0x2c6);
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) - *(short *)(param_1 + 0x2c6);
    sVar3 = *(short *)(param_1 + 0x2c6) + 8;
    *(short *)(param_1 + 0x2c6) = sVar3;
    if (0x40 < sVar3) {
      *(undefined2 *)(param_1 + 0x2c6) = 0x40;
    }
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x18) < *(short *)(param_1 + 0x2c8)) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x14) = 0x1000 - *(short *)(param_1 + 0x2c8);
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x18) = *(undefined2 *)(param_1 + 0x2c8);
      *(undefined1 *)(param_1 + 0x2c5) = 3;
      *(undefined2 *)(param_1 + 0x2c6) = 0;
      uVar4 = func_0x80033604();
      *(ushort *)(param_1 + 0x2c8) = *(short *)(param_1 + 0x2c8) + (uVar4 & 0xff) + 0x2c8;
    }
    break;
  case 5:
    *(short *)(*(int *)(param_2 + 0x120) + 0x14) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x14) + -0x20;
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) + -0x20;
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x18) < 0) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x18) = 0;
    }
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x14) < 0) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x14) = 0;
    }
    if ((*(short *)(*(int *)(param_2 + 0x120) + 0x14) == 0) &&
       (*(short *)(*(int *)(param_2 + 0x120) + 0x18) == 0)) {
      *(undefined1 *)(param_1 + 0x2c4) = 0;
      *(undefined1 *)(param_1 + 0x2c5) = 0;
    }
  }
  return;
}
