/* FUN_8017d880
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d880  body 0x8017d880..0x8017d9e3  size 356 B
 * body sha256 8552ec04d2f15b643b64c8825f269e7dd1e27c155511bd97f06c69bdd3dac0b5
 * provider record sha256 704bf08c8cbf27ffb114f95b73f7ceea0862298f259d9759bb986c5577f5162f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d880(void)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar1 = FUN_8017bec8(1);
  if (iVar1 != 0) {
    iVar1 = 0;
    do {
      uVar2 = FUN_8017bec8(8);
      pbVar3 = &DAT_801854a0 + iVar1;
      iVar1 = iVar1 + 1;
      iVar4 = DAT_80186c94 + (uint)*pbVar3 * 4;
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      *(undefined4 *)(iVar4 + 0x21c) = uVar2;
    } while (iVar1 < 0x40);
  }
  iVar1 = FUN_8017bec8(1);
  if (iVar1 != 0) {
    iVar1 = 0;
    do {
      uVar2 = FUN_8017bec8(8);
      pbVar3 = &DAT_801854a0 + iVar1;
      iVar1 = iVar1 + 1;
      iVar4 = DAT_80186c94 + (uint)*pbVar3 * 4;
      *(undefined4 *)(iVar4 + 0x11c) = uVar2;
      *(undefined4 *)(iVar4 + 0x31c) = uVar2;
    } while (iVar1 < 0x40);
  }
  iVar1 = FUN_8017bec8(1);
  iVar4 = 0;
  if (iVar1 != 0) {
    do {
      uVar2 = FUN_8017bec8(8);
      pbVar3 = &DAT_801854a0 + iVar4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(DAT_80186c94 + (uint)*pbVar3 * 4 + 0x21c) = uVar2;
    } while (iVar4 < 0x40);
  }
  iVar1 = FUN_8017bec8(1);
  iVar4 = 0;
  if (iVar1 != 0) {
    do {
      uVar2 = FUN_8017bec8(8);
      pbVar3 = &DAT_801854a0 + iVar4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(DAT_80186c94 + (uint)*pbVar3 * 4 + 0x31c) = uVar2;
    } while (iVar4 < 0x40);
  }
  return;
}
