/* FUN_800a1134
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1134  body 0x800a1134..0x800a1233  size 256 B
 * body sha256 3950cbb343fb5586c21f1f08782c5d6aa7a3ec28916bc55ce4ec84d60ac6315e
 * provider record sha256 093f6038502851798906eff0b6525a242218c011a4a59caf95f5a90fb80e07d5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1134(uint param_1,undefined2 param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar3 = 0;
    puVar2 = (uint *)&DAT_8013bc90;
    do {
      if ((*(char *)((int)puVar2 + 0xfc1) == '\0') && (*puVar2 == (param_1 & 0x7fffffff))) {
        uVar3 = uVar3 | param_1 & 0x80000000;
        goto LAB_800a11a8;
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 0x3fe;
    } while (uVar3 < 8);
    uVar3 = 0xffffffff;
LAB_800a11a8:
    if (uVar3 != 0xffffffff) {
      if ((int)uVar3 < 0) {
        iVar1 = (uVar3 * 0x200 - (uVar3 & 0x7fffffff)) * 8;
        *(undefined2 *)(iVar1 + -0x7fec3384) = param_2;
        *(byte *)(iVar1 + -0x7fec3382) = *(byte *)(iVar1 + -0x7fec3382) | 0x20;
      }
      else {
        *(undefined2 *)(&DAT_8013cc52 + uVar3 * 0xff8) = param_2;
      }
    }
    FUN_800a56c0();
  }
  return;
}
