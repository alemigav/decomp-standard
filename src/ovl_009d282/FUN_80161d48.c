/* FUN_80161d48
 * image   ovl_009d282 (ovl), base 0x80161cf0
 * address 0x80161d48  body 0x80161d48..0x80161daf  size 104 B
 * body sha256 e75f80451373b2ab28ecb57327b15a8195965e06a96bcb7ea2d34bf56951f142
 * provider record sha256 476090d590ff70d8c8b8d546f2fc6931e41f9546bf01bfdba8c9eefd66631310
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161d48(uint *param_1)

{
  param_1[1] = 0x1000000;
  func_0x80089d54();
  *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
  *param_1 = *param_1 | 0x44a;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  FUN_80161e1c(param_1);
  return;
}
