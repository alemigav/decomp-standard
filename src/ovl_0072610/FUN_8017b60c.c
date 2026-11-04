/* FUN_8017b60c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b60c  body 0x8017b60c..0x8017b79f  size 404 B
 * body sha256 5b36e4185c65c8d50445b2e7b3fb5b67bd98634d720f7a47a3ffe6711dfa05ba
 * provider record sha256 6975720b46769f9604673254657ef0edcff1db33d81462f8db5ca12094c174fc
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017b60c(undefined4 param_1)

{
  int iVar1;
  
  FUN_801800f0();
  iVar1 = -0x7fed0000;
  entry();
  DAT_80186c94 = &DAT_80185824;
  DAT_80184b30 = _DAT_8010b6e0;
  DAT_80184b34 = _DAT_8010b6e4;
  DAT_80185828 = FUN_8017b4d4(param_1);
  func_0x8009e9b0(*(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbaec),
                  *(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbaea),
                  *(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbae8),
                  *(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbae6),1);
  func_0x8009ec98(*(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbaec),
                  *(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbaea),
                  *(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbae8),
                  *(undefined2 *)(*(int *)(iVar1 + 0x44b0) * 0x112 + -0x7fecbae6),1);
  return;
}
