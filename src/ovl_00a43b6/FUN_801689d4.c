/* FUN_801689d4
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801689d4  body 0x801689d4..0x80168aaf  size 220 B
 * body sha256 39a935ae67ac59a51c5fdf24c5464e79a0455ba10f1a8681c79524c848c8586a
 * provider record sha256 a901cb0b59ab4463a3956c6da49ff328857e867333755578b43cb916ec8e6560
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801689d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x300;
    *(undefined1 *)(param_1 + 6) = 1;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    func_0x80077adc(0x4000001,param_1 + 0x28);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1e9) = 0;
  func_0x80089d54(param_1,param_2,param_3,0x400);
  func_0x80032dbc(param_1,*(undefined4 *)(_DAT_800e13f0 + 0x28),
                  *(undefined4 *)(_DAT_800e13f0 + 0x30),0x100);
  return;
}
