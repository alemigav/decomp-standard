/* thread_dispatcher
 * image   boot (boot), base 0x80000480
 * address 0x80000c68  body 0x80000c68..0x80000cb3  size 76 B
 * body sha256 056cfaac0ec6c0db8369f1a619b1d5050747b1c294f1f778d775ffa98fef2354
 * provider record sha256 153cee5c4d70b4b3bda82b5b2ce02a231d39e15afd8df76a1cf6812e16094d87
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thread_dispatcher(void)

{
  int *in_k0;
  
  if (in_k0[1] < *(int *)((int)_DAT_80012948 + 4)) {
    FUN_80000f08(&DAT_80012948,in_k0);
    FUN_80000f60();
    return;
  }
  *in_k0 = (int)_DAT_80012948;
  _DAT_80012948 = in_k0;
  FUN_80000f60();
  return;
}
