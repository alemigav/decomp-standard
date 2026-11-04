/* FUN_801714e0
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801714e0  body 0x801714e0..0x8017153f  size 96 B
 * body sha256 a2b55fb0e583e6fa0f944cddeff72ca8e57ce8b54e7bf2417485552a68d665fe
 * provider record sha256 428bad7a61f21c47d26abc96f8b88636c774b3bdd8b0d3e2e4a42209c693cb78
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801714e0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = &DAT_80171d50;
  do {
    uVar2 = uVar2 + 1;
    if (param_1 == *piVar1) {
      FUN_80171484(piVar1[1]);
    }
    piVar1 = piVar1 + 2;
  } while (uVar2 < 3);
  return;
}
