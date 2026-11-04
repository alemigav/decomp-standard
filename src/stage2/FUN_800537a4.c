/* FUN_800537a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800537a4  body 0x800537a4..0x80053843  size 160 B
 * body sha256 ca0b1b82447a669c889d5c8be657bcba28edddc7ac7e3c75a0451dadbeebde06
 * provider record sha256 1187ce05e8019eb426a21b2ffe66913680985a5b2fd929f28dee72e553998049
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800537a4(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 3;
  iVar3 = DAT_8010d940 + (uint)DAT_800dfbe8 * 0x40 + 0x52a0;
  puVar2 = (undefined4 *)(iVar3 + 0x30);
  do {
    *puVar2 = 0xffffff00;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + -4;
  } while (-1 < iVar4);
  *(undefined2 *)(iVar3 + 4) = param_1;
  *(undefined2 *)(iVar3 + 8) = param_3;
  *(undefined2 *)(iVar3 + 0x14) = param_1;
  *(undefined2 *)(iVar3 + 0x18) = param_3;
  *(undefined2 *)(iVar3 + 0x24) = param_1;
  *(undefined2 *)(iVar3 + 0x28) = param_1;
  *(undefined2 *)(iVar3 + 0x34) = param_3;
  *(undefined2 *)(iVar3 + 0x38) = param_3;
  *(undefined2 *)(iVar3 + 6) = param_2;
  *(undefined2 *)(iVar3 + 10) = param_2;
  *(undefined2 *)(iVar3 + 0x16) = param_4;
  *(undefined2 *)(iVar3 + 0x1a) = param_4;
  *(undefined2 *)(iVar3 + 0x26) = param_2;
  *(undefined2 *)(iVar3 + 0x2a) = param_4;
  *(undefined2 *)(iVar3 + 0x36) = param_2;
  *(undefined2 *)(iVar3 + 0x3a) = param_4;
  iVar3 = 2;
  do {
    bVar1 = -1 < iVar3;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  return;
}
