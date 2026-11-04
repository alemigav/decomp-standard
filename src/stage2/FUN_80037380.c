/* FUN_80037380
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037380  body 0x80037380..0x80037427  size 168 B
 * body sha256 eac01d1317da740fb251cbda98fca85744b08f984e64faff7976047ba36cfab9
 * provider record sha256 3acec42d25f176d0c5171d845770b2b4646e95c9dc8d4f25a462ed96de1c59bd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80037380(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = 0x60;
  puVar1 = &UNK_800eec28;
  do {
    iVar3 = iVar3 + -1;
    *(undefined2 *)(puVar1 + -100) = 0;
    puVar1 = puVar1 + -0x7c;
  } while (iVar3 != 0);
  iVar3 = 0x10;
  do {
    iVar4 = iVar3 + -1;
    *(undefined1 *)((int)&DAT_800ebb94 + iVar3 + 3) = 0xff;
    iVar3 = iVar4;
  } while (iVar4 != 0);
  iVar3 = 0x40;
  puVar5 = (undefined4 *)&DAT_800ebda8;
  puVar2 = (undefined4 *)&DAT_800ebca8;
  do {
    puVar5 = puVar5 + -1;
    puVar2 = puVar2 + -1;
    iVar3 = iVar3 + -1;
    *puVar2 = 0xffffffff;
    *puVar5 = 0xffffffff;
  } while (iVar3 != 0);
  FUN_8003751c(&DAT_801111d0,DAT_800c52dc,0);
  return 0;
}
