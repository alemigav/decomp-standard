/* FUN_8002dd34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002dd34  body 0x8002dd34..0x8002ddb3  size 128 B
 * body sha256 6b8ea6c778408e4914bf4f94620b9f52f2edb7c5f2583c7c1108e1ee2d6b92a7
 * provider record sha256 8a98162a92cfee6af5937539d588fcf77ee405ddb926b0d5b2575fa96f5f436b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002dd34(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x59];
  if ((*(int *)(iVar1 + 0x14) == 0) || (*(int *)(iVar1 + 0x14) == 2)) {
    if (param_1[0x11] != 0) {
      (**(code **)(param_1[0x62] + 8))();
    }
    *(undefined4 *)(iVar1 + 0x14) = 3;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)();
  }
  return;
}
