/* FUN_8000ec60
 * image   boot (boot), base 0x80000480
 * address 0x8000ec60  body 0x8000ec60..0x8000eca3  size 68 B
 * body sha256 67a9f8314fcd8babac2c434113bd0b8952d57c7cff0e2bae4d41ee7fb6a63cee
 * provider record sha256 d7e519d7206a8f1aca2cc630626ff64da2710fef1cf541674d3986a996bfc79c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000ec60(undefined4 param_1)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_800072e0();
  puVar2 = _DAT_800129d4;
  uVar1 = *_DAT_800129d4;
  *(undefined4 *)(_DAT_800129d4 + 2) = param_1;
  *puVar2 = uVar1 | 0x10;
  FUN_80007300(uVar3);
  return;
}
