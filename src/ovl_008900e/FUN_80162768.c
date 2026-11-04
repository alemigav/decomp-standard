/* FUN_80162768
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162768  body 0x80162768..0x8016289f  size 312 B
 * body sha256 fc460507895421359d44f8716c8673edf8182034790c4b597fedf05267ab5ae4
 * provider record sha256 06fd90b3101179234fbd1058004bef32d0d9c69d6b23589bef6ac6cd1ffaf69e
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80162768(int param_1)

{
  uint uVar1;
  
  if (-1 < _DAT_800e1322) {
    if (*(char *)(param_1 + 4) != '\a') {
      if ((*(ushort *)(param_1 + 0x2c8) & 1) == 0) {
        if (*(byte *)(param_1 + 0xd) < 2) {
          *(undefined1 *)(param_1 + 0x2b5) = 1;
          return *(undefined4 *)(&DAT_800e13e8 + (uint)*(byte *)(param_1 + 0xd) * 4);
        }
        uVar1 = func_0x80036ea0(*(undefined4 *)(param_1 + 0x28c),3000,9000,0x238c);
        if (uVar1 == 1) {
          if ((_DAT_800e1128 & 5) == 0) {
            return 0;
          }
          *(undefined1 *)(param_1 + 0x2b5) = 1;
        }
        else if (uVar1 == 0) {
          if ((_DAT_800e1128 & 0x17) == 0) {
            return 0;
          }
          *(undefined1 *)(param_1 + 0x2b5) = 1;
        }
        else {
          if (3 < uVar1) {
            return 0;
          }
          if ((_DAT_800e1128 & 5) == 0) {
            return 0;
          }
          *(undefined1 *)(param_1 + 0x2b5) = 1;
        }
      }
      return 0x800e1130;
    }
    *(undefined1 *)(param_1 + 0x2b5) = 0;
  }
  return 0;
}
