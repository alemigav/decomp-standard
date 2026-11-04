/* FUN_80080af4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080af4  body 0x80080af4..0x80080c67  size 372 B
 * body sha256 a9a99912e5994ebc89a97946972408f4e6d3959ea60f5617ec247c297c76adc7
 * provider record sha256 4ffd8d8ad06498d31e859bc73a4235896d8b7e230d53814a02347534ce84450e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80080af4(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = 0;
  uVar7 = 0;
  iVar2 = 2;
  while( true ) {
    if ((&DAT_8011b54c)[iVar2] != 0) {
      uVar7 = uVar7 + 1;
    }
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
  }
  uVar8 = 0;
  iVar2 = uVar7 - 1;
  if (uVar7 != 0) {
    puVar6 = &DAT_8011b560;
    piVar5 = &DAT_8011b54c;
    do {
      iVar3 = *piVar5;
      if (*puVar6 < param_2) {
        iVar1 = FUN_80032e74(param_1,*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x30),
                             0x400);
        if (iVar1 == 0) {
          uVar4 = uVar4 | 0x10000;
        }
        else {
          uVar4 = uVar4 | 0x20000;
        }
        uVar8 = uVar8 + 1;
      }
      iVar3 = FUN_80032e74(&DAT_800e1130,*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x30)
                           ,0x400);
      if (iVar3 == 0) {
        uVar4 = uVar4 | 1;
      }
      else {
        uVar4 = uVar4 | 2;
      }
      puVar6 = puVar6 + 1;
      iVar2 = iVar2 + -1;
      piVar5 = piVar5 + 1;
    } while (iVar2 != -1);
  }
  iVar2 = 0;
  if (uVar7 != 0) {
    if ((uVar4 & 0xffff0000) == 0) {
      iVar2 = uVar4 * 2;
      if (1 < uVar7) {
        iVar2 = iVar2 + 4;
      }
    }
    else if (uVar8 < 2) {
      iVar2 = (uVar4 >> 0xf) - 1;
    }
    else {
      iVar2 = (uVar4 >> 0xf) + 3;
    }
  }
  return iVar2;
}
