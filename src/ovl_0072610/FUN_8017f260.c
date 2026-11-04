/* FUN_8017f260
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f260  body 0x8017f260..0x8017f36f  size 272 B
 * body sha256 2985ff054863fba452b3bafe692088fb729145d6b3e989e196100d4e36d42707
 * provider record sha256 f4fce1fc3bcc7b04d6611f2e7ecc1b03e31443cc082b71bea14b5b32ff82ef82
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8017f260(undefined4 param_1)

{
  if (*(int *)(DAT_80186c94 + 0x420) == 3) {
    param_1 = FUN_8017f658();
  }
  else if (DAT_8018576c == 2) {
    if (*(int *)(DAT_80186c94 + 0x42c) == 0) {
      param_1 = FUN_8017f3b4();
    }
    else {
      param_1 = FUN_8017f540();
    }
  }
  else if (DAT_8018576c < 3) {
    if (DAT_8018576c == 1) {
      if (*(int *)(DAT_80186c94 + 0x42c) == 0) {
        param_1 = FUN_8017f370();
      }
      else {
        param_1 = FUN_8017f4dc();
      }
    }
  }
  else if (DAT_8018576c == 3) {
    if (*(int *)(DAT_80186c94 + 0x42c) == 0) {
      param_1 = FUN_8017f430();
    }
    else {
      param_1 = FUN_8017f5bc();
    }
  }
  else if (DAT_8018576c == 4) {
    param_1 = FUN_8017f4ac();
  }
  return param_1;
}
