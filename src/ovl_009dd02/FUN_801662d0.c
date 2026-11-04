/* FUN_801662d0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801662d0  body 0x801662d0..0x80166407  size 312 B
 * body sha256 9bacd4da516bb6058a68642a710c9dcfaf9255e0546590462ec15124c5384ba5
 * provider record sha256 271abd9d3e940e4a008944cbac68093482e13150fbd591e660b40233ddf42ac3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801662d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
      func_0x8003331c(param_1,param_2,param_3,0);
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x800;
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
      if (iVar2 == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 5) = 2;
      *(undefined2 *)(param_1 + 6) = 0;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
  func_0x8003331c(param_1,param_2,param_3,0);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x800;
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1003f00;
  }
  return;
}
