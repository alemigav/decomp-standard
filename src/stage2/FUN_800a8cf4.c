/* FUN_800a8cf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8cf4  body 0x800a8cf4..0x800a8e3f  size 332 B
 * body sha256 a51261700c17402bb4b7ade3d86b0c2e68b4c15e3152ecc883b6f4bc0b432a50
 * provider record sha256 13485f60eee8d165b7705cce9fa955a30aecb39089dd1e1b1cac61e0cc31d752
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800a8cf4(short param_1,short param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  
  if ((DAT_80136310 != '\0') && (iVar4 = 0, 0 < _DAT_80147fd0)) {
    piVar5 = (int *)&DAT_80147fe0;
    do {
      iVar3 = *piVar5;
      if (*(short *)(iVar3 + 4) == param_1) {
        if (*(short *)(iVar3 + 6) != 0) {
          return 0xffffffff;
        }
        psVar6 = (short *)(iVar3 + *(int *)(iVar3 + 0x24) + 8);
        sVar2 = *psVar6;
        iVar4 = iVar3 + *(int *)(iVar3 + 0x20) + 8;
        iVar3 = iVar3 + *(int *)(iVar3 + 0x1c) + 8;
        if (sVar2 == -1) {
          return 0xffffffff;
        }
        do {
          if (sVar2 == param_2) {
            if (param_5 == '\0') {
              FUN_800a5678(iVar3);
              uVar1 = FUN_8009f8b0(iVar3,iVar4,psVar6,param_3,param_4);
              FUN_800a56c0();
            }
            else {
              uVar1 = FUN_8009f8b0(iVar3,iVar4,psVar6,param_3,param_4);
            }
            return uVar1;
          }
          psVar6 = psVar6 + 0x42;
          sVar2 = *psVar6;
        } while (sVar2 != -1);
        return 0xffffffff;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < _DAT_80147fd0);
  }
  return 0xffffffff;
}
