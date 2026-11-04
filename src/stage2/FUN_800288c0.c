/* FUN_800288c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800288c0  body 0x800288c0..0x80028a1f  size 352 B
 * body sha256 9f7fdbfe821dad35b67e83db0f1b100b861e1a0ea4aa9520a530df0bd4afadd4
 * provider record sha256 90406e1617f732bd343c7ae4658b0cbe57fe5c9bd8c85db397937a59eccf77f2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800288c0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint local_18 [2];
  
  if (param_1[4] != 0xca) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)();
  }
  FUN_8002ddb4(param_1);
  while( true ) {
    (**(code **)param_1[0x59])(param_1);
    if (*(int *)(param_1[0x59] + 8) != 0) break;
    local_18[0] = 0;
    if (*(int *)(param_1[0x5a] + 8) != 0) {
      do {
        if (param_1[2] != 0) {
          *(uint *)(param_1[2] + 4) = local_18[0];
          *(undefined4 *)(param_1[2] + 8) = *(undefined4 *)(param_1[0x5a] + 8);
          (**(code **)param_1[2])(param_1);
        }
        uVar1 = local_18[0];
        (**(code **)(param_1[0x5a] + 4))(param_1,0,local_18,0);
        if (local_18[0] == uVar1) {
          *(undefined4 *)(*param_1 + 0x14) = 0x11;
          (**(code **)*param_1)(param_1);
        }
      } while (local_18[0] < *(uint *)(param_1[0x5a] + 8));
    }
    (**(code **)(param_1[0x59] + 4))(param_1);
  }
  iVar2 = 0xcb;
  param_1[0x1e] = 0;
  if (param_1[0x10] != 0) {
    iVar2 = 0xcc;
  }
  param_1[4] = iVar2;
  return;
}
