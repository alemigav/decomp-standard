/* FUN_80162f78
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162f78  body 0x80162f78..0x80162fbb  size 68 B
 * body sha256 0d4a66971888a85df5c6154e983a229982d21e822d3aaaa6b45f1005a820015c
 * provider record sha256 740c2652d5b63bdc2c8eb85571faf06e0a1939c2c71edff5726862d7dac20719
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162f78(int param_1)

{
  if (((**(uint **)(param_1 + 0x214) & 0x8000000) != 0) &&
     (**(uint **)(param_1 + 0x214) >> 0x1c < 2)) {
    func_0x80077d18();
  }
  return;
}
