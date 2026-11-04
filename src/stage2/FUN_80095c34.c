/* FUN_80095c34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80095c34  body 0x80095c34..0x80095faf  size 892 B
 * body sha256 92201574ef0f1f4f3170c24da03cbfa04ce8285edbaefa0f6f6f10f946ec092d
 * provider record sha256 2ee69bbc46021cb7a77f81b101c86e5d4cfc46b6e1d60d4b942b60e5e7c6850e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80095c34(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  short *psVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int unaff_s7;
  
  uVar3 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar3 = DAT_800c52dc + 0x3c004U;
  }
  iVar10 = 0;
  psVar7 = (short *)&UNK_801310e4;
  pbVar6 = &DAT_800e8efc;
  uVar8 = 0xd;
  while( true ) {
    uVar9 = uVar8 - 1;
    iVar1 = (uint)pbVar6[-4] * 8;
    iVar4 = 0;
    if (((&DAT_8012ffaa)[iVar1] & 0x80) != 0) {
      iVar4 = 10;
    }
    if (pbVar6[-2] == 2) {
      uVar3 = uVar3 + 0x50;
    }
    else if (uVar9 < DAT_800e8b38) {
      uVar3 = FUN_80095fb0(uVar3,pbVar6[-3],
                           ((int)*psVar7 + (int)DAT_8012bfcc) * 0x10000 + (int)psVar7[1] +
                           (int)DAT_8012bfce,iVar4 << 0x10 | (uint)(byte)(&DAT_8012ffaa)[iVar1]);
    }
    else {
      uVar3 = uVar3 + 0x50;
    }
    if (uVar9 == 0) break;
    psVar7 = psVar7 + -2;
    pbVar6 = pbVar6 + -4;
    uVar8 = uVar9;
  }
  iVar1 = (uint)DAT_8012bfa0 * 4;
  pbVar6 = &DAT_800e8ec8 + iVar1;
  if (DAT_8012bfa0 == 0x80) {
    iVar10 = uVar3 + 0x50;
  }
  else {
    iVar4 = 0;
    if (((&DAT_8012ffaa)[(uint)*pbVar6 * 8] & 0x80) != 0) {
      iVar4 = 10;
    }
    if ((&DAT_800e8eca)[iVar1] == '\0') {
      iVar10 = 0x14;
    }
    if (DAT_8012bfa8 == '\x01') {
      iVar10 = iVar10 + 0x36;
    }
    iVar10 = FUN_80095fb0(uVar3,(&DAT_800e8ec9)[iVar1],
                          (DAT_8012bfcc + -0x2e + iVar10) * 0x10000 + DAT_8012bfce + -0xf,
                          iVar4 << 0x10 | (uint)(byte)(&DAT_8012ffaa)[(uint)*pbVar6 * 8]);
  }
  if (DAT_8012bfa8 == '\x01') {
    uVar3 = (uint)DAT_8012bf9a;
    if (uVar3 == 3) {
      unaff_s7 = 0x52;
      pbVar6 = &DAT_800e8ef4 + (DAT_8012bfbc + 5 & 0x3f) * 4;
    }
    if (uVar3 == 2) {
      unaff_s7 = -0x26;
      pbVar6 = &DAT_800e8ef4 + (DAT_8012bfbc - 1 & 0x3f) * 4;
    }
    iVar1 = 0;
    if (((&DAT_8012ffaa)[(uint)*pbVar6 * 8] & 0x80) != 0) {
      iVar1 = 10;
    }
    if (uVar3 - 2 < 2) {
      iVar10 = FUN_80095fb0(iVar10,pbVar6[1],
                            ((int)*(short *)(&UNK_801310b4 + (uVar8 + 0xb) * 4) + (int)DAT_8012bfcc)
                            * 0x10000 + (int)DAT_8012bfce + (int)DAT_8012bfbd + unaff_s7,
                            iVar1 << 0x10 | (uint)(byte)(&DAT_8012ffaa)[(uint)*pbVar6 * 8]);
    }
    iVar4 = 5;
    iVar1 = 0x48;
    do {
      iVar4 = iVar4 + -1;
      iVar2 = ((uint)DAT_8012bfbc + iVar4 & 0x3f) * 4;
      iVar5 = 0;
      if (((&DAT_8012ffaa)[(uint)(byte)(&DAT_800e8ef4)[iVar2] * 8] & 0x80) != 0) {
        iVar5 = 10;
      }
      iVar10 = FUN_80095fb0(iVar10,(&DAT_800e8ef5)[iVar2],
                            ((int)*(short *)(&UNK_801310b0 + iVar1) + (int)DAT_8012bfcc) * 0x10000 +
                            (int)*(short *)(&UNK_801310b2 + iVar1) + (int)DAT_8012bfce +
                            (int)DAT_8012bfbd,
                            iVar5 << 0x10 |
                            (uint)(byte)(&DAT_8012ffaa)[(uint)(byte)(&DAT_800e8ef4)[iVar2] * 8]);
      iVar1 = iVar1 + -4;
    } while (iVar4 != 0);
  }
  return;
}
