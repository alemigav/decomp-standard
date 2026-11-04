/* FUN_80164db8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164db8  body 0x80164db8..0x80164e1b  size 100 B
 * body sha256 684305dda0513df9d88d78bc30155510620c25cb36398eb4348f8a31c8ee65a1
 * provider record sha256 da481753a7111c0c296daf78bff57d537129c1e8c2743a4ee702aec4401c1f7a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164db8(uint *param_1)

{
  int iVar1;
  
  iVar1 = func_0x80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)((int)param_1 + 0x2bf) = 0;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    param_1[1] = 0x1000000;
    *param_1 = *param_1 | 0xc000000;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
  }
  return;
}
