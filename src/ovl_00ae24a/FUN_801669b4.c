/* FUN_801669b4
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801669b4  body 0x801669b4..0x80166c3f  size 652 B
 * body sha256 461bb059825efe78bb210380e54ffc02524f267dc6e95f206f08afc0b3fe794e
 * provider record sha256 fcd00314c86ccc5a7616f3c1ae893c4724459c81f5d9dcd16f3c0c40e68eb90a
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801669b4(int param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
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
  pcVar11 = &DAT_80166f54 + iVar9;
  sVar6 = (&DAT_80166f5c)[param_2 * 0xe];
  bVar1 = (&DAT_80166f68)[iVar9];
  sVar7 = (&DAT_80166f5e)[param_2 * 0xe];
  iVar10 = *(int *)(param_1 + 0x234);
  if ((char)(&DAT_80166f56)[iVar9] < *pcVar11) {
    (&DAT_80166f5c)[param_2 * 0xe] = 0xffff;
  }
  if (*pcVar11 < (char)(&DAT_80166f56)[iVar9]) {
    (&DAT_80166f5c)[param_2 * 0xe] = 1;
  }
  if ((char)(&DAT_80166f57)[iVar9] < (char)(&DAT_80166f55)[iVar9]) {
    (&DAT_80166f5e)[param_2 * 0xe] = 0xffff;
  }
  if ((char)(&DAT_80166f55)[iVar9] < (char)(&DAT_80166f57)[iVar9]) {
    (&DAT_80166f5e)[param_2 * 0xe] = 1;
  }
  if (-(int)(short)(&DAT_80166f5c)[param_2 * 0xe] == (int)sVar6) {
    (&DAT_80166f58)[param_2 * 0xe] = (short)(((int)(short)(&DAT_80166f58)[param_2 * 0xe] << 1) / 3);
  }
  if (-(int)(short)(&DAT_80166f5e)[param_2 * 0xe] == (int)sVar7) {
    (&DAT_80166f5a)[param_2 * 0xe] = (short)(((int)(short)(&DAT_80166f5a)[param_2 * 0xe] << 1) / 3);
  }
  if (*pcVar11 == (&DAT_80166f56)[iVar9]) {
    iVar8 = (int)(short)(&DAT_80166f58)[param_2 * 0xe];
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    if (iVar8 < 3) {
      *pcVar11 = (&DAT_80166f56)[iVar9];
      (&DAT_80166f5c)[param_2 * 0xe] = 0;
      (&DAT_80166f58)[param_2 * 0xe] = 0;
    }
  }
  if ((&DAT_80166f55)[iVar9] == (&DAT_80166f57)[iVar9]) {
    iVar8 = (int)(short)(&DAT_80166f5a)[param_2 * 0xe];
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    if (iVar8 < 3) {
      (&DAT_80166f55)[iVar9] = (&DAT_80166f57)[iVar9];
      (&DAT_80166f5e)[param_2 * 0xe] = 0;
      (&DAT_80166f5a)[param_2 * 0xe] = 0;
    }
  }
  cVar2 = *pcVar11;
  cVar3 = (&DAT_80166f55)[iVar9];
  (&DAT_80166f58)[param_2 * 0xe] = (&DAT_80166f58)[param_2 * 0xe] + (&DAT_80166f5c)[param_2 * 0xe];
  cVar4 = *(char *)((int)&DAT_80166f58 + iVar9 + 1);
  (&DAT_80166f5a)[param_2 * 0xe] = (&DAT_80166f5a)[param_2 * 0xe] + (&DAT_80166f5e)[param_2 * 0xe];
  cVar5 = *(char *)((int)&DAT_80166f5a + iVar9 + 1);
  *pcVar11 = cVar2 + cVar4;
  (&DAT_80166f55)[iVar9] = (&DAT_80166f55)[iVar9] + cVar5;
  if ((char)(&DAT_80166f69)[iVar9] < *pcVar11) {
    *pcVar11 = (&DAT_80166f69)[iVar9];
  }
  if (*pcVar11 < (char)(&DAT_80166f6a)[iVar9]) {
    *pcVar11 = (&DAT_80166f6a)[iVar9];
  }
  if ((char)(&DAT_80166f6b)[iVar9] < (char)(&DAT_80166f55)[iVar9]) {
    (&DAT_80166f55)[iVar9] = (&DAT_80166f6b)[iVar9];
  }
  if ((char)(&DAT_80166f55)[iVar9] < (char)(&DAT_80166f6c)[iVar9]) {
    (&DAT_80166f55)[iVar9] = (&DAT_80166f6c)[iVar9];
  }
  func_0x800341f4(iVar10 + (uint)bVar1 * 0x178,
                  ((int)(char)(&DAT_80166f55)[iVar9] - (int)cVar3) * 0x10000 >> 0x10,
                  ((int)*pcVar11 - (int)cVar2) * 0x10000 >> 0x10,_DAT_800eb290);
  return;
}
