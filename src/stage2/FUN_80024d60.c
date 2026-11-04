/* FUN_80024d60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80024d60  body 0x80024d60..0x8002512f  size 976 B
 * body sha256 14c6f59ae3ce32b501668417eb979f5a8044bfb0b151477ea5b7abf6bc36539f
 * provider record sha256 6f63b969be85a5bc219444f00d40e43b11e708b347572626f585bd2ee219e360
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80024d60(void)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  float fVar8;
  
  iVar3 = DAT_800c56ec;
  *(undefined **)(DAT_800c56ec + 0x10) = &DAT_8001b740;
  puVar5 = *(undefined4 **)(iVar3 + 0x30);
  *(undefined **)(iVar3 + 0x18) = &DAT_800bb680;
  puVar6 = puVar5 + 10;
  *puVar5 = 0xdb060000;
  puVar5[1] = 0;
  puVar5[3] = &DAT_800efc60;
  puVar5[2] = 0xde000000;
  puVar5[4] = 0xde000000;
  puVar5[5] = &DAT_800efd30;
  uVar4 = DAT_8010b6fc;
  iVar3 = DAT_800c4f60;
  fVar8 = (float)DAT_800c4eb4;
  puVar5[6] = 0xff1001ff;
  puVar5[7] = uVar4;
  puVar5[8] = 0xed000000;
  puVar5[9] = (int)(fVar8 * 4.0) & 0xfffU | 0x800000;
  if (iVar3 != 0) {
    puVar5 = (undefined4 *)FUN_80024558(puVar6);
    puVar6 = puVar5 + 2;
    *puVar5 = 0xe7000000;
    puVar5[1] = 0;
  }
  bVar1 = DAT_800c56f4 == '\0';
  *puVar6 = 0xff1001ff;
  if (bVar1) {
    uVar4 = DAT_8010b6e4;
  }
  else {
    uVar4 = DAT_8010b6e0;
  }
  fVar8 = (float)DAT_800c4eb4;
  puVar7 = puVar6 + 4;
  puVar6[1] = uVar4;
  iVar3 = DAT_800c4f60;
  puVar6[2] = 0xed000000;
  puVar6[3] = (int)(fVar8 * 4.0) & 0xfffU | 0x800000;
  if (((iVar3 != 0) || (DAT_800e923c == '\x02')) || (DAT_800e923c == '\x03')) {
    if (DAT_800c56f4 == '\0') {
      uVar4 = DAT_8010b6e4;
    }
    else {
      uVar4 = DAT_8010b6e0;
    }
    puVar5 = (undefined4 *)FUN_80024784(puVar7,uVar4);
    puVar7 = puVar5 + 2;
    *puVar5 = 0xe7000000;
    DAT_800c4f60 = 0;
    puVar5[1] = 0;
    DAT_800c4f6c = 0;
  }
  bVar1 = DAT_800c56f4 == '\0';
  *puVar7 = DAT_801137d8 - 1U & 0xfff | 0xff100000;
  if (bVar1) {
    uVar4 = DAT_8010b6e4;
  }
  else {
    uVar4 = DAT_8010b6e0;
  }
  puVar7[1] = uVar4;
  puVar7[2] = 0xe1000000;
  puVar7[3] = 0xbc630;
  puVar7[4] = 0xdd0007ff;
  puVar7[5] = 0x1f7c0;
  puVar7[6] = 0xdb060000;
  puVar7[7] = 0;
  puVar7[8] = 0xde000000;
  puVar7[9] = (uint)&DAT_800efc60;
  fVar8 = (float)DAT_801137d8;
  bVar1 = DAT_801137d8 < 0;
  puVar7[10] = 0xed000000;
  if (bVar1) {
    fVar8 = fVar8 + 4.2949673e+09;
  }
  fVar2 = (float)DAT_801137dc;
  if (DAT_801137dc < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  puVar7[0xb] = ((int)(fVar8 * 4.0) & 0xfffU) << 0xc | (int)(fVar2 * 4.0) & 0xfffU;
  uVar4 = DAT_8010b6fc;
  puVar7[0xc] = 0xfe000000;
  puVar7[0xd] = uVar4;
  puVar7[0xf] = (uint)&DAT_800c76c0;
  puVar7[0xe] = 0xde010000;
  puVar5 = DAT_800df8b0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe9000000;
  DAT_800df8b0 = puVar6;
  puVar5[1] = 0;
  puVar5 = DAT_800df8b0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdf000000;
  DAT_800df8b0 = puVar6;
  iVar3 = DAT_800c56ec;
  puVar5[1] = 0;
  *(undefined4 *)(iVar3 + 4) = 6;
  *(undefined4 *)(iVar3 + 0x34) = 0;
  return;
}
