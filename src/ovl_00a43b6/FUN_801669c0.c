/* FUN_801669c0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801669c0  body 0x801669c0..0x80166c63  size 676 B
 * body sha256 7e343c7ae0be1bebd4b649e68f9716b04d6cbf0e897e17b44a568418b0e2c3f4
 * provider record sha256 fde32643f9c6d8296bfabdc634b18dee792761279f103065eaf79f1054034f9f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801669c0(int param_1)

{
  short sVar3;
  uint uVar1;
  int iVar2;
  char cVar4;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x640) = 0x404040;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x7b8) = 0x606060;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 5;
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    break;
  case 1:
    cVar4 = *(char *)(param_1 + 0x1e9);
    if (cVar4 == '\x11') {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) & 0xffffbfff;
      cVar4 = *(char *)(param_1 + 0x1e9);
    }
    if (cVar4 == '\x0e') {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x758) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x758) & 0xffffbfff;
    }
    if (*(char *)(param_1 + 0x1e9) == '\v') {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) & 0xffffbfff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) & 0xffffbfff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) & 0xffffbfff;
    }
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),
                            *(undefined4 *)(param_1 + 0x230),0x200);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined2 *)(param_1 + 500) = 10;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
      *(undefined2 *)(param_1 + 0x1f6) = 5;
    }
    func_0x80032b5c(param_1,0);
    if (10 < *(byte *)(param_1 + 0x1e9)) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0x46;
    }
    break;
  case 2:
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x28) = (*(int *)(param_1 + 0x28) + 0x10) - (uVar1 & 0x1f);
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x30) = (*(int *)(param_1 + 0x30) + 0x10) - (uVar1 & 0x1f);
    break;
  case 3:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),
                            *(undefined4 *)(param_1 + 0x230),0x200);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    }
    func_0x80032b5c(param_1,0);
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -4;
    if (*(char *)(param_1 + 0x1e9) == '\x19') {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) | 0x4000;
    }
    if (*(char *)(param_1 + 0x1e9) == '\x1e') {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x758) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x758) | 0x4000;
    }
    break;
  case 4:
    *(undefined1 *)(param_1 + 6) = 0;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) | 0x4000;
  }
  return;
}
