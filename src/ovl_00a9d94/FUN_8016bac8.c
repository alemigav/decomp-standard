/* FUN_8016bac8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016bac8  body 0x8016bac8..0x8016bdc3  size 764 B
 * body sha256 2af3b13b0b2e066cabb57d53e385352416e7f641b74d5f464404b285712dd68d
 * provider record sha256 abaa1eb46eed630b9e84d6b1af1e5b48288e5d4a77d3bc5e7b861d4f0e4a5f7e
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016bac8(int param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  
  param_2 = param_2 & 0xff;
  iVar9 = param_2 * 0x1c;
  pcVar11 = &DAT_8016c3ac + iVar9;
  sVar6 = (&DAT_8016c3b4)[param_2 * 0xe];
  bVar2 = (&DAT_8016c3c0)[iVar9];
  sVar7 = (&DAT_8016c3b6)[param_2 * 0xe];
  iVar10 = *(int *)(param_1 + 0x234);
  if ((char)(&DAT_8016c3ae)[iVar9] < *pcVar11) {
    (&DAT_8016c3b4)[param_2 * 0xe] = 0xffff;
  }
  if (*pcVar11 < (char)(&DAT_8016c3ae)[iVar9]) {
    (&DAT_8016c3b4)[param_2 * 0xe] = 1;
  }
  if ((char)(&DAT_8016c3af)[iVar9] < (char)(&DAT_8016c3ad)[iVar9]) {
    (&DAT_8016c3b6)[param_2 * 0xe] = 0xffff;
  }
  if ((char)(&DAT_8016c3ad)[iVar9] < (char)(&DAT_8016c3af)[iVar9]) {
    (&DAT_8016c3b6)[param_2 * 0xe] = 1;
  }
  if (-(int)(short)(&DAT_8016c3b4)[param_2 * 0xe] == (int)sVar6) {
    (&DAT_8016c3b0)[param_2 * 0xe] = (short)(((int)(short)(&DAT_8016c3b0)[param_2 * 0xe] << 1) / 3);
  }
  if (-(int)(short)(&DAT_8016c3b6)[param_2 * 0xe] == (int)sVar7) {
    (&DAT_8016c3b2)[param_2 * 0xe] = (short)(((int)(short)(&DAT_8016c3b2)[param_2 * 0xe] << 1) / 3);
  }
  if (*pcVar11 == (&DAT_8016c3ae)[iVar9]) {
    iVar8 = (int)(short)(&DAT_8016c3b0)[param_2 * 0xe];
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    if (iVar8 < 3) {
      *pcVar11 = (&DAT_8016c3ae)[iVar9];
      (&DAT_8016c3b4)[param_2 * 0xe] = 0;
      (&DAT_8016c3b0)[param_2 * 0xe] = 0;
    }
  }
  if ((&DAT_8016c3ad)[iVar9] == (&DAT_8016c3af)[iVar9]) {
    iVar8 = (int)(short)(&DAT_8016c3b2)[param_2 * 0xe];
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    if (iVar8 < 3) {
      (&DAT_8016c3ad)[iVar9] = (&DAT_8016c3af)[iVar9];
      (&DAT_8016c3b6)[param_2 * 0xe] = 0;
      (&DAT_8016c3b2)[param_2 * 0xe] = 0;
    }
  }
  cVar1 = *pcVar11;
  if (cVar1 == (&DAT_8016c3ae)[iVar9]) {
    if (cVar1 < (char)(&DAT_8016c3c1)[iVar9]) {
      if ((char)(&DAT_8016c3c2)[iVar9] < cVar1) goto LAB_8016bc8c;
      (&DAT_8016c3b0)[param_2 * 0xe] = 0;
    }
    else {
      (&DAT_8016c3b0)[param_2 * 0xe] = 0;
    }
    (&DAT_8016c3b4)[param_2 * 0xe] = 0;
  }
LAB_8016bc8c:
  cVar1 = (&DAT_8016c3ad)[iVar9];
  if (cVar1 == (&DAT_8016c3af)[iVar9]) {
    if (cVar1 < (char)(&DAT_8016c3c3)[iVar9]) {
      if ((char)(&DAT_8016c3c4)[iVar9] < cVar1) goto LAB_8016bcc4;
      (&DAT_8016c3b2)[param_2 * 0xe] = 0;
    }
    else {
      (&DAT_8016c3b2)[param_2 * 0xe] = 0;
    }
    (&DAT_8016c3b6)[param_2 * 0xe] = 0;
  }
LAB_8016bcc4:
  cVar1 = *pcVar11;
  cVar3 = (&DAT_8016c3ad)[iVar9];
  (&DAT_8016c3b0)[param_2 * 0xe] = (&DAT_8016c3b0)[param_2 * 0xe] + (&DAT_8016c3b4)[param_2 * 0xe];
  cVar4 = *(char *)((int)&DAT_8016c3b0 + iVar9 + 1);
  (&DAT_8016c3b2)[param_2 * 0xe] = (&DAT_8016c3b2)[param_2 * 0xe] + (&DAT_8016c3b6)[param_2 * 0xe];
  cVar5 = *(char *)((int)&DAT_8016c3b2 + iVar9 + 1);
  *pcVar11 = cVar1 + cVar4;
  (&DAT_8016c3ad)[iVar9] = (&DAT_8016c3ad)[iVar9] + cVar5;
  if ((char)(&DAT_8016c3c1)[iVar9] < *pcVar11) {
    *pcVar11 = (&DAT_8016c3c1)[iVar9];
  }
  if (*pcVar11 < (char)(&DAT_8016c3c2)[iVar9]) {
    *pcVar11 = (&DAT_8016c3c2)[iVar9];
  }
  if ((char)(&DAT_8016c3c3)[iVar9] < (char)(&DAT_8016c3ad)[iVar9]) {
    (&DAT_8016c3ad)[iVar9] = (&DAT_8016c3c3)[iVar9];
  }
  if ((char)(&DAT_8016c3ad)[iVar9] < (char)(&DAT_8016c3c4)[iVar9]) {
    (&DAT_8016c3ad)[iVar9] = (&DAT_8016c3c4)[iVar9];
  }
  func_0x800341f4(iVar10 + (uint)bVar2 * 0x178,
                  ((int)(char)(&DAT_8016c3ad)[iVar9] - (int)cVar3) * 0x10000 >> 0x10,
                  ((int)*pcVar11 - (int)cVar1) * 0x10000 >> 0x10,_DAT_800eb290);
  return;
}
