/* FUN_80164428
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80164428  body 0x80164428..0x8016448f  size 104 B
 * body sha256 dd1c6f7931315f7837e9542d67c0a262a817033d2adb893ee9310d4e8117d025
 * provider record sha256 414d57c63a60590f28b15fcb113d4096d2e5cbb3f778904e9df14e3a7670b421
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164428(int param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if ((sVar1 == 0) && (0x9c4 < uVar2)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
