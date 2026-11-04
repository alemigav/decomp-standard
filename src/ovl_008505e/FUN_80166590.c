/* FUN_80166590
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166590  body 0x80166590..0x801665e7  size 88 B
 * body sha256 37ce764b318fa25a27ccc2d8cd017f4033558f74fe376fc9700f139c15dfa265
 * provider record sha256 5d5dd29808efd1a7a9772c5203743a0f996c10562f9b500655a40dc40880d814
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166590(int param_1,short param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = (uint)(0 < param_2) << 1;
  }
  if ((*(char *)(param_1 + 0x1e8) != (&DAT_80166f78)[iVar1]) &&
     (*(undefined *)(param_1 + 0x1e8) = (&DAT_80166f78)[iVar1], *(byte *)(param_1 + 0x1ea) < 7)) {
    *(undefined1 *)(param_1 + 0x1ea) = 0xf;
  }
  return;
}
