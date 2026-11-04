/* FUN_80071b3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071b3c  body 0x80071b3c..0x80071b93  size 88 B
 * body sha256 259e3cffda10965442d645e9320c396e0d09bd00a55c8f889782b427f9f61ee6
 * provider record sha256 d98751236fbbc1eea4f9ffaa97a5a8f874a2288113581ac41780dbc675dc2075
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071b3c(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
