/* FUN_80166db8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166db8  body 0x80166db8..0x80166e9f  size 232 B
 * body sha256 4d294ab12dac06cffe5622e4800c030e94797e1684cc656b2a83d9e76e2685aa
 * provider record sha256 777d0591015e885c015207a38e61f2a2415b1632d8dfe857cc0b8f0b8e86f3c7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166db8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  iVar2 = iVar1 + 0x38;
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,iVar2);
  func_0x800424ec(iVar2,iVar1 + 0x180,iVar1 + 0x1b0);
  func_0x800424ec(iVar2,iVar1 + 0x760,iVar1 + 0x790);
  func_0x800424ec(iVar2,iVar1 + 0xd40,iVar1 + 0xd70);
  iVar2 = iVar1 + 0xee8;
  func_0x800424ec(iVar1 + 0xd70,iVar1 + 0xeb8,iVar2);
  func_0x800424ec(iVar2,iVar1 + 0x1498,iVar1 + 0x14c8);
  func_0x800424ec(iVar1 + 0x14c8,iVar1 + 0x1610,iVar1 + 0x1640);
  func_0x800424ec(iVar2,iVar1 + 0x1d68,iVar1 + 0x1d98);
  func_0x800424ec(iVar1 + 0x1d98,iVar1 + 0x1ee0,iVar1 + 0x1f10);
  return;
}
