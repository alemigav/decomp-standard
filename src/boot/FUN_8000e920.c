/* FUN_8000e920
 * image   boot (boot), base 0x80000480
 * address 0x8000e920  body 0x8000e920..0x8000e977  size 88 B
 * body sha256 ea2ab758bf8b050584ca0fb7c7dc4a7372617002fd67ae75862348f90dacace6
 * provider record sha256 b6f326a97dd1477f2574b19db2c03a42b7f45d6c61a80cc9aafb98931e9a1df7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e920(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_800072e0();
  iVar1 = _DAT_800129d4;
  *(undefined4 *)(_DAT_800129d4 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined2 *)(iVar1 + 2) = param_3;
  FUN_80007300(uVar2);
  return;
}
