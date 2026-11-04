/* FUN_8006bebc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bebc  body 0x8006bebc..0x8006bf47  size 140 B
 * body sha256 5b8ca4fcd74f401a53077be1eee02f8a06ef1b8d8134e3a6148e6eb45efd9e21
 * provider record sha256 284fa52d2df89dc5e0b04541e9f56d9e4c667ece5eae5ef5dce8873b134fcc88
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bebc(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar2 = &DAT_80112978;
  puVar1 = &DAT_801129c8;
  do {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (puVar1 != &DAT_80112a18);
  func_0x8000e980(&DAT_80112978);
  FUN_8006be10();
  if (DAT_801127b8 != 0) {
    func_0x8000ec60(param_1);
  }
  return;
}
