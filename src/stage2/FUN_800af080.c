/* FUN_800af080
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af080  body 0x800af080..0x800af0d3  size 84 B
 * body sha256 d609db329537cf92d793581afbbc938dedacaf87bfbfe55ab54379eaf9c662ef
 * provider record sha256 48685140f16112b3c864dc8d3c1c1a4129b2883ad7f740691941f4696832fca3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800af080(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  _DAT_80158220 = 0;
  _DAT_80158430 = 0;
  _DAT_80158434 = &DAT_80158230;
  puVar1 = (undefined4 *)&DAT_80158230;
  puVar3 = (undefined4 *)0x0;
  do {
    puVar2 = puVar1;
    puVar2[1] = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar2;
    }
    iVar4 = iVar4 + 1;
    puVar1 = puVar2 + 4;
    puVar3 = puVar2;
  } while (iVar4 < 0x20);
  *puVar2 = 0;
  return;
}
