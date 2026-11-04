/* FUN_80165da0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165da0  body 0x80165da0..0x80165df7  size 88 B
 * body sha256 1baaadfd1d7614f02d671c3dd7d1e95dc85cbe9a46c41fff1ffc637ce1c25593
 * provider record sha256 9529cd317ee11d0cf26018e5a616cf903189bc961214499e0e7d39786c015b09
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165da0(undefined4 param_1,int param_2)

{
  FUN_80165ea0();
  FUN_80165bd0(param_1,3,(int)*(short *)(param_2 + 2),0);
  FUN_80165bd0(param_1,4,(int)*(short *)(param_2 + 4),0);
  return;
}
