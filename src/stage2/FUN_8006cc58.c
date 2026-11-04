/* FUN_8006cc58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cc58  body 0x8006cc58..0x8006cccb  size 116 B
 * body sha256 488d806d17b61e0b42383de9dc675ee7d0f56ae17600265ca87bcc21cef7eae1
 * provider record sha256 d823d9ca44555c3393faeaf93aa8dcbd8e35acf8f266993d4fb95eab2a7ac459
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006cc58(int param_1,int param_2)

{
  *(int *)(param_1 + 0x1c) =
       ((int)((*(uint *)(param_1 + 0x1c) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x1c) & 0xffff) + param_2) % 0xffff;
  return;
}
