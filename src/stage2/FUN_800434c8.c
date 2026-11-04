/* FUN_800434c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800434c8  body 0x800434c8..0x8004355f  size 152 B
 * body sha256 3989cd15f4a8bd17901326364af31615ac7b7e2a2cfa9b5fcf3496e7741ce114
 * provider record sha256 851b41fdbdd272a6b356437e988c4f3a07c0b664e0400c596f08846ca07d653d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800434c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int *param_7)

{
  FUN_80042de0();
  FUN_8004341c(param_4);
  FUN_80042de0(param_2);
  FUN_8004341c(param_5);
  FUN_80042de0(param_3);
  FUN_8004341c(param_6);
  *param_7 = (int)_DAT_80139a78;
  return (int)_DAT_80139a78;
}
