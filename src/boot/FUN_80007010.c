/* FUN_80007010
 * image   boot (boot), base 0x80000480
 * address 0x80007010  body 0x80007010..0x80007027  size 24 B
 * body sha256 ec3c7a1e63557ac0e0116fe8f9e4a79f89f002d4feb5ffa5942970f51065543f
 * provider record sha256 89a543206e81ee063ee5fa47163d4c89a289f7e7ea83c7ca769936530bf52662
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80007010(int param_1)

{
  if (param_1 == 0) {
    param_1 = _DAT_80012950;
  }
  return *(undefined4 *)(param_1 + 4);
}
