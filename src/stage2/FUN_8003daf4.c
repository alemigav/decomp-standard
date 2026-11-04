/* FUN_8003daf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003daf4  body 0x8003daf4..0x8003dbdf  size 236 B
 * body sha256 c5758f592c26ab656493c53c2d071ecaec0d698756b2f1038031d3ca25668ea3
 * provider record sha256 e99fcc9f65771fcae65b7c062057f36ff3115b402af2c5c971f54f6011324975
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003daf4(void)

{
  int iVar1;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0xfce00000;
  local_14 = 0x19000c8;
  if (5 < *(byte *)(DAT_800ebb94 + 0x21)) {
    local_28 = (int)*(short *)(DAT_800ebb94 + 0x34);
    local_24 = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_20 = (int)*(short *)(DAT_800ebb94 + 0x38);
    iVar1 = FUN_80060f78(&local_28,500,5);
    if (iVar1 != 0) {
      FUN_80077adc(0x31d0001,&local_28);
      FUN_80038a20(0x30f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34)
      ;
      if (*(byte *)(iVar1 + 8) < 0x10) {
        FUN_80052bd0(8,0);
        FUN_80052d10(0xe,0xb4,0x3c,0);
      }
    }
  }
  return;
}
