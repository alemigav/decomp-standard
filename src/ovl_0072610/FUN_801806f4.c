/* FUN_801806f4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801806f4  body 0x801806f4..0x80180957  size 612 B
 * body sha256 549f8975d10a2f3ca93d58692cc41cee45e7072d461d70dded0c91e005393b0f
 * provider record sha256 4c9eed8a5366430f8898c11516740e0f0006a123ff59744701b0d55fc4bf05dc
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801806f4(void)

{
  int iVar1;
  
  if ((_DAT_801344d4 & 0xfffffffe) ==
      (int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185474) * 2 + -0x7fecba1e)) {
    if (DAT_80185484 != -1) {
      func_0x800b431c(DAT_80185484);
    }
    iVar1 = func_0x800b3704((int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185474) * 2 + -0x7fecba3e)
                            ,*(undefined2 *)(_DAT_801344b0 * 0x112 + -0x7fecba44),0x7f,
                            ((uint)*(ushort *)(_DAT_801344b0 * 0x112 + -0x7fecba42) *
                            (uint)DAT_80119e74) / 100 & 0xff,0x3f,0x3f,0);
    DAT_80185484 = DAT_80185480;
    DAT_80185474 = DAT_80185474 + 1;
    DAT_80185480 = iVar1;
  }
  if ((_DAT_801344d4 & 0xfffffffe) ==
      (int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185478) * 2 + -0x7fecb9f6)) {
    if (DAT_80185488 != -1) {
      FUN_801806cc(DAT_80185488);
    }
    DAT_80185488 = FUN_801805f0((int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185478) * 2 +
                                               -0x7fecb9fe),
                                (int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185478) * 2 +
                                               -0x7fecb9e6),
                                (int)*(short *)((_DAT_801344b0 * 0x89 + DAT_80185478) * 2 +
                                               -0x7fecb9ee));
    DAT_80185478 = DAT_80185478 + 1;
  }
  return;
}
