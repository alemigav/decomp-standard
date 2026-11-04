/* FUN_8016376c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x8016376c  body 0x8016376c..0x80163a97  size 812 B
 * body sha256 0b9dc772fcfb2f05a22f8afcb222027ff74880dd398a6d593dc0166de5a78bfc
 * provider record sha256 c18e980750c5a88e9aadead628466477b9badd631e3d546a220343d940663f61
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016376c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar3;
  uint uVar1;
  short sVar2;
  uint *puVar4;
  byte local_20 [8];
  
  local_20[0] = 0xe;
  local_20[1] = 0xe;
  local_20[2] = 0x10;
  local_20[3] = 0xf;
  puVar4 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(uint *)(param_1 + 0x1e8) = (uint)local_20[*(byte *)(param_1 + 0x2b4)] << 0x18;
    uVar1 = *puVar4;
    *puVar4 = uVar1 | 1;
    if (*(char *)(param_1 + 0x2b4) == '\x01') {
      *puVar4 = uVar1 | 0x4001;
      *(undefined1 *)(param_1 + 0x2b5) = 2;
      *(undefined2 *)(param_1 + 100) = 0;
    }
    else {
      *(undefined2 *)(param_1 + 100) = 0;
    }
    *(undefined2 *)(param_1 + 0x66) = 0;
    *(undefined2 *)(param_1 + 0x68) = 0;
    *(undefined2 *)(puVar4 + 0x49) = 0;
    break;
  case 1:
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    func_0x80077d18(0,param_1);
  case 2:
    cVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    sVar2 = *(short *)(puVar4 + 0x49);
    *(short *)(puVar4 + 0x49) = sVar2 + 0x100;
    if (0x1000 < (short)(sVar2 + 0x100)) {
      *(undefined2 *)(puVar4 + 0x49) = 0x1000;
    }
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 6) = 4;
    func_0x80077d18(2,param_1);
    *(undefined1 *)(param_1 + 0x2be) = 7;
  case 4:
    if (*(short *)(param_1 + 500) < 5) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + *(short *)(param_1 + 500) * -10;
    }
    if (*(ushort *)(param_1 + 500) - 6 < 0x1d) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 10;
    }
    if (*(short *)(param_1 + 500) == 0x24) {
      *(undefined1 *)(param_1 + 6) = 5;
    }
    goto LAB_80163a00;
  case 5:
    *(undefined2 *)(param_1 + 500) = 0;
    break;
  case 6:
    if (*(short *)(param_1 + 500) < 0x14) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 500);
    }
    if (*(ushort *)(param_1 + 500) - 0x10 < 0xa4) {
      uVar1 = func_0x80033604();
      *(uint *)(param_1 + 0x28) =
           *(int *)(param_1 + 0x28) + (uVar1 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
      uVar1 = func_0x80033604();
      *(uint *)(param_1 + 0x2c) =
           *(int *)(param_1 + 0x2c) + (uVar1 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
      uVar1 = func_0x80033604();
      *(uint *)(param_1 + 0x30) =
           *(int *)(param_1 + 0x30) + (uVar1 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
    }
    if (0xa0 < *(short *)(param_1 + 500)) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 5;
    }
    if (*(short *)(param_1 + 500) == 0xb4) {
      *(undefined1 *)(param_1 + 6) = 7;
    }
LAB_80163a00:
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    break;
  case 8:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    *(short *)(puVar4 + 0x49) = *(short *)(puVar4 + 0x49) + -0x40;
    if (*(byte *)(param_1 + 0x2b4) < 2) {
      sVar2 = *(short *)(param_1 + 0x66) + -0x10;
    }
    else {
      sVar2 = *(short *)(param_1 + 0x66) + 0x10;
    }
    *(short *)(param_1 + 0x66) = sVar2;
    if (*(short *)(puVar4 + 0x49) < 0x800) {
      *(undefined2 *)(puVar4 + 0x49) = 0;
      *(undefined1 *)(param_1 + 6) = 9;
      func_0x80077d18(0);
    }
  }
  return;
}
