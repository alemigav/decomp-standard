/* FUN_801657c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801657c8  body 0x801657c8..0x801658fb  size 308 B
 * body sha256 f555268984fe19fbf7d79596b1339a8b4ecf4572efd111826c5cc181dca26ec9
 * provider record sha256 31735fb78e3f74e7996ed819d6e7772b85b3bba28a2641fba451504bd4358240
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801657c8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    param_1[0x7a] = 0xc000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    if (*(char *)(param_1 + 0xb6) != '\x01') {
      FUN_8016703c(param_1,0,0);
    }
    *param_1 = *param_1 | 0x42;
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  if ((*(uint *)param_1[0x85] & 0x80000) != 0) {
    *param_1 = *param_1 & 0xe3ffffff;
    if (*(short *)(param_1 + 0x6a) != 0) {
      bVar1 = *(byte *)(param_1 + 0xb6);
      if ((8 < bVar1) && ((bVar1 < 0xb || (bVar1 == 0x10)))) {
        FUN_8016703c(param_1,0,7);
      }
      *(undefined1 *)((int)param_1 + 0x2d6) = 0xff;
      if (*(char *)((int)param_1 + 0x2da) == '\0') {
        *(undefined1 *)((int)param_1 + 0x2da) = 3;
        *(undefined1 *)((int)param_1 + 0x2db) = 1;
      }
    }
    param_1[1] = 0x7000000;
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      *(undefined2 *)((int)param_1 + 0x1f2) = 1;
      *(undefined1 *)(param_1 + 0xb0) = 1;
    }
  }
  return;
}
