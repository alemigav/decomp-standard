/* FUN_80163824
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163824  body 0x80163824..0x8016385f  size 60 B
 * body sha256 46e33cddd7a8d2ca430b165e96d84a5a8d49dccc7528250db0882071946b987d
 * provider record sha256 7093963a6daccc1127ceac611a780f1d48bcae6216f805689111875f8190a831
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163824(uint *param_1)

{
  if (_DAT_800e1322 < 0) {
    *(undefined1 *)((int)param_1 + 5) = 1;
    *(undefined2 *)((int)param_1 + 6) = 0;
    *param_1 = *param_1 | 0x4a;
  }
  return;
}
