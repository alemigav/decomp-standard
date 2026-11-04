/* FUN_8007ecd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ecd8  body 0x8007ecd8..0x8007ed3f  size 104 B
 * body sha256 97e6a2fb0ddc52fbf1aed7db49ecff1e2b8da6fe9acd1b5e280aa60d68e8a244
 * provider record sha256 0e1b315ae07cc003aebdfe73543c2d6c3e7b88b54629abf55cb7863c55fbe6ff
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ecd8(int param_1)

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
