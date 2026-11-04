/* FUN_8000de9c
 * image   boot (boot), base 0x80000480
 * address 0x8000de9c  body 0x8000de9c..0x8000dec3  size 40 B
 * body sha256 0d7985280746a3d235ce705c9ae3ddcaa480beabcb6cc1a6df12105219a4aa39
 * provider record sha256 9184e069596adbcfa1dc3876295bee2dbf772f23ec48d6479df28f6f4d272654
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 * FUN_8000de9c(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = param_1;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}
