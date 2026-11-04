/* FUN_8008f290
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f290  body 0x8008f290..0x8008f2cb  size 60 B
 * body sha256 13bd08e421767a96482f32b5e0f3efd57ed38230ef157499a01b86f983a16350
 * provider record sha256 aac931f8bd5d2f41f9d13ac8b8d7cc014b68989aa34180e9b7798ac28e5b3f5e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f290(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int unaff_s2;
  
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (8 < bVar1) {
    FUN_8004ac04(0xaf0010,0xe400,param_3,0);
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
