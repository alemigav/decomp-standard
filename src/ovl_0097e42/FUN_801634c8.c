/* FUN_801634c8
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x801634c8  body 0x801634c8..0x8016358b  size 196 B
 * body sha256 f41146f53a4b26df531bf0f9e03e2f1da1ab6798ebf9b18b3c85cde87d3ed67d
 * provider record sha256 c87b1fd88cb34a112de44061bd491591bced101be4399a03d33639e4d128d2e1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801634c8(int param_1)

{
  short sVar2;
  int iVar1;
  
  sVar2 = func_0x80032d14(0xffff9d90,0xfffff8f8,(int)*(short *)(param_1 + 0x32),
                          (int)*(short *)(param_1 + 0x2e));
  *(short *)(param_1 + 0x2b4) = sVar2;
  iVar1 = func_0x800408c0((int)sVar2);
  iVar1 = iVar1 * 0x708;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  *(int *)(param_1 + 0x30) = (iVar1 >> 0xc) + -0x6270;
  iVar1 = func_0x80040968((int)*(short *)(param_1 + 0x2b4));
  iVar1 = iVar1 * -0x708;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  *(int *)(param_1 + 0x2c) = (iVar1 >> 0xc) + -0x708;
  *(undefined2 *)(param_1 + 0x1da) = 0xc00;
  *(short *)(param_1 + 0x1dc) = 0xc00 - *(short *)(param_1 + 0x2b4);
  func_0x80040e58(param_1 + 0x1d8,*(undefined4 *)(param_1 + 0x70));
  return;
}
