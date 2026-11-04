/* FUN_80162bc4
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162bc4  body 0x80162bc4..0x80162cf7  size 308 B
 * body sha256 d87412627ad3af6193a4318b1c23b58234b1584465f5b58613e760451eeaa22e
 * provider record sha256 d5177c7ece8afbc7e831522babade7bcbe05f37dcf3394a49276d9f2781a4a02
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162bc4(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x2c4);
  if (bVar1 != 4) {
    if (bVar1 < 5) {
      if (bVar1 == 0) {
        DAT_80166654 = (uint)*(byte *)(param_1 + 0x26e);
        FUN_80162a18(param_1,1,0,6,0x2000,3);
        *(code **)(param_1 + 700) = FUN_80162bc4;
        *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
        return;
      }
      goto LAB_80162cd8;
    }
    if ((bVar1 != 7) && (bVar1 != 10)) goto LAB_80162cd8;
  }
  DAT_80166658 = (uint)*(byte *)(param_1 + 0x26e);
  *(undefined1 *)(param_1 + 0x26e) = (undefined1)DAT_80166654;
  if ((_DAT_800df914 & 0x40) != 0) {
    FUN_80162a18(param_1,1,0,6,0x1800,3);
  }
  *(undefined1 *)(param_1 + 0x26e) = (undefined1)DAT_80166658;
  if (*(char *)(param_1 + 0x2c4) == '\n') {
    *(undefined4 *)(param_1 + 700) = 0;
  }
LAB_80162cd8:
  *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
  return;
}
