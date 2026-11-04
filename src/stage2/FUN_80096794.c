/* FUN_80096794
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80096794  body 0x80096794..0x800969a3  size 528 B
 * body sha256 5dadea2f0866981a59a73c74f2bfb9bd98c3c1520228a53b7c157a5bb5a53bd0
 * provider record sha256 2e1bde86c75f44784dc584ce61c165d81f555b8650d3ae5eea1359f891fa6386
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80096794(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0xd;
  if (DAT_800e1138 == 0xd) {
    DAT_8013115c = 0x2a;
    DAT_80131164 = 0;
    DAT_80131165 = 0xb4;
    DAT_80131161 = 0xb4;
    DAT_8013115d = 0xb4;
  }
  else {
    if (DAT_800e1138 < 0xe) {
      if (DAT_800e1138 == 0xc) {
        DAT_80131164 = 0x58;
      }
      else {
        DAT_80131164 = 0;
      }
    }
    else {
      DAT_80131164 = 0x2c;
    }
    DAT_8013115d = 200;
    DAT_80131161 = 0xd6;
    DAT_80131165 = 0xeb;
    DAT_8013115c = DAT_80131164;
  }
  puVar2 = (undefined2 *)(DAT_800c52dc + 0x3ba32);
  puVar1 = &UNK_80131190;
  iVar4 = DAT_800c52dc + 0x3ba28;
  DAT_80131160 = DAT_80131164;
  do {
    iVar3 = iVar3 + -1;
    FUN_80047b04(iVar4,0);
    FUN_8004786c(iVar4,0x80,0x80,0x80);
    FUN_800478ac(iVar4,puVar1[-4],puVar1[-3]);
    FUN_800479bc(iVar4,puVar1[-2],puVar1[-1]);
    *(undefined **)(puVar2 + 1) = &DAT_8012f530;
    *puVar2 = 0;
    puVar2 = puVar2 + 10;
    puVar1 = puVar1 + -4;
    iVar4 = iVar4 + 0x14;
  } while (iVar3 != 0);
  iVar4 = 10;
  puVar2 = (undefined2 *)(DAT_800c52dc + 0x3bb36);
  puVar1 = &UNK_801311b8;
  iVar3 = DAT_800c52dc + 0x3bb2c;
  do {
    iVar4 = iVar4 + -1;
    FUN_80047b04(iVar3,0);
    FUN_8004786c(iVar3,0x80,0x80,0x80);
    FUN_800478ac(iVar3,puVar1[-4],puVar1[-3]);
    FUN_800479bc(iVar3,puVar1[-2],puVar1[-1]);
    *(undefined **)(puVar2 + 1) = &DAT_8012f530;
    *puVar2 = 0;
    puVar2 = puVar2 + 10;
    puVar1 = puVar1 + -4;
    iVar3 = iVar3 + 0x14;
  } while (iVar4 != 0);
  return;
}
