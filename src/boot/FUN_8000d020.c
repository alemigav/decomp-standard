/* FUN_8000d020
 * image   boot (boot), base 0x80000480
 * address 0x8000d020  body 0x8000d020..0x8000d047  size 40 B
 * body sha256 bf248149f441c4ef9bdd5d6ad8650acf2e1616407774cc54f8543b225eb96f68
 * provider record sha256 f950ba0d88f44d0302082466b380e7aa357b6aa93f094395d03c74031e766a35
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000d020(void)

{
  osSendMesg(0x800177c0,0,0);
  return;
}
