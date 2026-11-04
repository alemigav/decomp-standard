/* FUN_8008769c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008769c  body 0x8008769c..0x80087867  size 460 B
 * body sha256 9e37be23cff684eb6ac245dad0d7f009759eeff3084fa2b4ab2c2b36bb2ba48e
 * provider record sha256 d9c26df9bbf76b23fedf2e1accb90ec3cf9d25166195240cee170fc067a95aed
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_8008769c(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  short *psVar6;
  short *psVar7;
  uint *puVar8;
  int iVar9;
  
  puVar4 = (uint *)(param_1 + 3U & 0xfffffffc);
  if (-1 < param_4) {
    param_4 = param_4 * 2;
    uVar1 = *(ushort *)(&DAT_801275c0 + param_4);
    psVar6 = (short *)(&DAT_801275c4 + param_4);
    if (*(short *)(&DAT_801275c2 + param_4) != 2) {
      puVar4 = (uint *)FUN_800874d4(puVar4);
      return puVar4;
    }
    if (param_5 != 0) {
      *(ushort *)(param_5 + 0x5c) = uVar1;
      *(undefined2 *)(param_5 + 0x5e) = 2;
    }
    uVar3 = (uint)uVar1;
    if (uVar3 != 0) {
      *param_2 = puVar4;
      puVar8 = puVar4 + uVar3;
      *param_3 = puVar8;
      puVar5 = puVar8 + uVar3;
      psVar7 = psVar6 + uVar3;
      for (iVar9 = 0; iVar9 < (int)(uint)uVar1; iVar9 = iVar9 + 1) {
        if (*psVar6 == *psVar7) {
          uVar3 = (int)puVar5 + 7U & 0xfffffff8;
          *puVar4 = uVar3;
          iVar2 = func_0x80004cfc(*psVar6,uVar3,1,&DAT_800b9dcc);
          puVar5 = (uint *)(uVar3 + iVar2);
          uVar3 = FUN_80085164(*puVar4);
          *puVar8 = uVar3;
        }
        else {
          uVar3 = (int)puVar5 + 7U & 0xfffffff8;
          *puVar4 = uVar3;
          iVar2 = func_0x80004cfc(*psVar6,uVar3,1,&DAT_800b9dcc);
          uVar3 = uVar3 + iVar2 + 7 & 0xfffffff8;
          iVar2 = func_0x80004cfc(*psVar7,uVar3,1,&DAT_800b9dcc);
          puVar5 = (uint *)(uVar3 + iVar2);
          uVar3 = FUN_8008522c(*puVar4,uVar3);
          *puVar8 = uVar3;
        }
        psVar6 = psVar6 + 1;
        psVar7 = psVar7 + 1;
        puVar4 = puVar4 + 1;
        puVar8 = puVar8 + 1;
      }
      return (uint *)((int)puVar5 + 7U & 0xfffffff8);
    }
  }
  *param_2 = 0;
  *param_3 = 0;
  return puVar4;
}
