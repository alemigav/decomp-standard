/* FUN_80162694
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162694  body 0x80162694..0x801627c7  size 308 B
 * body sha256 fdbea2a55a7c922ae2fed4e71531386087b836bd236469e4283aab3dabf0f3b6
 * provider record sha256 aed138803713a00aaf52a2b4d833dff0e6e612b772e3b9d2c797c42c5e90af09
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162694(int param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined1 uVar4;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = 300 - (uVar1 & 0x1f);
  }
  if (*(short *)(param_1 + 0x270) == 0) {
    return;
  }
  uVar3 = _DAT_800e1134 & 0xffff0000;
  if ((uVar3 == 0x1010000) || (uVar3 == 0x1030000)) {
    sVar2 = *(short *)(param_1 + 500) + -10;
  }
  else {
    if (uVar3 != 0x1020000) goto LAB_80162728;
    sVar2 = *(short *)(param_1 + 500) + -0xf;
  }
  *(short *)(param_1 + 500) = sVar2;
LAB_80162728:
  uVar1 = *(short *)(param_1 + 500) - 1;
  *(ushort *)(param_1 + 500) = uVar1;
  if (((int)((uint)uVar1 << 0x10) < 1) || (_DAT_800e1322 < 0)) {
    uVar3 = func_0x80033604();
    if ((0x5335 >> (uVar3 & 0xf) & 1U) == 0) {
      *(undefined2 *)(param_1 + 500) = 0;
    }
    else {
      uVar3 = func_0x80033604();
      uVar4 = 2;
      if ((0x990 >> (uVar3 & 0xf) & 1U) != 0) {
        uVar4 = 5;
      }
      *(undefined1 *)(param_1 + 0x2b9) = uVar4;
      *(undefined2 *)(param_1 + 0x2ba) = _DAT_800e115a;
      *(undefined2 *)(param_1 + 700) = _DAT_800e1162;
      *(undefined2 *)(param_1 + 6) = 0x100;
      *(undefined2 *)(param_1 + 500) = 0;
    }
  }
  return;
}
