/* FUN_800b4930
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4930  body 0x800b4930..0x800b4a03  size 212 B
 * body sha256 fd81a4449dfba11eec72638a6653ddfd8a5c3a2d96760d15b3d95540a1ace38f
 * provider record sha256 e0f1f38a76c1f73a3dad18e845dbf940d2f05130ad9b4f837a6b6aef70b8ae5a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b4930(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  func_0x80006650(param_1,400);
  *(undefined2 *)(param_1 + 0x166) = 0x28;
  *(int *)(param_1 + 0x194) = param_2;
  *(undefined4 *)(param_1 + 0x198) = param_3;
  *(undefined4 *)(param_1 + 0x19c) = param_4;
  *(undefined4 *)(param_1 + 0x11a8) = 0;
  *(int *)(param_1 + 400) = param_5;
  osCreateMesgQueue(param_1 + 0x11ac,param_1 + 0x11c4,1);
  if (param_2 == 0 || param_5 == 0) {
    *(undefined1 *)(param_1 + 0x11dd) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x11dd) = 1;
  }
  *(undefined1 *)(param_1 + 0x11dc) = 0;
  *(undefined2 *)(param_1 + 0x11a2) = 0;
  *(undefined4 *)(param_1 + 0x11a4) = 0;
  *(undefined2 *)(param_1 + 0x11a0) = 0;
  *(undefined4 *)(param_1 + 0x11c8) = 0;
  *(undefined4 *)(param_1 + 0x11d0) = 0;
  *(undefined4 *)(param_1 + 0x11cc) = 0;
  *(undefined4 *)(param_1 + 0x11d8) = 0;
  *(undefined4 *)(param_1 + 0x11d4) = 0;
  *(undefined1 *)(param_1 + 0x11de) = 2;
  return;
}
