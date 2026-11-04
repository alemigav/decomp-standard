/* FUN_80180014
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180014  body 0x80180014..0x80180067  size 84 B
 * body sha256 5c141eb0f21af891352a0a640768535b149300d863ba98e943c6a1683a732fbe
 * provider record sha256 5a29fca23ec014ab5c598943390124c3e7048164c9e14b2859252e277020457d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80180014(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  DAT_801874a0 = &DAT_801870a0;
  iVar2 = -0x200;
  puVar1 = &DAT_80186ca0;
  do {
    if (iVar2 < -0x100) {
      *puVar1 = 0xff00;
    }
    else if (iVar2 < 0x100) {
      *puVar1 = (short)iVar2;
    }
    else {
      *puVar1 = 0xff;
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 0x200);
  return;
}
