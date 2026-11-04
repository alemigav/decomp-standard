/* FUN_80165374
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165374  body 0x80165374..0x8016540f  size 156 B
 * body sha256 be13c17529e4fc3b7e89ae05a99f8f2bb60c0b826ee2ae3499bd7fd2407ea584
 * provider record sha256 93f97a10e7ccc943e3a79f0e46f2f07eb491efcd9b94da584a1e0755aefe32bf
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165374(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  func_0x800334c8();
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    *(undefined1 *)(param_1 + 0x2ba) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)(param_1 + 699) = *(undefined1 *)(param_1 + 6);
    *(undefined1 *)(param_1 + 700) = *(undefined1 *)(param_1 + 7);
  }
  func_0x80032b5c(param_1,0);
  return;
}
