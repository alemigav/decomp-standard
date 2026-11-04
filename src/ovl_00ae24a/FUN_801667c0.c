/* FUN_801667c0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801667c0  body 0x801667c0..0x8016680b  size 76 B
 * body sha256 632764893134fe0b5a2520d33e0281b36c48b6f2b4343cc830e0d02aa2add713
 * provider record sha256 dd065926446c0164e9c6154f0cd9f6bb6ab1b58147ea172099afdaf70dc2cbc9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801667c0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(&DAT_800e13e8 + (param_1 + 3) * 4);
  uVar1 = func_0x800844e4(param_2);
  *(undefined4 *)(iVar2 + 4) = uVar1;
  return;
}
