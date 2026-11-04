/* FUN_80166e8c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166e8c  body 0x80166e8c..0x80166edf  size 84 B
 * body sha256 a19043eb9b925eeada3b842f0b884af908a1de7930f9496337f7a80534df16b2
 * provider record sha256 8a54dd107300a9682d3588679abc1fd5440015648d33166b97f0d842f567ef5d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166e8c(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,
                  *(int *)(param_1 + 0x234) + param_6 * 0x178 + 0x38,param_7);
  return;
}
