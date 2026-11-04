/* FUN_80164588
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80164588  body 0x80164588..0x80164623  size 156 B
 * body sha256 01a12675007d04214e9962c558c9a9d6b6d3aa81eff26b6b4125cdf3b74ae5f3
 * provider record sha256 bf95c7e1a703bd955f3a28258b66197d90c2ce637f0d61ff8e4b471f74b2cff9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164588(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    if (*(char *)(param_1 + 0x2ce) == '\0') {
      func_0x80077d18(0,param_1);
    }
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    FUN_80165364(param_1);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = func_0x80036c68(param_1,10,3,0);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  return;
}
