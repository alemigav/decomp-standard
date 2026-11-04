/* FUN_8016289c
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x8016289c  body 0x8016289c..0x8016292f  size 148 B
 * body sha256 6befb724ba1d9e24c4bb57b855f3269547a567d53422a19d430c6bb84a855d74
 * provider record sha256 4f4d606657dcfd5ef2c3386ca76fe25f012f54fcc54ae5b1a68a7f9e26c59dd0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016289c(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80162930();
  }
  else {
    FUN_80162a14(param_1);
  }
  *(undefined1 *)(param_1 + 0x2ca) = *(undefined1 *)(param_1 + 7);
  *(undefined1 *)(param_1 + 0x2c9) = *(undefined1 *)(param_1 + 6);
  if ((*(short *)(param_1 + 0x270) == 1) || ((_DAT_800e1128 & 0x10) != 0)) {
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    *(undefined4 *)(param_1 + 4) = 0x30a0000;
  }
  return;
}
