/* FUN_8016326c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016326c  body 0x8016326c..0x80163307  size 156 B
 * body sha256 27160a5e32cac0266ce6fe1061c4196f1418ded6af759941366d508b95b5af94
 * provider record sha256 bdfaec7ef37203750011af82da30e13226ed7e508e3b4ccf9207eb4926c45416
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016326c(int param_1)

{
  short sVar1;
  
  (*(code *)(&PTR_FUN_80167e1c)[*(byte *)(param_1 + 6)])();
  sVar1 = (&DAT_80167d6c)[*(short *)(param_1 + 0x2b6) * 2];
  if (*(char *)(param_1 + 0x207) != '\0') {
    FUN_80167374(param_1,(int)sVar1 + 1U & 0xff,1);
    FUN_80167374(param_1,(int)sVar1 + 3U & 0xff,1);
    *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
  }
  return;
}
