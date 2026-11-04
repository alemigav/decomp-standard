/* FUN_8006d5a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d5a8  body 0x8006d5a8..0x8006d5db  size 52 B
 * body sha256 7d5a12e1db82fb96e1aa17e8ba43c998e862e7efe42954dcdca9440df9dad49c
 * provider record sha256 98cd3baabf7e061b2d6114ad08f2062ec87f57465df5e2647f1e8c148870a0c4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d5a8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_800dfb60;
  iVar2 = 0x20;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  DAT_800e8604 = 0;
  return;
}
