/* FUN_8007e208
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e208  body 0x8007e208..0x8007e2bf  size 184 B
 * body sha256 25bea0947fe5f42d51f81750126a7cd14abd15d9f4baebcb0c8207c8db400a4f
 * provider record sha256 b809e16d9a4336958e3ac3b94ebd9c3e00a540550f42c9fe01ef8aeb024ad0e0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e208(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
  case 1:
    uVar2 = 0x200;
    goto LAB_8007e290;
  case 2:
    *(undefined1 *)(param_1 + 6) = 4;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 5;
  case 5:
    uVar2 = 0x10200;
LAB_8007e290:
    cVar1 = FUN_80089d54(param_1,param_2,param_3,uVar2);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    break;
  case 6:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  return;
}
