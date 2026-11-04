/* func_80161cf0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161e5f  size 368 B
 * body sha256 13afa3895461c307ff9e0a3bee29d8da55a1bbcfa5f9cead2a05cab2eddb1358
 * provider record sha256 2356938babadcdf6f5c0ecbf000b4a9ddd7403901906aed3357f42a30ca79c5b
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  uint uVar1;
  uint uVar2;
  uint *in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) == 0) {
      *(undefined1 *)((int)in_a0 + 0x2d6) = 0;
    }
    else {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    if (*(char *)((int)in_a0 + 0x2ce) != '\0') {
      *(char *)((int)in_a0 + 0x2ce) = *(char *)((int)in_a0 + 0x2ce) + -1;
    }
    (*(code *)(&PTR_FUN_80166650)[*(byte *)(in_a0 + 1)])();
    FUN_80165c74();
    if (*(char *)((int)in_a0 + 0x2cf) != '\0') {
      uVar1 = func_0x80033604();
      if ((uVar1 & 3) == 0) {
        func_0x80033604();
        FUN_801663a4();
        func_0x80033604();
        FUN_801663a4();
      }
      else {
        FUN_80166270();
      }
      *(char *)((int)in_a0 + 0x2cf) = *(char *)((int)in_a0 + 0x2cf) + -1;
    }
    uVar1 = *in_a0;
    *in_a0 = uVar1 & 0xe3ffffff;
    uVar2 = 0x18000000;
    if ((*(char *)(in_a0 + 0xaf) == '\0') &&
       (uVar2 = 0x18000000, *(char *)((int)in_a0 + 0x2c5) == '\0')) {
      uVar2 = 0xc000000;
    }
    *in_a0 = uVar1 & 0xe3ffffff | uVar2;
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
