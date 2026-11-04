/* FUN_8007ed40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ed40  body 0x8007ed40..0x8007edbf  size 128 B
 * body sha256 806be2d9ed77af1f39f43a71d4b0a07dbfebba57a95bd43a70011b0c70045ade
 * provider record sha256 d7d0728d95925fb94d0c0ec15856fa4eb63c43aaebbfa3b96a979783f4efffd9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ed40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032f64(param_1,(int)((DAT_800e1196 + 0x800) * 0x10000) >> 0x10,0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  else {
    FUN_80032ef4(param_1,(int)((DAT_800e1196 + 0x800) * 0x10000) >> 0x10,0xa0);
  }
  return;
}
