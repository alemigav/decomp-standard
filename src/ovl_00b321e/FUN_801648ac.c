/* FUN_801648ac
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801648ac  body 0x801648ac..0x8016490b  size 96 B
 * body sha256 bad05d216548e60a13e66f55b13cd941320b0622205c60dbfb16b8b5ff892a8d
 * provider record sha256 829a5b8cdf196318aa20a26ad222c6e51b3faae19401c7c86e1ebe272f8d6c2b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801648ac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x80033604();
  FUN_80166270(param_1,iVar1 + 1U & 1,0);
  FUN_801643d4(param_1,param_2,param_3);
  return;
}
