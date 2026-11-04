/* FUN_80075fc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075fc0  body 0x80075fc0..0x80076043  size 132 B
 * body sha256 a52e55d6dc14e2c32fb780a5283a6766a89598e4e7d07491aa40596d8cbdda22
 * provider record sha256 d48fee821a1162070a69cab72ff89f7cdfc800b9acfa560c8f08b1d76781ff61
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075fc0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_80075f54();
  iVar3 = 3;
  puVar2 = (undefined4 *)&DAT_80119f00;
  puVar1 = (undefined4 *)&DAT_80119efc;
  DAT_8011a290 = 0;
  DAT_80119e78 = 0;
  DAT_80119e9d = 0xff;
  DAT_80119e9c = 0xff;
  do {
    puVar2 = puVar2 + -2;
    puVar1 = puVar1 + -2;
    iVar3 = iVar3 + -1;
    *puVar1 = 0xffffff;
    *puVar2 = 0x6e006e;
  } while (iVar3 != 0);
  DAT_8011a378 = 0;
  return;
}
