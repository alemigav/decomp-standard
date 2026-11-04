/* FUN_801654e0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801654e0  body 0x801654e0..0x8016554f  size 112 B
 * body sha256 c96862904ea253f511a3e57f210929094c93b6f98cb428d40efd5609e9f609e9
 * provider record sha256 6baf3f403849126d7764cfe58592563eae7124dfaacd40deaf789d055db6f8a5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801654e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(char *)(param_1 + 6) == '\0') && (*(char *)(param_1 + 0x2db) == '\0')) {
    *(undefined1 *)(param_1 + 0x2db) = 0x3c;
    FUN_80165310(param_1,2,6);
  }
  FUN_80164e88(param_1,param_2,param_3);
  return;
}
