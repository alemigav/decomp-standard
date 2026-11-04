/* FUN_8017f61c
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f61c  body 0x8017f61c..0x8017f76f  size 340 B
 * body sha256 890557d5fb55ee533801fd8694cfd5c83b13c0d025f9e08eb1b59c6415842fc2
 * provider record sha256 a72775f6b31a04cf4be7b359c7e3ed445ca4ad3433f96abfaa2ddcd20340768d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017f61c(void)

{
  int iVar1;
  
  DAT_800e8b3a = DAT_800e1138;
  _DAT_800e8b52 = _DAT_800e115a;
  _DAT_800e8b54 = _DAT_800e115e;
  _DAT_800e8b56 = _DAT_800e1162;
  _DAT_800e900c = _DAT_800e1196;
  if ((_DAT_800e10ec & 0x200000) == 0) {
    iVar1 = func_0x8006bb0c(0xffffffff);
    _DAT_800e8b30 = _DAT_800e8b30 + (iVar1 - _DAT_800dfbe4);
    _DAT_800dfbe4 = func_0x8006bb0c(0xffffffff);
  }
  else {
    _DAT_800e8b30 = 0;
  }
  DAT_800e8b48 = DAT_8012bfa2;
  DAT_800e8b49 = DAT_8012bfa0;
  if ((_DAT_800e10ec & 0x20) != 0) {
    _DAT_800e110c = _DAT_800e110c | 0x4000000;
  }
  _DAT_800e8b44 = _DAT_800e110c;
  _DAT_800e8b4a = _DAT_800e1322;
  DAT_800e8b3f = DAT_800e13e6;
  DAT_800e8b3c = DAT_80119e73;
  _DAT_800e8b40 = _DAT_800e13e4;
  DAT_800e8b3d = DAT_80119e74;
  DAT_800e8b39 = DAT_800dfbe9;
  DAT_800e8b3e = DAT_800e923e;
  return;
}
