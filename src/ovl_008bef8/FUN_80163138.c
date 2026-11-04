/* FUN_80163138
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163138  body 0x80163138..0x8016320f  size 216 B
 * body sha256 6d97ae95ffc023e3744527ab66da8794c314e603e8e8836e3e417ab7d616da61
 * provider record sha256 51f606d0d2ab791f16fe4c93d7a1103f63a698bd8421c441696d83afd46d78cd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163138(uint *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_800e139f == 0) &&
     (iVar1 = _DAT_800e1158 - *(int *)(param_1[0x8d] + 0x4c),
     iVar2 = _DAT_800e1160 - *(int *)(param_1[0x8d] + 0x54),
     iVar1 = func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2), iVar1 < 0x1450)) {
    *(undefined1 *)(param_1 + 0xb2) = 8;
    *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) | 2;
    _DAT_800e1134 = 0x5010000;
    _DAT_800e1380 = param_1;
    *param_1 = *param_1 | 0x100a;
    _DAT_800e1322 = 0xffff;
    _DAT_800e1130 = _DAT_800e1130 | 0x1008;
    DAT_800e139f = DAT_800e139f | 0x80;
  }
  return;
}
