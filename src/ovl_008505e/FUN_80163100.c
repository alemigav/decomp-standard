/* FUN_80163100
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163100  body 0x80163100..0x8016313b  size 60 B
 * body sha256 6a5c1240588ec27e5da69791737d24741fb4c927db12e27c43893c24910da32b
 * provider record sha256 5f972c7c5703f8ef6e8113ca8d5ca879f911b7148e40c6262e1725fcddc2b79e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163100(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8016313c();
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 0x2ba) = 0;
  }
  return;
}
