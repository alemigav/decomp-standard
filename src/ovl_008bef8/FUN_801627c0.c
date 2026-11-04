/* FUN_801627c0
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801627c0  body 0x801627c0..0x80162803  size 68 B
 * body sha256 9ce5029df379fe71f93e17ce528470e1e59900220d15b1f71f40e387e0f59a31
 * provider record sha256 c1bb4e35a0a153cdbb1cc844511a57aee232165e381caa8f88a8ded5c71d3569
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627c0(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 6) == '\0') && (iVar1 = func_0x80036c68(param_1,1,4,0), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
