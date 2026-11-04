/* FUN_80053260
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053260  body 0x80053260..0x800532b3  size 84 B
 * body sha256 85b1e6345f316b0cc9b2666ef30b1ddfa2c4c08c23b9f66474c8c710cf9de7b9
 * provider record sha256 0bee1217a7ceb1b923c86c9dc31d7477a7d94a18dca4fe55314b24efbfe81f48
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053260(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)

{
  int iVar1;
  
  iVar1 = DAT_8010d940;
  *(undefined1 *)(DAT_8010d940 + 0x30e) = param_4;
  *(undefined1 *)(iVar1 + 0x30f) = param_1;
  *(undefined2 *)(iVar1 + 0x300) = 0x30;
  *(undefined2 *)(iVar1 + 0x304) = param_2;
  *(undefined2 *)(iVar1 + 0x306) = param_3;
  *(undefined2 *)(iVar1 + 0x302) = 0x8e;
  *(undefined1 *)(iVar1 + 799) = param_1;
  *(undefined1 *)(iVar1 + 2) = 1;
  *(undefined1 *)(iVar1 + 3) = 0;
  *(undefined1 *)(iVar1 + 0x2de) = 0;
  return;
}
