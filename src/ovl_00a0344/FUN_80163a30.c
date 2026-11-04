/* FUN_80163a30
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163a30  body 0x80163a30..0x80163ab7  size 136 B
 * body sha256 70cc5861498d0790a6ffd0be2c2bc6603d6110a295d619f9e6eb4da7f3df864b
 * provider record sha256 0f70847c606f2b661d023202b9b45d798544ce8db905d35817f9259672a17a14
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80163a30(undefined4 param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_80163898(param_1,0,(int)param_2);
  if ((iVar1 == 0) &&
     (((_DAT_800e110c & 0x10000000) == 0 ||
      (iVar1 = FUN_80163898(param_1,1,(int)param_2), iVar1 == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}
