/* FUN_800724fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800724fc  body 0x800724fc..0x80072547  size 76 B
 * body sha256 3820ec620ae8fba2ee80e65b99686fd4877edbff14ae2e06b563da0c4fd9726e
 * provider record sha256 561aa0aadc1ec68444794524da21d980efeaa1744b9f8f511ebc0e78c1a58640
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800724fc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800275c0(*(undefined1 *)(iVar1 + 1),(int)*(short *)(iVar1 + 2),0,0);
  *(int *)(param_1 + 0x1c) = iVar1 + 4;
  return 1;
}
