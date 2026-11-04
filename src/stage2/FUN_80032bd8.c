/* FUN_80032bd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032bd8  body 0x80032bd8..0x80032c6b  size 148 B
 * body sha256 5d890228fb08b8de28d10625bb8e69c235030024f8f8d8a8f6fcb0a994985a1d
 * provider record sha256 0f8b7c53877143cd57577b0bff00329c84cd76840230c0e6aaec5bafa299df1a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032bd8(int param_1,short param_2,short param_3)

{
  short local_38;
  short local_36;
  short local_34;
  undefined1 auStack_30 [32];
  
  local_38 = 0;
  local_36 = *(short *)(param_1 + 0x66) + param_2;
  local_34 = *(short *)(param_1 + 0x68) + param_3;
  FUN_80040e58(&local_38,auStack_30);
  FUN_8004276c(auStack_30,param_1 + 0x1e0,&local_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_38;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)local_36;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_34;
  return;
}
