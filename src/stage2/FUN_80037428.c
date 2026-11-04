/* FUN_80037428
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037428  body 0x80037428..0x8003751b  size 244 B
 * body sha256 9239796ed8cfdfabc5215175957e382ad59ad7dee948d908ce1600e3803ce090
 * provider record sha256 2ed57f2fccc143fb1c2f8ec7cfee3fd9fd23383a8e7c079485f369d656cb63f6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80037428(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  byte *pbVar5;
  
  iVar2 = 0x60;
  puVar1 = &UNK_800eec28;
  do {
    iVar2 = iVar2 + -1;
    *(undefined2 *)(puVar1 + -100) = 0;
    puVar1 = puVar1 + -0x7c;
  } while (iVar2 != 0);
  uVar3 = 8;
  pbVar5 = &DAT_800ebba0;
  do {
    uVar3 = uVar3 + 1;
    if (*pbVar5 == 0xff) {
      uVar3 = 0x10;
    }
    else {
      iVar2 = (uint)*pbVar5 * 4;
      *(undefined4 *)(&DAT_800ebba8 + iVar2) = 0xffffffff;
      *(undefined4 *)(&DAT_800ebca8 + iVar2) = 0xffffffff;
      *pbVar5 = 0xff;
    }
    pbVar5 = &DAT_800ebb98 + uVar3;
  } while (uVar3 < 0x10);
  piVar4 = *(int **)(DAT_800df92c + 0x50);
  if (piVar4 != (int *)0x0) {
    if (*piVar4 != -1) {
      DAT_800df934 = FUN_8003751c(piVar4,DAT_800df934,8);
    }
    FUN_8003765c(*(undefined4 *)(DAT_800df92c + 0x5c),*(undefined4 *)(DAT_800df92c + 0x58));
  }
  return 0;
}
