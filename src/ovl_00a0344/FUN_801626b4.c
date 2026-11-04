/* FUN_801626b4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801626b4  body 0x801626b4..0x80162753  size 160 B
 * body sha256 57caa860a8f8f36df2c74e703a27e2b12ecebb2cdfd833eb8bd06ec871b7b22d
 * provider record sha256 a0a982323e91577bc838279843ee7b971c47c9b690b495a1f7da32e4c6b65235
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801626b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) * 0x10000 + 0x5000700;
    *(undefined2 *)(param_1 + 0x2c2) = 0;
    *(undefined2 *)(param_1 + 700) = *(undefined2 *)(param_1 + 0x2c0);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_8016375c(param_1,0);
  return;
}
