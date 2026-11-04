/* FUN_8016bf68
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016bf68  body 0x8016bf68..0x8016c14b  size 484 B
 * body sha256 d121d7a54363c06639fda7f09a4d071c666328d6b03a8e1e2af9b05d25660f1b
 * provider record sha256 081660dda34e8bc2322fcaf314e7cfed43b7f82e0d67b0e726441538fad41e3a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016bf68(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = 0x7fffffff;
  uVar1 = func_0x80033604();
  uVar2 = func_0x80033604();
  uVar1 = (int)(uVar1 & 0xff) >> (uVar2 & 3) & 1;
  if (*(int *)(param_1 + 0x28) < -15000) {
    uVar1 = 0;
  }
  if (-0x2e18 < *(int *)(param_1 + 0x28)) {
    uVar1 = 1;
  }
  bVar5 = 0;
  uVar6 = 0;
  DAT_8016c2d0 = '\0';
  uVar2 = uVar1;
  if ((*(ushort *)(param_1 + 0x2b6) & 0x20) != 0) {
    uVar2 = uVar1 ^ 1;
  }
  do {
    iVar3 = uVar2 * 4 + (uint)bVar5;
    iVar3 = func_0x80032e74(param_1,(int)(short)(&DAT_8016c2b0)[iVar3 * 2],
                            (int)(short)(&DAT_8016c2b2)[iVar3 * 2],0x270);
    if (iVar3 == 0) {
      uVar4 = uVar6 & 0xff;
      uVar6 = uVar6 + 1;
      DAT_8016c2d0 = DAT_8016c2d0 + '\x01';
      (&DAT_8016c2d4)[uVar4] = (char)(uVar2 * 4) + bVar5;
    }
    bVar5 = bVar5 + 1;
  } while (bVar5 < 4);
  bVar5 = 0;
  DAT_8016c318 = '\0';
  uVar2 = 0;
  do {
    iVar3 = (uVar1 * 8 + uVar2) * 4;
    uVar2 = func_0x80040bb4((_DAT_800e1158 - *(short *)(&DAT_8016c2d8 + iVar3)) *
                            (_DAT_800e1158 - *(short *)(&DAT_8016c2d8 + iVar3)) +
                            (_DAT_800e1160 - *(short *)(&DAT_8016c2da + iVar3)) *
                            (_DAT_800e1160 - *(short *)(&DAT_8016c2da + iVar3)));
    if (uVar2 < uVar7) {
      uVar7 = uVar2;
      DAT_8016c318 = (char)(uVar1 * 8) + bVar5;
    }
    bVar5 = bVar5 + 1;
    uVar2 = (uint)bVar5;
  } while (bVar5 < 8);
  return;
}
