/* FUN_8007608c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007608c  body 0x8007608c..0x800761ab  size 288 B
 * body sha256 4f836ebc43008ca6afd6be2ec8cda2cfd7aafbb82fbee417de47131709c7b9fc
 * provider record sha256 56afdbb9a4cbc6b82383161b8bc34889a8872ac545924da85aa60231c928bb5a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007608c(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_8004cd88(1);
  if (-1 < DAT_80119eac) {
    FUN_80075608(4,1);
    DAT_80119eac = -1;
  }
  iVar1 = (param_1 & 0xff) * 2;
  uVar2 = DAT_800c52dc + 0x3210U & 0xfffffff0;
  DAT_80119edc = uVar2;
  do {
    func_0x80004cfc(*(undefined2 *)(&DAT_80115fd8 + iVar1),uVar2,1,"CORE EDH");
    DAT_80119eac = FUN_800752dc(*(undefined2 *)(&DAT_80115f60 + iVar1),4,1);
    DAT_8011a2a4 = (&PTR_DAT_80115f88)[param_1 & 0xff];
    FUN_8004cd88(1);
  } while (DAT_80119eac == -1);
  return;
}
