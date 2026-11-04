/* FUN_80162fec
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80162fec  body 0x80162fec..0x801630d3  size 232 B
 * body sha256 dea2ec83a230073296f06cad1598cfc7628506e75ace494736c1c72f8b32cf7a
 * provider record sha256 1f789559181938b06453e07c458b6e2eb5311557cda5ee0c876b14fbbb856139
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162fec(int param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if (((sVar1 == 0) && (uVar3 < 4000)) && (*(char *)(param_1 + 0x2ba) == '\0')) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  if ((sVar2 == 0) && (uVar3 < 2000)) {
    *(undefined4 *)(param_1 + 4) = 0x1080000;
  }
  if (*(short *)(param_1 + 0x1f2) < 700) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  }
  return;
}
