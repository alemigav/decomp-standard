/* FUN_8006d384
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d384  body 0x8006d384..0x8006d457  size 212 B
 * body sha256 3122544d0939401c27c484f6a438d10385a279ad6fcfb72605d89e1366d09b91
 * provider record sha256 def589d31069f65e400d85ba989e2c43b3562bfc84711e29055069abbe9d6a43
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d384(void)

{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_800e13f0;
  DAT_800e113a = 0xffff;
  if (DAT_800df93c != &DAT_800e13f0) {
    do {
      if ((*(uint *)*puVar3 & 1) != 0) {
        *(undefined2 *)((int)*puVar3 + 10) = 0xffff;
      }
      puVar3 = puVar3 + 1;
    } while (puVar3 != DAT_800df93c);
  }
  bVar1 = *(byte *)(DAT_800df92c + 2);
  for (puVar2 = &DAT_800e18f8; puVar2 < &DAT_800e18f8 + (uint)bVar1 * 0xda; puVar2 = puVar2 + 0xda)
  {
    if ((*puVar2 & 1) != 0) {
      *(undefined2 *)((int)puVar2 + 10) = 0xffff;
    }
  }
  return;
}
