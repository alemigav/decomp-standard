/* FUN_80090ca0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090ca0  body 0x80090ca0..0x80090e0f  size 368 B
 * body sha256 140127ed16ac28da1872a0e41756a2d956f1e8cde2bb44fdc9f10397b583b11c
 * provider record sha256 2e5778a94897ab469b4d2741fa11cc9d0913651d772198bb84f2694cda7a8a1b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090ca0(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  
  FUN_80043620();
  uVar3 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar3 = DAT_800c52dc + 0x3c004U;
  }
  iVar5 = uVar3 + 0xa64;
  iVar7 = 0xe;
  puVar6 = &UNK_8012fa10;
  do {
    iVar7 = iVar7 + -1;
    if (DAT_8012bfc1 == '\0') {
      uVar4 = 0x50;
    }
    else {
      uVar4 = 0x80;
    }
    FUN_8004786c(iVar5,uVar4,uVar4,uVar4);
    iVar1 = FUN_800837ac(&DAT_800e8db0,DAT_8012bfb2);
    if (((iVar1 != 0) && (puVar6[-7] == DAT_8012bfb2)) &&
       (iVar1 = FUN_800837ac(&DAT_800e8ec0,puVar6[-8]), iVar1 == 0)) {
      if ((DAT_800e110c & 0x40000000) == 0) {
        bVar2 = puVar6[-6] & 0x40;
      }
      else {
        if (((int)DAT_800e110c < 0) && ((puVar6[-6] & 0x40) != 0)) goto LAB_80090de0;
        bVar2 = puVar6[-6] & 0x80;
      }
      if (bVar2 == 0) {
        DAT_800df8b8 = FUN_80043988(DAT_800df8b8,iVar5,0,0);
      }
    }
LAB_80090de0:
    iVar5 = iVar5 + 0x28;
    puVar6 = puVar6 + -8;
    if (iVar7 == 0) {
      return;
    }
  } while( true );
}
