/* FUN_801620fc
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x801620fc  body 0x801620fc..0x8016217b  size 128 B
 * body sha256 fb5e7a77b2ba78459e51b2d907e9eeae97010335b308d3803b49e4dfef3d176f
 * provider record sha256 b937ed9c03bd27a3759e2d1e9e3d3e27be1590ab6118dd9824cc09e535dc963d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801620fc(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x2b8);
  if ((cVar1 != '\0') && (*(char *)(param_1 + 0x2b8) = cVar1 + -1, cVar1 == '\x01')) {
    _DAT_800e1128 = _DAT_800e1128 & 0xffef;
  }
  if (*(char *)(param_1 + 0x2b5) != '\0') {
    *(char *)(param_1 + 0x2b5) = *(char *)(param_1 + 0x2b5) + -1;
  }
  (*(code *)(&PTR_FUN_80163050)[*(byte *)(param_1 + 5)])();
  return;
}
