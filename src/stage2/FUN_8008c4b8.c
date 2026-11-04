/* FUN_8008c4b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c4b8  body 0x8008c4b8..0x8008c51b  size 100 B
 * body sha256 7127976fbedba7009748789f15d51aec45fae155cf753654a5c106fa45cb704b
 * provider record sha256 049d2f9fe92730bc35c117e03470bcf7fe8ab5d93c4c7e65e29b7747b1158699
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008c4b8(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  puVar2 = &DAT_800c76b0;
  while ((*(char *)(puVar2 + 0x8606) != '\0' || (uVar3 = uVar3 + 1, param_1 != 0))) {
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
    if (DAT_800e8b38 <= uVar1) {
      uVar1 = 0xffffffff;
      if (param_1 != 0) {
        uVar1 = uVar3;
      }
      return uVar1;
    }
  }
  return uVar1;
}
