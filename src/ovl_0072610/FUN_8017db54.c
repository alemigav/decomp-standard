/* FUN_8017db54
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017db54  body 0x8017db54..0x8017dca3  size 336 B
 * body sha256 878c59ab6bd57cdaec9d4c81a06611875eeaa837b2a0a48059dc6209ac28cfef
 * provider record sha256 aeb64d338cc0c69408df8e3f8ddf2e0fa17dbeff14dc822d107acd27499a7d11
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017db54(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_8017bec8(4);
  DAT_8018578c = iVar1 + -1;
  iVar1 = FUN_8017bec8(4);
  DAT_80185790 = iVar1 + -1;
  iVar1 = FUN_8017bec8(4);
  DAT_80185794 = iVar1 + -1;
  iVar1 = FUN_8017bec8(4);
  DAT_80185798 = iVar1 + -1;
  DAT_8018579c = FUN_8017bec8(2);
  DAT_801857a0 = FUN_8017bec8(2);
  DAT_801857a4 = FUN_8017bec8(1);
  DAT_801857a8 = FUN_8017bec8(1);
  DAT_801857ac = FUN_8017bec8(1);
  uVar2 = FUN_8017bec8(1);
  *(undefined4 *)(DAT_80186c94 + 0x424) = uVar2;
  DAT_801857b0 = FUN_8017bec8(1);
  uVar2 = FUN_8017bec8(1);
  *(undefined4 *)(DAT_80186c94 + 0x428) = uVar2;
  DAT_801857b4 = FUN_8017bec8(1);
  FUN_8017bec8(1);
  DAT_801857b8 = FUN_8017bec8(1);
  iVar1 = FUN_8017bec8(1);
  if (iVar1 != 0) {
    FUN_8017bec8(1);
    FUN_8017bec8(3);
    FUN_8017bec8(1);
    FUN_8017bec8(7);
    FUN_8017bec8(8);
  }
  return;
}
