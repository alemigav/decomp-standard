/* FUN_80164af0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164af0  body 0x80164af0..0x80164b4f  size 96 B
 * body sha256 c1c30c23788eab4a947f933dde0281890c48da1abbbaf6c2b516a6ff30619323
 * provider record sha256 53face2487bba91790830fa7df862ebc98be6c7ee9b4fc08750f6c92e00a296c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164af0(uint *param_1,undefined2 param_2)

{
  if ((DAT_800e9012 & 8) == 0) {
    *param_1 = 0;
  }
  else {
    *param_1 = *param_1 | 0x4a;
  }
  *(undefined2 *)(param_1 + 0x4d) = 800;
  *(undefined2 *)((int)param_1 + 0x136) = 10;
  *(undefined2 *)(param_1 + 0x4c) = param_2;
  *(undefined2 *)(param_1 + 0x4e) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)(param_1 + 0x4f) = 0xff9c;
  param_1[0x18] = 0x101040;
  return;
}
