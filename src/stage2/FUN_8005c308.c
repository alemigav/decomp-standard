/* FUN_8005c308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c308  body 0x8005c308..0x8005c32b  size 36 B
 * body sha256 cf74f5897d95f1ad4ce6556404d28d1dc591856c1f268f7de13c89b592ff7798
 * provider record sha256 1452d9147f6676ac6277211352056bcbd955a8ab6ffab602153906dc1b9c1d23
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c308(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x1780;
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0x234) + 0x1d60;
  }
  *(undefined1 *)(iVar1 + 0x112) = 1;
  return;
}
