/* FUN_80053d38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053d38  body 0x80053d38..0x80053d7b  size 68 B
 * body sha256 d78d4ac6092408cf560522d2f2543a5b6f760b05be672ee8adbad5980742a681
 * provider record sha256 56d45d88218136684b4e577226a5d909ed5bea9945999ec4527f33d391dc51fe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053d38(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  puVar1 = DAT_8010d940;
  uVar4 = 0;
  puVar3 = DAT_8010d940 + 4;
  puVar2 = DAT_8010d940 + 0x16c;
  do {
    *puVar3 = 0x20;
    puVar3 = puVar3 + 1;
    *puVar2 = 0;
    uVar4 = uVar4 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar4 < 0x168);
  puVar1[0x2d7] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  return;
}
