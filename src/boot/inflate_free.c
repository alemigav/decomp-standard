/* inflate_free
 * image   boot (boot), base 0x80000480
 * address 0x80004594  body 0x80004594..0x800045db  size 72 B
 * body sha256 b0cfadb89f907f44f79a3d1a69f9a23c5f329e4b1fc804c97881aca2ac920a26
 * provider record sha256 73cf939924c5d99c6962aa2139912ccd39f2e7afcef3e33e8d4fa2193fa554ed
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void inflate_free(int param_1,uint param_2)

{
  FUN_800014ac(*(undefined4 *)(param_1 + 0x4c));
  if ((param_2 & 1) != 0) {
    func_0x8008b0a4(param_1);
  }
  return;
}
