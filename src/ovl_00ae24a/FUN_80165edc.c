/* FUN_80165edc
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165edc  body 0x80165edc..0x801661eb  size 784 B
 * body sha256 626aae113ee144b1e8ea120f78b63d59fd5db78823656a0f67a761e7e61193ee
 * provider record sha256 c61391822e868e71451e027e9158d94629dfa6bcd14d189431f3e34d96e388f3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165edc(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  
  switch(*(undefined1 *)(param_1 + 0x2b5)) {
  case 0:
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 0x2b8) = (uVar1 & 0x1f) + 0x1e;
    *(undefined2 *)(param_1 + 0x2ba) = 6;
    *(undefined1 *)(param_1 + 0x2b7) = 0;
  case 1:
    sVar2 = *(short *)(*(int *)(param_2 + 0x120) + 0x18);
    if (sVar2 != 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x18) = sVar2 >> 1;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + *(short *)(param_1 + 0x2ba);
    if (((*(short *)(param_1 + 0x2ba) < 0xa2) &&
        (sVar2 = *(short *)(param_1 + 0x2ba) + 6, *(char *)(param_1 + 0x2b7) == '\0')) &&
       (*(short *)(param_1 + 0x2ba) = sVar2, 0xa1 < sVar2)) {
      *(undefined1 *)(param_1 + 0x2b7) = 1;
      *(undefined2 *)(param_1 + 0x2ba) = 0xa2;
    }
    if ((0x2134 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) &&
       (uVar1 = *(short *)(param_1 + 0x2ba) - 6, *(ushort *)(param_1 + 0x2ba) = uVar1,
       (int)((uint)uVar1 << 0x10) < 0)) {
      *(undefined1 *)(param_1 + 0x2b5) = 2;
      *(undefined2 *)(param_1 + 0x2ba) = 8;
      *(undefined1 *)(param_1 + 0x2b7) = 0;
    }
    break;
  case 2:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2ba);
    if (((*(short *)(param_1 + 0x2ba) < 0xc0) &&
        (sVar2 = *(short *)(param_1 + 0x2ba) + 8, *(char *)(param_1 + 0x2b7) == '\0')) &&
       (*(short *)(param_1 + 0x2ba) = sVar2, 0xbf < sVar2)) {
      *(undefined1 *)(param_1 + 0x2b7) = 1;
      *(undefined2 *)(param_1 + 0x2ba) = 0xc0;
    }
    if ((*(short *)(*(int *)(param_2 + 0x120) + 0xc) < -0x418) &&
       (uVar1 = *(short *)(param_1 + 0x2ba) - 8, *(ushort *)(param_1 + 0x2ba) = uVar1,
       (int)((uint)uVar1 << 0x10) < 0)) {
      *(undefined1 *)(param_1 + 0x2b5) = 1;
      *(undefined2 *)(param_1 + 0x2ba) = 6;
      *(undefined1 *)(param_1 + 0x2b7) = 0;
    }
    if (*(ushort *)(*(int *)(param_2 + 0x120) + 0xc) - 1 < 0x7ff) {
      *(undefined1 *)(param_1 + 0x2b5) = 6;
    }
    if (*(short *)(param_1 + 0x2b8) != 0) {
      *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + -1;
    }
    break;
  case 3:
    bVar3 = func_0x80033604();
    *(byte *)(param_1 + 0x2b7) = (bVar3 & 3) + 7;
    *(undefined1 *)(param_1 + 0x2b5) = 4;
    *(undefined2 *)(param_1 + 0x2ba) = 0;
  case 4:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + -0x858;
    sVar2 = *(short *)(param_1 + 0x2ba) + -1;
    *(short *)(param_1 + 0x2ba) = sVar2;
    if (sVar2 == -1) {
      *(undefined2 *)(param_1 + 0x2ba) = 2;
      uVar5 = 5;
LAB_801661d4:
      *(undefined1 *)(param_1 + 0x2b5) = uVar5;
    }
    break;
  case 5:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + 0x2c8;
    sVar2 = *(short *)(param_1 + 0x2ba) + -1;
    *(short *)(param_1 + 0x2ba) = sVar2;
    if (sVar2 == -1) {
      *(undefined1 *)(param_1 + 0x2b5) = 4;
      *(undefined2 *)(param_1 + 0x2ba) = 0;
      cVar4 = *(char *)(param_1 + 0x2b7) + -1;
      *(char *)(param_1 + 0x2b7) = cVar4;
      if (cVar4 == -1) {
        *(undefined1 *)(param_1 + 0x2b5) = 0;
      }
    }
    break;
  case 6:
    *(undefined1 *)(param_1 + 700) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 7;
  case 7:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(&DAT_80167418 + *(char *)(param_1 + 700) * 2) * -0x18 + 8000;
    cVar4 = *(char *)(param_1 + 700) + '\x01';
    *(char *)(param_1 + 700) = cVar4;
    uVar5 = 6;
    if (cVar4 != 'n') {
      return;
    }
    goto LAB_801661d4;
  }
  return;
}
