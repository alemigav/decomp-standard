/* FUN_80165d20
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165d20  body 0x80165d20..0x80165d87  size 104 B
 * body sha256 85a853e85da05125b942b49dfd9ac373b673fe8422e75ae3b3a951cf808c5df1
 * provider record sha256 5cc65a580799a78ec349854cff126eae66cd6be4cd45642dbcc1a078274cdea8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165d20(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  iVar5 = 0;
  do {
    iVar4 = *(int *)(param_1 + 0x234) + iVar5;
    uVar1 = *(uint *)(iVar4 + 0x60);
    uVar3 = uVar1 & 0xff;
    if (uVar3 != 0) {
      uVar3 = uVar3 - 1;
    }
    uVar2 = uVar1 & 0xff00;
    if (uVar2 != 0) {
      uVar2 = uVar2 - 0x100;
    }
    uVar1 = uVar1 & 0xff0000;
    if (uVar1 != 0) {
      uVar1 = uVar1 - 0x10000;
    }
    *(uint *)(iVar4 + 0x60) = uVar1 | uVar2 | uVar3;
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 0x178;
  } while (uVar6 < 0x1a);
  return;
}
