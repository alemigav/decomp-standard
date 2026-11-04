/* FUN_8006d718
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d718  body 0x8006d718..0x8006d7a3  size 140 B
 * body sha256 d4e4ecddf513d775f4b4e4b84ed05536d1fcf6316f0c4a8eba30f5c0ac082f7d
 * provider record sha256 1dfee39dfe0677b2e0a2d727190098b4d1108fe40ae8289f4e7586910c78976e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d718(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_8010bf7e;
  uVar2 = 0;
  if (uVar3 != 0) {
    pbVar1 = &DAT_8010bc34;
    do {
      if ((*pbVar1 & 0x80) == 0) {
        if ((*pbVar1 & 0x40) != 0) {
          FUN_8004fc3c(uVar2,pbVar1);
        }
      }
      else {
        FUN_8004fc34(uVar2,pbVar1);
      }
      pbVar1 = pbVar1 + 0x1c;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return;
}
