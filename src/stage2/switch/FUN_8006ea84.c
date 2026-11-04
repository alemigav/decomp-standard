/* FUN_8006ea84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ea84  body 0x8006ea84..0x8006ea8f  size 12 B
 * body sha256 442f57c22c55cb0e470d75067d75995c028833d476dd91ac22af06cc11b29d23
 * provider record sha256 d5c7ec90a8d7da6d6486cc1200aa25776723255518aa6ecdbe146b58dae1eced
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_8(void)

{
  ushort uVar1;
  ushort *unaff_s1;
  
  uVar1 = FUN_800844cc((int)(short)~*unaff_s1);
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
