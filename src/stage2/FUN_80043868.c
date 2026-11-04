/* FUN_80043868
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043868  body 0x80043868..0x800438d3  size 108 B
 * body sha256 c366562ca56218f79d87151f8a1aa44e5510890ccdb3b9771a81429bcdcf6a85
 * provider record sha256 8eb3c44512ddd78ff975f42fc6c0ca207f1d3a1b0bbf7ed6bddb994a6a42cdb7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80043868(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efda0 = 0;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x14) {
    param_1 = FUN_80043988(param_1,param_2,0,0);
  }
  return param_1;
}
