/* FUN_80166d64
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166d64  body 0x80166d64..0x80166db7  size 84 B
 * body sha256 27a00c22e6cb3c101ae5f50e430053612409896446c24da1b0e40221c2fa850b
 * provider record sha256 6e433302c3fdf2fecdd332a3289be0ef7857e5067dd58fc29c7eb150b4ee6e6a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80166d64(int param_1)

{
  short sVar1;
  short sVar2;
  
  sVar1 = *(short *)(param_1 + 0x66);
  *(ushort *)(param_1 + 0x66) = sVar1 + (ushort)*(byte *)(param_1 + 0x2cd) * 0x800;
  sVar2 = func_0x80032e74();
  *(short *)(param_1 + 0x66) = sVar1;
  return (int)sVar2;
}
