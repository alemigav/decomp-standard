/* FUN_8000ec10
 * image   boot (boot), base 0x80000480
 * address 0x8000ec10  body 0x8000ec10..0x8000ec53  size 68 B
 * body sha256 a7e03561031c67c00551da64c2ca8a9fcf1ebc1761d1b60bf843eb4c9a207e43
 * provider record sha256 9faf5e68ed8e92d8eaaa8968642098cf5e43f2b3d505a0df8426ccf2a9b62bf6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000ec10(undefined4 param_1)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_800072e0();
  puVar2 = _DAT_800129d4;
  uVar1 = *_DAT_800129d4;
  *(undefined4 *)(_DAT_800129d4 + 0x12) = param_1;
  *puVar2 = uVar1 | 4;
  FUN_80007300(uVar3);
  return;
}
