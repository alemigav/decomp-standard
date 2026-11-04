/* FUN_80163604
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163604  body 0x80163604..0x801636b7  size 180 B
 * body sha256 305e1c9c24ca62c1909bb4a7931593a81366d9f1b3ea0ebdb37728a1afb8f7cc
 * provider record sha256 84e5d9d1d686850c792814ca85d2e87eadc0e50af526d75cac5c684fe89c0749
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163604(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar3 = func_0x80033604();
    bVar1 = (&DAT_80166c88)[uVar3 & 7];
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(ushort *)(param_1 + 500) = (ushort)bVar1;
  }
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  func_0x80089d54(param_1,param_2,param_3,0x80);
  FUN_801664d8(param_1);
  return;
}
