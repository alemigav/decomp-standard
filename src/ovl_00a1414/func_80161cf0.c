/* func_80161cf0
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161f7f  size 656 B
 * body sha256 3901716f9b36d55ef82405944a4a67d0883bf477c7498287e941920392c8d3ce
 * provider record sha256 481f921b8f6d8e631e271d8ec064c5520a0e8cd0596d07948d5c63bcf1df70fd
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  char cVar1;
  int in_a0;
  int iVar2;
  ushort local_18;
  
  func_0x800653d0();
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (((*(ushort *)(in_a0 + 0x2b8) & 2) != 0) &&
       (cVar1 = *(char *)(in_a0 + 0x2b4) + -1, *(char *)(in_a0 + 0x2b4) = cVar1, cVar1 == -1)) {
      if (*(char *)(in_a0 + 0x2b5) != '\0') {
        *(char *)(in_a0 + 0x2b5) = *(char *)(in_a0 + 0x2b5) + -1;
      }
      *(undefined1 *)(in_a0 + 0x2b4) = 0xf;
      if (*(char *)(in_a0 + 0x2b5) == '\0') {
        *(ushort *)(in_a0 + 0x2b8) = *(ushort *)(in_a0 + 0x2b8) & 0xfffd;
      }
    }
    if ((*(ushort *)(in_a0 + 0x2b8) & 4) != 0) {
      *(ushort *)(in_a0 + 0x2b8) = *(ushort *)(in_a0 + 0x2b8) | 1;
    }
    if (*(char *)(in_a0 + 0x2b6) != '\0') {
      *(char *)(in_a0 + 0x2b6) = *(char *)(in_a0 + 0x2b6) + -1;
    }
    if (*(char *)(in_a0 + 0x2c8) != '\0') {
      *(char *)(in_a0 + 0x2c8) = *(char *)(in_a0 + 0x2c8) + -1;
    }
    *(byte *)(in_a0 + 0x2ba) = *(char *)(in_a0 + 0x2ba) + 1U & 0x3f;
    (*(code *)(&PTR_FUN_80168ed0)[*(byte *)(in_a0 + 4)])();
    FUN_80166fec();
    *(undefined4 *)(in_a0 + 0x250) = 0x800e1130;
    func_0x800349d0();
    local_18 = local_18 & 0xfff;
    if (0x800 < local_18) {
      local_18 = local_18 - 0xfff;
    }
    iVar2 = *(int *)(in_a0 + 0x234);
    *(ushort *)(iVar2 + 0x4c2) = *(short *)(iVar2 + 0x4c2) + local_18;
    func_0x80040e58(iVar2 + 0x4c0,iVar2 + 0x470);
    *(ushort *)(iVar2 + 0x4c2) = *(short *)(iVar2 + 0x4c2) - local_18;
    FUN_8016841c();
    FUN_801687f0();
    if ((*(ushort *)(in_a0 + 0x2b8) & 0x40) == 0) {
      func_0x80033648();
    }
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
