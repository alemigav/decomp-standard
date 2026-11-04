/* FUN_80039228
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039228  body 0x80039228..0x8003954b  size 804 B
 * body sha256 c01e8d985d62b31a658c3a671acba385c4e566a17d1428303ae8d81df44287d6
 * provider record sha256 1301881529e2901fb16c416cc7f7c6f675d8a637bd8c518cd464fe8f2096bdde
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039228(void)

{
  byte bVar1;
  byte *pbVar2;
  
  if ((DAT_800e1110 & 0x10000000) == 0) {
    DAT_800ebb94 = &DAT_800ebda8;
    do {
      pbVar2 = DAT_800ebb94;
      if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x8000) != 0) {
        if ((DAT_800ebb94[0x1a] != 0) && ((&DAT_800ebdc0)[(uint)DAT_800ebb94[0x1a] * 0x3e] == 0)) {
          DAT_800ebb94[1] = 0;
          *pbVar2 = 0;
          pbVar2[0x18] = 0;
          pbVar2[0x19] = 0;
        }
        (*(code *)(&PTR_FUN_800eb9b0)[*DAT_800ebb94])();
      }
      DAT_800ebb94 = DAT_800ebb94 + 0x7c;
    } while (DAT_800ebb94 < &UNK_800eec28);
    DAT_800ebb94 = &DAT_800ebda8;
    do {
      if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x4000) != 0) {
        bVar1 = *DAT_800ebb94;
        pbVar2 = DAT_800ebb94;
        pbVar2[0x18] = 0xa0;
        pbVar2[0x19] = 3;
        (*(code *)(&PTR_FUN_800eb9b0)[bVar1])();
      }
      if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x8000) != 0) {
        FUN_8003954c(0);
      }
      DAT_800ebb94 = DAT_800ebb94 + 0x7c;
    } while (DAT_800ebb94 < &UNK_800eec28);
  }
  else {
    DAT_800ebb94 = &DAT_800ebda8;
    do {
      pbVar2 = DAT_800ebb94;
      bVar1 = DAT_800ebb94[0x1c];
      if (((((bVar1 == 0x1a) || (bVar1 == 0x1c)) || (bVar1 == 0x28)) ||
          ((bVar1 == 0x15 || (bVar1 == 0x16)))) &&
         ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x8000) != 0)) {
        if ((DAT_800ebb94[0x1a] != 0) && ((&DAT_800ebdc0)[(uint)DAT_800ebb94[0x1a] * 0x3e] == 0)) {
          DAT_800ebb94[1] = 0;
          *pbVar2 = 0;
          pbVar2[0x18] = 0;
          pbVar2[0x19] = 0;
        }
        (*(code *)(&PTR_FUN_800eb9b0)[*DAT_800ebb94])();
      }
      DAT_800ebb94 = DAT_800ebb94 + 0x7c;
    } while (DAT_800ebb94 < &UNK_800eec28);
    DAT_800ebb94 = &DAT_800ebda8;
    do {
      bVar1 = DAT_800ebb94[0x1c];
      if ((((bVar1 == 0x1a) || (bVar1 == 0x1c)) || (bVar1 == 0x28)) ||
         ((bVar1 == 0x15 || (bVar1 == 0x16)))) {
        if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x4000) != 0) {
          bVar1 = *DAT_800ebb94;
          pbVar2 = DAT_800ebb94;
          pbVar2[0x18] = 0xa0;
          pbVar2[0x19] = 3;
          (*(code *)(&PTR_FUN_800eb9b0)[bVar1])();
        }
        if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x8000) != 0) {
          FUN_8003954c(0);
        }
      }
      DAT_800ebb94 = DAT_800ebb94 + 0x7c;
    } while (DAT_800ebb94 <= &UNK_800eec27);
  }
  return;
}
