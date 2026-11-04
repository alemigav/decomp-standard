/* FUN_80164838
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164838  body 0x80164838..0x801648a7  size 112 B
 * body sha256 302d3fa87cff7ff7087b023f5d7434e8dd968cff3ec6bfb09a695eb946717a3b
 * provider record sha256 a2bde0c572fd4fdf581207fece2c8570c34e955f100ee751d12f05b39e6d2209
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164838(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x2c8) = 1;
  iVar1 = FUN_80163060();
  if (iVar1 < 0) {
    *(undefined2 *)(param_1 + 6) = 0x200;
    *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
