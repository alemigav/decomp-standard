/* FUN_80032b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032b5c  body 0x80032b5c..0x80032bd7  size 124 B
 * body sha256 582b8f95182952b7f1a7ed8ca0738e73b9e28b6772a3676b177ab7e4a458ea84
 * provider record sha256 550dc7aef8d87131ad886c82256081daec393213d4b991bc8c061df5131c6ee6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032b5c(int param_1,short param_2)

{
  short local_38;
  short local_36;
  short local_34;
  undefined1 auStack_30 [32];
  
  local_38 = 0;
  local_34 = 0;
  local_36 = *(short *)(param_1 + 0x66) + param_2;
  FUN_80040e58(&local_38,auStack_30);
  FUN_8004276c(auStack_30,param_1 + 0x1e0,&local_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_38;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_34;
  return;
}
