/* FUN_800ab3cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab3cc  body 0x800ab3cc..0x800ab3f3  size 40 B
 * body sha256 ac942531b5728f4bff48022d003a89b1483c87e2043e15115a57539b9798bd98
 * provider record sha256 3c4c2fcec47375cc4604e4bcab6d8310f6346dce08f7881377a00f236f8dc123
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800ab3cc(void)

{
  DAT_80136320 = DAT_80136320 * -0x57cae29d;
  return DAT_80136320 >> 6 & 0xffff;
}
