/* FUN_8005cad8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005cad8  body 0x8005cad8..0x8005cb0b  size 52 B
 * body sha256 7d4b284651f7c384e1e1ba6fd8aa0a911508ea2576fda51684b98574eec3aa60
 * provider record sha256 d327c3090bea63240f0fdfa64548837f9afa2ec9988780817aab87ab2c6a02ef
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005cad8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
