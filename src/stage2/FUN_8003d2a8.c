/* FUN_8003d2a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d2a8  body 0x8003d2a8..0x8003d453  size 428 B
 * body sha256 69c8a756da9a5427ffce31216ff6a27556f3c6197f2230e8826801b3fc60b3fd
 * provider record sha256 f2e4c3d9a59e6437bd6a725ff7329ed62b7e50491122628e5dfd1d0b01767f2a
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d2a8(void)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar2 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar2 == 0) || (*(short *)(DAT_800ebb94 + 0x36) <= iVar2)) {
    iVar2 = FUN_80069f1c(&local_20,2,0x2000,0);
    puVar3 = (uint *)FUN_80060f78(&local_20,500,5);
    if (puVar3 == (uint *)0x0) {
      if (iVar2 < local_1c) {
        (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 2)])();
      }
      else {
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
      }
    }
    else {
      uVar4 = 0x3060000;
      if ((*puVar3 & 0x2000) != 0) {
        uVar4 = 0x3160000;
      }
      FUN_80077adc(uVar4 | 1,&local_20);
      if (*(byte *)(puVar3 + 2) < 0x10) {
        FUN_80052bd0(8,0);
        FUN_80052d10(0xe,0xb4,0x3c,0);
      }
    }
  }
  else {
    (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 2)])();
  }
  return;
}
