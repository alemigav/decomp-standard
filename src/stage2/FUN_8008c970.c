/* FUN_8008c970
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c970  body 0x8008c970..0x8008ca0b  size 156 B
 * body sha256 029eb0726a4d5c696d860353e2f5ada5bfd5399e709dccd1cdaa3cac5fc7aed8
 * provider record sha256 7c6618a4eaec4961f4ae5214a186f97ea8be9caad5cd5fd0602a4e8e01a64609
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c970(uint param_1,undefined4 param_2)

{
  short local_10;
  short local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  if ((DAT_800e110c & 0x8000) != 0) {
    local_c = 0x28;
    local_a = 0x1e;
    local_10 = (short)(param_1 % 3) * 0x28;
    local_e = (short)(param_1 / 3) * 0x1e;
    FUN_80047b74(&DAT_8012f530,&local_10,param_2);
  }
  return;
}
