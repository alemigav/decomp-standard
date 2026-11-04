/* FUN_80028510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028510  body 0x80028510..0x8002857b  size 108 B
 * body sha256 f800e1cd329c45f7bf36352b94e3a4f2e0e2550356c1fa5c4ad61600e1101b31
 * provider record sha256 6f5e188f36e4f298839559a9c4a3a9fd782843362071ac844da24c1d20984499
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028510(int *param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0xfe) {
    *(undefined4 *)(param_1[0x5d] + 0xc) = param_3;
  }
  else if (param_2 - 0xe0U < 0x10) {
    *(undefined4 *)(param_1[0x5d] + (param_2 - 0xe0U) * 4 + 0x10) = param_3;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x3c;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)();
  }
  return;
}
