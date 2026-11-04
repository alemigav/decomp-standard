/* FUN_80166cbc
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166cbc  body 0x80166cbc..0x80166d57  size 156 B
 * body sha256 7d000cd4f54b59cabc7927ee780c6a0cda213cf18a46a4a3849e1f823661449d
 * provider record sha256 2442dac3b7f430930eb694eaeb5cbcb88d73bd331d06f8352d1d081ae1956a77
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166cbc(int param_1,short param_2,short param_3,short param_4)

{
  short local_38;
  short local_36;
  short local_34;
  undefined1 auStack_30 [32];
  
  local_38 = *(short *)(param_1 + 100) + param_2;
  local_36 = *(short *)(param_1 + 0x66) + param_3;
  local_34 = *(short *)(param_1 + 0x68) + param_4;
  func_0x80040e58(&local_38,auStack_30);
  func_0x8004276c(auStack_30,param_1 + 0x1e0,&local_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_38;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)local_36;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_34;
  return;
}
