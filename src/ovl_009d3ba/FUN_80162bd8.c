/* FUN_80162bd8
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162bd8  body 0x80162bd8..0x80162c27  size 80 B
 * body sha256 c73eece87ac849870d4fac8829c03a5665e97d76cabb8696e54288fa07bfc19c
 * provider record sha256 dd98f619480f183d7f68577ee5be0e0856d916e12f43b91f5b2154e0bb8c9856
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162bd8(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 4) = 0x1050000;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  uVar1 = func_0x80033604();
  uVar2 = 3;
  if ((uVar1 & 1) != 0) {
    uVar2 = 2;
  }
  func_0x80077d18(uVar2,param_1);
  return;
}
