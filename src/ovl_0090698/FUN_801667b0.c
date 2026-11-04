/* FUN_801667b0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801667b0  body 0x801667b0..0x801668b3  size 260 B
 * body sha256 4b9f08d6f73e44f6e49ed32d2b44b4b44fd4eafb9b1365f89c1b8c39cfccbfb8
 * provider record sha256 55b70e6c873ce017f0c14566d5e521b86163a49824039ae3f4efa1af9e685b0b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801667b0(uint *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1[0x82];
  switch(*(undefined1 *)((int)param_1 + 0x2c1)) {
  case 0:
    iVar2 = func_0x80074d64(param_1[10],param_1[0xc]);
    if (iVar2 == 0) {
      *param_1 = *param_1 & 0xfffffbff;
      return;
    }
  case 1:
    *param_1 = *param_1 | 0x400;
    break;
  case 2:
    iVar2 = func_0x80074d64(param_1[10],param_1[0xc]);
    if (iVar2 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x2c1) = 3;
    func_0x800341dc(uVar3,0xbf10bf00);
    *(undefined1 *)((int)param_1 + 0x207) = 0x5a;
    *param_1 = *param_1 & 0xfffffbff;
  case 3:
    *(short *)(uVar3 + 4) = *(short *)(uVar3 + 4) + 8;
    *(short *)(uVar3 + 6) = *(short *)(uVar3 + 6) + 8;
    cVar1 = *(char *)((int)param_1 + 0x207);
    *(char *)((int)param_1 + 0x207) = cVar1 + -1;
    if (cVar1 == '\x01') {
      *(undefined1 *)((int)param_1 + 0x2c1) = 4;
    }
  }
  return;
}
