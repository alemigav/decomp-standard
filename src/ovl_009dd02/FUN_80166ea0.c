/* FUN_80166ea0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166ea0  body 0x80166ea0..0x80166f83  size 228 B
 * body sha256 17210be76679bcdc008d787a817057340be9dd6ca418b2388fa2fa63fa8873b9
 * provider record sha256 5b8c39b8aa0d847e1255cc5d9cc4b75cc060d5b3b69c74e49ec14631266b2170
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166ea0(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  short local_48;
  ushort local_46;
  short local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined1 auStack_38 [32];
  
  local_48 = *(short *)(param_2 + 100);
  iVar1 = *(int *)(param_2 + 0x234) + (uint)*(byte *)(param_2 + 0x25d) * 0x178;
  local_46 = *(short *)(iVar1 + 0x130) + *(short *)(param_2 + 0x66) + *(short *)(iVar1 + 0x5a) +
             (ushort)*(byte *)(param_2 + 0x2cd) * 0x800 & 0xfff;
  local_44 = *(short *)(param_2 + 0x68);
  func_0x80040e58(&local_48,auStack_38);
  local_3c = 0;
  local_3e = 0;
  local_40 = param_3;
  func_0x8004276c(auStack_38,&local_40,&local_48);
  *(int *)(param_1 + 0x28) = *(int *)(param_2 + 0x28) + (int)local_48;
  *(int *)(param_1 + 0x30) = *(int *)(param_2 + 0x30) + (int)local_44;
  return;
}
