/* FUN_801652c8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801652c8  body 0x801652c8..0x80165327  size 96 B
 * body sha256 611d3272998be039f1b02229b4163ba64a2601a2f95001a205ba572426d250ea
 * provider record sha256 c6d407de76e560e14fc37d4cc46bc6f456613b2cd0bb72cbe0a089ad41e00691
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801652c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  }
  return;
}
