/* func_80161cf0
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161ec7  size 472 B
 * body sha256 907606705793e7889158f909ad86f157155cc8d14cfec862412188e0e4fdecd3
 * provider record sha256 94ef416adc0760656d281390c5cab91d19f99acf4e26bcafb8ef61cdf3a1af44
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int iVar1;
  int in_a0;
  int iVar2;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (*(char *)(in_a0 + 0x2b8) != '\0') {
      *(char *)(in_a0 + 0x2b8) = *(char *)(in_a0 + 0x2b8) + -1;
    }
    if (*(char *)(in_a0 + 0x2b9) != '\0') {
      *(char *)(in_a0 + 0x2b9) = *(char *)(in_a0 + 0x2b9) + -1;
    }
    if (*(char *)(in_a0 + 0x2c7) != '\0') {
      *(char *)(in_a0 + 0x2c7) = *(char *)(in_a0 + 0x2c7) + -1;
    }
    if (*(char *)(in_a0 + 0x2bf) != '\0') {
      *(char *)(in_a0 + 0x2bf) = *(char *)(in_a0 + 0x2bf) + -1;
    }
    (*(code *)(&PTR_FUN_80167dc4)[*(byte *)(in_a0 + 4)])();
    func_0x800347b0();
    if (*(char *)(in_a0 + 0x2b5) != '\0') {
      *(char *)(in_a0 + 0x2b5) = *(char *)(in_a0 + 0x2b5) + -1;
      func_0x80033604();
      FUN_80167374();
      func_0x80033604();
      FUN_80167374();
    }
    FUN_80166ef4();
    FUN_801678e4();
    FUN_8016726c();
    FUN_8016578c();
    func_0x8004db5c();
    func_0x8004dcb8();
    iVar2 = *(int *)(in_a0 + 0x28) - (int)*(short *)(in_a0 + 0x34);
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    iVar1 = *(int *)(in_a0 + 0x30) - (int)*(short *)(in_a0 + 0x38);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar2 < 0xc) {
      if (iVar1 < 0xc) {
        if ((*(uint *)(in_a0 + 0x1ac) & 1) == 0) {
          *(undefined1 *)(in_a0 + 0x2c1) = 0;
        }
        else {
          *(char *)(in_a0 + 0x2c1) = *(char *)(in_a0 + 0x2c1) + '\x01';
        }
      }
      else {
        *(undefined1 *)(in_a0 + 0x2c1) = 0;
      }
    }
    else {
      *(undefined1 *)(in_a0 + 0x2c1) = 0;
    }
  }
  return;
}
