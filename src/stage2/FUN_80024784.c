/* FUN_80024784
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80024784  body 0x80024784..0x80024d5f  size 200 B
 * body sha256 2935902b42f236ffb85072832bce28c00cd06f5f67c568d3b85ce5457293f5d7
 * provider record sha256 5eda3336d8d8dd050d71a4eadc68c77b9b9b34bad9de2b9bbea06e58eb8d4528
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80024784(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar3 = DAT_801137d8;
  DAT_800c4ec8 = DAT_800c56e8 - (int)DAT_800e8920 * DAT_801137d8 * 2;
  puVar5 = param_1;
  switch(DAT_800e923c) {
  case 0:
  case 3:
    puVar5 = param_1 + 6;
    *param_1 = 0xe200001c;
    param_1[1] = 0;
    param_1[2] = 0xe3000a01;
    param_1[3] = 0x200000;
    param_1[4] = 0xa000000;
    param_1[5] = &DAT_800c4eb8;
    break;
  case 2:
  case 4:
    *param_1 = 0xe7000000;
    param_1[1] = 0;
    param_1[3] = param_2;
    fVar1 = (float)iVar3;
    param_1[2] = iVar3 - 1U & 0xfff | 0xff100000;
    param_1[4] = 0xed000000;
    iVar4 = DAT_801137dc;
    if (iVar3 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)DAT_801137dc;
    if (DAT_801137dc < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    param_1[5] = ((int)(fVar1 * 4.0) & 0xfffU) << 0xc | (int)(fVar2 * 4.0) & 0xfffU;
    param_1[7] = 0x300000;
    param_1[6] = 0xe3000a01;
    param_1[8] = 0xfcffffff;
    param_1[9] = 0xfffe793c;
    param_1[10] = 0xe200001c;
    param_1[0xb] = 0xf0a4000;
    param_1[0xc] = 0xf7000000;
    puVar5 = param_1 + 0x10;
    param_1[0xd] = CONCAT22(DAT_800e924a,DAT_800e924a);
    param_1[0xe] = (iVar3 - 1U & 0x3ff) << 0xe | (iVar4 - 1U & 0x3ff) << 2 | 0xf6000000;
    param_1[0xf] = 0;
    break;
  case 5:
    *param_1 = 0xed000000;
    param_1[1] = 0x5003c0;
    param_1[2] = 0xff10013f;
    param_1[3] = param_2;
    param_1[5] = 0x300000;
    param_1[4] = 0xe3000a01;
    param_1[6] = 0xfcffffff;
    param_1[7] = 0xfffe793c;
    param_1[8] = 0xe200001c;
    param_1[9] = 0xf0a4000;
    iVar3 = DAT_801137d8;
    param_1[10] = 0xf7000000;
    iVar4 = DAT_801137dc;
    param_1[0xb] = 0;
    param_1[0xd] = 0;
    param_1[0xc] = (iVar3 - 1U & 0x3ff) << 0xe | (iVar4 - 1U & 0x3ff) << 2 | 0xf6000000;
    param_1[0xe] = 0xe7000000;
    param_1[0xf] = 0;
    param_1[0x10] = 0xe7000000;
    param_1[0x11] = 0;
    param_1[0x12] = 0xe200001c;
    param_1[0x13] = 0x504240;
    param_1[0x14] = 0xfcff97ff;
    param_1[0x15] = 0xff2cfe7f;
    param_1[0x16] = 0xe3000a01;
    param_1[0x17] = 0;
    puVar5 = param_1 + 0x18;
    if ((DAT_800e9184 != 0x8000) && (DAT_800e9184 != 0x7fff)) {
      if (DAT_800e9184 == 0xff00) {
        *puVar5 = 0xfa000000;
        param_1[0x19] = 0xfe;
      }
      else {
        *puVar5 = 0xfa000000;
        param_1[0x19] = 0xfeU - ((int)((uint)DAT_800e9184 << 0x10) >> 0x17) & 0xff;
      }
      puVar7 = param_1 + 0x1a;
      if (DAT_800c4ece == '\x02') {
        puVar7 = param_1 + 0x20;
        param_1[0x1a] = 0xe3001001;
        param_1[0x1b] = 0x8000;
        param_1[0x1d] = &DAT_800c4f30;
        param_1[0x1c] = 0x5000017;
        param_1[0x1e] = 0xe7000000;
        param_1[0x1f] = 0;
      }
      puVar5 = puVar7 + 2;
      *puVar7 = 0x9000000;
      puVar7[1] = &DAT_800c4eb8;
    }
    *puVar5 = 0xe7000000;
    puVar5[1] = 0;
    puVar7 = puVar5 + 2;
    if ((DAT_800e9208 != 0x8000) && (DAT_800e9208 != 0x7fff)) {
      if (DAT_800e9208 == 0xff00) {
        *puVar7 = 0xfa000000;
        puVar5[3] = 0xfe;
      }
      else {
        *puVar7 = 0xfa000000;
        puVar5[3] = 0xfeU - ((int)((uint)DAT_800e9208 << 0x10) >> 0x17) & 0xff;
      }
      puVar6 = puVar5 + 4;
      if (DAT_800c4f1e == '\x02') {
        puVar6 = puVar5 + 10;
        puVar5[4] = 0xe3001001;
        puVar5[5] = 0x8000;
        puVar5[7] = &DAT_800c4f48;
        puVar5[6] = 0x5000017;
        puVar5[8] = 0xe7000000;
        puVar5[9] = 0;
      }
      puVar7 = puVar6 + 2;
      *puVar6 = 0x9000000;
      puVar6[1] = &DAT_800c4f08;
    }
    puVar5 = puVar7 + 2;
    *puVar7 = 0xe7000000;
    puVar7[1] = 0;
  }
  return puVar5;
}
