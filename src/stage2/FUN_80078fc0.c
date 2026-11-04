/* FUN_80078fc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078fc0  body 0x80078fc0..0x800790a3  size 228 B
 * body sha256 490b391460be06c54c7bbfc8344fee1ebd0d625e9906c6aacc71e1da4fa46287
 * provider record sha256 cbe64654b6d9321e6cfc5559c7f20ffb1941c750274cba312aeb4f37583981b6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80078fc0(short param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0x3c;
  if ((&DAT_8011a3a4)[iVar2] != '\0') {
    iVar3 = 0;
    if ((&DAT_8011a3a4)[iVar2] == -1) {
      do {
        if (*(int *)((int)&DAT_8011a390 + iVar2) == 0) break;
        cVar1 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
        iVar3 = iVar3 + 1;
        if (cVar1 != '\0') {
          FUN_800a1fc8(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
        }
        iVar2 = iVar2 + 4;
      } while (iVar3 < 4);
    }
    (&DAT_8011a3a4)[param_1 * 0x3c] = 0xfe;
  }
  return;
}
