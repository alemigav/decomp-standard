/* FUN_8017fdbc
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017fdbc  body 0x8017fdbc..0x8017fe53  size 152 B
 * body sha256 0e66971589ddf21c34185a55a4054043d6642bd51f6f14aca3c5da39e58c9ac0
 * provider record sha256 3cb9914edd6d73fdf218b2ae396dc9b93e6d6dfc3bc6885a658de4437c333095
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017fdbc(int param_1)

{
  int iVar1;
  uint unaff_s0;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 8;
  FUN_8017f844();
  uVar3 = 0xff;
  do {
    iVar1 = FUN_8017ff88(param_1 << 4);
    uVar4 = uVar3;
    if (iVar1 != 0) {
      unaff_s0 = FUN_8017ff0c();
      if (unaff_s0 == 3) {
        return 3;
      }
      uVar4 = unaff_s0;
      if (((unaff_s0 & 1) == 0) && (unaff_s0 == uVar3)) {
        return unaff_s0;
      }
    }
    iVar2 = iVar2 + -1;
    uVar3 = uVar4;
    if (iVar2 == 0) {
      return unaff_s0;
    }
  } while( true );
}
