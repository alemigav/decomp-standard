/* FUN_8009ec98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ec98  body 0x8009ec98..0x8009eedf  size 584 B
 * body sha256 ed5ad6092085b00a7fbff368c4764d00cfd5525d2c00e7f0ead077403b9fc087
 * provider record sha256 7b636eb85d80b84e76f588fe121ad9801b515b9618e9d1f49848a8ba379eb990
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ec98(int param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (param_5 == 0) {
    uVar1 = param_1 * 2;
    DAT_80134324 = 0x800 / uVar1;
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    DAT_80134328 = param_2 / DAT_80134324;
    if (DAT_80134324 == 0) {
      trap(0x1c00);
    }
    DAT_80134320 = param_1 * DAT_80134324 * 2;
    puVar3 = &DAT_80134468;
    puVar2 = &DAT_801331d0;
    DAT_80134338 = 0xf80007c0;
    DAT_8013433c = 0x3e0001;
    DAT_80134334 = param_3 * DAT_80134324 * 2;
    DAT_80134340 = 0x80000800;
    DAT_80134330 = (param_3 - param_1) * 0x200000 | uVar1 - 1;
    DAT_80134344 = 0x400002;
    DAT_8013432c = param_2 - DAT_80134328 * DAT_80134324;
    do {
      uVar4 = puVar2[1];
      uVar5 = puVar2[2];
      uVar6 = puVar2[3];
      *puVar3 = *puVar2;
      puVar3[1] = uVar4;
      puVar3[2] = uVar5;
      puVar3[3] = uVar6;
      puVar2 = puVar2 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar2 != &DAT_80133210);
  }
  else {
    uVar1 = param_1 * 4;
    if (param_5 == 1) {
      DAT_80134324 = 0x800 / uVar1;
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      DAT_80134328 = param_2 / DAT_80134324;
      if (DAT_80134324 == 0) {
        trap(0x1c00);
      }
      DAT_80134320 = param_1 * DAT_80134324 * 4;
      puVar3 = &DAT_80134468;
      puVar2 = &DAT_80133210;
      DAT_80134338 = 0xf80007c0;
      DAT_8013433c = 0x3e0001;
      DAT_80134334 = param_3 * DAT_80134324 * 4;
      DAT_80134340 = 0x80000800;
      DAT_80134330 = (param_3 - param_1) * 0x400000 | uVar1 - 1;
      DAT_80134344 = 0x400002;
      DAT_8013432c = param_2 - DAT_80134328 * DAT_80134324;
      do {
        uVar4 = puVar2[1];
        uVar5 = puVar2[2];
        uVar6 = puVar2[3];
        *puVar3 = *puVar2;
        puVar3[1] = uVar4;
        puVar3[2] = uVar5;
        puVar3[3] = uVar6;
        puVar2 = puVar2 + 4;
        puVar3 = puVar3 + 4;
      } while (puVar2 != (undefined4 *)&DAT_80133250);
    }
  }
  return;
}
