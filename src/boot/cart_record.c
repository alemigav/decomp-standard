/* cart_record
 * image   boot (boot), base 0x80000480
 * address 0x80001180  body 0x80001180..0x80001193  size 20 B
 * body sha256 882aa031f250c37f6afd89861ccdc66fe37dfff6a317d6720d783d8ffb1ca1b3
 * provider record sha256 7ef73d14db6160567b9fccbf4549153f4ca0105fa696f5478d08a2eadca35c53
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int cart_record(int param_1)

{
  return param_1 * 0x10 + -0x7ffedeb0;
}
