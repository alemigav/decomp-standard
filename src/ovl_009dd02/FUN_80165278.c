/* FUN_80165278
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165278  body 0x80165278..0x8016530f  size 152 B
 * body sha256 979e892e5948bbe164ccdcbdf17457a2071d2707dc2f53620c0d6e09f744478f
 * provider record sha256 9d248207375650048729abee6604ed7bdbe22c113b10fd9eb44782229a4b9ea0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165278(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    if (((uint)*(byte *)(param_1 + 0x26e) % 3 != 0) ||
       (uVar1 = 5, *(char *)(param_1 + 0x2d9) != '\0')) {
      uVar1 = 0xb;
    }
    FUN_80166b98(param_1,uVar1,2);
  }
  FUN_80164e88(param_1,param_2,param_3);
  return;
}
