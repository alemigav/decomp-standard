/* FUN_80166408
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166408  body 0x80166408..0x801664c3  size 188 B
 * body sha256 81e7d4bae3db634fc9f4b32b495f0138d689dd8b30ab291e0794b5aaa93d9424
 * provider record sha256 08b3090853cb8c3c07107b1a6e5fa0a71b46f7a2c5a44f4ce3aa1265aeae510a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166408(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x7a] = 0x2003f00;
    *param_1 = *param_1 | 8;
  }
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
  func_0x8003331c(param_1,param_2,param_3,0);
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + -0x800;
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  *(char *)((int)param_1 + 5) = *(char *)((int)param_1 + 5) + cVar2;
  return;
}
