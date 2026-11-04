/* FUN_80161d50
 * image   ovl_00b5e64 (ovl), base 0x80161cf0
 * address 0x80161d50  body 0x80161d50..0x80161df7  size 168 B
 * body sha256 325fdd3b6f4e8231aa2140611a7dd7b0a1d3164358ed95f80affb391bd16d3a3
 * provider record sha256 494ec8ce46db9d76b297bcaef25c558e5553eb7f2d3616682461cdf4bb57bba7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161d50(uint *param_1)

{
  param_1[1] = 0x2000000;
  param_1[0x7a] = 0;
  func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0);
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  param_1[0xa1] = 0;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  *(undefined1 *)(param_1[0x82] + 0xe) = 0;
  param_1[0xad] = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = 0;
  param_1[0xb0] = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  param_1[0xb5] = 0;
  param_1[0xb6] = 0;
  *param_1 = *param_1 | 10;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  return;
}
