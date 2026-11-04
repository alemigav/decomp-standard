/* FUN_801657ac
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801657ac  body 0x801657ac..0x8016587b  size 208 B
 * body sha256 9bf2436a9a56c149a0eba1d746b17ce4362bc5809360ef4f083bbc845dca6a3f
 * provider record sha256 e0096085dde57bf30b658d98b4de30aa1dd7f4e39df083970ece9c7f8e2e21c5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801657ac(int param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if ((((sVar1 == 0) && (0x9c4 < uVar2)) && (uVar2 < 4000)) && (*(char *)(param_1 + 0x2ba) == '\0'))
  {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  if (*(short *)(param_1 + 0x1f2) < 700) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  }
  return;
}
