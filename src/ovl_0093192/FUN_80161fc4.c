/* FUN_80161fc4
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80161fc4  body 0x80161fc4..0x801621e3  size 544 B
 * body sha256 e917f560d06cbc9f2bb0e0b262fe9237084745d25bdb1627ddf7df5cb21219e2
 * provider record sha256 709f28bf63e19f86a7624cf4bb834d5d6a49b423561c45fe52b817a6422cadfd
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161fc4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  (*(code *)(&PTR_FUN_80162d4c)[*(byte *)(param_1 + 6)])();
  iVar4 = *(int *)(param_1 + 0x2b4);
  iVar1 = func_0x80032e74(param_1,*(undefined4 *)(iVar4 + 0x28),*(undefined4 *)(iVar4 + 0x30),0x100)
  ;
  if (*(short *)(param_1 + 0x2b8) != 0) {
    *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + -1;
  }
  if (iVar4 == -0x7ff1eed0) {
    iVar2 = *(int *)(param_1 + 0x28c);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x290);
  }
  if ((((iVar2 < 2000) && (iVar1 == 0)) && (*(short *)(param_1 + 0x2b8) == 0)) &&
     ((*(byte *)(iVar4 + 0x26f) & 0x80) == 0)) {
    *(undefined1 *)(param_1 + 5) = 3;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  if ((((*(uint *)(param_1 + 0x28c) < 500) && ((_DAT_800e112a & 6) != 0)) &&
      (*(char *)(param_1 + 0x1a2) == DAT_800e12d2)) &&
     (((uVar3 = _DAT_800e1134 & 0xffff0000, uVar3 == 0x1010000 || (uVar3 == 0x1020000)) ||
      ((uVar3 == 0x1030000 || (uVar3 == 0x1040000)))))) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
    func_0x80052bd0(1,0);
    func_0x80052c6c(3,0x50,0);
  }
  if (((((_DAT_800e110c & 0x10000000) != 0) &&
       (*(char *)(param_1 + 0x1a2) == *(char *)(_DAT_800e13ec + 0x1a2))) &&
      ((*(uint *)(param_1 + 0x290) & 0x3fffffff) < 500)) &&
     (((uVar3 = *(uint *)(_DAT_800e13ec + 4) & 0xffff0000, uVar3 == 0x1010000 ||
       (uVar3 == 0x1020000)) || ((uVar3 == 0x1030000 || (uVar3 == 0x1040000)))))) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  return;
}
