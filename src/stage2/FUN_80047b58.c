/* FUN_80047b58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b58  body 0x80047b58..0x80047b73  size 28 B
 * body sha256 d162565e44607befdd377c79be6ef85be154b3dc766ea4353f9537a903376709
 * provider record sha256 15de56b5af896f7c765edb02c60b0482bc8ee4d72a4d378b39941a9c15c402e6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b58(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  return;
}
