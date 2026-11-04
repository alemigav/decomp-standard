/* FUN_8009e9b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e9b0  body 0x8009e9b0..0x8009ec1b  size 620 B
 * body sha256 29eafe285e6d7c3884627d344d06005eb0916994adb5e4155537b5657062069d
 * provider record sha256 d9d658c640cb1a884c3731c69f75e280048bdb5ce2dcf7804fa47d62435a572e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8009eb0c) */
/* WARNING: Removing unreachable block (ram,0x8009ea08) */

void FUN_8009e9b0(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_5 == 0) {
    DAT_801342b4 = param_2 / 4;
    puVar2 = &DAT_80134428;
    puVar1 = &DAT_80133150;
    DAT_801342b0 = 4;
    DAT_801342b8 = (param_3 - param_1) * 0x200000 | 0x3000U | param_1 * 2 - 1U;
    DAT_801342bc = param_3 << 3;
    DAT_801342d8 = 0xb3755b69;
    DAT_801342dc = 0x2c0de2d1;
    DAT_801342e0 = 0x950b1000;
    DAT_801342e4 = 0x2000080;
    DAT_801342e8 = 0x40007c00;
    DAT_801342ec = 0x17f80;
    DAT_80134420 = ((param_4 - param_2 >> 1) * param_3 + ((uint)(param_3 - param_1) >> 1)) * 2;
    DAT_801342a8 = param_1;
    DAT_801342ac = param_2;
    do {
      uVar3 = puVar1[1];
      uVar4 = puVar1[2];
      uVar5 = puVar1[3];
      *puVar2 = *puVar1;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
      puVar1 = puVar1 + 4;
      puVar2 = puVar2 + 4;
    } while (puVar1 != &DAT_80133190);
  }
  else if (param_5 == 1) {
    DAT_801342b4 = param_2 / 2;
    puVar2 = &DAT_80134428;
    puVar1 = &DAT_80133190;
    DAT_801342b0 = 2;
    DAT_801342b8 = (param_3 - param_1) * 0x400000 | 0x1000U | param_1 * 4 - 1U;
    DAT_801342bc = param_3 << 3;
    DAT_801342d8 = 0xb3755b69;
    DAT_801342dc = 0x2c0de2d1;
    DAT_801342e0 = 0x950b1000;
    DAT_801342e4 = 0x2000080;
    DAT_801342e8 = 0x40007c00;
    DAT_801342ec = 0x17f80;
    DAT_80134420 = ((param_4 - param_2 >> 1) * param_3 + ((uint)(param_3 - param_1) >> 1)) * 4;
    DAT_801342a8 = param_1;
    DAT_801342ac = param_2;
    do {
      uVar3 = puVar1[1];
      uVar4 = puVar1[2];
      uVar5 = puVar1[3];
      *puVar2 = *puVar1;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
      puVar1 = puVar1 + 4;
      puVar2 = puVar2 + 4;
    } while (puVar1 != &DAT_801331d0);
  }
  return;
}
