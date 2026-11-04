/* FUN_800850a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800850a4  body 0x800850a4..0x800850db  size 56 B
 * body sha256 415d1be32f17101384857ea610e0d5a9cca2fc22247abc8e2d577e03215c7080
 * provider record sha256 22b2a8fde9b1f19ffc9bc40766d5d7809efebef380e26a48208b8fc1daa122b1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800850a4(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_8011c924;
  iVar2 = 0x300;
  do {
    *(undefined2 *)(puVar1 + 0x22) = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x28;
  } while (iVar2 != 0);
  FUN_8008456c();
  return;
}
