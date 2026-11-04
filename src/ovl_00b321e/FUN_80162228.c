/* FUN_80162228
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162228  body 0x80162228..0x801623ab  size 388 B
 * body sha256 6d1b2a38a8195f78f367a0062746b6f8c51eb3affbcd9de4e541ad1a5a28e82d
 * provider record sha256 89afe42deb2c1c3ea546d4c3ef7c9e515171f3c0a14054529bae90c62b38a672
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162228(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if ((int)uVar1 < 0x2711) {
    if (((int)uVar1 < 0x1771) && (*(char *)(param_1 + 0x2c8) == '\0')) {
      *(undefined1 *)(param_1 + 0x2be) = 2;
      *(undefined1 *)(param_1 + 5) = 4;
      if ((*(byte *)(param_1 + 0x2bd) & 1) != 0) {
        uVar1 = func_0x80033604();
        *(undefined *)(param_1 + 5) = (&DAT_801666ac)[uVar1 & 7];
      }
      *(undefined1 *)(param_1 + 0x2c7) = 0;
      *(undefined1 *)(param_1 + 0x2c6) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x2be) = 1;
      uVar1 = func_0x80033604();
      *(undefined *)(param_1 + 5) = (&DAT_801666a4)[uVar1 & 7];
      if ((*(byte *)(param_1 + 0x2bd) & 1) == 0) {
        *(undefined1 *)(param_1 + 5) = 9;
        *(undefined1 *)(param_1 + 0x2c7) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x2c7) = 1;
      }
      *(undefined1 *)(param_1 + 0x2c6) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x2be) = 0;
    uVar1 = func_0x80033604();
    *(undefined *)(param_1 + 5) = (&DAT_801666a4)[uVar1 & 7];
    if ((*(byte *)(param_1 + 0x2bd) & 1) == 0) {
      *(undefined1 *)(param_1 + 5) = 9;
    }
    *(undefined1 *)(param_1 + 0x2c7) = 1;
    *(undefined1 *)(param_1 + 0x2c6) = 0;
  }
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 100) = 0;
  FUN_801623ac(param_1);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
