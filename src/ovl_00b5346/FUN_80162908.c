/* FUN_80162908
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162908  body 0x80162908..0x8016294f  size 72 B
 * body sha256 2f89d8ef03f5f48fc270bfd1d717ba5a7e2b27460a64cd56282b6fae5034bd18
 * provider record sha256 476745d6c4724cb6e41782079151279bdb7e88c6e7ca1657af9d0ca264fdb1c1
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162908(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  if (*(char *)(param_1 + 0x2b7) == '\0') {
    uVar2 = func_0x80036ed8(param_1,0,0x3b,0);
    *(undefined1 *)(param_1 + 0x2b6) = uVar2;
    cVar1 = '\x0f';
  }
  else {
    cVar1 = *(char *)(param_1 + 0x2b7) + -1;
  }
  *(char *)(param_1 + 0x2b7) = cVar1;
  return;
}
