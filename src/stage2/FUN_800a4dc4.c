/* FUN_800a4dc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a4dc4  body 0x800a4dc4..0x800a5017  size 596 B
 * body sha256 93699ee27ae8f507c97413b1331afad671efd6dea5859c8ed9696fb671e748fb
 * provider record sha256 e92cee5d1766b193a1af2f9f4e1bfc93e1a2ca1f0478342be460da26b61d3e9e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a4dc4(int *param_1,ushort param_2,uint param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  
  if (0x20 < param_2) {
    param_2 = 0x20;
  }
  DAT_80143f4d = 0;
  FUN_800a2950(param_2,*param_1);
  FUN_800a2bd0(param_2,*param_1,param_4);
  if ((param_3 & 0xffff) == 0) {
    _DAT_80143f70 = 0;
  }
  else {
    _DAT_80143f68 = 0;
    _DAT_80143f74 = ((*param_1 * (param_3 & 0xffff)) / 0x2ee00) * 0xc0 + 0xc0;
    _DAT_80143f70 = (*_DAT_80144008)(_DAT_80143f74 * 2,0);
  }
  _DAT_80143fa0 = 0xffff;
  _DAT_80143fd4 = 0;
  _DAT_80143fd8 = 0;
  (*_DAT_80143ff8)(FUN_800a48e4);
  iVar2 = *param_1;
  if (iVar2 < 0) {
    fVar5 = (float)iVar2 + 4.2949673e+09;
  }
  else {
    fVar5 = (float)iVar2;
  }
  fVar5 = (fVar5 / 60.0) / 192.0 + 0.5;
  if (fVar5 < 2.1474836e+09) {
    _DAT_80143f18 = (uint)fVar5;
  }
  else {
    _DAT_80143f18 = (int)(fVar5 - 2.1474836e+09) | 0x80000000;
  }
  uVar4 = 0;
  _DAT_80147fa0 = _DAT_80143f18 * 0xc0;
  _DAT_80147850 = *param_1;
  DAT_80147855 = 0x10;
  DAT_80147854 = 1;
  _DAT_80143f1c = _DAT_80143f18;
  do {
    uVar3 = uVar4 & 0xff;
    uVar4 = uVar4 + 1;
    cVar1 = "N64 RSP mixer V1.1"[uVar4 & 0xff];
    *(char *)(uVar3 + 0x80147956) = "N64 RSP mixer V1.1"[uVar3];
  } while (cVar1 != '\0');
  *(undefined1 *)((uVar4 & 0xff) + 0x80147956) = 0;
  return;
}
