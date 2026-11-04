/* FUN_80052df4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052df4  body 0x80052df4..0x80052e57  size 100 B
 * body sha256 d320d8e8008ee931bbcc61ab6a9c30d2a2d9751472dddb7c4b9813109d45b6a1
 * provider record sha256 11fbe950ae78971ae6f6a547845a9d7f3f7c160a572071c4f8001f224f6776f5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052df4(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = &DAT_8010c124;
  puVar1 = &DAT_8010bfd8;
  do {
    *puVar1 = 0;
    *puVar2 = 0;
    puVar2 = puVar2 + 10;
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 10;
  } while (uVar3 < 0x21);
  PTR_DAT_8010bfa0 = &DAT_8010bfd8;
  PTR_DAT_8010bfa4 = &DAT_8010c124;
  DAT_80112975 = 0;
  DAT_80112974 = 0;
  return;
}
