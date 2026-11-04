/* FUN_80162c5c
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162c5c  body 0x80162c5c..0x80162d13  size 184 B
 * body sha256 9737acdabedbc708cee5e51b20aae25f5a7032a1da0355490b7cc8837fcd541a
 * provider record sha256 08f1ee47f248c4f5cf5e15e7e02834da4d4e46f9fd366958ddfc2cb46f6de8a5
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162c5c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  local_10 = 0;
  local_e = 0;
  local_c = 0;
  func_0x80037780(0x21000,(int)*(short *)(param_1 + 0x66),
                  *(int *)(param_1 + 0x234) +
                  (uint)(byte)(&DAT_80163020)[(*(ushort *)(param_1 + 0x1aa) & 1) * 7] * 0x178 + 0x38
                  ,&local_10);
  *(undefined2 *)(param_1 + 0x1f2) = 0xfa;
  *(undefined4 *)(param_1 + 4) = 0x1050000;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  uVar1 = func_0x80033604();
  uVar2 = 3;
  if ((uVar1 & 1) != 0) {
    uVar2 = 2;
  }
  func_0x80077d18(uVar2,param_1);
  return;
}
