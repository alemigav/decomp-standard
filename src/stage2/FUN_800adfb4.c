/* FUN_800adfb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800adfb4  body 0x800adfb4..0x800ae033  size 128 B
 * body sha256 cd5be43b6c4b3f6c46d4255f5cc619e095d6686c53c47d908ae53b6593f6c1da
 * provider record sha256 e0f6353de3a298c627a444f288670610b1a11a1b12e7f8a09d58751782c2c0b7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800adfb4(undefined2 param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  _DAT_8014e154 = param_1;
  _DAT_8014e15c = (undefined4 *)FUN_800ab43c(0x8014e150,0x80152a00,_DAT_801529f0,0xc,&LAB_800ae174);
  if (_DAT_8014e15c == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    *param_2 = *(undefined2 *)((int)_DAT_8014e15c + 6);
    uVar1 = *_DAT_8014e15c;
  }
  return uVar1;
}
