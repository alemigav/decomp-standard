/* FUN_8017b7e8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b7e8  body 0x8017b7e8..0x8017b8f3  size 268 B
 * body sha256 97716c56490656c6d8a959e56dfe039ea680486dbfc93421e9d4e4be9b5696d4
 * provider record sha256 5d0a350d6d4edc618c261978189102e1bcb985be953aa6454a6b92e5440813c9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017b824) */

void FUN_8017b7e8(void)

{
  uint uVar1;
  
  uVar1 = FUN_8017b50c(DAT_80186c94[1],DAT_80186c94,0x800);
  DAT_80186c94[2] = *DAT_80186c94;
  if ((int)uVar1 < 0x800) {
    if ((int)uVar1 < 0) {
      uVar1 = 0;
    }
    for (; (uVar1 & 3) != 0; uVar1 = uVar1 + 1) {
      *(undefined1 *)(*DAT_80186c94 + uVar1) = 0;
    }
    for (; (int)uVar1 < 0x800; uVar1 = uVar1 + 4) {
      *(undefined1 *)(*DAT_80186c94 + uVar1) = 0;
      *(undefined1 *)(*DAT_80186c94 + uVar1 + 1) = 0;
      *(undefined1 *)(*DAT_80186c94 + uVar1 + 2) = 1;
      *(undefined1 *)(*DAT_80186c94 + uVar1 + 3) = 0xb7;
    }
  }
  return;
}
