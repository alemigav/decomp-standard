/* FUN_80032f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032f64  body 0x80032f64..0x80032fab  size 72 B
 * body sha256 2a89d86cc60819216765a3b4073fb66e52ecb60fab088d5c8c7a504ffb46594a
 * provider record sha256 725b6139aae36d814e8cfaa3ffeefe448401dd5df50302db030e012f22d71f36
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80032f64(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3 + (param_2 - (uint)*(ushort *)(param_1 + 0x66)) & 0xfff;
  iVar2 = (int)(short)param_3;
  if ((int)uVar1 < iVar2 << 1) {
    return 0;
  }
  if (uVar1 < 0x801) {
    return iVar2;
  }
  return -iVar2;
}
