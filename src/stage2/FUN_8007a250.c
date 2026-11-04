/* FUN_8007a250
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a250  body 0x8007a250..0x8007a35f  size 272 B
 * body sha256 77dba6a13efd2a7f67023555399bf07296d6e6cb4d668259cff1e18bd8b58885
 * provider record sha256 ff4866cb6cebe64721cd469cb72a2cd441e55e0a74079670d5eb950ad3546ecd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a250(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_800e110c & 0x10000000) != 0) {
    *(undefined4 **)(param_1 + 0x254) = &DAT_800e1130;
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    uVar1 = DAT_800e9010;
    *(undefined2 *)(param_1 + 0x1fe) = 200;
    *(undefined2 *)(param_1 + 0x1f2) = uVar1;
  }
  iVar3 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(param_1 + 0x2b8) = 0;
  *(undefined2 *)(param_1 + 0x2c0) = 0;
  *(undefined2 *)(param_1 + 700) = 0;
  *(undefined1 *)(param_1 + 0x2bf) = 0;
  *(undefined1 *)(param_1 + 0x2c6) = 0;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(undefined4 *)(iVar3 + 0x1608) = 0;
  *(int *)(iVar3 + 0x166c) = iVar3 + 0x38;
  *(undefined4 *)(iVar3 + 0x1624) = 8;
  *(int *)(iVar3 + 0x1734) = iVar3;
  *(undefined4 *)(iVar3 + 0x1628) = 0xfffffe53;
  *(undefined4 *)(iVar3 + 0x162c) = 0;
  *(undefined2 *)(iVar3 + 0x1660) = 0;
  *(undefined2 *)(iVar3 + 0x1662) = 0;
  *(undefined2 *)(iVar3 + 0x1664) = 0;
  FUN_80040e58(iVar3 + 0x1660,iVar3 + 0x1610);
  *(undefined2 *)(iVar3 + 0x1738) = 0;
  *(undefined2 *)(iVar3 + 0x173a) = 0;
  *(uint *)(iVar3 + 0x1608) = *(uint *)(iVar3 + 0x1608) | 0x40;
  iVar2 = FUN_800837ac(&DAT_800e8ce0,0xff);
  if (iVar2 != 0) {
    *(uint *)(iVar3 + 0x1608) = *(uint *)(iVar3 + 0x1608) | 1;
  }
  return;
}
