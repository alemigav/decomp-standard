/* FUN_800a12f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a12f8  body 0x800a12f8..0x800a13c3  size 204 B
 * body sha256 d14367ef6726faf1ceb983dab19325905f202f96f04397c5863696e8cf5c433a
 * provider record sha256 fd84a1b57802fad8073c6667fcca39e1d20af78703242a310af5e57a62907f1a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a12f8(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (uint *)&DAT_8013bc90;
  while ((*(char *)((int)puVar2 + 0xfc1) != '\0' || (*puVar2 != (param_1 & 0x7fffffff)))) {
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 0x3fe;
    if (7 < uVar3) {
      uVar3 = 0xffffffff;
LAB_800a1340:
      if (uVar3 != 0xffffffff) {
        if (-1 < (int)uVar3) {
          *(undefined4 *)(uVar3 * 0xff8 + -0x7fec4260) = param_2;
          *(undefined4 *)(uVar3 * 0xff8 + -0x7fec425c) = param_3;
          return;
        }
        iVar1 = (uVar3 * 0x200 - (uVar3 & 0x7fffffff)) * 8;
        *(undefined4 *)(iVar1 + -0x7fec338c) = param_2;
        *(undefined4 *)(iVar1 + -0x7fec3388) = param_3;
        *(byte *)(iVar1 + -0x7fec3382) = *(byte *)(iVar1 + -0x7fec3382) | 0x10;
      }
      return;
    }
  }
  uVar3 = uVar3 | param_1 & 0x80000000;
  goto LAB_800a1340;
}
