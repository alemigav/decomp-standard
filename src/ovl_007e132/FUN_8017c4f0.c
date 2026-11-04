/* FUN_8017c4f0
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c4f0  body 0x8017c4f0..0x8017c5ef  size 256 B
 * body sha256 e4be275b96e7691534d761bad0dffb6cca9e38d9842bb9fd7691e2ee46260981
 * provider record sha256 06d75e649533d0d0b9013ee1f22d1b72b902d5e271732dc458939ade86a6e2c8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c4f0(void)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(_DAT_800df92c + 0x2c) + _DAT_800e8cac * 0x28;
  FUN_8017c8f0();
  FUN_8017c664();
  DAT_8017e704 = DAT_8017e704 + 1;
  if (DAT_8017e704 == 0x6e) {
    func_0x800274f8(0x200,0x200,7,3);
  }
  if (0xa2 < DAT_8017e704) {
    DAT_8017e702 = DAT_8017e702 + 1;
  }
  uVar1 = *(ushort *)(iVar2 + 0x22);
  *(char *)(iVar2 + 4) = *(char *)(iVar2 + 4) - (*(char *)(iVar2 + 4) != '\0');
  *(char *)(iVar2 + 5) = *(char *)(iVar2 + 5) - (*(char *)(iVar2 + 5) != '\0');
  *(char *)(iVar2 + 6) = *(char *)(iVar2 + 6) - (*(char *)(iVar2 + 6) != '\0');
  if (100 < uVar1) {
    uVar1 = uVar1 - 100;
  }
  *(ushort *)(iVar2 + 0x22) = uVar1;
  return;
}
