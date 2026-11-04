/* FUN_80053d7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053d7c  body 0x80053d7c..0x80053eb7  size 316 B
 * body sha256 ae65fc6c4d6343f8bbc65c30ee556341bfa1d4a5ac0cee196686f2a8718f41aa
 * provider record sha256 aa04dae20fe6902343b0b229262e32bf809dc34b9e330f768ad66d6da5b01b71
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053d7c(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  FUN_80043620();
  pbVar2 = DAT_8010d940;
  pbVar7 = DAT_8010d940 + 4;
  pbVar6 = DAT_8010d940 + 0x16c;
  pbVar5 = DAT_8010d940 + 0x340;
  pbVar8 = DAT_8010d940 + 0x19c0;
  pbVar4 = DAT_8010d940 + 0x34f;
  do {
    pbVar5 = pbVar5 + 0x10;
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar4[-0xffffffff0000000b] = 0;
    pbVar4[-0xffffffff0000000a] = 8;
    pbVar4[-0xffffffff00000009] = 0;
    pbVar4[-0xffffffff00000008] = 10;
    iVar3 = FUN_800844e4(((bVar1 - 0x20 & 0xffff) >> 5) * 0xa00 & 0xfef8 |
                         (bVar1 - 0x20 & 0x1f) << 3);
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    *pbVar4 = (byte)param_1;
    *(uint *)(pbVar4 + -7) = iVar3 + (uint)bVar1 * 0x20;
    pbVar4 = pbVar4 + 0x10;
  } while (pbVar5 < pbVar8);
  *(ushort *)(pbVar2 + 800) = (ushort)*pbVar2 * 8 + 0x10;
  bVar1 = pbVar2[0x2d5];
  *(ushort *)(pbVar2 + 0x322) = (ushort)pbVar2[1] * 10 + 0x15;
  pbVar2[0x2d5] = bVar1 + 1 & 0x1f;
  *(ushort *)(pbVar2 + 0x32a) = (ushort)pbVar2[0x2d7];
  if (param_1 == 0) {
    pbVar2[0x32f] = 0;
  }
  else {
    pbVar2[0x32f] = bVar1 + 1 & 0x10;
  }
  pbVar2[0x33f] = (byte)param_1;
  return;
}
