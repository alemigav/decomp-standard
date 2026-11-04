/* FUN_8008cc1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008cc1c  body 0x8008cc1c..0x8008ccbb  size 160 B
 * body sha256 12bbdaa08759fe3aa1a4ca812dc72ce6dd30c3cd85dc2156703812704c3fa088
 * provider record sha256 3dbb8d4a7c4f0386eefa08cd6089da031395ed7677b6fe39b904c98a278a509d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008cc1c(uint param_1)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  if ((DAT_800e110c & 0x8000) != 0) {
    local_10 = 0x50;
    local_c = 0x28;
    local_e = 0;
    local_a = 0x1e;
    FUN_80047cc8(&DAT_8012f530,&local_10,(param_1 % 3) * 0x28,(param_1 / 3) * 0x1e & 0xfffe);
  }
  return;
}
