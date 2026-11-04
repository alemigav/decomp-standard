/* FUN_80162858
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162858  body 0x80162858..0x801628df  size 136 B
 * body sha256 06dce07a3f1e71ac160695730cb02f721f64603f123c02ead2ee83df334dc464
 * provider record sha256 6480f76cf9c363015cd5eccad108395eaa721cb188a9a6cb87ce0246d3c9a1d3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162858(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 0xf) + 0xf;
  }
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if ((sVar1 == 1) && (*(undefined4 *)(param_1 + 4) = 0x1010000, _DAT_800e1322 < 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1090000;
  }
  FUN_801623ac(param_1);
  return;
}
