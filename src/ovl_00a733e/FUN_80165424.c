/* FUN_80165424
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165424  body 0x80165424..0x801654af  size 140 B
 * body sha256 add4f2f18aab6520d2777da37b52f5b0288ea06f5a687ad16b84b574a3616f13
 * provider record sha256 9b045d4d1de536c7a15d263287565ea06c8b6557d8e787a4db5bcd02447d308d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165424(int param_1)

{
  uint uVar1;
  
  uVar1 = func_0x80033604();
  FUN_80167374(param_1,(&DAT_80167db0)[((uint)*(byte *)(param_1 + 0x26e) % 3) * 4 + (uVar1 & 3)],
               (&DAT_80167d97)[*(byte *)(param_1 + 5)]);
  return;
}
