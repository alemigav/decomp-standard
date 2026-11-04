/* FUN_8006568c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006568c  body 0x8006568c..0x8006572f  size 164 B
 * body sha256 cf13c0fba7ac579ccf0bfc33e0b7700a55f2069c8692e455a96151636a6bd40a
 * provider record sha256 da57ac1e266d527931789e7ea44ddc2f90109f83660bec21035b379d324251ab
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8006568c(short param_1,short param_2)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  
  puVar1 = *(ushort **)(DAT_800df92c + 0x38);
  uVar2 = (uint)*puVar1;
  puVar3 = puVar1 + uVar2 * 6 + 2;
  puVar1 = puVar1 + uVar2 * 6 + -3;
  while( true ) {
    puVar3 = puVar3 + -6;
    uVar2 = uVar2 - 1;
    if (((ushort)(param_1 - *puVar3) < (ushort)(puVar1[1] - *puVar3)) &&
       ((ushort)(param_2 - *puVar1) < (ushort)(puVar1[2] - *puVar1))) break;
    puVar1 = puVar1 + -6;
    if ((uVar2 & 0xffff) == 0) {
      return 0xff;
    }
  }
  return uVar2 & 0xffff;
}
