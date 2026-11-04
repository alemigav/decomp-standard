/* FUN_800a2bd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2bd0  body 0x800a2bd0..0x800a2e3f  size 624 B
 * body sha256 82ad7a4b22412ad93a39a6bd0dd80d57e4a3ab75f92717af1020148b8061ee34
 * provider record sha256 95c522351c4f915d690aa0c14435ea9bf438cab9f50f538eb69c768e8bec3d74
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800a2d28) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a2bd0(short param_1,int param_2,uint param_3)

{
  float fVar1;
  
  if (DAT_80143fe8 == '\0') {
    fVar1 = (float)param_2;
    if (param_2 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar1 = fVar1 / 50.0;
  }
  else {
    fVar1 = (float)param_2;
    if (param_2 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar1 = fVar1 / 25.0;
  }
  fVar1 = (fVar1 * 1.2) / 192.0;
  if (2.1474836e+09 <= fVar1) {
    fVar1 = fVar1 - 2.1474836e+09;
  }
  _DAT_80143f20 = param_1 * ((short)(int)fVar1 + 1);
  fVar1 = (float)((uint)_DAT_80143f20 * 0x310) * 0.9;
  if (2.1474836e+09 <= fVar1) {
    fVar1 = fVar1 - 2.1474836e+09;
  }
  _DAT_80143f24 = ((int)fVar1 + 0x3fU >> 6) * 0x28 + 0xf & 0xfff0;
  _DAT_80143fec = (*_DAT_80144008)((uint)_DAT_80143f20 * 0x18,0);
  osCreateMesgQueue(0x80143f30,0x80143f48,1);
  DAT_80143f4c = 0;
  FUN_800a3264(_DAT_80143f20);
  FUN_800a34b8(*(short *)(&DAT_80135ca0 + (param_3 & 0xff) * 2) * param_1);
  return;
}
