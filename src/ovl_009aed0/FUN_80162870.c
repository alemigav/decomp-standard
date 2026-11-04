/* FUN_80162870
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162870  body 0x80162870..0x801628ef  size 128 B
 * body sha256 83a1c9e45eba56adbcf6c9ce918db9044bd4e4f3d4c6ada34c21d1af54c54fe5
 * provider record sha256 667e268d70ab029032099f5b506a9797ec9ebe41f63b73f1d5a7a4c237ea044e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80162870(uint param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  if ((0x20 < *param_2) || (uVar1 = *param_2 - 1, *param_2 = uVar1, uVar1 == 0)) {
    param_1 = param_1 & 0xff;
    *param_2 = param_1;
    uVar1 = func_0x80033604();
    if (param_1 == 0) {
      trap(0x1c00);
    }
    *param_3 = 0x80000000 >> ((uVar1 & 0xff) % param_1 & 0x1f);
  }
  uVar1 = *param_3;
  *param_3 = uVar1 << 1;
  return uVar1 >> 0x1f;
}
