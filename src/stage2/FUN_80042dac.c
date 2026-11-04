/* FUN_80042dac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042dac  body 0x80042dac..0x80042ddf  size 52 B
 * body sha256 d059df677aafc66e9ad012e4d76b69030a2f982ed884c79e00853034cfcd4650
 * provider record sha256 08182940a85d1c516bc8ac2143678bc70352edb538c2c9bc19ef9b8a994cefeb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80042dac(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)&DAT_80139a64;
  iVar2 = 2;
  puVar3 = (undefined4 *)(param_1 + 0x14);
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != -1);
  return;
}
