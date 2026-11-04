/* FUN_8017ee88
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017ee88  body 0x8017ee88..0x8017eed3  size 76 B
 * body sha256 ec771453f3873bc6791da07e60d5c0970f7592ade13eb2076edf02b4eba87c39
 * provider record sha256 8411a52add75e87eb866511cb3185e2a8864f17d6752cf0b2660ca8dbba12c45
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017ee88(int param_1)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  
  psVar3 = (short *)(&DAT_80185c5c + param_1 * 0x80);
  psVar2 = (short *)(&DAT_80186694 + param_1 * 0x80);
  iVar4 = 0;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    iVar4 = iVar4 + 1;
    *psVar3 = *psVar3 + sVar1;
    psVar3 = psVar3 + 1;
  } while (iVar4 < 0x40);
  return;
}
