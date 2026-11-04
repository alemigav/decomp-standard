/* FUN_80009b9c
 * image   boot (boot), base 0x80000480
 * address 0x80009b9c  body 0x80009b9c..0x80009c2f  size 148 B
 * body sha256 bad172b70395a3db8ee42fa34322fbc64035ac41b06b9e4354c448d450cb9dab
 * provider record sha256 5b386359a8d86a4eb49aaa5113a28660b040b212726a9dfa7a088b96ee1ac74e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80009b9c(int param_1,int param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x65) = param_4;
  iVar1 = FUN_8000a66c();
  iVar2 = 0;
  if (iVar1 == 0) {
    do {
      iVar1 = FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           param_2 * 8 + iVar2 & 0xffff,param_3,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + 0x65) = 0;
        goto LAB_80009c0c;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    *(undefined1 *)(param_1 + 0x65) = 0;
LAB_80009c0c:
    FUN_8000a66c(param_1);
  }
  return;
}
