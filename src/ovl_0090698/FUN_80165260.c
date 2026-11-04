/* FUN_80165260
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165260  body 0x80165260..0x8016534b  size 236 B
 * body sha256 0251fc34089d1adf09c1cb75e3ad8b24bd65cf66f093ead16d10538d21c35044
 * provider record sha256 a186e68c93920862dfe7e67f0937b67612a3d0bcf3c969eefada127a488383d8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165260(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 5) = 7;
  FUN_80164a78();
  uVar3 = 0;
  if (*(byte *)(param_1 + 0x26e) / 3 != 2) {
    do {
      uVar1 = func_0x80033604();
      iVar2 = (uVar1 & 0xf) + 3;
      if ((*(uint *)(*(int *)(param_1 + 0x234) + iVar2 * 0x178) & 0x4b) == 1) {
        FUN_8016703c(param_1,iVar2,5);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 2 - *(byte *)(param_1 + 0x26e) / 3);
  }
  return;
}
