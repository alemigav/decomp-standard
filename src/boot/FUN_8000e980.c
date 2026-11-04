/* FUN_8000e980
 * image   boot (boot), base 0x80000480
 * address 0x8000e980  body 0x8000e980..0x8000e9cb  size 76 B
 * body sha256 467dd7988e459c901e17c70195d92edc2be4b5bed6d997901289212e634802d3
 * provider record sha256 31c2810ca0cab6ae64fb043cb491f474766acb63c183b19bafcbb6fb2622415e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e980(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_800072e0();
  puVar1 = _DAT_800129d4;
  *(undefined4 *)(_DAT_800129d4 + 4) = param_1;
  *puVar1 = 1;
  *(undefined4 *)(puVar1 + 6) = *(undefined4 *)(*(int *)(puVar1 + 4) + 4);
  FUN_80007300(uVar2);
  return;
}
