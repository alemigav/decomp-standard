/* FUN_800a5180
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5180  body 0x800a5180..0x800a5357  size 472 B
 * body sha256 0ec32e0fbed46428845cba46a451b845249ab61f906adef2ba0adf569a14e348
 * provider record sha256 7510f30a5b8bd7fb3d67c4acbdaa4bc9c3e9722c3b7f7032895db2b0849da07a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5180(void)

{
  undefined1 local_18 [8];
  
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
    local_18[0] = 0xff;
    osSendMesg(0x80143e60,local_18,1);
    (*_DAT_8014400c)(_DAT_80143ea0);
    (*_DAT_8014400c)(_DAT_80143e50);
  }
  return;
}
