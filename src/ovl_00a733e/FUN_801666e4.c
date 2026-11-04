/* FUN_801666e4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801666e4  body 0x801666e4..0x80166833  size 336 B
 * body sha256 a0cbab0f055a0c1a88e94dcec6a3b79ab5d3ba6c5e012168e44c0efc0b24e355
 * provider record sha256 75419a1ef18877d3ee967804c77df93043850cc37e7bc432ca729028f6b54457
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801666e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    func_0x800334c8();
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined1 *)(param_1 + 0x207) = 0;
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 5) = 3;
      *(undefined2 *)(param_1 + 6) = 0;
    }
    func_0x80032b5c(param_1,0);
    func_0x80033648(param_1);
    if (((**(uint **)(param_1 + 0x214) & 0x10000) != 0) && (*(char *)(param_1 + 7) == '\0')) {
      *(undefined1 *)(param_1 + 7) = 1;
      func_0x80077d18(3,param_1);
      *(undefined1 *)(param_1 + 0x207) = 0xf;
    }
    if (*(char *)(param_1 + 0x207) != '\0') {
      FUN_80167374(param_1,0xe,1);
      FUN_80167374(param_1,0x10,1);
      *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
    }
    FUN_80167c1c(param_1);
  }
  return;
}
