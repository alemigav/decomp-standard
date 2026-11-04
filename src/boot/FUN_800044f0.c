/* FUN_800044f0
 * image   boot (boot), base 0x80000480
 * address 0x800044f0  body 0x800044f0..0x8000454f  size 96 B
 * body sha256 6ff62d2c5f124fff15a14a99d43b453c8d5ff66608fb72004b0a3792ecacdce5
 * provider record sha256 19239652563614ddd628cc71b81ba6e2f5b96a1a2308e72d5a9b39d5132349a4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800044f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_80012820;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (iVar1 == 0) {
    _DAT_80012820 = _DAT_8010b6f8;
  }
  FUN_800013b0(_DAT_80012820);
  uVar2 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return param_1;
}
