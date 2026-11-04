/* FUN_8017b744
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017b744  body 0x8017b744..0x8017bb1f  size 988 B
 * body sha256 039333dac6dd9684ac351850eb5600c96dc924588382987d942d1a4a2a48781a
 * provider record sha256 1061d7fa24f8f884850568e795b2a89d48f5eeccde79f12fc642b24fcbe6e118
 * callees 13 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017b744(void)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  if (DAT_8017e706 < 0x7fff) {
    DAT_8017e704 = DAT_8017e704 + DAT_8017e700;
    if ((_DAT_800e10ec & 0x100) == 0) {
      DAT_8017e700 = DAT_8017e700 + 2;
    }
    else {
      DAT_8017e700 = DAT_8017e700 + 0x18;
    }
    DAT_8017e734 = DAT_8017e734 + 1;
    if (DAT_8017e734 < 3) {
      _DAT_800e1110 = _DAT_800e1110 | 0xff000000;
    }
    else {
      DAT_8017e734 = 0;
      _DAT_800e1110 = _DAT_800e1110 ^ 0xfc000000;
      func_0x800777d8(0x2000000);
      func_0x800777d8(0x12000000);
      func_0x800777d8(0x22000000);
    }
    DAT_8017e706 = DAT_8017e706 + DAT_8017e704;
    if ((0x7ffe < DAT_8017e706) && (DAT_8017e706 = 0x7fff, (_DAT_800e10ec & 4) != 0)) {
      if ((_DAT_800e110c & 0x20) == 0) {
        func_0x80052d10(0x3c,0xfa,0x78,0);
      }
      else {
        func_0x80052c6c(1,0xfa,0);
        DAT_8017e704 = 1;
        DAT_8017e700 = 0;
        DAT_8017e706 = 0x7ffe;
      }
    }
    func_0x800274f8(0x100,0,7,3);
    func_0x800275c0(0,(int)(short)DAT_8017e706,0xffff,0);
  }
  else {
    DAT_8017e734 = 0;
    FUN_8017e150();
    _DAT_800e10ec = _DAT_800e10ec | 0x100000;
    func_0x800274e4(4,0);
    func_0x80026a98();
    func_0x8004cd88(1);
    if (((_DAT_800e10ec & 4) == 0) && ((DAT_800e9012 & 0xc) >> 3 != 0)) {
      func_0x80038f7c();
    }
    else {
      func_0x80038ff0();
    }
    iVar4 = -0x7ff38950;
    _DAT_800e1130 = _DAT_800e1130 | 8;
    bVar1 = *(byte *)(_DAT_800df92c + 2);
    uVar3 = 0;
    if (bVar1 != 0) {
      do {
        uVar3 = uVar3 + 1;
        *(uint *)(iVar4 + 0x1a248) = *(uint *)(iVar4 + 0x1a248) | 0x80000;
        iVar4 = iVar4 + 0x368;
      } while (uVar3 < bVar1);
    }
    if ((*(char *)(_DAT_800e1380 + 8) == '#') && (_DAT_800e1cd0 != -0x7ff16fd8)) {
      _DAT_800e1c60 = _DAT_800e1c60 & 0xfff7ffff;
    }
    if ((_DAT_800e10ec & 0x100) == 0) {
      FUN_8017bdb0();
    }
    else {
      FUN_8017bb20();
    }
    func_0x8004cd88(1);
    DAT_8017e704 = 0;
    sVar2 = DAT_8017e702 + 1;
    if ((_DAT_800e10ec & 0x100) == 0) {
      sVar2 = DAT_8017e702 + 2;
    }
    if ((DAT_8017e734 & 1) == 0) {
      uVar3 = 0x40000000;
    }
    else {
      uVar3 = 0x80000000;
    }
    _DAT_800e1110 = _DAT_800e1110 & 0x3ffffff | uVar3;
    DAT_8017e702 = sVar2;
    func_0x800274f8(0x100,0xfffff444,7,3);
  }
  return;
}
