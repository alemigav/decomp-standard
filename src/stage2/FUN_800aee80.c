/* FUN_800aee80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aee80  body 0x800aee80..0x800aefb3  size 308 B
 * body sha256 5ecc0e49aedaa7e88a9b199ed790ded9cd01b1786b76b3671af6e01155b89f82
 * provider record sha256 a13e865056302581a777e8653a1fa4d678411266c67c9b8305aaed134c2e8ef7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800aee80(uint param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = 0xffffffff;
  if (DAT_80136310 == '\0') {
    return 0xffffffff;
  }
  if (param_1 != 0xffffffff) {
    piVar3 = (int *)0x0;
    piVar5 = _DAT_80158430;
    if (_DAT_80158430 != (int *)0x0) {
      while (piVar5[2] != param_1) {
        piVar3 = (int *)0x0;
        if ((param_1 < (uint)piVar5[2]) || (piVar5 = (int *)*piVar5, piVar5 == (int *)0x0))
        goto LAB_800aeee4;
      }
      piVar3 = piVar5;
    }
LAB_800aeee4:
    if (piVar3 != (int *)0x0) {
      uVar2 = piVar3[3];
      goto joined_r0x800aef08;
    }
  }
  uVar2 = 0xffffffff;
joined_r0x800aef08:
  while (uVar2 != 0xffffffff) {
    uVar7 = uVar2 & 0xff;
    iVar4 = uVar7 * 0x1a0;
    uVar8 = *(uint *)(iVar4 + -0x7febbba8);
    bVar1 = *(uint *)(&DAT_801444a8 + iVar4) == uVar2;
    uVar2 = uVar8;
    if (bVar1) {
      if (*(int *)(&DAT_80144448 + iVar4) != 0) {
        FUN_800ae1a0(&DAT_80144448 + iVar4);
        *(undefined4 *)(&DAT_80144470 + iVar4) = 0;
        *(uint *)(&DAT_8014446c + iVar4) = *(uint *)(&DAT_8014446c + iVar4) & 0xfffffffc;
        FUN_800aebfc();
      }
      FUN_800a5b14(uVar7);
      uVar6 = 0;
    }
  }
  return uVar6;
}
