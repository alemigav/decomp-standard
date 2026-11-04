/* FUN_80163868
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163868  body 0x80163868..0x80163907  size 160 B
 * body sha256 f4980600123aa09a9979324f966d57d0a60445e529ac79ab7d0fde1e7798b226
 * provider record sha256 827a5949b5c5bd7aab0fd0c9fadd2abc30b44daf039addf5e682ceff3a7c6f6e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163868(int param_1)

{
  if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
    *(undefined2 *)(param_1 + 100) = 0;
    *(undefined2 *)(param_1 + 0x68) = 0x400;
  }
  else {
    *(undefined2 *)(param_1 + 0x68) = 0;
    *(undefined2 *)(param_1 + 100) = *(undefined2 *)(param_1 + 0x66);
  }
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0x1e001e;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 1000;
  *(undefined4 *)(param_1 + 0x138) = 0x3e80578;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined1 *)(param_1 + 0x2c1) = 1;
  *(undefined2 *)(param_1 + 0x2c2) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0x300;
  func_0x80089d54();
  return;
}
