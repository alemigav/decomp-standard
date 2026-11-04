/* FUN_800790a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800790a4  body 0x800790a4..0x80079193  size 240 B
 * body sha256 d72f116e47f1eeb1390d85a8f69950a482332e7e541f03caef83701065c7dc6f
 * provider record sha256 e0ff5e68bba1c90bbf599b3908bbe2e2cfd2fe69a19c5fbb0c557f7855d0daa4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800790a4(short param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0x3c;
  if ((&DAT_8011a3a4)[iVar2] != '\0') {
    iVar3 = 0;
    do {
      if (*(int *)((int)&DAT_8011a390 + iVar2) == 0) break;
      cVar1 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
      if (cVar1 == '\0') {
        *(undefined4 *)((int)&DAT_8011a380 + iVar2) = 0xffffffff;
      }
      else {
        FUN_800a1f40(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
        *(undefined4 *)((int)&DAT_8011a380 + iVar2) = 0xffffffff;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < 4);
    (&DAT_8011a3a4)[param_1 * 0x3c] = 1;
  }
  return;
}
