/* FUN_8000c840
 * image   boot (boot), base 0x80000480
 * address 0x8000c840  body 0x8000c840..0x8000c867  size 40 B
 * body sha256 32d776bff69c91eebd448ad08d6b2b7827ca5a69a6ff42aa81dbfcaa6a65781e
 * provider record sha256 8db78516ec8d156f4f79c2bab1a6c4be9e08aa2c43ecbb8a3ea79b519e17b253
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000c840(void)

{
  osSendMesg(0x80017710,0,0);
  return;
}
