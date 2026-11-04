/* FUN_80011390
 * image   boot (boot), base 0x80000480
 * address 0x80011390  body 0x80011390..0x800113d7  size 72 B
 * body sha256 d5b9316eab4ada543e84946fb6de60ceec2d80818642b49be69ccfa34d0c2bf0
 * provider record sha256 afc084870eaad61dda4f4ca46dd6b26a3354a35a5715e86284a3d2f34556c2de
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80011390(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  *(undefined2 *)(_DAT_80012950 + 0x10) = 2;
  FUN_80000dd4(&DAT_80012948);
  FUN_80007300(uVar1);
  return;
}
