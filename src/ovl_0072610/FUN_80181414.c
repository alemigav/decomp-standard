/* FUN_80181414
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80181414  body 0x80181414..0x8018152b  size 280 B
 * body sha256 14615eb8ab27380ff79ee2c6d0421ab3db4acedaa714778c5b53f3d4348624a0
 * provider record sha256 d7359de0eee0de029c3bde86796bb6da228effe8f6e456f8c28082814ca4ba24
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80181414(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = (int)((uint)*(ushort *)(_DAT_801344b0 * 0x112 + -0x7fecbae8) -
               (uint)*(ushort *)(_DAT_801344b0 * 0x112 + -0x7fecbaec)) >> 1;
  for (uVar6 = 0; uVar6 < *(ushort *)(_DAT_801344b0 * 0x112 + -0x7fecbaea); uVar6 = uVar6 + 1) {
    uVar3 = 0;
    if (uVar5 != 0) {
      puVar4 = param_1;
      do {
        iVar1 = _DAT_801344b0;
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        iVar2 = uVar3 + uVar5;
        uVar3 = uVar3 + 1;
        param_1[iVar2 + (uint)*(ushort *)(iVar1 * 0x112 + -0x7fecbaec)] = 0;
      } while (uVar3 < uVar5);
    }
    param_1 = param_1 + *(ushort *)(_DAT_801344b0 * 0x112 + -0x7fecbae8);
  }
  return;
}
