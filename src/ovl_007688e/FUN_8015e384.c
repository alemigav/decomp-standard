/* FUN_8015e384
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015e384  body 0x8015e384..0x8015e66f  size 748 B
 * body sha256 077f4164a74069786b17ae11fde5e72f70faf15239c3ea32743fd7caf0590b73
 * provider record sha256 df61a75d13a1f2e253b01ccbc633b02c20c537fc52be73dc5be14c34d5cd434d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015e584) */
/* WARNING: Removing unreachable block (ram,0x8015e530) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015e384(uint param_1,uint param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  func_0x80043620();
  if (param_4 == 0) {
    uVar6 = 8 - DAT_80160c25;
  }
  else {
    uVar6 = (uint)DAT_80160c25;
  }
  uVar7 = 0;
  iVar8 = 0x50;
  iVar9 = 2;
  do {
    sVar2 = (short)(param_3 * uVar6 * uVar6 * uVar6 * uVar6 >> 0xc);
    iVar3 = iVar9 * 0x28;
    pcVar5 = &DAT_80160c38 + iVar3;
    sVar1 = *(short *)(uVar7 * 0x18 + DAT_801614d4 + 0x1a);
    (&DAT_80160c3a)[iVar3] = 0x80;
    (&DAT_80160c39)[iVar3] = 0x80;
    *pcVar5 = -0x80;
    (&DAT_80160c3e)[iVar9 * 0x14] = sVar1;
    cVar4 = DAT_80160c26;
    if (DAT_80160c25 != 0) {
      if (uVar7 == param_2) {
        if (param_4 == 0) {
          (&DAT_80160c3e)[iVar9 * 0x14] = (&DAT_80160c3e)[iVar9 * 0x14] - ((short)param_3 - sVar2);
        }
        else {
          (&DAT_80160c3e)[iVar9 * 0x14] = sVar1 - sVar2;
        }
      }
      else {
        (&DAT_80160c3a)[iVar3] = DAT_80160c26;
        (&DAT_80160c39)[iVar3] = cVar4;
        *pcVar5 = cVar4;
      }
    }
    if (uVar7 == param_1) {
      if (DAT_80160c25 == 8) {
        *(undefined2 *)((int)&DAT_80160c42 + (uint)DAT_800dfbe8 * 0x14 + iVar8) = 0;
      }
      else {
        *(undefined2 *)((int)&DAT_80160c42 + (uint)DAT_800dfbe8 * 0x14 + iVar8) = 0;
        cVar4 = DAT_80160c23 + -0x80;
        (&DAT_80160c3a)[iVar3] = cVar4;
        (&DAT_80160c39)[iVar3] = cVar4;
        *pcVar5 = cVar4;
      }
    }
    else {
      (&DAT_80160c42)[(uVar7 * 2 + 2) * 0x14 + (uint)DAT_800dfbe8 * 10] = 0x100;
    }
    _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,pcVar5,0,0);
    iVar8 = iVar8 + 0x50;
    uVar7 = uVar7 + 1;
    iVar9 = iVar9 + 2;
  } while (uVar7 < 3);
  return;
}
