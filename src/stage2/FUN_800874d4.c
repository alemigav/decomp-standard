/* FUN_800874d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800874d4  body 0x800874d4..0x8008769b  size 456 B
 * body sha256 deb2d1754f20eceac423f3c0afa68b0cb708cd69745223b04da63984393b5ed5
 * provider record sha256 ccab8d3524c399bb84aad6a47fcc8a74dbefa641c3c77391da0da2257fb7cdc4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_800874d4(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,int param_5)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  short *psVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  
  puVar7 = (uint *)(param_1 + 3U & 0xfffffffc);
  if (-1 < param_4) {
    param_4 = param_4 * 2;
    uVar1 = *(ushort *)(&DAT_801275c0 + param_4);
    uVar2 = *(ushort *)(&DAT_801275c2 + param_4);
    psVar10 = (short *)(&DAT_801275c4 + param_4);
    if (param_5 != 0) {
      *(ushort *)(param_5 + 0x5c) = uVar1;
      *(ushort *)(param_5 + 0x5e) = uVar2;
    }
    uVar5 = (uint)uVar1;
    if (uVar5 != 0) {
      iVar13 = 0;
      iVar12 = uVar5 * uVar2;
      *param_2 = puVar7;
      puVar11 = puVar7 + iVar12;
      *param_3 = puVar11;
      puVar9 = puVar11 + iVar12;
      do {
        iVar12 = 0;
        if ((int)(uint)uVar2 <= iVar13) {
          return (uint *)((int)puVar9 + 7U & 0xfffffff8);
        }
        for (; iVar12 < (int)uVar5; iVar12 = iVar12 + 1) {
          if (*psVar10 == 0x1835) {
            DAT_800eb290 = iVar12;
          }
          iVar6 = 0;
          if (iVar13 < 1) {
LAB_800875f4:
            uVar8 = (int)puVar9 + 7U & 0xfffffff8;
            *puVar7 = uVar8;
            iVar6 = func_0x80004cfc(*psVar10,uVar8,1,&DAT_800b9dcc);
            puVar9 = (uint *)(uVar8 + iVar6);
            uVar8 = FUN_80085164(*puVar7);
            *puVar11 = uVar8;
          }
          else {
            do {
              bVar3 = iVar13 <= iVar6;
              iVar6 = iVar6 + 1;
              if (bVar3) goto LAB_800875f4;
              iVar4 = uVar5 * iVar6;
            } while (*psVar10 != psVar10[-iVar4]);
            *puVar7 = puVar7[-iVar4];
            *puVar11 = puVar11[-iVar4];
          }
          psVar10 = psVar10 + 1;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        iVar13 = iVar13 + 1;
      } while( true );
    }
  }
  *param_2 = 0;
  *param_3 = 0;
  return puVar7;
}
