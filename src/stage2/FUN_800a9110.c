/* FUN_800a9110
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9110  body 0x800a9110..0x800a924b  size 316 B
 * body sha256 77cecd1a42a4718e032c95401813ce2e11574a9818c851975dce47b20d1a4aa8
 * provider record sha256 1d9bc5e9a3b18391cfbcdf3c9a212ebd50d92860b805870867affd5987f7ca71
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9110(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  iVar6 = 0;
  if (DAT_80147a58 != 0) {
    pcVar5 = &DAT_801481e0;
    do {
      if (*pcVar5 != '\x01') goto LAB_800a9220;
      uVar1 = FUN_800a5c08(iVar6);
      uVar4 = *(uint *)(pcVar5 + 0x10);
      if (uVar4 == uVar1) {
LAB_800a9218:
        *(uint *)(pcVar5 + 0x10) = uVar1;
      }
      else if (uVar4 < uVar1) {
        cVar2 = (**(code **)(pcVar5 + 4))
                          (*(int *)(pcVar5 + 8) + uVar4 * 2,uVar1 - uVar4,0,0,
                           *(undefined4 *)(pcVar5 + 0x14));
        if (cVar2 != '\0') {
          iVar3 = *(int *)(pcVar5 + 8) + *(int *)(pcVar5 + 0x10) * 2;
          uVar4 = uVar1 - *(int *)(pcVar5 + 0x10);
LAB_800a9210:
          FUN_800a5c34(iVar3,uVar4);
          goto LAB_800a9218;
        }
        *(uint *)(pcVar5 + 0x10) = uVar1;
      }
      else {
        cVar2 = (**(code **)(pcVar5 + 4))
                          (*(int *)(pcVar5 + 8) + uVar4 * 2,*(int *)(pcVar5 + 0xc) - uVar4,
                           *(undefined4 *)(pcVar5 + 8),uVar1,*(undefined4 *)(pcVar5 + 0x14));
        if (cVar2 != '\0') {
          FUN_800a5c34(*(int *)(pcVar5 + 8) + *(int *)(pcVar5 + 0x10) * 2,
                       *(int *)(pcVar5 + 0xc) - *(int *)(pcVar5 + 0x10));
          iVar3 = *(int *)(pcVar5 + 8);
          uVar4 = uVar1;
          goto LAB_800a9210;
        }
        *(uint *)(pcVar5 + 0x10) = uVar1;
      }
LAB_800a9220:
      iVar6 = iVar6 + 1;
      pcVar5 = pcVar5 + 0x18;
    } while (iVar6 < (int)(uint)DAT_80147a58);
  }
  return;
}
