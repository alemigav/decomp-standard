/* FUN_800981d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800981d8  body 0x800981d8..0x800986a3  size 1228 B
 * body sha256 0d56cd60e66eb11f67f3aa4f1bb6310968bb38c096917ab8b5c29290af06f334
 * provider record sha256 f6ddd5b9707d9078f4c96e70fc1138d9c53230b49b4c4a9e317bdc9c551393f1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800981d8(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short *psVar4;
  char cVar5;
  int iVar6;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  
  iVar1 = DAT_800c52dc;
  iVar9 = DAT_800c52dc + 0x3b800;
  pcVar8 = (char *)(DAT_800c52dc + 0x3b828);
  puVar7 = (&PTR_DAT_8013143c)[param_1];
  DAT_8012bff8 = DAT_8012bff8 + 1 & 0x7f;
  iVar6 = 0x20;
  if (DAT_8012bffa == '\x01') {
    if (DAT_8012bffb == '\0') {
      psVar4 = (short *)(DAT_800c52dc + 0x3b832);
      cVar5 = -1;
      DAT_8012bffc = DAT_8012bffc + 3;
      do {
        iVar2 = (int)DAT_8012bffc;
        iVar6 = iVar6 + -1;
        cVar5 = cVar5 + '\b';
        if ((iVar2 - iVar6) - 0xbU < 0x52) {
          *pcVar8 = '\x10';
          *(char *)((int)psVar4 + -9) = cVar5;
          *(undefined1 *)(psVar4 + -4) = 0x10;
          sVar3 = DAT_8012bfd4 + (short)(iVar2 - iVar6);
          psVar4[-1] = sVar3;
          psVar4[-3] = sVar3;
          psVar4[-2] = DAT_8012bfd6 + 4;
          pcVar8 = pcVar8 + 0x10;
          *psVar4 = DAT_8012bfd6 + 0x23;
          psVar4 = psVar4 + 8;
        }
      } while (iVar6 != 0);
LAB_80098520:
      if (0x80 < DAT_8012bffc) {
        DAT_8012bffb = '\x01';
      }
      goto LAB_80098540;
    }
LAB_80098494:
    DAT_8012bffc = 10;
  }
  else {
    if (DAT_8012bffa < '\x02') {
      if (DAT_8012bffa == '\0') {
        iVar2 = param_1 * 6;
        psVar4 = (short *)(DAT_800c52dc + 0x3b832);
        do {
          iVar6 = iVar6 + -1;
          uVar10 = (short)DAT_8012bff8 - iVar6;
          if (uVar10 < 0x50) {
            cVar5 = (char)iVar6;
            *pcVar8 = (&DAT_8013141c)[iVar2] - (&DAT_8013141f)[iVar2] * cVar5;
            *(char *)((int)psVar4 + -9) = (&DAT_8013141d)[iVar2] - (&DAT_80131420)[iVar2] * cVar5;
            *(char *)(psVar4 + -4) = (&DAT_8013141e)[iVar2] - (&DAT_80131421)[iVar2] * cVar5;
            sVar3 = DAT_8012bfd4 + 0xc + (short)uVar10;
            psVar4[-3] = sVar3;
            psVar4[-1] = sVar3;
            sVar3 = (ushort)(byte)puVar7[uVar10 * 2] + DAT_8012bfd6 + 2;
            psVar4[-2] = sVar3;
            pcVar8 = pcVar8 + 0x10;
            *psVar4 = sVar3 + (ushort)(byte)(puVar7 + uVar10 * 2)[1];
            psVar4 = psVar4 + 8;
          }
        } while (iVar6 != 0);
      }
      goto LAB_80098540;
    }
    if (DAT_8012bffa != '\x02') {
      if (DAT_8012bffa != '\x03') goto LAB_80098540;
      if (DAT_8012bffb == '\0') {
        psVar4 = (short *)(DAT_800c52dc + 0x3b832);
        cVar5 = -1;
        DAT_8012bffc = DAT_8012bffc + 3;
        do {
          iVar2 = (int)DAT_8012bffc;
          iVar6 = iVar6 + -1;
          cVar5 = cVar5 + '\b';
          if ((iVar2 - iVar6) - 0xbU < 0x52) {
            *pcVar8 = cVar5;
            *(char *)((int)psVar4 + -9) = cVar5;
            *(undefined1 *)(psVar4 + -4) = 0x10;
            sVar3 = DAT_8012bfd4 + (short)(iVar2 - iVar6);
            psVar4[-1] = sVar3;
            psVar4[-3] = sVar3;
            psVar4[-2] = DAT_8012bfd6 + 4;
            pcVar8 = pcVar8 + 0x10;
            *psVar4 = DAT_8012bfd6 + 0x23;
            psVar4 = psVar4 + 8;
          }
        } while (iVar6 != 0);
        goto LAB_80098520;
      }
      goto LAB_80098494;
    }
    if (DAT_8012bffb == '\0') {
      psVar4 = (short *)(DAT_800c52dc + 0x3b82e);
      DAT_8012bffe = DAT_8012bffe + -3;
      do {
        iVar2 = (int)DAT_8012bffe;
        iVar6 = iVar6 + -1;
        if ((iVar2 - iVar6) - 3U < 0x21) {
          *(undefined1 *)((int)psVar4 + -5) = 0x10;
          *pcVar8 = '\x10';
          *(char *)(psVar4 + -2) = (char)iVar6 * '\b';
          psVar4[-1] = DAT_8012bfd4 + 0xb;
          psVar4[1] = DAT_8012bfd4 + 0x5c;
          pcVar8 = pcVar8 + 0x10;
          sVar3 = DAT_8012bfd6 + (short)(iVar2 - iVar6);
          psVar4[2] = sVar3;
          *psVar4 = sVar3;
          psVar4 = psVar4 + 8;
        }
      } while (iVar6 != 0);
      if (DAT_8012bffe < -0x14) {
        DAT_8012bffb = '\x01';
      }
      goto LAB_80098540;
    }
    DAT_8012bffe = 0x46;
  }
  DAT_8012bffa = '\0';
  DAT_8012bffb = '\0';
  DAT_8012bff8 = 0;
LAB_80098540:
  FUN_800478ac(iVar9,param_1 * 0x2e & 0xfffe,0x23);
  FUN_800478b8(iVar9,DAT_8012bfd4 + 0x2f,DAT_8012bfd6 + 0x19);
  *(undefined **)(iVar1 + 0x3b80c) = &DAT_8012f584;
  *(undefined2 *)(iVar1 + 0x3b80a) = 0x20;
  uVar10 = iVar1 + 0x3b814;
  DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar9,0,0);
  FUN_800478b8(uVar10,DAT_8012bfd4 + 2,DAT_8012bfd6);
  DAT_800df8b4 = FUN_80043988(DAT_800df8b4,uVar10,0,0);
  do {
    uVar10 = uVar10 - 0x14;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,uVar10,0,0);
  } while (DAT_800c52dc + 0x3b814U < uVar10);
  if ((char *)(DAT_800c52dc + 0x3b828) < pcVar8) {
    do {
      pcVar8 = pcVar8 + -0x10;
      DAT_800df8b4 = FUN_80047298(DAT_800df8b4,pcVar8);
    } while ((char *)(DAT_800c52dc + 0x3b828) < pcVar8);
  }
  return;
}
