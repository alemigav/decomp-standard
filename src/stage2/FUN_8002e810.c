/* FUN_8002e810
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e810  body 0x8002e810..0x8002e847  size 56 B
 * body sha256 e94b88e4921cb38cc7d0682b188fda202c0d21c1f3efe6aaabfa0508728118f1
 * provider record sha256 e14725b6054d0ea0501cea9cfd74f401580ce0631efde83a6e107f55b0dfb29c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e810(int *param_1)

{
  (**(code **)(*param_1 + 8))();
  FUN_800283b0(param_1);
  return;
}
