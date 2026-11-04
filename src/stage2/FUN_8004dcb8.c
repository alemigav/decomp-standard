/* FUN_8004dcb8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004dcb8  body 0x8004dcb8..0x8004dd4f  size 152 B
 * body sha256 af3d7af56d41bda8db34ae15e60ec1a52f84cf3c02ef4bd98b7d8b95ce555861
 * provider record sha256 69fcf73d5dad096a90e86ebb1e469a7824ddfcb32e50d826b44291742713a6dd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004dcb8(uint *param_1,uint param_2)

{
  uint uVar1;
  
  param_1[0x6b] = 0;
  if (((*param_1 & 8) == 0) && (param_1[0xa0] == 0)) {
    *param_1 = *param_1 & 0xffffbfff;
    uVar1 = FUN_800667d4(param_1 + 0x48,*(undefined2 *)(param_1 + 0x4b),
                         1 << (*(byte *)((int)param_1 + 0x1a2) & 0x1f),param_2 | 0x1000000);
    param_1[0x6b] = uVar1;
    param_1[0x6c] = DAT_800e1068;
  }
  *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x122);
  *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x12a);
  return;
}
