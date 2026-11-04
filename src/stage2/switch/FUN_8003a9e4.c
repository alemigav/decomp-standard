/* FUN_8003a9e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a9e4  body 0x8003a9e4..0x8003a9ff  size 28 B
 * body sha256 65e692a669f0ed7ead3ff38c81af1ea4530ab1b3919eec905476c790d41f53a6
 * provider record sha256 60533bc51b6777f135455fe1a4dd2b8195aca50ba284b6e7804d55a8ae69cb1d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_6(void)

{
  undefined1 *puVar1;
  
  FUN_80027650(0);
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  DAT_800ebb94[2] = DAT_800ebb94[2] + '\x01';
  return;
}
