/* FUN_800a1ecc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1ecc  body 0x800a1ecc..0x800a1f3f  size 116 B
 * body sha256 f236ba6e4417620ed7c20b5dbe98bf543a779e91dc982fb079f587ce25c5768f
 * provider record sha256 fbeac9b1f5ab8062d95532e4ade1a9de92796b8ba6a4dfcc5c0ca808d95d529f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a1ecc(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar4 = 0;
  puVar2 = &DAT_8013bc90;
  do {
    puVar2[0xfc0] = 0;
    puVar2[0xfc1] = 1;
    uVar4 = uVar4 + 1;
    puVar2 = puVar2 + 0xff8;
  } while (uVar4 < 8);
  _DAT_8013bc80 = &DAT_8013a480;
  iVar6 = 0;
  puVar1 = (undefined4 *)&DAT_8013a480;
  puVar5 = (undefined4 *)0x0;
  do {
    puVar3 = puVar1;
    puVar3[1] = puVar5;
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = puVar3;
    }
    iVar6 = iVar6 + 1;
    puVar1 = puVar3 + 6;
    puVar5 = puVar3;
  } while (iVar6 < 0x100);
  *puVar3 = 0;
  _DAT_80143c5c = 0;
  return;
}
