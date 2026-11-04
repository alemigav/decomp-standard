/* FUN_801635d0
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801635d0  body 0x801635d0..0x80163697  size 200 B
 * body sha256 cd0d71b0d3b5b8c523d2aeb7b8632011a75086a3db9ea6ff87230c06330f9aff
 * provider record sha256 6f6521292816afd0741c6278fe6162a32fd66363e838850b18627528062eae7d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_801635d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = param_3 * param_2 * param_2;
  param_1 = param_1 * param_1;
  if (param_1 == 0) {
    trap(0x1c00);
  }
  if ((param_1 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  iVar2 = param_3 * (param_2 + -1) * (param_2 + -1);
  if (param_1 == 0) {
    trap(0x1c00);
  }
  if ((param_1 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / param_1 - iVar2 / param_1;
}
