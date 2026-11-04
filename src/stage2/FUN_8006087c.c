/* FUN_8006087c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006087c  body 0x8006087c..0x800608c7  size 76 B
 * body sha256 c17ce19efed0ae92c0098641f4fae00762ab5ce308ade122207e1ada62dcc4ec
 * provider record sha256 6be4612816f4c799335c1250528c4c970c358c5730deab558f2e1a54051f1aad
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006087c(int param_1,int param_2,int param_3,short *param_4)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = param_3 + (param_1 - param_2) & 0xfff;
  sVar1 = (short)param_2 - (short)param_3;
  if ((int)uVar2 < (param_3 << 0x10) >> 0xf) {
    *param_4 = (short)param_1;
    return 0;
  }
  if (uVar2 < 0x801) {
    sVar1 = sVar1 + (short)param_3 * 2;
  }
  *param_4 = sVar1;
  return 1;
}
