/* FUN_801628bc
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x801628bc  body 0x801628bc..0x80162937  size 124 B
 * body sha256 956fe6777bbbcb564fe04ce4d2c05c909a08fb84724f89a892fba6a38fa7fb35
 * provider record sha256 a3126ab236452c0b9bcfa127ee04c0b1496ce9a374268b319c030f2997d0f455
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801628bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x80074d64(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
  if ((iVar1 < *(short *)(param_1 + 0x25e)) && (*(char *)(param_1 + 0x2be) == '\0')) {
    FUN_801629d0(param_1,param_2,param_3);
  }
  else {
    FUN_80162938(param_1,param_2,param_3);
  }
  return;
}
