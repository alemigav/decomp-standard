/* FUN_80162084
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162084  body 0x80162084..0x801620fb  size 120 B
 * body sha256 126730e0d1c844783f5911a890b9c5e24d2e371d1e1c216f2ca62ee259b91128
 * provider record sha256 2ce1b45480f8f752951bf7e916699f699b644c7cfd4b9f50248d800344763422
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162084(uint *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  *(undefined2 *)((int)param_1 + 0x28a) = 400;
  *(undefined2 *)(param_1 + 0x19) = param_2;
  *(undefined2 *)((int)param_1 + 0x66) = param_3;
  *(undefined2 *)(param_1 + 0x1a) = param_4;
  *(undefined2 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)(param_1 + 0xb0) = 1;
  *param_1 = *param_1 | 0x800040c;
  if (_DAT_800e115c + -0xe10 < (int)param_1[0xb]) {
    *param_1 = *param_1 | 0x4000000;
  }
  return;
}
