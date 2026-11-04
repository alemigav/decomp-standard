/* FUN_8017b530
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017b530  body 0x8017b530..0x8017b70f  size 480 B
 * body sha256 247cc2e6385c2e01e73e860ad29e64159c48364a6c3c7f67bffff337838596d7
 * provider record sha256 a85f54348280cf8fe365cb55cff100d9652ffdab0e35dd0e0ea00f34b00f8755
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017b530(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0xe;
  DAT_8017e706 = 0x400;
  DAT_8017e700 = 0;
  DAT_8017e704 = 0;
  DAT_8017e734 = 0;
  DAT_8017e736 = 0;
  DAT_8017e735 = 0;
  if ((_DAT_800e10ec & 0x100) != 0) {
    bVar2 = *(byte *)(_DAT_800e1380 + 8);
    if ((bVar2 == 0x34) && ((*(ushort *)(_DAT_800e1380 + 0x1aa) & 1) == 0)) {
      iVar3 = 0xf;
    }
    else if (bVar2 < 0x20) {
      iVar3 = 1;
    }
    else {
      if (bVar2 == 0x39) {
        bVar2 = 0x2e;
      }
      if (bVar2 != 0x24) {
        do {
          iVar1 = iVar3 + -1;
          if (iVar3 << 0x18 < 1) break;
          iVar3 = iVar1;
        } while ((&DAT_8017e6d4)[iVar1 * 0x1000000 >> 0x18] != bVar2);
      }
    }
    DAT_8017e738 = *(undefined2 *)(&UNK_8017e510 + ((iVar3 << 0x18) >> 0x17));
  }
  _DAT_800e1110 = _DAT_800e1110 | 0x2000000;
  if ((_DAT_800e10ec & 4) == 0) {
    _DAT_800e110c = _DAT_800e110c & 0xf7ffffff | 0x140;
  }
  else {
    _DAT_8011a718 = 0x80115440;
    _DAT_800e110c = _DAT_800e110c | 0x140;
    func_0x80004a6c(1,0);
    _DAT_800e110c = _DAT_800e110c | 0x20;
    func_0x80052bd0(5,5);
    func_0x80052bd0(5,0xf);
    func_0x80052bd0(10,0x19);
    func_0x80052d10(0x28,200,0xfa,5);
  }
  DAT_8017e702 = DAT_8017e702 + 2;
  return;
}
