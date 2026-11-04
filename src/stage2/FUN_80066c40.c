/* FUN_80066c40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80066c40  body 0x80066c40..0x80066e27  size 488 B
 * body sha256 5af893adca9435b23eb4d33f6b691fc23acdaf1bbc5e13dbcd6fab17cf1e7f6d
 * provider record sha256 eb42a0624af31eb2370465e7dca17f64ea0293536bfe2dd8310a670675c7049a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80066c40(uint *param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  
  if ((*param_1 & 8) != 0) {
    return 0;
  }
  sVar2 = *(short *)(param_1 + 0x4f);
  uVar5 = param_1[10];
  iVar6 = param_1[0xc] + (int)*(short *)((int)param_1 + 0x13e);
  psVar7 = *(short **)(DAT_800df92c + 0x20);
  psVar11 = psVar7 + *(int *)(psVar7 + 2) * 8;
  uVar4 = FUN_800667b0(uVar5 + (int)sVar2,iVar6,(int)*psVar7,(int)psVar7[1]);
  bVar1 = *(byte *)((int)param_1 + 0x1a2);
  _DAT_80139e40 = 0;
  iVar10 = uVar5 + (int)sVar2 + (uint)*(ushort *)(param_1 + 0x4b);
  iVar6 = iVar6 + (uint)*(ushort *)((int)param_1 + 0x12e);
  iVar9 = (uint)*(ushort *)(param_1 + 0x4b) * 2;
  iVar8 = (uint)*(ushort *)((int)param_1 + 0x12e) * 2;
  do {
    psVar7 = psVar7 + 8;
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              if (psVar7 == psVar11) {
                return (int)(short)_DAT_80139e40;
              }
              if ((psVar7[5] & uVar4) != 0) break;
              psVar7 = psVar7 + 8;
            }
            if ((uint)(iVar10 - *psVar7) < (uint)(ushort)psVar7[2] + iVar9) break;
            psVar7 = psVar7 + 8;
          }
          if ((uint)(iVar6 - psVar7[1]) < (uint)(ushort)psVar7[3] + iVar8) break;
          psVar7 = psVar7 + 8;
        }
        uVar3 = psVar7[4];
        if ((uVar3 & 0x4000) != 0) break;
        psVar7 = psVar7 + 8;
      }
      if ((uVar3 & param_3) == 0) break;
      psVar7 = psVar7 + 8;
    }
    if ((*(uint *)(psVar7 + 6) & 1 << (bVar1 & 0x1f)) != 0) {
      if ((uVar3 & 0xf) == 10) {
        _DAT_80139e40 = _DAT_80139e40 | 4;
      }
      else {
        if (param_3 != 0) {
          iVar6 = iVar8 >> 1;
          FUN_80066ec8(param_1,iVar6,psVar7);
          iVar10 = param_1[10] + (int)*(short *)(param_1 + 0x4f) + (iVar9 >> 1);
          iVar6 = param_1[0xc] + (int)*(short *)((int)param_1 + 0x13e) + iVar6;
        }
        _DAT_80139e40 = _DAT_80139e40 | 1;
      }
    }
  } while( true );
}
