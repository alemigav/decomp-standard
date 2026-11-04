/* func_800b23fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b23fc  body 0x800b23fc..0x800b245f  size 100 B
 * body sha256 9e6570c9bb20d52e8d1dd12d4510f6ad0d153e9f17d99fced468273884413f21
 * provider record sha256 d8446b68cada0f537c608caf953c5d26f46ef39726a7c84ca68d152e747ac826
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b23fc(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a777c(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
