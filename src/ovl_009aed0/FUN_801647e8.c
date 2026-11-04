/* FUN_801647e8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801647e8  body 0x801647e8..0x8016496b  size 388 B
 * body sha256 54ee36faa09f23cfed7dfd62cf541969863967cb847177370bfeb8e0ba8c9def
 * provider record sha256 76ffc4e188082092c0a755a426a54f2953dc5d16bb394f1375925e1dfb3a161c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801647e8(int param_1)

{
  char cVar2;
  short sVar1;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
    func_0x80036c68(param_1,10,0,0);
    *(undefined2 *)(param_1 + 500) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 1:
    if (*(short *)(param_1 + 0x270) == 1) {
      *(undefined1 *)(param_1 + 0x1e9) = 1;
      *(undefined1 *)(param_1 + 0x2d2) = 1;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      return;
    }
    return;
  case 2:
    *(undefined1 *)(param_1 + 0x1e8) = 10;
    if (*(byte *)(param_1 + 0x1e9) < 0x10) {
      func_0x80036c68(param_1,10,0,0);
      return;
    }
    if (*(short *)(param_1 + 0x270) == 2) {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      return;
    }
    return;
  case 3:
    *(undefined1 *)(param_1 + 0x1e8) = 10;
    cVar2 = func_0x80036c68(param_1,10,0,0);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    break;
  case 4:
    sVar1 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar1;
    if (5 < sVar1) {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    break;
  case 5:
    func_0x80036b84(param_1,10,3,1);
    break;
  default:
    goto switchD_80164818_default;
  }
  if (*(short *)(param_1 + 0x270) == 3) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
switchD_80164818_default:
  return;
}
