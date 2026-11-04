/* FUN_80075ef8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075ef8  body 0x80075ef8..0x80075f53  size 92 B
 * body sha256 7fcbe941cee9e52d94f236ad1e3129023d4ab9789dd1beaed0eb43ff9dae0aeb
 * provider record sha256 9368ffc04941b26b0993f973c50676788956dd39fd9371f44148af9b0a1f1849
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075ef8(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
  }
  iVar2 = 0x18;
  puVar1 = &DAT_8011a268;
  do {
    iVar2 = iVar2 + -1;
    if ((*(short *)(puVar1 + 4) != 4) || (puVar1[1] != '\x03')) {
      *puVar1 = 0;
      *(undefined2 *)(puVar1 + 0x12) = 0;
    }
    puVar1 = puVar1 + -0x24;
  } while (iVar2 != 0);
  return;
}
