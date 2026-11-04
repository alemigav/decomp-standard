/* FUN_80181020
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80181020  body 0x80181020..0x801813c7  size 936 B
 * body sha256 42401d287ae28e4aa9b203484bbc9f12aebe9213f2df2a8a4938c3699ac362f4
 * provider record sha256 35001f4410b4b5a30105adaf7eacce13004793a6b283cb3434b986d86634352c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80181280) */
/* WARNING: Removing unreachable block (ram,0x80181298) */
/* WARNING: Removing unreachable block (ram,0x801812a0) */
/* WARNING: Removing unreachable block (ram,0x801812a4) */
/* WARNING: Removing unreachable block (ram,0x801812a8) */
/* WARNING: Removing unreachable block (ram,0x801812c8) */
/* WARNING: Removing unreachable block (ram,0x801812d0) */
/* WARNING: Removing unreachable block (ram,0x801812d4) */
/* WARNING: Removing unreachable block (ram,0x801812d8) */
/* WARNING: Removing unreachable block (ram,0x80181110) */
/* WARNING: Removing unreachable block (ram,0x80181120) */
/* WARNING: Removing unreachable block (ram,0x80181128) */
/* WARNING: Removing unreachable block (ram,0x80181130) */
/* WARNING: Removing unreachable block (ram,0x80181324) */
/* WARNING: Removing unreachable block (ram,0x80181350) */
/* WARNING: Removing unreachable block (ram,0x80181354) */
/* WARNING: Removing unreachable block (ram,0x80181360) */
/* WARNING: Removing unreachable block (ram,0x80181368) */
/* WARNING: Removing unreachable block (ram,0x8018136c) */

void FUN_80181020(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar1 = FUN_80180070(0x400);
  DAT_80185740 = iVar1 + 0x180;
  iVar1 = -0x180;
  do {
    puVar3 = (undefined1 *)(DAT_80185740 + iVar1);
    if (iVar1 < 0) {
      *puVar3 = 0;
    }
    else if (iVar1 < 0x100) {
      *puVar3 = (char)iVar1;
    }
    else {
      *puVar3 = 0xff;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x280);
  DAT_80185818 = 5;
  DAT_801857b8 = 1;
  DAT_801857a8 = 1;
  DAT_801857a0 = 3;
  DAT_80185788 = 1;
  DAT_8018575c = 1;
  iVar1 = DAT_80185744 + 0xf;
  if (iVar1 < 0) {
    iVar1 = DAT_80185744 + 0x1e;
  }
  DAT_8018574c = iVar1 >> 4;
  iVar1 = DAT_80185748 + 0xf;
  if (iVar1 < 0) {
    iVar1 = DAT_80185748 + 0x1e;
  }
  DAT_80185750 = iVar1 >> 4;
  DAT_80185754 = DAT_8018574c << 4;
  DAT_80185758 = DAT_80185750 << 4;
  DAT_80185760 = DAT_80185754 >> 1;
  DAT_80185764 = DAT_80185758 >> 1;
  puVar4 = &DAT_801857f0;
  puVar7 = &DAT_80185728;
  puVar6 = &DAT_8018571c;
  puVar5 = &DAT_80185710;
  DAT_80185768 = 6;
  do {
    if (puVar4 == &DAT_801857f0) {
      iVar1 = DAT_80185754 * DAT_80185758;
    }
    else {
      iVar1 = DAT_80185760 * DAT_80185764;
    }
    uVar2 = FUN_80180070(iVar1);
    *puVar5 = uVar2;
    uVar2 = FUN_80180070(iVar1);
    *puVar6 = uVar2;
    uVar2 = FUN_80180070(iVar1);
    *puVar7 = uVar2;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  } while ((int)puVar4 < -0x7fe7a804);
  FUN_80180014();
  return;
}
