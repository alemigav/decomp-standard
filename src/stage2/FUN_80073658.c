/* FUN_80073658
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073658  body 0x80073658..0x800736a3  size 76 B
 * body sha256 92747162ee032edb938098e1fd2ceb8abd89a7f50c1268749ad03994d9cb6bc6
 * provider record sha256 50a7b791e69f9b0e42ec9fd8019a1a5a3ef6a2f54f6bcf2dcd3717eabbab6b94
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073658(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_80052d10(*(undefined2 *)(iVar1 + 4),*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3),
               *(undefined2 *)(iVar1 + 6));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 8;
  return 1;
}
