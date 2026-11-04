/* FUN_80049ff8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049ff8  body 0x80049ff8..0x8004a09f  size 168 B
 * body sha256 cb59340fb7dee0ee3c67aff53ce497f019bbaa518524be132951de0db456b888
 * provider record sha256 a73b4bb419e1b7948e5af08d61a713b39f324b78d211b38f3f46942ab8c5b9ef
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80049ff8(int param_1,int param_2,int param_3)

{
  undefined1 auStack_40 [32];
  int local_20;
  int local_1c;
  int local_18;
  
  FUN_800416bc(param_1,auStack_40);
  FUN_8004226c(auStack_40,param_2,param_3);
  local_20 = *(int *)(param_2 + 0x14) - *(int *)(param_1 + 0x14);
  local_1c = *(int *)(param_2 + 0x18) - *(int *)(param_1 + 0x18);
  local_18 = *(int *)(param_2 + 0x1c) - *(int *)(param_1 + 0x1c);
  FUN_800421b4(auStack_40,&local_20,&local_20);
  *(int *)(param_3 + 0x14) = local_20;
  *(int *)(param_3 + 0x18) = local_1c;
  *(int *)(param_3 + 0x1c) = local_18;
  return;
}
