/* FUN_80162f54
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162f54  body 0x80162f54..0x80162f97  size 68 B
 * body sha256 30500fe3fb66eb8e82332ba7e203735eb3e40ffd9bd976d759152f80dbdcb112
 * provider record sha256 f6cfe1d9b4222366801f00422323751fb8650d507488b3e5fd5036249f54d214
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162f54(uint *param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x7d) = 8;
  *(undefined2 *)(param_1 + 0x78) = param_2;
  *(undefined2 *)((int)param_1 + 0x1e2) = param_3;
  param_1[0x7a] = 0x14000700;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)((int)param_1 + 699) = 0;
  *param_1 = *param_1 & 0xefffffff | 0x4000000;
  return;
}
