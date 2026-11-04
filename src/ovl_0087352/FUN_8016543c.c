/* FUN_8016543c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016543c  body 0x8016543c..0x8016558b  size 336 B
 * body sha256 e0750757548c922c0a2768b0b59783b43a58ee3637dc33da8519215cd5509a49
 * provider record sha256 ad51a2099cb90c553b5015ef5d4d4b37bf7fa091f28018c755fc8caa73e04737
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016543c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      func_0x80032bd8(param_1,0,0);
      func_0x80089d54(param_1,param_2,param_3,0x200);
      cVar2 = *(char *)((int)param_1 + 0x2b5) + -1;
      *(char *)((int)param_1 + 0x2b5) = cVar2;
      *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + -10;
      if (cVar2 == -1) {
        *param_1 = *param_1 & 0xfffffff7;
        FUN_80165c58(param_1,1,4);
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *param_1 = *param_1 | 0x80008;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  }
  if ((param_1[0x9c] & 0x40000) != 0) {
    param_1[0x7a] = 0x4000700;
    *(undefined2 *)(param_1 + 0x78) = 300;
    *(undefined1 *)((int)param_1 + 0x2b5) = 6;
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *param_1 = *param_1 & 0xfff7ffff;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
  }
  return;
}
