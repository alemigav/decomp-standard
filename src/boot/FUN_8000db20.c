/* FUN_8000db20
 * image   boot (boot), base 0x80000480
 * address 0x8000db20  body 0x8000db20..0x8000db6b  size 76 B
 * body sha256 a82714ec5ced79eee9476d90612902319959bb46b2474a6bae59fc253c7763d8
 * provider record sha256 4d35b26881b3522d4da2eb4badf040a88ebf274edfe5da408a2d09d6eafdde81
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8000db20(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_8000db70();
  uVar2 = uVar1 >> 8 & 1;
  if ((uVar1 & 0x80) != 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd | uVar2;
  }
  return uVar2;
}
