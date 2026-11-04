/* FUN_80166684
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166684  body 0x80166684..0x8016680f  size 396 B
 * body sha256 a881fce308bca6e2213bd7e6741ad5785bb102b19186cbd5d1bfda67fd176f9d
 * provider record sha256 09d594aa41d6ab0e1445db1396a388da67c4eeaf502d31fb9bede7fa7b48b57c
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166684(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    sVar2 = *(short *)((int)param_1 + 0x1e2) + 0x48;
    *(short *)((int)param_1 + 0x1e2) = sVar2;
    param_1[0xb] = param_1[0xb] + (int)sVar2;
    func_0x8008a994(param_1,param_2,param_3,0x100);
    if (-1 < (int)(param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2) + 0x48)) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      func_0x80077d18(2,param_1);
      FUN_801629c0(param_1);
      *(undefined1 *)(param_1 + 0x7a) = 0;
      *param_1 = *param_1 & 0xfffffff7;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined1 *)((int)param_1 + 0x1e9) = 0;
      func_0x80036dc4(param_1,3,0,0);
      if (*(short *)(param_1 + 0x9c) != 0) {
        param_1[0x7a] = 0x13000f00;
        *(undefined2 *)(param_1 + 0x9c) = 0;
        *(undefined2 *)((int)param_1 + 0x1e2) = 0;
        *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      }
    }
  }
  else if (bVar1 == 2) {
    param_1[0xb] = 0;
    cVar3 = func_0x80036be4(param_1,0x13,0,0);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
  }
  else if (bVar1 == 3) {
    func_0x80036dc4(param_1,3,3,0);
    *(undefined1 *)((int)param_1 + 0x2ce) = 4;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
    if (*(short *)(param_1 + 0x9c) != 0) {
      param_1[1] = 0x10e0000;
    }
  }
  return;
}
