/* func_80161cf0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161e33  size 324 B
 * body sha256 c650d124cdeea92fd42def55892877d28c83176f2ca8ca36cdea4d258c9ac31e
 * provider record sha256 7b284ae6f3c3956e056f3ec87cd9f60a7285f543cd861332daf2829a39cf7c13
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if (*(char *)(in_a0 + 0x2c1) != '\0') {
      *(undefined1 *)(in_a0 + 0x2c1) = 0;
      *(undefined1 *)(in_a0 + 0x2c3) = 0;
    }
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (*(char *)(in_a0 + 0x2db) != '\0') {
      *(char *)(in_a0 + 0x2db) = *(char *)(in_a0 + 0x2db) + -1;
    }
    (*(code *)(&PTR_FUN_80167240)[*(byte *)(in_a0 + 4)])();
    if (*(char *)(in_a0 + 0x2d8) != '\0') {
      *(char *)(in_a0 + 0x2d8) = *(char *)(in_a0 + 0x2d8) + -1;
      func_0x80033604();
      FUN_80166b98();
    }
    if (*(char *)(in_a0 + 0x2b6) == '\0') {
      func_0x8004db5c();
    }
    else {
      FUN_801670b8();
    }
    func_0x8004dcb8();
    FUN_80166db8();
    if (*(int *)(in_a0 + 0x28) == (int)*(short *)(in_a0 + 0x34)) {
      if (*(int *)(in_a0 + 0x30) == (int)*(short *)(in_a0 + 0x38)) {
        *(char *)(in_a0 + 0x2c9) = *(char *)(in_a0 + 0x2c9) + '\x01';
      }
      else {
        *(undefined1 *)(in_a0 + 0x2c9) = 0;
      }
    }
    else {
      *(undefined1 *)(in_a0 + 0x2c9) = 0;
    }
  }
  return;
}
