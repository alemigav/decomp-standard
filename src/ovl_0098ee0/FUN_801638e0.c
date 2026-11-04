/* FUN_801638e0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801638e0  body 0x801638e0..0x80163a2f  size 336 B
 * body sha256 5f9f8bdfd7327bb56fc0a39e096b782061da21bf2c730abda2e5cdff8ef0e467
 * provider record sha256 271a1964ac076d53b5c95bae7cd7bbeca4399dac9f5f2f809aa36a59c3684948
 * callees 7 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801638e0(int param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  
  FUN_801633bc();
  if ((_DAT_800e1322 < 0) || (0xed7 < *(uint *)(param_1 + 0x28c))) {
    FUN_801621c4(param_1);
    if (*(char *)(param_1 + 6) == '\0') {
      *(undefined2 *)(param_1 + 500) = 0;
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    else if (*(char *)(param_1 + 6) != '\x01') {
      return;
    }
    func_0x80036c68(param_1,8,0xf,0);
    if (*(int *)(param_1 + 0x1b0) != 0) {
      uVar1 = func_0x8006a42c(param_1 + 0x28);
      iVar2 = func_0x80032f64(param_1,(int)(((uVar1 & 0xffff) * 0x400 + 0x800) * 0x10000) >> 0x10,
                              0x50);
      if (iVar2 == 0) {
        *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
      }
      else if (*(short *)(param_1 + 500) < 0x10) {
        *(undefined2 *)(param_1 + 500) = 0;
      }
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
    if (0x3c < *(short *)(param_1 + 500)) {
      sVar3 = FUN_80162b88(param_1);
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar3 * 0x20;
      if (0x30 < *(short *)(param_1 + 500)) {
        *(undefined2 *)(param_1 + 500) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
