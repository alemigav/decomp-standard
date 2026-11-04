/* idle_spin
 * image   boot (boot), base 0x80000480
 * address 0x80000518  body 0x80000518..0x8000051f  size 8 B
 * body sha256 2afbaddad49e36716ec9ca344d615228f579004349539ffa2cc4e65d7330356c
 * provider record sha256 ec8c6b99d7905f812d5e1d4fe57a0eed9222edffa32d37fb0d7aec9d7f07110f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void idle_spin(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
