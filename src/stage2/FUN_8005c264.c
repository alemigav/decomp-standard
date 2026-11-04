/* FUN_8005c264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c264  body 0x8005c264..0x8005c27b  size 24 B
 * body sha256 62adef96f8ee9f85a8c2182e54eab5757654b6a1f2f94b40ed38e522af775d30
 * provider record sha256 732eb64c3aeeafc88a082734160519245638df20fda22e9c11b7852c242a3248
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c264(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(iVar1 + 0x1e7c) = 0;
  *(undefined1 *)(iVar1 + 0x1e72) = 0;
  *(undefined2 *)(iVar1 + 0x1e7e) = 0;
  return;
}
