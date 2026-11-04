/* FUN_8017f190
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f190  body 0x8017f190..0x8017f20f  size 128 B
 * body sha256 d98b629a6495338cc19d66a11a186cd57ad78f9e75d97e19aa0d19a0499de774
 * provider record sha256 ff49ee4cd127c4fde0a9083383aeb94c673886bcb29cda8a60005c6dbba2c386
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017f1d4) */

void FUN_8017f190(undefined1 *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = param_1;
  do {
    *puVar1 = 0xf;
    uVar2 = uVar2 + 1;
    puVar1 = param_1 + uVar2;
  } while (uVar2 < 0xf);
  return;
}
