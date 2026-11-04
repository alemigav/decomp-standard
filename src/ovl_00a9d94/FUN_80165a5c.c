/* FUN_80165a5c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80165a5c  body 0x80165a5c..0x80165b2b  size 208 B
 * body sha256 d5f842ec51a741a561894df0069cbaee7e15b37008a81e877a2d35aedc5efe7e
 * provider record sha256 ec70bca11b3da0235f6d5b7a4573334eace86fa628d8a130eed94ce8b2e76a28
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165a5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x12000f00;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if ((iVar1 != 0) && (*(undefined4 *)(param_1 + 4) = 0x1030000, _DAT_800e1322 < 0)) {
    *(undefined4 *)(param_1 + 4) = 0x10a0000;
  }
  func_0x80032b5c(param_1,0);
  return;
}
