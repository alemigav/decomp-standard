/* FUN_80097364
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097364  body 0x80097364..0x80097577  size 532 B
 * body sha256 c59a5d1be6a73d09eef7d4e695a8abeeac5e940f221dc4c32a42b1bddced0a42
 * provider record sha256 e2c60c4d4440cf99e8b7188b4af52e5cdf13dfda75a5ec77ab90e71830399a83
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097364(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  uVar7 = 8;
  if (param_2 != 0) {
    uVar7 = 9;
  }
  if ((param_1 & 1) == 0) {
    DAT_80131370 = 0x30;
  }
  else {
    DAT_80131370 = 0;
  }
  if ((param_1 & 2) == 0) {
    DAT_80131364 = 0xc0;
    DAT_80131365 = 0x38;
  }
  else {
    DAT_80131364 = 0x68;
    DAT_80131365 = 0x13;
  }
  puVar6 = (undefined2 *)(uVar1 + 0x956);
  puVar3 = &DAT_80131364 + uVar7 * 4;
  iVar5 = uVar1 + 0x94c;
  do {
    iVar4 = iVar5;
    uVar7 = uVar7 - 1;
    FUN_80047b04(iVar4,0);
    FUN_8004786c(iVar4,0x80,0x80,0x80);
    FUN_800478ac(iVar4,puVar3[-4],puVar3[-3]);
    FUN_800479bc(iVar4,puVar3[-2],puVar3[-1]);
    *(undefined **)(puVar6 + 1) = &DAT_8012f530;
    *puVar6 = 0;
    puVar6 = puVar6 + 10;
    puVar3 = puVar3 + -4;
    iVar5 = iVar4 + 0x14;
  } while (4 < uVar7);
  puVar6 = (undefined2 *)(iVar4 + 0x1e);
  puVar3 = &DAT_80131364 + uVar7 * 4;
  do {
    FUN_80047b04(iVar5,0);
    uVar7 = uVar7 - 1;
    if (uVar7 == DAT_8012bfa7) {
      uVar2 = 0x40;
    }
    else {
      uVar2 = 0x80;
    }
    FUN_8004786c(iVar5,uVar2,uVar2,0x80);
    FUN_800478ac(iVar5,puVar3[-4],puVar3[-3]);
    FUN_800479bc(iVar5,puVar3[-2],puVar3[-1]);
    *(undefined **)(puVar6 + 1) = &DAT_8012f584;
    *puVar6 = 0;
    puVar6 = puVar6 + 10;
    puVar3 = puVar3 + -4;
    iVar5 = iVar5 + 0x14;
  } while (uVar7 != 0);
  DAT_8012bfe0 = 0xa2;
  DAT_8012bfe2 = 0x46;
  DAT_8012bfa7 = 3;
  return;
}
