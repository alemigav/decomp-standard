/* FUN_800800b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800800b0  body 0x800800b0..0x80080167  size 184 B
 * body sha256 aa61287ff7bdbcd8f495f975ef089875acb28d5c30dfc37f5046368e5da44122
 * provider record sha256 c3e70a08ab88306a8b6003f2eee430f75cfbdc62a8e1d7828dc9dc8318c4b8b1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800800b0(int param_1,undefined4 param_2,undefined4 param_3)

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
    goto LAB_80080138;
  case 2:
    *(undefined1 *)(param_1 + 6) = 4;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 5;
  case 5:
    uVar2 = 0x10200;
LAB_80080138:
    cVar1 = FUN_80089d54(param_1,param_2,param_3,uVar2);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    break;
  case 6:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  return;
}
