/* FUN_80165178
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165178  body 0x80165178..0x80165277  size 256 B
 * body sha256 8fc67a77eb70d266d2d0897f7c764e2c5cf19bcca4e552da5cb0caf3667c4405
 * provider record sha256 dc326a4609cbc35dc0d14862aaf4490cce3363d75f33fa2fca0ebebe92841660
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165178(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        if (bVar1 == 3) {
          param_1[1] = 0x1010000;
          *param_1 = *param_1 & 0xfffffff7;
          *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
          return;
        }
        return;
      }
      goto LAB_8016521c;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    *param_1 = *param_1 | 8;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  if (*(short *)(param_1 + 0x9c) != 1) {
    return;
  }
  *(undefined1 *)((int)param_1 + 0x1e9) = 0x1a;
  *(undefined1 *)(param_1 + 0x7a) = 0x10;
  func_0x800334c8(param_1,param_2,param_3,0);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
LAB_8016521c:
  *(undefined1 *)(param_1 + 0x7a) = 0x10;
  cVar2 = func_0x80036c68(param_1,0x10,7,0);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  return;
}
