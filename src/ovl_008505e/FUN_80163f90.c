/* FUN_80163f90
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163f90  body 0x80163f90..0x80164107  size 376 B
 * body sha256 d483b444d6d56064bc8efdf19d8933339cc174462921abb7f30f6512dfac5f88
 * provider record sha256 27a94ae8011fbe3ad21532360e22fb72907f48396b8f54e1ec78fb2508fbf50a
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163f90(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (((_DAT_800e110c & 0x10000000) == 0) ||
     (iVar3 = _DAT_800e13ec, *(short *)(_DAT_800e13ec + 0x1f2) != 0)) {
    iVar3 = -0x7ff1eed0;
  }
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if ((1 < bVar1) || (bVar1 != 0)) goto LAB_801640d4;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0x1e;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 0x2c9) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar2 & 0x3f) * 0x10000 + 0x1000f00;
  }
  func_0x800653d0(param_1,iVar3 + 0x28,0,0);
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
  func_0x80032b5c(param_1,0);
  iVar3 = func_0x80032fac(param_1 + 0x28,iVar3 + 0x28,(int)*(short *)(param_1 + 0x66),0x100);
  if (((iVar3 == 0) && (*(uint *)(param_1 + 0x28c) < 0x9c4)) || (*(char *)(param_1 + 0xd) != -1)) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
LAB_801640d4:
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_801664d8(param_1);
  return;
}
