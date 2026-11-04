/* FUN_800ace1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ace1c  body 0x800ace1c..0x800acfa7  size 396 B
 * body sha256 f0f230e239f11314408ec6f4ea30d6bfb8c0438c17fd371d63d1fb09ac658a1c
 * provider record sha256 c38e00ca78a1d48b44c216fc66635f82d4067a793a795789612b3a1599ef3021
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ace1c(ushort param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  FUN_800a5678();
  iVar4 = 0;
  if (0 < _DAT_801529f0) {
    iVar1 = -0x7fead600;
    do {
      if (param_1 <= *(ushort *)(iVar1 + 4)) break;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar4 < _DAT_801529f0);
    if (iVar4 < _DAT_801529f0) {
      iVar1 = iVar4 * 0xc;
      if (*(ushort *)(&DAT_80152a04 + iVar1) == param_1) {
        *(short *)(iVar1 + -0x7fead5f8) = *(short *)(iVar1 + -0x7fead5f8) + 1;
        goto LAB_800acf48;
      }
      iVar1 = _DAT_801529f0 + -1;
      if (0xff < _DAT_801529f0) goto LAB_800acf48;
      if (iVar4 <= iVar1) {
        puVar3 = (undefined4 *)(iVar1 * 0xc + -0x7fead600);
        iVar2 = iVar1 * 0xc + 0xc;
        do {
          uVar5 = puVar3[1];
          uVar6 = puVar3[2];
          *(undefined4 *)(iVar2 + -0x7fead600) = *puVar3;
          *(undefined4 *)(&DAT_80152a04 + iVar2) = uVar5;
          *(undefined4 *)(iVar2 + -0x7fead5f8) = uVar6;
          puVar3 = puVar3 + -3;
          iVar1 = iVar1 + -1;
          iVar2 = iVar2 + -0xc;
        } while (iVar4 <= iVar1);
      }
      goto LAB_800acf5c;
    }
  }
  if (0xff < _DAT_801529f0) {
LAB_800acf48:
    FUN_800a56c0();
    return 0;
  }
LAB_800acf5c:
  _DAT_801529f0 = _DAT_801529f0 + 1;
  iVar4 = iVar4 * 0xc;
  *(ushort *)(&DAT_80152a04 + iVar4) = param_1;
  *(undefined4 *)(iVar4 + -0x7fead600) = param_2;
  *(undefined2 *)(iVar4 + -0x7fead5fa) = param_3;
  *(undefined2 *)(iVar4 + -0x7fead5f8) = 1;
  FUN_800a56c0();
  return 1;
}
