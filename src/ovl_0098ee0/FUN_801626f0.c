/* FUN_801626f0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801626f0  body 0x801626f0..0x80162823  size 308 B
 * body sha256 f13d0e097a0845a106648a0f4c4f6d1444f292c09c0d1aa37d856a19341072c3
 * provider record sha256 dcf9f53cad2daba120d30dea9753b74b13fe23333c2ae6493e88f37e4ee88e64
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801626f0(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x2c4);
  if (bVar1 != 4) {
    if (bVar1 < 5) {
      if (bVar1 == 0) {
        DAT_80166900 = (uint)*(byte *)(param_1 + 0x26e);
        FUN_80162568(param_1,1,0,6,0x1000,3);
        *(code **)(param_1 + 700) = FUN_801626f0;
        *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
        return;
      }
      goto LAB_80162804;
    }
    if ((bVar1 != 7) && (bVar1 != 10)) goto LAB_80162804;
  }
  DAT_80166904 = (uint)*(byte *)(param_1 + 0x26e);
  *(undefined1 *)(param_1 + 0x26e) = (undefined1)DAT_80166900;
  if ((_DAT_800df914 & 0x40) != 0) {
    FUN_80162568(param_1,1,0,6,0x1000,3);
  }
  *(undefined1 *)(param_1 + 0x26e) = (undefined1)DAT_80166904;
  if (*(char *)(param_1 + 0x2c4) == '\n') {
    *(undefined4 *)(param_1 + 700) = 0;
  }
LAB_80162804:
  *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
  return;
}
