/* FUN_8006cccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cccc  body 0x8006cccc..0x8006cda7  size 220 B
 * body sha256 d0f5dc5e2090f22743b1542db8296738fb208faa69c0c0a308ef087c56893c38
 * provider record sha256 200dc755831f9d4e95390a606f72bf760db6da0d6c2599a93a14e03b6d0ac67a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006cccc(int param_1,int param_2)

{
  *(int *)(param_1 + 0x30) =
       ((int)((*(uint *)(param_1 + 0x30) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x30) & 0xffff) + param_2) % 0xffff;
  *(int *)(param_1 + 0x44) =
       ((int)((*(uint *)(param_1 + 0x44) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x44) & 0xffff) + param_2) % 0xffff;
  return;
}
