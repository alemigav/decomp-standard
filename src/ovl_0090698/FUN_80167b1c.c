/* FUN_80167b1c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167b1c  body 0x80167b1c..0x80167bcf  size 180 B
 * body sha256 9fe494dca0d8b2c1fbe3c806517247608d935fb67e886d4c05bfd076c4d96e26
 * provider record sha256 b964273b9ef132ae5c2a6305d10e16dd795f0daf09587f085028cb19881afd2f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167b1c(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *param_1;
  bVar1 = *(byte *)((int)param_1 + 0x2be);
  *param_1 = uVar2 & 0xe3ffffff;
  if (bVar1 == 1) {
    uVar3 = 0x10000000;
  }
  else {
    if (1 < bVar1) {
      if (bVar1 < 4) {
        iVar4 = _DAT_800e115c - param_1[0xb];
        if (iVar4 < 0x1069) {
          uVar2 = *param_1 | 0x18000000;
          *param_1 = uVar2;
          if (0x833 < iVar4) {
            return;
          }
          uVar3 = 0x4000000;
        }
        else {
          uVar3 = *param_1;
          uVar2 = 0x10000000;
        }
        *param_1 = uVar2 | uVar3;
      }
      return;
    }
    uVar3 = 0xc000000;
    if (bVar1 != 0) {
      return;
    }
  }
  *param_1 = uVar2 & 0xe3ffffff | uVar3;
  return;
}
