/* FUN_80180a20
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180a20  body 0x80180a20..0x80180b0f  size 240 B
 * body sha256 e567cd6e30903ffad0ad3ddae695d168a352338df6447eaab382a4ed32b3a774
 * provider record sha256 76de0ef320a319854339db16935550c61936ac4538ec9cb2e648b2ee0577bca2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80180a20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 auStackX_0 [4];
  undefined4 local_50 [20];
  
  puVar4 = local_50;
  puVar3 = local_50;
  if (_DAT_80000300 == 2) {
    puVar1 = (undefined4 *)&DAT_800134f0;
  }
  else {
    puVar1 = (undefined4 *)&DAT_80012c30;
  }
  puVar2 = puVar1 + 0x14;
  do {
    uVar5 = puVar1[1];
    uVar6 = puVar1[2];
    uVar7 = puVar1[3];
    *puVar4 = *puVar1;
    puVar4[1] = uVar5;
    puVar4[2] = uVar6;
    puVar4[3] = uVar7;
    puVar1 = puVar1 + 4;
    puVar4 = puVar4 + 4;
  } while (puVar1 != puVar2);
  puVar4 = (undefined4 *)&DAT_801129c8;
  local_50[2] = 0x108;
  local_50[10] = 0x838;
  local_50[0xf] = 0x418;
  local_50[8] = 0x1a6;
  local_50[0xb] = 0x300;
  local_50[0x10] = 0x300;
  local_50[7] = 0x6802f0;
  local_50[0xc] = 0x7301ad;
  local_50[0x11] = 0x7501af;
  do {
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    uVar7 = puVar3[3];
    *puVar4 = *puVar3;
    puVar4[1] = uVar5;
    puVar4[2] = uVar6;
    puVar4[3] = uVar7;
    puVar3 = puVar3 + 4;
    puVar4 = puVar4 + 4;
  } while (puVar3 != auStackX_0);
  return;
}
