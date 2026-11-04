/* FUN_80165178
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165178  body 0x80165178..0x8016525f  size 232 B
 * body sha256 6473cb6a49fec21fbc5460921af5c71073d9936ec3e7a890e7ae70e2211d76d0
 * provider record sha256 7b73ea293a3cd2d9cf03097aac4eded37013af4e71c3a912096ba5cbd0da6c5e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165178(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_8016703c(param_1,(&DAT_80167f18)[uVar1 & 3],3);
    uVar1 = func_0x80033604();
    if (((int)(uint)*(byte *)(param_1 + 700) >> (uVar1 & 7) & 1U) == 0) {
      FUN_8016703c(param_1,(uVar1 & 7) * 2 + 3,3);
    }
    if (((*(char *)(param_1 + 0x1ed) < '\0') || (*(char *)(param_1 + 0x1ee) < '\0')) ||
       (*(char *)(param_1 + 0x1ef) < '\0')) {
      FUN_8016753c(param_1);
      *(undefined1 *)(param_1 + 0x1ed) = 6;
      *(undefined1 *)(param_1 + 0x1ee) = 6;
      *(undefined1 *)(param_1 + 0x1ef) = 6;
    }
  }
  FUN_801647c8(param_1,param_2,param_3);
  return;
}
