/* FUN_80166e18
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166e18  body 0x80166e18..0x80166ecf  size 184 B
 * body sha256 3154195e2564060737fd9c7750abc11b2980d4a3eb401d4f1786be0f573a27cd
 * provider record sha256 8eab6f1ca16739fe8ac4ec89001ecbe33435b6c319d2e8ef74a67610c74cae91
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_80166e18(int param_1,undefined4 param_2,ushort param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    iVar2 = -0x7ff1eed0;
  }
  else {
    iVar2 = _DAT_800e13ec;
  }
  iVar1 = func_0x8006a880((int)(short)param_3);
  if ((param_3 & 1) == 0) {
    iVar1 = *(int *)(iVar2 + 0x28) - iVar1;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x30) - iVar1;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
  }
  return iVar1 < 3000;
}
