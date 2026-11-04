/* FUN_8009325c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009325c  body 0x8009325c..0x80093bdf  size 2436 B
 * body sha256 ec822037e7d1919274687b7bbf08bee33df0dee17eae7c23d7812c7ca501c793
 * provider record sha256 41cb0a111efb1a2bb46ff7eb6256870c6566440fa1b6f6b8574efeec3dcdc9ba
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009325c(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  
  bVar5 = DAT_8012bfa4;
  uVar13 = (uint)DAT_8012bfa4;
  iVar6 = uVar13 * 4;
  uVar1 = (&DAT_800e8ec8)[iVar6];
  uVar2 = (&DAT_800e8ec9)[iVar6];
  uVar3 = (&DAT_800e8eca)[iVar6];
  uVar14 = DAT_8012bfbc + 2 & 0x3f;
  iVar7 = uVar14 * 4;
  cVar12 = ((&DAT_800e8eca)[iVar6] != '\0') * '\x02';
  if ((&DAT_800e8ef6)[iVar7] != '\0') {
    cVar12 = cVar12 + '\x01';
  }
  uVar10 = (uint)(byte)(&DAT_800e8ef4)[iVar7];
  bVar4 = (&DAT_800e8ef5)[iVar7];
  if (uVar10 - 0x14 < 0xc) {
    if (uVar10 == (&DAT_800e8ec8)[iVar6]) {
      pbVar11 = &DAT_8012ffa8 + uVar10 * 8;
      bVar5 = (&DAT_800e8ec9)[iVar6];
      if (bVar5 == *pbVar11) {
        (&DAT_800e8ec9)[iVar6] = bVar4;
        (&DAT_800e8ef5)[iVar7] = bVar5;
        return;
      }
      uVar10 = (uint)(byte)(&DAT_800e8ec9)[iVar6] + (uint)bVar4;
      if (*pbVar11 < uVar10) {
        (&DAT_800e8ec9)[iVar6] = *pbVar11;
        (&DAT_800e8ef5)[iVar7] = (char)uVar10 - *pbVar11;
        return;
      }
LAB_800933bc:
      (&DAT_800e8ec9)[uVar13 * 4] = (&DAT_800e8ec9)[uVar13 * 4] + bVar4;
      iVar6 = uVar14 * 4;
      (&DAT_800e8ef4)[iVar6] = 0;
      (&DAT_800e8ef5)[iVar6] = 0;
      (&DAT_800e8ef6)[iVar6] = 0;
      uVar13 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar13 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008ca0c(0x10,(uint)(byte)(&DAT_800e8ef4)[iVar6],
                   uVar13 + (uint)(byte)(&DAT_800e8ef4)[iVar6] * 0x4b0 + 0xa64);
      return;
    }
    if ((&DAT_800e8ec8)[iVar6] == 0) {
      uVar8 = 0;
      iVar6 = 0;
      do {
        if ((uVar10 == (&DAT_800e8ec8)[iVar6]) &&
           ((uint)(byte)(&DAT_800e8ec9)[iVar6] <=
            (uint)(byte)(&DAT_8012ffa8)[uVar10 * 8] - (uint)bVar4)) {
          uVar13 = uVar8;
          goto LAB_800933bc;
        }
        uVar8 = uVar8 + 1;
        iVar6 = uVar8 * 4;
      } while (uVar8 < DAT_800e8b38);
    }
  }
  if (cVar12 == '\x01') {
    iVar6 = FUN_8008c4b8(1);
    if (((iVar6 == 1) && ((&DAT_800e8ec8)[uVar13 * 4] == '\0')) || (iVar6 == 0)) {
      FUN_8004ac04(0xaf0010,0xe400,8,0);
      DAT_8012bf9a = 5;
      return;
    }
    if (DAT_8012bfa0 == uVar13) {
      DAT_8012bfa0 = 0x80;
      DAT_8012bfa2 = 0;
    }
    (&DAT_800e8ec8)[uVar13 * 4] = 0;
    FUN_8008c568();
    FUN_8008c6c8(1);
    iVar6 = uVar14 * 4;
    DAT_800e8ec8 = (&DAT_800e8ef4)[iVar6];
    DAT_800e8ec9 = (&DAT_800e8ef5)[iVar6];
    DAT_800e8eca = 1;
    DAT_800e8ece = 2;
    DAT_800e8ecc = DAT_800e8ec8;
    DAT_800e8ecd = DAT_800e8ec9;
    (&DAT_800e8ef4)[iVar6] = uVar1;
    (&DAT_800e8ef5)[iVar6] = uVar2;
    (&DAT_800e8ef6)[iVar6] = uVar3;
    uVar13 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar13 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(0x10,(uint)(byte)(&DAT_800e8ef4)[iVar6],
                 uVar13 + (uint)(byte)(&DAT_800e8ef4)[iVar6] * 0x4b0 + 0xa64);
    uVar13 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar13 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008c970(0,uVar13 + (uint)DAT_800e8ec8 * 0x4b0 + 0xa64);
    uVar13 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar13 = DAT_800c52dc + 0x3c004U;
    }
    iVar6 = 1;
    uVar14 = DAT_800e8ec8 + 0x56;
    goto LAB_80093b9c;
  }
  if (cVar12 == '\0') {
    if (DAT_8012bfa0 == uVar13) {
      DAT_8012bfa0 = 0x80;
      DAT_8012bfa2 = 0;
    }
    uVar10 = FUN_8008c4b8(0);
    if (uVar10 < uVar13) {
      uVar13 = uVar10;
    }
    iVar6 = uVar13 * 4;
    iVar7 = uVar14 * 4;
    (&DAT_800e8ec8)[iVar6] = (&DAT_800e8ef4)[iVar7];
    (&DAT_800e8ec9)[iVar6] = (&DAT_800e8ef5)[iVar7];
    (&DAT_800e8eca)[iVar6] = (&DAT_800e8ef6)[iVar7];
    (&DAT_800e8ef4)[iVar7] = uVar1;
    (&DAT_800e8ef5)[iVar7] = uVar2;
    (&DAT_800e8ef6)[iVar7] = uVar3;
    uVar14 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar14 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(0x10,(uint)(byte)(&DAT_800e8ef4)[iVar7],
                 uVar14 + (uint)(byte)(&DAT_800e8ef4)[iVar7] * 0x4b0 + 0xa64);
    uVar14 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar14 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008c970((uVar13 >> 1) + uVar13,uVar14 + (uint)(&DAT_800e8ec8)[iVar6] * 0x4b0 + 0xa64);
    FUN_8008c568();
    return;
  }
  if (cVar12 != '\x02') {
    if (cVar12 != '\x03') {
      return;
    }
    if ((&DAT_800e8eca)[uVar13 * 4] == '\x01') {
      if ((DAT_8012bfa0 == uVar13) || ((uint)DAT_8012bfa0 == uVar13 + 1)) {
        DAT_8012bfa0 = 0x80;
        DAT_8012bfa2 = 0;
      }
      iVar6 = (uVar13 + 1) * 4;
      iVar9 = uVar14 * 4;
      iVar7 = uVar13 * 4;
      uVar3 = (&DAT_800e8ef4)[iVar9];
      (&DAT_800e8ec8)[iVar6] = uVar3;
      (&DAT_800e8ec8)[iVar7] = uVar3;
      uVar3 = (&DAT_800e8ef5)[iVar9];
      (&DAT_800e8ec9)[iVar6] = uVar3;
      (&DAT_800e8ec9)[iVar7] = uVar3;
      (&DAT_800e8eca)[iVar7] = 1;
      (&DAT_800e8eca)[iVar6] = 2;
      (&DAT_800e8ef4)[iVar9] = uVar1;
      (&DAT_800e8ef6)[iVar9] = 3;
      (&DAT_800e8ef5)[iVar9] = uVar2;
      uVar14 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar14 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008ca0c(0x10,(uint)(byte)(&DAT_800e8ef4)[iVar9],
                   uVar14 + (uint)(byte)(&DAT_800e8ef4)[iVar9] * 0x4b0 + 0xa64);
      uVar14 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar14 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008c970((bVar5 >> 1) + uVar13,uVar14 + (uint)(&DAT_800e8ec8)[iVar7] * 0x4b0 + 0xa64);
      iVar6 = (uVar13 + 1 >> 1) + uVar13 + 1;
      uVar13 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar13 = DAT_800c52dc + 0x3c004U;
      }
      uVar14 = (&DAT_800e8ec8)[iVar7] + 0x56;
    }
    else {
      if ((DAT_8012bfa0 == uVar13) || ((uint)DAT_8012bfa0 == uVar13 - 1)) {
        DAT_8012bfa0 = 0x80;
        DAT_8012bfa2 = 0;
      }
      iVar6 = (uVar13 - 1) * 4;
      iVar9 = uVar14 * 4;
      iVar7 = uVar13 * 4;
      uVar3 = (&DAT_800e8ef4)[iVar9];
      (&DAT_800e8ec8)[iVar6] = uVar3;
      (&DAT_800e8ec8)[iVar7] = uVar3;
      uVar3 = (&DAT_800e8ef5)[iVar9];
      (&DAT_800e8ec9)[iVar6] = uVar3;
      (&DAT_800e8ec9)[iVar7] = uVar3;
      (&DAT_800e8eca)[iVar7] = 2;
      (&DAT_800e8eca)[iVar6] = 1;
      (&DAT_800e8ef4)[iVar9] = uVar1;
      (&DAT_800e8ef6)[iVar9] = 3;
      (&DAT_800e8ef5)[iVar9] = uVar2;
      uVar14 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar14 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008ca0c(0x10,(uint)(byte)(&DAT_800e8ef4)[iVar9],
                   uVar14 + (uint)(byte)(&DAT_800e8ef4)[iVar9] * 0x4b0 + 0xa64);
      uVar14 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar14 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008c970((bVar5 >> 1) + uVar13,uVar14 + ((&DAT_800e8ec8)[iVar7] + 0x56) * 0x4b0 + 0xa64);
      iVar6 = (uVar13 - 1 >> 1) + uVar13 + -1;
      uVar13 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar13 = DAT_800c52dc + 0x3c004U;
      }
      uVar14 = (uint)(&DAT_800e8ec8)[iVar7];
    }
    goto LAB_80093b9c;
  }
  if ((&DAT_800e8eca)[uVar13 * 4] == '\x02') {
    if ((DAT_8012bfa0 == uVar13) || ((uint)DAT_8012bfa0 == uVar13 - 1)) {
      DAT_8012bfa0 = 0x80;
      DAT_8012bfa2 = 0;
    }
    (&DAT_800e8ec8)[uVar13 * 4] = 0;
    FUN_8008c568();
    (&DAT_800e8ec8)[(uVar13 - 1) * 4] = 0;
LAB_800937f4:
    FUN_8008c568();
  }
  else if ((&DAT_800e8eca)[uVar13 * 4] == '\x01') {
    if ((DAT_8012bfa0 == uVar13) || ((uint)DAT_8012bfa0 == uVar13 + 1)) {
      DAT_8012bfa0 = 0x80;
      DAT_8012bfa2 = 0;
    }
    (&DAT_800e8ec8)[uVar13 * 4] = 0;
    FUN_8008c568();
    (&DAT_800e8ec8)[uVar13 * 4] = 0;
    goto LAB_800937f4;
  }
  iVar6 = FUN_8008c4b8(0);
  iVar7 = iVar6 * 4;
  iVar9 = uVar14 * 4;
  (&DAT_800e8ec8)[iVar7] = (&DAT_800e8ef4)[iVar9];
  (&DAT_800e8ec9)[iVar7] = (&DAT_800e8ef5)[iVar9];
  (&DAT_800e8eca)[iVar7] = (&DAT_800e8ef6)[iVar9];
  (&DAT_800e8ef4)[iVar9] = uVar1;
  (&DAT_800e8ef6)[iVar9] = 3;
  (&DAT_800e8ef5)[iVar9] = uVar2;
  uVar13 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar13 = DAT_800c52dc + 0x3c004U;
  }
  FUN_8008ca0c(0x10,(uint)(byte)(&DAT_800e8ef4)[iVar9],
               uVar13 + (uint)(byte)(&DAT_800e8ef4)[iVar9] * 0x4b0 + 0xa64);
  iVar6 = iVar6 / 2 + iVar6;
  uVar13 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar13 = DAT_800c52dc + 0x3c004U;
  }
  uVar14 = (uint)(&DAT_800e8ec8)[iVar7];
LAB_80093b9c:
  FUN_8008c970(iVar6,uVar13 + uVar14 * 0x4b0 + 0xa64);
  return;
}
