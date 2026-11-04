/* FUN_8008b130
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b130  body 0x8008b130..0x8008b2e3  size 436 B
 * body sha256 9115180b4f2eadca6152503de35a004b2f19707373eb137dcf7009bdb1c9074b
 * provider record sha256 be842778a8c988780565d73fa267d519eb05e7ad70f792820f52185a1699e9a4
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008b130(void)

{
  uint uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (DAT_800e110c < 0) {
    uVar2 = 0x14d1;
  }
  else {
    uVar2 = 0x14d0;
  }
  uVar2 = FUN_800479c8(DAT_8010b6e8,&DAT_8012f530,uVar2,1);
  uVar2 = FUN_800479c8(uVar2,&DAT_8012f54c,0x14d5,1);
  uVar4 = 10;
  DAT_8012f568 = 0;
  DAT_8012f56c = 0;
  DAT_8012f570 = 0;
  DAT_8012f574 = 0;
  DAT_8012f578 = 0;
  DAT_8012f580 = 0;
  DAT_8012f57c = 0;
  FUN_800479c8(uVar2,&DAT_8012f584,0x14d2,0);
  FUN_8008d2e4(DAT_800c52dc + 0x3b800);
  pbVar3 = &DAT_800e8eec;
  do {
    uVar4 = uVar4 - 1;
    if (pbVar3[2] == 2) {
      uVar1 = *pbVar3 + 0x56;
    }
    else {
      uVar1 = (uint)*pbVar3;
    }
    FUN_8008c970((uVar4 >> 1) + uVar4,DAT_800c52dc + uVar1 * 0x4b0 + 0x3b800);
    pbVar3 = pbVar3 + -4;
  } while (uVar4 != 0);
  return;
}
