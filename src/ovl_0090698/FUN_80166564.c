/* FUN_80166564
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166564  body 0x80166564..0x80166633  size 208 B
 * body sha256 4f6b5af9f49aebf9b9f92284cdf0703826c7b0a9c6adcf711f2623c67e81c880
 * provider record sha256 5d40487425c84f8e482a3719535c6cb8a37962f7898b4cfff59a4ebdd4cf7fb3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166564(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 6) == '\0') && (*(char *)(param_1 + 0x2c0) == '\0')) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar1 + 0x1be8) = *(uint *)(iVar1 + 0x1be8) | 0x10;
    *(undefined2 *)(iVar1 + 0x1d1e) = 0x5a;
    *(undefined2 *)(iVar1 + 0x1d18) = 0;
    *(undefined2 *)(iVar1 + 0x1d1a) = 0;
    *(undefined1 *)(iVar1 + 0x1d1c) = 100;
    *(undefined1 *)(iVar1 + 0x1d1d) = 100;
    FUN_801679c8(param_1,0x101f3f);
    FUN_8016703c(param_1,0x13,7);
    FUN_8016703c(param_1,0,6);
    FUN_8016703c(param_1,1,6);
    *(undefined1 *)(param_1 + 0x2d5) = 1;
  }
  FUN_8016577c(param_1,param_2,param_3);
  return;
}
