/* FUN_8004fc44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fc44  body 0x8004fc44..0x8004fd1b  size 216 B
 * body sha256 64e2698c3d19fe36dd79a972d084e8b886cc9f8cfa809dcdd66d61342f6db27e
 * provider record sha256 6034d2bf52b87e6a54a61eee3224d621bb38dac437ac4d8e964dc48ba94e2588
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004fc44(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)DAT_8010bf7e;
  if (uVar5 != 0) {
    pbVar3 = &DAT_8010bc34;
    uVar4 = 0;
    uVar2 = (uint)DAT_800dfbe8;
    do {
      bVar1 = *pbVar3;
      if ((bVar1 & 0x80) == 0) {
        if ((bVar1 & 0x40) != 0) {
          FUN_8004fea4(pbVar3,pbVar3 + uVar2 * 8 + 8,*pbVar3 & 0xbf);
        }
      }
      else {
        FUN_8004fd1c(pbVar3,pbVar3 + uVar2 * 8 + 8,bVar1 & 0x7f);
      }
      pbVar3 = pbVar3 + 0x1c;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  return;
}
