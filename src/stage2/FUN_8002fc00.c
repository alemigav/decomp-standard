/* FUN_8002fc00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fc00  body 0x8002fc00..0x8002fc23  size 36 B
 * body sha256 3d8bb3d00346f4d692b04471389c53a4b4c98a9c4a9eb09ba2e5e6d81bad30b1
 * provider record sha256 1b7f16f52327313662d1ff3d9627294370496195fe5122c0c3b59ebed81c47e0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002fc00(int param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(param_1 + iVar2);
      iVar2 = iVar2 + -1;
      *puVar1 = param_2;
    } while (iVar2 != -1);
  }
  return;
}
