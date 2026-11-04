/* FUN_80164680
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164680  body 0x80164680..0x80164733  size 180 B
 * body sha256 476128667e64fb31f5bb3a70cadb9c7bb7769dcf565c2126399b08ee10f69d82
 * provider record sha256 452a04f586ff7fc7ebea5956939a9e8a1e3daf86854fec3fb30466dd1cc8f7ec
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164680(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  func_0x80089d54();
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if ((uVar1 < 0x1c20) ||
     (iVar2 = FUN_80166e18(param_1,*(undefined4 *)(param_1 + 0x2c4),*(undefined1 *)(param_1 + 0x2cc)
                          ), iVar2 != 0)) {
    if (*(char *)(param_1 + 0x2d3) == '\0') {
      uVar3 = 7;
      if (2999 < *(uint *)(param_1 + 0x28c)) {
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 7;
      if (2999 < (*(uint *)(param_1 + 0x290) & 0x3fffffff)) {
        uVar3 = 3;
      }
    }
    *(undefined1 *)(param_1 + 5) = uVar3;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
