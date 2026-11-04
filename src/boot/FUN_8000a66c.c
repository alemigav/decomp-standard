/* FUN_8000a66c
 * image   boot (boot), base 0x80000480
 * address 0x8000a66c  body 0x8000a66c..0x8000a6b7  size 76 B
 * body sha256 a7cc2ec71b561dd2a7f41b7cfd801112e4019f3e93128cbd916213c12d8d5738
 * provider record sha256 c552831ebb8d4a95ea95b637739e234e0b78978c27550cae29cb3c15051b543f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000a66c(int param_1)

{
  undefined1 *puVar1;
  undefined1 local_28 [32];
  
  puVar1 = local_28;
  do {
    *puVar1 = *(undefined1 *)(param_1 + 0x65);
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < (int)(local_28 + 0x20));
  FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0x400,local_28,0);
  return;
}
