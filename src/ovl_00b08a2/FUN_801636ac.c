/* FUN_801636ac
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801636ac  body 0x801636ac..0x80163763  size 184 B
 * body sha256 24e8f2cb11edd16a8677f7190e1e9ed236b1428932e4ac00cc283a19c8e6f4e5
 * provider record sha256 02108763d320985fe4676eef505e400c57dc163dbc13b014d87629ca2bd5d243
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801636ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7001f00;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80166704(param_1,*(int *)(_DAT_800e1364 + 0x50) + -500,*(undefined4 *)(_DAT_800e1364 + 0x54),
               0x40);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1040000;
  }
  return;
}
