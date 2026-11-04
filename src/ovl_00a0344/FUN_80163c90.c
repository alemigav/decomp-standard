/* FUN_80163c90
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163c90  body 0x80163c90..0x80163cef  size 96 B
 * body sha256 18e8e066886d75bab34eaeb1d9cb304e5cd89401d6ae494172714c0b60065255
 * provider record sha256 61625a45399254be72264e6f1d462a5ccd1fc00c22d664e17bc067c1a3c15862
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163c90(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x2cc) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x234);
    func_0x80036290(param_1,uVar1,&DAT_80163e68);
    func_0x80036290(param_1,uVar1,&DAT_80163ed4);
    func_0x80036694(param_1);
  }
  return;
}
