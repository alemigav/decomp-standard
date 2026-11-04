/* FUN_800274f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800274f8  body 0x800274f8..0x800275bf  size 200 B
 * body sha256 0fed7ea04ec98406728c71a9ce0463d6b1061317563dc29e3a8cf7eb40ef3466
 * provider record sha256 2072ae9031db65ddce092cccbc0cb209b406eff58af84da0f5ad90737a28040e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800274f8(uint param_1,ushort param_2,uint param_3,undefined1 param_4)

{
  int iVar1;
  
  if ((DAT_800e10ec & 0x2000000) != 0) {
    param_2 = param_2 << 1;
  }
  iVar1 = (param_1 & 0xff) * 0x2c;
  (&DAT_800e9188)[iVar1] = (char)(param_1 >> 8);
  *(ushort *)(&DAT_800e9186 + iVar1) = param_2;
  (&DAT_800e918c)[iVar1] = param_4;
  if ((param_3 & 4) == 0) {
    (&DAT_800e9189)[iVar1] = 0;
  }
  else {
    (&DAT_800e9189)[iVar1] = 0xff;
  }
  if ((param_3 & 2) == 0) {
    (&DAT_800e918a)[iVar1] = 0;
  }
  else {
    (&DAT_800e918a)[iVar1] = 0xff;
  }
  if ((param_3 & 1) == 0) {
    (&DAT_800e918b)[iVar1] = 0;
  }
  else {
    (&DAT_800e918b)[iVar1] = 0xff;
  }
  if ((int)((uint)param_2 << 0x10) < 0) {
    (&DAT_800e9184)[(param_1 & 0xff) * 0x16] = param_2 + 0x8000;
    return;
  }
  (&DAT_800e9184)[(param_1 & 0xff) * 0x16] = 0;
  return;
}
