/* FUN_80161e14
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80161e14  body 0x80161e14..0x80161e9f  size 140 B
 * body sha256 aed01e8b4d4ef20d5f530fe9d0d2b1ffed7f54cb22cb7d8773fcd212deee6af7
 * provider record sha256 b61db7f52ee993e19714836f54e161bffaceb2c8d099aacb8bd2e1489d3c113c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80161e70) */

void FUN_80161e14(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 4) != '\a') {
    iVar1 = (int)*(short *)(param_1 + 0x25e) - *(int *)(param_1 + 0x2c);
    if (0 < iVar1 + -0xfa) {
      iVar1 = iVar1 + 0x60e >> 1;
      uVar2 = 360000 / iVar1;
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      *(uint *)(*(int *)(param_1 + 0x208) + 4) = uVar2 | uVar2 << 0x10;
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x208) + 4) = 0x1900190;
  }
  return;
}
