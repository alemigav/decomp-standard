/* FUN_80080168
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080168  body 0x80080168..0x800801cf  size 104 B
 * body sha256 c3d7189d169cca8f91322ee63da29a8b8581180c094fc8185dc2b396529e2c15
 * provider record sha256 bb75e0bf0a757d351b7efcabf8296d8e70827cf8c6e1dd4a95ecd6f962c47a8f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80080168(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032f64(param_1,(int)DAT_800e1196,0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  else {
    FUN_80032ef4(param_1,(int)DAT_800e1196,0xa0);
  }
  return;
}
