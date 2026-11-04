/* FUN_801640ac
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801640ac  body 0x801640ac..0x801641e7  size 316 B
 * body sha256 591c004593335b61ccfebd4c5f077d94ac819ccad0d74f44b10a14df07f3da42
 * provider record sha256 5e0b7363e9784010428ed30da960130cecaf1f7cdbc8b4ed5eff45931c19c6e8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801640ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2cd) * 0xd000000 + 0x3f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    *(undefined1 *)(param_1 + 0x2c6) = 1;
    *(undefined1 *)(param_1 + 0x2c7) = 0;
    *(undefined1 *)(param_1 + 0x2c8) = 8;
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
    *(undefined1 *)(param_1 + 0x2b6) = 0;
  }
  else {
    uVar1 = func_0x80033604();
    if ((uVar1 & 7) == 0) {
      uVar1 = func_0x80033604();
      FUN_80166b98(param_1,(uVar1 & 0xff) % 3 + 0xb,4);
    }
    if (*(char *)(param_1 + 0x2c7) != '\0') {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  return;
}
