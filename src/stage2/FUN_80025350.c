/* FUN_80025350
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025350  body 0x80025350..0x80025473  size 292 B
 * body sha256 23d3df47fa9a15694449e6f168a16ec6be326587fd466a2e9b4c64865b5e6860
 * provider record sha256 445afdeee8e0cf5a2f57243ea2732876a5970d561c57264de8ad39d945532ff0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025350(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float fVar5;
  
  puVar4 = *(undefined4 **)(DAT_800c7648 + 0x30);
  *puVar4 = 0xdb060000;
  puVar4[1] = 0;
  puVar3 = puVar4 + 8;
  puVar4[1] = &DAT_800efc60;
  *puVar4 = 0xde000000;
  puVar4[2] = 0xde000000;
  puVar4[3] = &DAT_800efd30;
  iVar1 = DAT_801344c0;
  uVar2 = DAT_8010b6fc;
  fVar5 = (float)DAT_800c4eb4;
  puVar4[4] = 0xff1001ff;
  puVar4[5] = uVar2;
  puVar4[6] = 0xed000000;
  puVar4[7] = (int)(fVar5 * 4.0) & 0xfffU | 0x800000;
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)FUN_80024558(puVar3);
  }
  *puVar3 = 0xe7000000;
  puVar3[1] = 0;
  puVar3[2] = 0xe9000000;
  puVar3[3] = 0;
  puVar3[4] = 0xdf000000;
  iVar1 = DAT_800c7648;
  puVar3[5] = 0;
  *(undefined4 *)(iVar1 + 4) = 6;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  return;
}
