/* FUN_80166100
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80166100  body 0x80166100..0x8016618b  size 140 B
 * body sha256 988c1b9ac074c5b974d03609054e1477fdbf564951accd7ff8227a8a002fb447
 * provider record sha256 d079c99f86ce6769cfb2a6de5703819095a49f0ed1970343837f511d0bc42ffd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166100(int param_1)

{
  char cVar2;
  uint uVar1;
  short local_10;
  short local_e;
  short local_c;
  
  cVar2 = func_0x80033604();
  local_10 = *(short *)(param_1 + 0x2a) + (short)cVar2;
  cVar2 = func_0x80033604();
  local_e = *(short *)(param_1 + 0x2e) + (short)cVar2;
  cVar2 = func_0x80033604();
  local_c = *(short *)(param_1 + 0x32) + (short)cVar2;
  uVar1 = func_0x80033604();
  func_0x80037780(0x12800,(uVar1 & 0xff) << 4,0x800e9028,&local_10);
  return;
}
