/* FUN_800b21a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b21a8  body 0x800b21a8..0x800b21ef  size 72 B
 * body sha256 d933aa35bfffec678cf2c2f08a71e9bd4b73b11cad42fa41b9419ee3928ba856
 * provider record sha256 0d3662a48714d3c2221b77b24765b2af81c2b5dc21a3b64f0d8aed96852e0fe8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b21a8(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a2444();
    FUN_800aaea8();
    FUN_800aefb4(0);
    FUN_800a56c0();
  }
  return;
}
