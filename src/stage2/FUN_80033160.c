/* FUN_80033160
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033160  body 0x80033160..0x800331b7  size 88 B
 * body sha256 0a4d6757a0b95189bce06c200fb9f7cd3b3376e38894f49e29e18118e267f848
 * provider record sha256 88cf043d166b5ad179eed55fe0a4d052cb04ea9ba9b7a25a5bc9fcf7e89e3e9f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033160(int param_1,int param_2)

{
  short sVar1;
  
  sVar1 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                       (int)*(short *)(param_2 + 0x2a),(int)*(short *)(param_2 + 0x32));
  return (((int)*(short *)(param_2 + 0x66) - (int)sVar1) + 0x400U & 0xfff) < 0x800;
}
