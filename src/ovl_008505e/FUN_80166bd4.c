/* FUN_80166bd4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166bd4  body 0x80166bd4..0x80166c73  size 160 B
 * body sha256 37affc8ef07adfeb29fcdf15bb6fa9004aa5c1c3b4093b317c7c6255e2f96202
 * provider record sha256 5d088984837b3e7551ac977ae5eca6234b65a7b5135ddf260b31e1ea191d6989
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80166bd4(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x2c3) = 0;
  iVar1 = _DAT_800e13ec;
  iVar2 = -0x7ff1eed0;
  if ((_DAT_800e110c & 0x10000000) != 0) {
    if ((*(uint *)(param_1 + 0x290) & 0xc0000000) == 0x40000000) {
      *(undefined1 *)(param_1 + 0x2c3) = 1;
      iVar2 = iVar1;
    }
    iVar1 = _DAT_800e13ec;
    if ((((*(uint *)(param_1 + 0x290) & 0xc0000000) == 0x80000000) &&
        ((*(uint *)(param_1 + 0x290) & 0x3fffffff) < *(uint *)(param_1 + 0x28c))) &&
       (0x14 < *(short *)(_DAT_800e13ec + 0x1f2))) {
      *(undefined1 *)(param_1 + 0x2c3) = 1;
      iVar2 = iVar1;
    }
  }
  return iVar2;
}
