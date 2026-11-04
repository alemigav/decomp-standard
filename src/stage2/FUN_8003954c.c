/* FUN_8003954c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003954c  body 0x8003954c..0x80039737  size 492 B
 * body sha256 17823e02cd7e24d0415a90ad53b0b553ac36e05cdcb837b338c3cc7528e174b9
 * provider record sha256 3bab93541fe53a881ec6b5f45873ceda5244e19993c445b74426b085ac9334d2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003954c(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (param_1 != 0) {
    (*(code *)(&PTR_FUN_800eb9b0)[*DAT_800ebb94])();
  }
  if ((*(uint *)(DAT_800ebb94 + 0x1c) & 0xff00ff00) == 0x4001d00) {
    FUN_80039b5c(0xff,0xff,200);
  }
  FUN_80039738();
  (*(code *)(&PTR_FUN_800eb9b0)[DAT_800ebb94[1]])();
  pbVar5 = DAT_800ebb94;
  if ((*(ushort *)(DAT_800ebb94 + 0x18) & 2) != 0) {
    bVar1 = DAT_800ebb94[8];
    bVar2 = DAT_800ebb94[9];
    bVar3 = DAT_800ebb94[10];
    pbVar6 = DAT_800ebb94 + 0x26;
    sVar4 = *(short *)(DAT_800ebb94 + 0xe);
    *(short *)(DAT_800ebb94 + 0x24) =
         *(short *)(DAT_800ebb94 + 0x24) + *(short *)(DAT_800ebb94 + 0xc);
    *(short *)(pbVar5 + 0x26) = *(short *)pbVar6 + sVar4;
    *(short *)(pbVar5 + 0x28) = *(short *)(pbVar5 + 0x28) + *(short *)(pbVar5 + 0x10);
    *(short *)(pbVar5 + 0xc) = *(short *)(pbVar5 + 0xc) + (short)(char)bVar1;
    *(short *)(pbVar5 + 0xe) = sVar4 + (char)bVar2;
    *(short *)(pbVar5 + 0x10) = *(short *)(pbVar5 + 0x10) + (short)(char)bVar3;
  }
  if ((*(ushort *)(DAT_800ebb94 + 0x18) & 1) != 0) {
    if (DAT_800ebb94[0x20] == 0) {
      DAT_800ebb94[0x21] = DAT_800ebb94[0x21] + (DAT_800ebb94[0x19] & 1);
      pbVar5 = DAT_800ebb94;
      pbVar6 = (byte *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)DAT_800ebb94[0x21] * 8);
      if (pbVar6[2] == 0) {
        if (*pbVar6 == 0) {
          DAT_800ebb94[1] = 0;
          *pbVar5 = 0;
          pbVar5[0x18] = 0;
          pbVar5[0x19] = 0;
        }
      }
      else if (pbVar6[2] == 0xff) {
        DAT_800ebb94[0x21] = *pbVar6;
        pbVar6 = (byte *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)DAT_800ebb94[0x21] * 8);
      }
      DAT_800ebb94[0x20] = pbVar6[2];
    }
    DAT_800ebb94[0x20] = DAT_800ebb94[0x20] - 1;
  }
  return;
}
