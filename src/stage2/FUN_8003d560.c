/* FUN_8003d560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d560  body 0x8003d560..0x8003d79b  size 572 B
 * body sha256 c490dfe1d687f4e7a48811f703536252878bc09818fe06adc07dfbe5a9a25dd4
 * provider record sha256 06426ee941c287ea959b043f1309ea2369e654dc53dc8021a0bf712eb58a12c1
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d560(void)

{
  byte bVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar2 = FUN_80060f78(&local_20,600,0x14);
  if (iVar2 == 0) {
    iVar2 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
    if ((iVar2 == 0) || (*(short *)(DAT_800ebb94 + 0x36) <= iVar2)) {
      local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
      local_1c = *(short *)(DAT_800ebb94 + 0x36) + 700;
      local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
      iVar2 = FUN_80069f1c(&local_20,2,0x2000,0);
      if (local_1c <= iVar2) {
        if (DAT_8011270c != 0) {
          if (iVar2 == *(int *)(DAT_800ebb94 + 0x14)) {
            bVar1 = *(byte *)(DAT_800ebb94 + 3);
          }
          else {
            bVar1 = *(byte *)(DAT_800ebb94 + 2);
          }
          (*(code *)(&PTR_FUN_800eb9b0)[bVar1])();
        }
        *(int *)(DAT_800ebb94 + 0x14) = iVar2;
        return;
      }
    }
    FUN_80038a20(0x30f2800,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  }
  else if (*(byte *)(iVar2 + 8) < 0x10) {
    if ((*(byte *)(DAT_800ebb94 + 0x1e) & 8) != 0) {
      DAT_800e13e4 = 0x1518;
      DAT_800e13e6 = 0x1e;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
    FUN_80052bd0(8,0);
    FUN_80052d10(0xe,0xb4,0x3c,0);
  }
  else if ((*(byte *)(DAT_800ebb94 + 0x1e) & 8) != 0) {
    DAT_800e900f = DAT_800e900f | 1;
  }
  (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 2)])();
  return;
}
