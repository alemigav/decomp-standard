/* FUN_800a5358
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5358  body 0x800a5358..0x800a54eb  size 404 B
 * body sha256 7c7f2bac67309f5a5325664949d31622f1d77640b3290ec0f5b648a9678956f8
 * provider record sha256 3174412541ecb0c646da60d65a65f190ccab7563160d981813f5b02e0bf5fc35
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5358(void)

{
  if (DAT_80136310 != '\0') {
    _DAT_80143fa2 = _DAT_80143f0a;
    do {
    } while (0 < (int)((uint)_DAT_80143f0a << 0x10));
    (*_DAT_80143ffc)(FUN_800a48e4);
    if (DAT_80143f4d != '\0') {
      (*_DAT_80143ff4)();
      func_0x80011390();
      DAT_80143f4d = '\0';
    }
    if (_DAT_80143f68 != 0) {
      FUN_800a5750();
      (*_DAT_8014400c)(_DAT_80143f68);
      _DAT_80143f68 = 0;
    }
    if (_DAT_80143f70 != 0) {
      (*_DAT_8014400c)();
    }
    do {
    } while (DAT_80143f4c != '\0');
    (*_DAT_8014400c)(_DAT_80143fec);
    (*_DAT_8014400c)(_DAT_80143f7c);
    (*_DAT_8014400c)(_DAT_80143f78);
    (*_DAT_8014400c)(_DAT_80143f90);
    (*_DAT_8014400c)(_DAT_80143f8c);
    (*_DAT_8014400c)(_DAT_80143f58);
    (*_DAT_8014400c)(_DAT_80143f5c);
    (*_DAT_8014400c)(_DAT_80143f10);
    (*_DAT_8014400c)(_DAT_80143f64);
  }
  return;
}
