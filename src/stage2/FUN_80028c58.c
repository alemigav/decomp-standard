/* FUN_80028c58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028c58  body 0x80028c58..0x80028d8b  size 308 B
 * body sha256 c789cf4a0b1321d24496b917b7ab12815b47911aa65e327bf72e0836aadcc180
 * provider record sha256 d9cdb2834a020f1aa53480b2a03adbc1ac90bb1d23df7c7e17a695ff08b0e1cd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80028c58(int *param_1)

{
  int iVar1;
  
  if (param_1[4] - 0xcbU < 2) {
    if ((uint)param_1[0x1e] < (uint)param_1[0x18]) {
      *(undefined4 *)(*param_1 + 0x14) = 0x3b;
      (**(code **)*param_1)();
    }
    (**(code **)(param_1[0x59] + 4))(param_1);
    param_1[4] = 0xcd;
  }
  else if (param_1[4] != 0xcd) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)(param_1);
  }
  if (*(int *)(param_1[0x59] + 0xc) == 0) {
    iVar1 = (**(code **)(param_1[0x5d] + 4))(param_1);
    if (iVar1 != 1) {
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          *(undefined4 *)(*param_1 + 0x14) = 0x1d;
          (**(code **)*param_1)(param_1);
        }
      }
      else if (iVar1 == 2) {
        return 0;
      }
    }
  }
  (**(code **)(param_1[5] + 0x18))(param_1);
  FUN_80028350(param_1);
  return 1;
}
