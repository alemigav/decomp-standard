/* FUN_801623cc
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801623cc  body 0x801623cc..0x8016245f  size 148 B
 * body sha256 46824cb16b2ef41798cfc35af436f3dfaeada72a514150cb3198469616d9782f
 * provider record sha256 69e3847b1d3cb760b7880d1e1803e9357a859d69c930d0c5e5e7a91dc031f54f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801623cc(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = FUN_801621a0();
  if ((DAT_800e12d2 == *(char *)(param_1 + 0x1a2)) &&
     ((((uVar2 = 1, *(uint *)(param_1 + 0x28c) < 4000 || (uVar2 = 1, iVar1 == 1)) ||
       (uVar2 = 1, (_DAT_800e1128 & 0x20) != 0)) || (uVar2 = 2, (_DAT_800e112a & 1) != 0)))) {
    *(undefined1 *)(param_1 + 5) = uVar2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_80166ba0(param_1);
  return;
}
