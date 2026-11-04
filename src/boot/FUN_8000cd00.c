/* FUN_8000cd00
 * image   boot (boot), base 0x80000480
 * address 0x8000cd00  body 0x8000cd00..0x8000cd3f  size 64 B
 * body sha256 823c4e2367346b5ca8bd06de79fb423f3f36b6671f9ae826b6a25a6cb9480ab1
 * provider record sha256 65088d7ec32105c6470d31e6f986970c2754877d8239c10bc9e7649305595333
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cd00(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  _DAT_800128d0 = _DAT_800128d0 | param_1;
  FUN_80007300(uVar1);
  return;
}
