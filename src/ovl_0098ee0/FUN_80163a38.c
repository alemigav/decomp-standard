/* FUN_80163a38
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80163a38  body 0x80163a38..0x80163cc7  size 656 B
 * body sha256 07bc0f9a7d22e58867f645538c3f7c042a1c4405e2b025b2749f21fc00bf54be
 * provider record sha256 1cbdfdd1ecd62694bfe6c8d416998204ccc3a995c57f00c2a9fa47a8a99db252
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163a38(int param_1)

{
  byte bVar1;
  short sVar4;
  int iVar2;
  char cVar5;
  undefined4 uVar3;
  int iVar6;
  undefined2 local_28 [2];
  undefined2 local_24;
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar6 = *(int *)(param_1 + 0x234);
  if (bVar1 == 1) {
LAB_80163aa4:
    sVar4 = FUN_801621c4(param_1);
    if (*(byte *)(param_1 + 0x1e9) - 1 < 0x33) {
      iVar2 = (int)sVar4;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if ((0x352 < iVar2) || (0x1068 < *(uint *)(param_1 + 0x28c))) {
        *(undefined1 *)(param_1 + 6) = 3;
        *(undefined1 *)(param_1 + 0x2c9) = 0x1e;
        goto LAB_80163ca4;
      }
    }
    cVar5 = func_0x80036c68(param_1,2,0xf,0);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,4);
    local_28[0] = *(undefined2 *)(param_1 + 0x2b8);
    local_24 = *(undefined2 *)(param_1 + 0x2ba);
    iVar2 = FUN_80161e10(param_1,0xc,0x38,0x3b,0x352);
    if (iVar2 == 0) {
      return;
    }
    func_0x80077d18(2,param_1);
    func_0x80052bd0(3,0);
    func_0x80052c6c(8,0xff,0);
    func_0x80052d10(4,0xff,0x28,8);
    FUN_8016227c(param_1,local_28,0xc);
    local_20 = *(undefined2 *)(iVar6 + 0x11ee);
    local_1c = *(undefined2 *)(iVar6 + 0x11f6);
    local_1e = *(short *)(iVar6 + 0x11f2);
    if ((int)*(short *)(iVar6 + 0x11f2) < *(short *)(param_1 + 0x25e) + -3000) {
      local_1e = *(short *)(param_1 + 0x25e) + -3000;
    }
    func_0x80037780(0x2400,0,0x800e9028,&local_20);
    FUN_80162114(0x32);
    if (-1 < _DAT_800e1322) {
      return;
    }
    _DAT_800e1322 = -1;
    _DAT_800e1134 = 0x5020000;
    _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
    uVar3 = 0x1100000;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined2 *)(param_1 + 500) = 0;
      goto LAB_80163aa4;
    }
    if (bVar1 != 2) {
      if (bVar1 != 3) {
        return;
      }
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,4);
      *(undefined1 *)(param_1 + 0x1e9) = 0;
      func_0x80036b84(param_1,2,0xf,0);
      sVar4 = *(short *)(param_1 + 500);
      *(short *)(param_1 + 500) = sVar4 + -1;
      if (sVar4 != 1) {
        return;
      }
    }
LAB_80163ca4:
    uVar3 = 0x1010000;
  }
  *(undefined4 *)(param_1 + 4) = uVar3;
  return;
}
