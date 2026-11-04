/* FUN_8004c4a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c4a0  body 0x8004c4a0..0x8004c563  size 196 B
 * body sha256 cc11084fc1c15c60e337a930deda8b00415779f6ac2f0980f17eaed4d910edb1
 * provider record sha256 e88b44fc1955f9ebc114fe72c7fe25372591ad786477368dbcdd8be9002d0af8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004c4a0(int param_1)

{
  short *psVar1;
  short sVar4;
  int iVar2;
  uint uVar3;
  short *psVar5;
  short *psVar6;
  
  psVar5 = *(short **)(param_1 + 0xd008);
  psVar1 = (short *)(param_1 + 0xc808);
  if (psVar5 != psVar1) {
    do {
      sVar4 = FUN_800844cc((int)*psVar1);
      psVar6 = psVar1 + 2;
      iVar2 = FUN_800844cc((int)psVar1[1]);
      iVar2 = (int)sVar4 + iVar2 * 0x10000;
      uVar3 = FUN_800844cc((int)*psVar6);
      if ((uVar3 & 0x200) == 0) {
        psVar1 = (short *)FUN_8004c564(psVar6,iVar2,param_1);
      }
      else {
        psVar1 = (short *)FUN_8004c70c(psVar6,iVar2,param_1);
      }
    } while (psVar1 < psVar5);
  }
  return;
}
