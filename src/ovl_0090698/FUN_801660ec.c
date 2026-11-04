/* FUN_801660ec
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801660ec  body 0x801660ec..0x801661b7  size 204 B
 * body sha256 6a9287ef36be0decac1d0ea7b6a0de1f732eb68361c000bd59d6dea9605da49c
 * provider record sha256 1b2c041b7267d8ae97e6a16889db089daddbafa48b2543eadf9152230968edbb
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801660ec(int param_1)

{
  uint uVar1;
  
  *(undefined2 *)(param_1 + 500) = 0x800;
  *(undefined1 *)(param_1 + 6) = 1;
  *(undefined4 *)(param_1 + 0x1e8) = 0x1090000;
  func_0x80089d54();
  *(undefined1 *)(param_1 + 0x2bf) = 1;
  *(undefined2 *)(param_1 + 0x2b6) = 0;
  *(undefined2 *)(param_1 + 0x1e0) = 0x1e0;
  *(undefined2 *)(param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    *(short *)(param_1 + 500) = -*(short *)(param_1 + 100);
  }
  else {
    *(undefined2 *)(param_1 + 500) = 0;
    *(ushort *)(param_1 + 0x1f6) =
         (ushort)*(byte *)(param_1 + 0x2cc) * 0x400 - *(short *)(param_1 + 0x66);
  }
  FUN_80166248(param_1);
  FUN_8016703c(param_1,0x13,1);
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2004,(uVar1 & 3) + 6);
  return;
}
