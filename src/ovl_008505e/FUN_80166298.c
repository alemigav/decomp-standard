/* FUN_80166298
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166298  body 0x80166298..0x8016632f  size 152 B
 * body sha256 df9422a33f0fe97df722e4b9ebde6ff2cdbd5477bd4e29de5a408a19322243ac
 * provider record sha256 0a5d46a619de3869f5a9c6cae5c566888e0ef3b5ad653fd4b2b86d097f084496
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166298(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_80165b38();
  uVar2 = 0;
  iVar1 = 0;
  do {
    uVar2 = uVar2 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = 0x3f203f;
    iVar1 = iVar1 + 0x178;
  } while (uVar2 < 0x11);
  *(undefined1 *)(param_1 + 699) = 0x14;
  *(undefined1 *)(param_1 + 0x207) = 0;
  uVar2 = func_0x80033604();
  FUN_80166980(param_1,uVar2 & 0xf,0xb);
  uVar2 = func_0x80033604();
  FUN_80166980(param_1,uVar2 & 0xf,0xc);
  FUN_80166980(param_1,1,0xc);
  return;
}
