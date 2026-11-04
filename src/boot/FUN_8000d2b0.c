/* FUN_8000d2b0
 * image   boot (boot), base 0x80000480
 * address 0x8000d2b0  body 0x8000d2b0..0x8000d2c7  size 24 B
 * body sha256 e1699d5c6f9f672b8c7b56fc3eca92758f4be3aa38f413c2a4e0221f1be93736
 * provider record sha256 2449c922be4d8259bbcd0957920a4b5315b24e0b879a261d6eb7d133e9df37f1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8000d2b0(void)

{
  return (_DAT_a4800018 & 3) != 0;
}
