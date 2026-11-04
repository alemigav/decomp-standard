/* FUN_80025600
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025600  body 0x80025600..0x8002584b  size 588 B
 * body sha256 bcc712e116cb92f13abf7675988f1eb44eac4b82b2869fb613c0ca9e86f8dce7
 * provider record sha256 0a985d34dd21f0f34be2b713831ee183614bd540ff89caf07f6fbbe00d20a5b0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025600(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  float fVar7;
  
  puVar6 = *(undefined4 **)(DAT_800c763c + 0x30);
  *puVar6 = 0xdb060000;
  puVar6[1] = 0;
  puVar6[3] = &DAT_800efc60;
  puVar6[2] = 0xde000000;
  puVar6[4] = 0xde000000;
  cVar2 = DAT_800c56f4;
  puVar6[5] = &DAT_800efd30;
  puVar6[6] = 0xff1001ff;
  if (cVar2 == '\0') {
    uVar5 = DAT_8010b6e0;
  }
  else {
    uVar5 = DAT_8010b6e4;
  }
  fVar7 = (float)DAT_800c4eb4;
  puVar4 = puVar6 + 10;
  puVar6[7] = uVar5;
  iVar3 = DAT_801344c0;
  puVar6[8] = 0xed000000;
  puVar6[9] = (int)(fVar7 * 4.0) & 0xfffU | 0x800000;
  if (iVar3 == 0) {
    if (DAT_800c56f4 == '\0') {
      uVar5 = DAT_8010b6e0;
    }
    else {
      uVar5 = DAT_8010b6e4;
    }
    puVar4 = (undefined4 *)FUN_80024784(puVar4,uVar5);
  }
  *puVar4 = 0xe7000000;
  iVar3 = DAT_801137d8;
  puVar4[1] = 0;
  fVar7 = (float)iVar3;
  puVar4[2] = 0xed000000;
  cVar2 = DAT_800c56f4;
  if (iVar3 < 0) {
    fVar7 = fVar7 + 4.2949673e+09;
  }
  fVar1 = (float)DAT_801137dc;
  if (DAT_801137dc < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  puVar4[3] = ((int)(fVar7 * 4.0) & 0xfffU) << 0xc | (int)(fVar1 * 4.0) & 0xfffU;
  puVar4[4] = iVar3 - 1U & 0xfff | 0xff100000;
  if (cVar2 == '\0') {
    uVar5 = DAT_8010b6e0;
  }
  else {
    uVar5 = DAT_8010b6e4;
  }
  puVar4[5] = uVar5;
  puVar4[6] = 0xe7000000;
  puVar4[7] = 0;
  puVar4[8] = 0xe9000000;
  puVar4[9] = 0;
  puVar4[10] = 0xdf000000;
  puVar4[0xb] = 0;
  iVar3 = DAT_800c763c;
  *(undefined4 *)(DAT_800c763c + 4) = 6;
  *(undefined4 *)(iVar3 + 0x34) = 0;
  return;
}
