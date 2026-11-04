/* FUN_800066f0
 * image   boot (boot), base 0x80000480
 * address 0x800066f0  body 0x800066f0..0x80006777  size 136 B
 * body sha256 2957332fa58441fcd5220c237eda662bd22648ee5d7e0482467200659b77d551
 * provider record sha256 739c2df9f2d88dad2cf7a38e969fd55e4f5f56999bbd8c690c6d36c5d0b0007d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800066f0(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_8000cfb4();
  if (DAT_80014fe0 != '\x01') {
    FUN_80006814();
    FUN_8000d1f0(1,&DAT_80014fa0);
    osRecvMesg(param_1,0,1);
  }
  uVar1 = FUN_8000d1f0(0,&DAT_80014fa0);
  DAT_80014fe0 = 1;
  FUN_8000d020();
  return uVar1;
}
