/* FUN_8000d360
 * image   boot (boot), base 0x80000480
 * address 0x8000d360  body 0x8000d360..0x8000d3cb  size 108 B
 * body sha256 b0ba906131736abef1c8281f51406e617a780600d836387e7eab3b15b0a6901e
 * provider record sha256 047126f870eb10cfdab8f88bba81c06f9fe09606628f619eb593593ee5e53488
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8000d360(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 & 3) != 0) {
    FUN_8000c620(0x80011cc0,0x80011cc4,0x34);
  }
  iVar1 = FUN_8000d2b0();
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 | 0xa0000000) = param_2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
