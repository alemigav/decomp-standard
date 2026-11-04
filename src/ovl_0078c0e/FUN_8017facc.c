/* FUN_8017facc
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017facc  body 0x8017facc..0x8017fc33  size 360 B
 * body sha256 8868edfaf5ce9bcc393cc35feef928e5fddf8ee956d7b1d3e0a9af14d89b9df0
 * provider record sha256 11ed38ed66685dde977bacb2c85d4f19909b1d8376f98c4d751d221317b0aff1
 * callees 5 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4
FUN_8017facc(undefined4 param_1,int param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  DAT_80180adc = 7;
  DAT_80180ae0 = &DAT_80180d3c;
  DAT_80180d3c = (uint)DAT_80180d78;
  DAT_80180d40 = &DAT_80180ad8;
  DAT_80180d50 = param_5;
  DAT_80180d54 = param_4;
  DAT_80180d58._0_2_ = param_3;
  func_0x80082224(0x80180d5e,param_2,0x10);
  func_0x80082224(0x80180d5a,param_2 + 0x10,4);
  DAT_80180d48 = 0;
  DAT_80180d44 = param_6;
  DAT_80180d74 = &DAT_80181f94;
  DAT_80180d70 = param_1;
  if (DAT_80180d78 == 0) {
    func_0x8000de9c(param_1,&UNK_80181fec +
                            ((*(byte *)(param_2 + 0x12) - 0x1a) * 10 + -0x1a +
                            (uint)*(byte *)(param_2 + 0x13)) * 0x824 + param_6,DAT_80180d50);
    osSendMesg(DAT_80180d74,0,0);
    DAT_80180ad8 = 0;
  }
  else {
    func_0x800879a0(&DAT_80180adc);
    osRecvMesg(&DAT_80181f94,0,1);
  }
  return DAT_80180ad8;
}
