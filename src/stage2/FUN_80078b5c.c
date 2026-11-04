/* FUN_80078b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078b5c  body 0x80078b5c..0x80078c47  size 236 B
 * body sha256 1574332cfb1872a5048345667a7797d2a34095360855ff2c8b6793a2020d35ff
 * provider record sha256 e42cff65ba2c7dbda9246eee7f454012fea95e3741bdb3ffb8493f2f042c0aef
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80078b5c(short param_1)

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
    (&DAT_8011a3a4)[param_1 * 0x3c] = 0;
  }
  return;
}
