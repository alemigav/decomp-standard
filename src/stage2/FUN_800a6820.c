/* FUN_800a6820
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a6820  body 0x800a6820..0x800a6c03  size 996 B
 * body sha256 69e814d4403ca87ebf67d14028f648607ce8a2c85362a753afbaa81d12e7fec7
 * provider record sha256 7c76fa1d7a4743c99e093db9bc450d1ed433893a61faacd4201dd357093c776e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800a6820(uint param_1,uint param_2,undefined1 param_3,uint param_4,char param_5,
                undefined1 param_6,undefined2 param_7,undefined2 param_8,undefined1 param_9,
                short param_10)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = param_1 >> 0x10;
  iVar6 = (param_1 >> 8 & 0xff) + (int)param_10;
  if (iVar6 < 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = 0xff;
    if (iVar6 < 0x100) {
      iVar7 = iVar6;
    }
  }
  uVar8 = param_1 & 0xffff00ff | iVar7 << 8;
  uVar3 = uVar9 & 0xc000;
  if (uVar3 == 0x4000) {
    iVar6 = FUN_800adf54(uVar9);
    uVar3 = param_2 & 0x7f;
    if (iVar6 == 0) {
      return -1;
    }
    psVar5 = (short *)(uVar3 * 8 + iVar6);
    if (*psVar5 == -1) {
      return -1;
    }
    if ((*(byte *)((int)psVar5 + 3) & 0x80) == 0) {
      uVar8 = (*(byte *)((param_2 & 0xff) * 8 + iVar6 + 3) - 0x40) + (param_4 & 0xff);
      param_4 = 0;
      if ((-1 < (int)uVar8) && (param_4 = uVar8, 0x7f < (int)uVar8)) {
        param_4 = 0x7f;
      }
    }
    else {
      param_4 = 0x80;
    }
    uVar8 = (param_2 & 0x7f) + (int)*(char *)(uVar3 * 8 + iVar6 + 2);
    uVar4 = 0x7f;
    if (((int)uVar8 < 0x80) && (uVar4 = uVar8, (int)uVar8 < 0)) {
      uVar4 = 0;
    }
    iVar7 = iVar7 + *(short *)(uVar3 * 8 + iVar6 + 4);
    if (iVar7 < 0x100) {
      if (iVar7 < 0) {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 0xff;
    }
    uVar1 = *(ushort *)(uVar3 * 8 + iVar6);
    uVar8 = param_1 & 0xff | iVar7 << 8 | (uint)uVar1 << 0x10;
    if ((uVar1 & 0xc000) != 0) {
      param_2 = uVar4 & 0xff | param_2 & 0x80;
      goto LAB_800a6bc0;
    }
    if (param_5 != -1) {
      cVar2 = FUN_800ac77c(param_5,param_6);
      if ((cVar2 != '\0') && (iVar6 = FUN_800a62c0(uVar4 & 0x7f,param_5,param_6), iVar6 != -1)) {
        return iVar6;
      }
    }
    param_2 = uVar4 & 0xff | param_2 & 0x80;
  }
  else {
    if (0x4000 < uVar3) {
      if (uVar3 != 0x8000) {
        return -1;
      }
      uVar9 = uVar8 >> 0x10;
      param_2 = param_2 & 0xff;
LAB_800a6bc0:
      iVar6 = FUN_800a64c8(uVar8,uVar9,param_2,param_3,param_4 & 0xff,param_5,param_6,param_7,
                           param_8,param_9);
      return iVar6;
    }
    if (uVar3 != 0) {
      return -1;
    }
    if (param_5 != -1) {
      cVar2 = FUN_800ac77c(param_5,param_6);
      if ((cVar2 != '\0') && (iVar6 = FUN_800a62c0(param_2 & 0x7f,param_5,param_6), iVar6 != -1)) {
        return iVar6;
      }
    }
    uVar9 = uVar8 >> 0x10;
    param_2 = param_2 & 0xff;
  }
  iVar6 = FUN_800b185c(uVar8,uVar9,param_2,param_3,param_4 & 0xff,param_5,param_6,param_7,param_8,1,
                       param_9);
  return iVar6;
}
