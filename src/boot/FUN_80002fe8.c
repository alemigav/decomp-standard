/* FUN_80002fe8
 * image   boot (boot), base 0x80000480
 * address 0x80002fe8  body 0x80002fe8..0x8000305b  size 116 B
 * body sha256 de7e2f716e31bb315fe2df319bb4161471540838d784a4b8422a0f250ad8b825
 * provider record sha256 f8694cfcf812302b726674511bd3509d39b16077e73b9a2ab88c45ada45c12b7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80002fe8(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      return 0xfffffffe;
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x14);
      if (iVar1 != 0) {
        FUN_800022bc(iVar1,param_1,auStack_10);
      }
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c))
      ;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      return 0;
    }
  }
  return 0xfffffffe;
}
