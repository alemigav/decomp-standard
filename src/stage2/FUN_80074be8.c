/* FUN_80074be8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074be8  body 0x80074be8..0x80074d63  size 380 B
 * body sha256 69c0d58f374971c26f11dc34e677186898b2b0b6207f41ad1fb4ae366a4d695a
 * provider record sha256 ac441921ffe103ac903de31741863669eb60406b1d6587b212b69ee8c75b2926
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80074be8(void)

{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  if (-1 < DAT_800e1322) {
    DAT_800e12d8 = 0;
    if ((DAT_800e110c & 0x200000) != 0) {
      FUN_800736b0(&DAT_800e1130,1,0x10);
    }
    FUN_800736b0(&DAT_800e1130,1,0);
    puVar3 = &DAT_800e13f0;
    if (DAT_800df93c != &DAT_800e13f0) {
      do {
        puVar2 = (uint *)*puVar3;
        if ((*puVar2 & 1) != 0) {
          *(undefined2 *)(puVar2 + 0x6a) = 0;
          FUN_800736b0(puVar2,2,0);
        }
        puVar3 = puVar3 + 1;
      } while (puVar3 != DAT_800df93c);
    }
    bVar1 = *(byte *)(DAT_800df92c + 2);
    for (puVar2 = &DAT_800e18f8; puVar2 < &DAT_800e18f8 + (uint)bVar1 * 0xda; puVar2 = puVar2 + 0xda
        ) {
      if ((*puVar2 & 1) != 0) {
        *(undefined2 *)(puVar2 + 0x6a) = 0;
        FUN_800736b0(puVar2,4,0);
      }
    }
    if ((*DAT_800e13ec & 1) != 0) {
      *(undefined2 *)(DAT_800e13ec + 0x6a) = 0;
      FUN_800736b0(DAT_800e13ec,8,0);
    }
  }
  return;
}
