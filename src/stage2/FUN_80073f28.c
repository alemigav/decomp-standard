/* FUN_80073f28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073f28  body 0x80073f28..0x80073f63  size 60 B
 * body sha256 633076197426f69472eb31b35a3234e1f17c56c77e0d002636e7234d9eff9f5b
 * provider record sha256 9caa41280d8cc2b66083c22ea4e61fe971798ba25857be8065e09193183197c3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073f28(undefined2 *param_1)

{
  FUN_8004ac04(0,param_1[1] + 0x300,*param_1,(uint)(ushort)param_1[2] << 0x10);
  return 0;
}
