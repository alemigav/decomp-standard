/* FUN_8008dd74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008dd74  body 0x8008dd74..0x8008de47  size 212 B
 * body sha256 71b99da20db78722c1efc69a8b72f402184227526b35211b94ecad2f5a19b6e7
 * provider record sha256 bca505528c1d17d5fd959f2798f892aaa960186d82ee67ee9ca19db4a6a0721d
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008dd74(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int unaff_s1;
  int unaff_s2;
  
  FUN_80097578(DAT_8013a380);
  bVar1 = *(byte *)(unaff_s1 + 3);
  if (bVar1 == 1) {
    FUN_8008e278();
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      iVar2 = FUN_800837ac(&DAT_800e8ce0,0x7e);
      if (iVar2 == 0) {
        FUN_80083758(&DAT_800e8ce0,0x7e);
        uVar3 = 2;
      }
      else {
        FUN_80083780(&DAT_800e8ce0,0x7e);
        uVar3 = 0;
      }
      FUN_80097364(uVar3 | 1,1);
      *(undefined1 *)(unaff_s1 + 0xf) = 0;
      *(undefined1 *)(unaff_s1 + 2) = 1;
      *(undefined1 *)(unaff_s1 + 3) = 0;
    }
  }
  else if (bVar1 == 2) {
    FUN_8008f0a8();
  }
  else if (bVar1 == 3) {
    FUN_8008def4();
  }
  FUN_800962fc(*(undefined1 *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x2181a));
  return;
}
