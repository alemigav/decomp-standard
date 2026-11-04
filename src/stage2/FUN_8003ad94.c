/* FUN_8003ad94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ad94  body 0x8003ad94..0x8003adff  size 108 B
 * body sha256 8a38b19bccfd82d02c550e5bf11fd8099e12c160781b55a37e66436d05c99d43
 * provider record sha256 d6d560441b5b719c463e8de283fde26c3a16b93e6982e717924ce1af703322d8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ad94(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  uVar3 = FUN_80069f1c(&local_18,2,0x2000,0);
  puVar2 = DAT_800ebb94;
  puVar1 = DAT_800ebb94 + 0xb;
  *(undefined4 *)(DAT_800ebb94 + 0x14) = uVar3;
  *puVar2 = *puVar1;
  DAT_800ebb94[1] = 5;
  return;
}
