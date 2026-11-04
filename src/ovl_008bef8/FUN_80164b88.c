/* FUN_80164b88
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80164b88  body 0x80164b88..0x80164d07  size 384 B
 * body sha256 b6f347b057fc9cb05774d6790947760dbaf4f4916499059cf9d3398a8706a3cc
 * provider record sha256 aebbcaba3db9301aa656859d4b8f166157482fbcb82a76fab7f55863acd599a8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164b88(int param_1)

{
  char cVar3;
  int iVar1;
  int iVar2;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80077adc(0x4020001,param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1e8) = 0x14000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 800;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
  case 1:
    func_0x80032b5c(param_1,0);
    cVar3 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),
                            *(undefined4 *)(param_1 + 0x230),0x400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -0x78;
    if (*(short *)(param_1 + 0x1e0) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 2:
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x11000300;
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined1 *)(param_1 + 0x26f) = 0;
  case 5:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),
                            *(undefined4 *)(param_1 + 0x230),0x400);
    iVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),
                            *(undefined4 *)(param_1 + 0x230),0x400);
    if (iVar2 + iVar1 != 0) {
      *(undefined1 *)(param_1 + 6) = 6;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000300;
    }
    break;
  case 6:
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                            *(undefined4 *)(param_1 + 0x218),0x10400);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(undefined1 *)(param_1 + 0x26f) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
    }
  }
  return;
}
