/* FUN_80165a48
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165a48  body 0x80165a48..0x80165b8b  size 324 B
 * body sha256 fcef4e33a29860440acceb49269596c650034939b86d202d9a09fb8fb7bb81bf
 * provider record sha256 16bf42faea15ea0d67c24bc4d0425f57590ed001e68f02d66229369f3be89b8f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165a48(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if (*(char *)((int)param_1 + 0x2d9) == '\0') {
    if (*(char *)((int)param_1 + 6) != '\0') {
      FUN_801656c0(param_1,param_2,param_3);
      goto LAB_80165b68;
    }
    FUN_80165310(param_1,3,6);
    FUN_80165310(param_1,3,6);
    *param_1 = *param_1 & 0xfffffffb;
    FUN_8016561c(param_1,param_2,param_3);
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
  }
  else {
    if (*(char *)((int)param_1 + 6) != '\0') {
      sVar1 = *(short *)(param_1 + 0x7d);
      *(short *)(param_1 + 0x7d) = sVar1 + -1;
      if (sVar1 == 1) {
        param_1[1] = 0x7000000;
      }
      goto LAB_80165b68;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0x78;
    FUN_80165310(param_1,3,6);
    FUN_80165310(param_1,3,6);
  }
  *(undefined1 *)((int)param_1 + 0x2c1) = 7;
  *(undefined1 *)((int)param_1 + 0x2c3) = 3;
  *(undefined2 *)(param_1 + 0xb5) = 1;
LAB_80165b68:
  FUN_80165d20(param_1);
  return;
}
