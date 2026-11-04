/* FUN_80165310
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165310  body 0x80165310..0x8016539f  size 144 B
 * body sha256 497cc5cfaf2f3955de55620af973ad2082ffe37652cc1e6158ee68db99ce2303
 * provider record sha256 7d98a99727960e7cc8bb53568146750fc04d7b7fe474fb258e599d22593542f9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165310(undefined4 param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = func_0x80033604();
  if (param_3 != 0) {
    uVar2 = uVar1 & 7;
    do {
      uVar3 = uVar3 + 1;
      FUN_80166b98(param_1,(&DAT_80167230)[uVar2],param_2);
      uVar2 = (uVar1 & 7) + uVar3;
    } while (uVar3 < param_3);
  }
  return;
}
