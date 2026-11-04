/* FUN_80079260
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079260  body 0x80079260..0x80079343  size 228 B
 * body sha256 82973a7bf2ae49d882939704723a3384b34fad7a513c93fc970ec89662761b4e
 * provider record sha256 279250a79209f70f73230fee865c6e82ef72c937f95c008fa44b5c360d04b608
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079260(short param_1)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 * 0x3c;
  iVar5 = 0;
  if ((&DAT_8011a3a4)[iVar4] != '\0') {
    iVar6 = iVar4;
    do {
      if (*(int *)((int)&DAT_8011a390 + iVar6) == 0) {
        return;
      }
      uVar2 = (&DAT_8011a37e)[param_1 * 0x1e];
      bVar1 = (&DAT_8011a3a0)[iVar5 + iVar4];
      cVar3 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar6));
      if (cVar3 != '\0') {
        FUN_800a2218((uint)uVar2 * (uint)bVar1 >> 7 & 0xff,0,
                     *(undefined4 *)((int)&DAT_8011a380 + iVar6),0);
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar5 < 4);
  }
  return;
}
