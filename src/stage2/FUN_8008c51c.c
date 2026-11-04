/* FUN_8008c51c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c51c  body 0x8008c51c..0x8008c567  size 76 B
 * body sha256 87730a3907588b368a302b1ef2a30142e281036dc646fd6a81be9ec4209b4419
 * provider record sha256 3208eae4af66d61702c0398916f0b716510385704c380c4f8e73969201b72b08
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008c51c(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0;
  puVar2 = &DAT_800c76b0;
  do {
    if (*(byte *)(puVar2 + 0x8606) == param_1) {
      return uVar1;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < DAT_800e8b38);
  return 0xffffffff;
}
