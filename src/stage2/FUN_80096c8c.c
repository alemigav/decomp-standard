/* FUN_80096c8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80096c8c  body 0x80096c8c..0x80096d8f  size 260 B
 * body sha256 407182950325f9d238ef7d6ed1ea9ffc29b41d20cea269c1ded36690b0259a0d
 * provider record sha256 3dfd90f69b8f9262afbdf3ef66cf440eb92630d7d397e27f4fb826dfe49c65b9
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80096c8c(void)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar5 = 0x11;
  puVar4 = (undefined2 *)(uVar1 + 0x762);
  puVar2 = &UNK_80131258;
  iVar3 = uVar1 + 0x758;
  do {
    iVar5 = iVar5 + -1;
    FUN_80047b04(iVar3,0);
    FUN_8004786c(iVar3,0x80,0x80,0x80);
    FUN_800478ac(iVar3,puVar2[-4],puVar2[-3]);
    FUN_800479bc(iVar3,puVar2[-2],puVar2[-1]);
    *(undefined **)(puVar4 + 1) = &DAT_8012f530;
    *puVar4 = 0;
    puVar4 = puVar4 + 10;
    puVar2 = puVar2 + -4;
    iVar3 = iVar3 + 0x14;
  } while (iVar5 != 0);
  DAT_8012bfd0 = 7;
  DAT_8012bfd2 = 0xaa;
  return;
}
