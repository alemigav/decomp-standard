/* FUN_80083758
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083758  body 0x80083758..0x8008377f  size 40 B
 * body sha256 5a235af125ea5816247be08fd0e78d7cba831f166dd3b22f4e8e39bed190fa9f
 * provider record sha256 8298f7c83e1c08d44864158fe31037410efd3c8d7afd529df0975f8975848350
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083758(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
  *puVar1 = *puVar1 | 0x80000000U >> (param_2 & 0x1f);
  return;
}
