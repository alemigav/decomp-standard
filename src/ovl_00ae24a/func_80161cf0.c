/* func_80161cf0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161fbf  size 720 B
 * body sha256 92a4b4ee7e7809e76840354b72090e205898554975155b1e427ef2a4a58628c7
 * provider record sha256 a81dad7272bfffef707f9aa9fb40200f275f17580dc8d71e6dc237f40f809255
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80161f48) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  char cVar3;
  uint uVar1;
  uint uVar2;
  int in_a0;
  int iVar4;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (((*(ushort *)(in_a0 + 0x2c2) & 1) != 0) &&
       (cVar3 = *(char *)(in_a0 + 0x2bd) + -1, *(char *)(in_a0 + 0x2bd) = cVar3, cVar3 == -1)) {
      if (*(char *)(in_a0 + 0x2be) != '\0') {
        *(char *)(in_a0 + 0x2be) = *(char *)(in_a0 + 0x2be) + -1;
      }
      *(undefined1 *)(in_a0 + 0x2bd) = 0xf;
      if (*(char *)(in_a0 + 0x2be) == '\0') {
        *(ushort *)(in_a0 + 0x2c2) = *(ushort *)(in_a0 + 0x2c2) & 0xfffe;
      }
    }
    (*(code *)(&PTR_FUN_80166f10)[*(byte *)(in_a0 + 4)])();
    if (*(char *)(in_a0 + 0x2c5) != '\0') {
      *(char *)(in_a0 + 0x2c5) = *(char *)(in_a0 + 0x2c5) + -1;
    }
    if ((*(ushort *)(in_a0 + 0x2c2) & 8) == 0) {
      if ((*(byte *)(in_a0 + 0x1e9) & 0xf) == 0) {
        uVar1 = func_0x80033604();
        uVar2 = func_0x80033604();
        FUN_8016698c(0,7 - (uVar1 & 0xff) % 0xf,7 - (uVar2 & 0xff) % 0xf);
      }
      if ((*(byte *)(in_a0 + 0x1e9) & 0xf) == 7) {
        uVar1 = func_0x80033604();
        uVar2 = func_0x80033604();
        FUN_8016698c(1,7 - (uVar1 & 0xff) % 0xf,7 - (uVar2 & 0xff) % 0xf);
      }
    }
    FUN_801669b4();
    FUN_801669b4();
    FUN_8016680c();
    FUN_80166c40();
    func_0x80033648();
    FUN_80165670();
    *(undefined1 **)(in_a0 + 0x250) = &DAT_800e1130;
    func_0x800349d0();
    iVar4 = *(int *)(in_a0 + 0x234);
    *(undefined2 *)(iVar4 + 0x1d2) = *(undefined2 *)(iVar4 + 0x1d2);
    func_0x80040e58(iVar4 + 0x1d0,iVar4 + 0x180);
    *(undefined2 *)(iVar4 + 0x1d2) = *(undefined2 *)(iVar4 + 0x1d2);
    func_0x8004da40();
    *(undefined1 *)(in_a0 + 0xd) = 0xff;
    func_0x8004d3a0(_DAT_800e13e8);
  }
  return;
}
