/* FUN_80029648
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80029648  body 0x80029648..0x800296e7  size 160 B
 * body sha256 a373c9ed9d620f68a0355e7c9b3a194ed09592b4a521d21c9a5eb452ab717da8
 * provider record sha256 21c10866a941ceef0b9eefabeeb1f2eb858179f5ec6a3ae3c28551bae66f30ad
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80029648(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[8]) {
    puVar1 = (undefined4 *)(param_1[0x2c] + 0x10);
    do {
      if ((puVar1[8] != 0) && (puVar1[0xf] == 0)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x2c;
        *(undefined4 *)(*param_1 + 0x18) = *puVar1;
        (**(code **)*param_1)(param_1);
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x14;
    } while (iVar2 < param_1[8]);
  }
  return;
}
