/* FUN_800a2560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2560  body 0x800a2560..0x800a2773  size 532 B
 * body sha256 8ea26efa2340c251d8be62ad691d4ec88e8d8d24309ddd0c1c680b54a7599e4c
 * provider record sha256 de0f638ed4150e1c0ff586f15148b31611ab37e19173d4c6af05ee8a9d63e3c5
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a2560(void)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  char *local_30 [2];
  
  uVar3 = 0x10;
  if (DAT_80143fe8 != '\0') {
    uVar3 = 0x18;
  }
  _DAT_80143f0a = (ushort)uVar3;
  if (_DAT_80143f04 < 0x5623) {
    _DAT_80143f0a = (ushort)(uVar3 >> 1);
  }
  _DAT_80143ea0 = (*_DAT_80144008)((uint)_DAT_80143f0a * 0x300,0x80);
  iVar6 = 1;
  uVar3 = (uint)_DAT_80143f0a;
  if (1 < uVar3) {
    piVar5 = (int *)&DAT_80143ea4;
    iVar4 = 0;
    do {
      piVar2 = (int *)(&DAT_80143ea0 + iVar4);
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
      *piVar5 = *piVar2 + 0x300;
      piVar5 = piVar5 + 1;
    } while (iVar6 < (int)uVar3);
  }
  bVar1 = false;
  func_0x80006650(_DAT_80143ea0,(uint)_DAT_80143f0a * 0x300);
  func_0x8000efa0(_DAT_80143ea0,(uint)_DAT_80143f0a * 0x300);
  DAT_80143f00 = 0;
  func_0x80011510(_DAT_80143ea0,0x300);
  do {
    osRecvMesg(0x80143e60,local_30,1);
    if (DAT_80143f08 == '\0') {
      if (*local_30[0] == '\x01') {
        uVar3 = (uint)_DAT_80143f0a;
        uVar7 = (DAT_80143f00 + 1) % uVar3;
        if (uVar3 == 0) {
          trap(0x1c00);
        }
        if ((uVar3 == 0xffffffff) && (DAT_80143f00 + 1 == 0x80000000)) {
          trap(0x1800);
        }
        DAT_80143f00 = (byte)uVar7;
        func_0x80011510(*(undefined4 *)(&DAT_80143ea0 + (uVar7 & 0xff) * 4),0x300);
      }
      else if (*local_30[0] == -1) {
        bVar1 = true;
      }
    }
  } while (!bVar1);
  return;
}
