/* FUN_80164ac8
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80164ac8  body 0x80164ac8..0x80164bff  size 312 B
 * body sha256 2ceff8cdfc1866d78c19530ca1babb0eb82d3a0512012142da0251e03b1b1abf
 * provider record sha256 3ff514a23932689b81a4f038fa1651ea033d58229709ff7dfc1189f90967f24a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164ac8(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x28c);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338);
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if (sVar3 != 0) {
    *(short *)(param_1 + 0x2b6) = *(short *)(param_1 + 0x2b6) + 2;
  }
  if (((sVar1 != 0) && (uVar4 < 5000)) && (0x5a < *(ushort *)(param_1 + 0x2b6))) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  if (((sVar2 == 0) && (uVar4 < 0xdac)) &&
     ((DAT_800e139f == '\0' &&
      ((*(char *)(param_1 + 0x2b9) == '\0' && (*(short *)(param_1 + 500) < 0x1e)))))) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  if (0xdac < uVar4) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
