/* FUN_801656c0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801656c0  body 0x801656c0..0x8016576f  size 176 B
 * body sha256 d98fbdcaef3094397425fe9881c5b0d3a20f7598dde72138b781aa44f1e6664b
 * provider record sha256 ee14a30ea0f66f8324c9220eb8192631d6b1db04aa698c34123a4953538e0636
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801656c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  func_0x800334c8();
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  }
  func_0x80032b5c(param_1,0);
  func_0x80033648(param_1);
  if (*(char *)(param_1 + 0x2d9) == '\0') {
    *(undefined1 *)(param_1 + 0x2c1) = 6;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
    *(undefined1 *)(param_1 + 0x2c1) = 0x41;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  return;
}
