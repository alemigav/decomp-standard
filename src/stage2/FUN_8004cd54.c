/* FUN_8004cd54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd54  body 0x8004cd54..0x8004cd87  size 52 B
 * body sha256 f647ecff2ad345894ca512cb4508eac2997914667527da13402e48282f456e91
 * provider record sha256 78725cffc9291e682cec23e9dbb5c734f0d3e19a0f32264cd759a28553af1eb8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cd54(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_8010b4e0 + param_1 * 0x1c8) = param_2;
  (&DAT_8010b328)[param_1 * 0xe4] = 2;
  return;
}
