/* FUN_80164910
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164910  body 0x80164910..0x801649bf  size 176 B
 * body sha256 831158efb2aa4bf410fc06c14b648063b82ad016fbb60de2398bd61d56fe962b
 * provider record sha256 36cf69a5d208dc5fce6b9d3746967003031e3421e2ef648eb9a712d9300a1490
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164910(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 0x2d2) == '\0') {
    FUN_801647fc(param_1,param_2,param_3);
  }
  else {
    *(uint *)(param_1 + 4) =
         (uint)*(byte *)(param_1 + 0x2cf) * 0x10000 + (uint)*(byte *)(param_1 + 0x2d0) * 0x100 +
         (uint)*(byte *)(param_1 + 0x2d1) + 0x1000000;
    if (*(char *)(param_1 + 0x2d8) != '\x01') {
      FUN_8016703c(param_1,0,0);
    }
    FUN_80162148(param_1,param_2,param_3);
  }
  return;
}
