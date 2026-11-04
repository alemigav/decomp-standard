/* FUN_80162d3c
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162d3c  body 0x80162d3c..0x80162dcf  size 148 B
 * body sha256 b3cf4347b009a985ce12c75aef63f2d6ba08185e5619bec2919907138c1ed7dd
 * provider record sha256 f1b0717f7cd8a6469a0e59183bac4efa99818ea723dfe44222ec3535b5491936
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162d3c(int param_1)

{
  char cVar1;
  
  _DAT_800e1134 = 0x5010000;
  cVar1 = func_0x80033144(param_1,&DAT_800e1130);
  if (cVar1 == '\0') {
    func_0x80032ef4(&DAT_800e1130,(int)((*(ushort *)(param_1 + 0x66) - 0x800) * 0x10000) >> 0x10,
                    0x200);
  }
  else {
    func_0x80032ef4(&DAT_800e1130,(int)*(short *)(param_1 + 0x66),0x200);
    cVar1 = DAT_800e1135 + '\x01';
    _DAT_800e1135 = CONCAT12(cVar1,DAT_800e1134_1._1_2_);
  }
  _DAT_800e1380 = param_1;
  _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
  _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
  return;
}
