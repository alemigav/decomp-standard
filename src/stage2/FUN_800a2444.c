/* FUN_800a2444
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2444  body 0x800a2444..0x800a248f  size 76 B
 * body sha256 323b3570760c8f06b249edb0e5b39f1958eec1f8ece97f3279d5084898a9e2be
 * provider record sha256 392d19e6bb12355715453beb82650cceefd0cd4af59649545d26a8476fd40478
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a2444(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)&DAT_8013bc90;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 0x3fe;
    uVar3 = uVar3 + 1;
    FUN_800a0f1c(uVar1);
  } while (uVar3 < 8);
  return;
}
