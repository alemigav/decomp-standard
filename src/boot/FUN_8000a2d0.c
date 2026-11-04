/* FUN_8000a2d0
 * image   boot (boot), base 0x80000480
 * address 0x8000a2d0  body 0x8000a2d0..0x8000a393  size 196 B
 * body sha256 26d977c5dc0d412608db8f780cf03e0d023a40d3c012ae080347dbf981179d41
 * provider record sha256 7cb449205e807af995af973a30aabc1b2cf6cb02f7dac9e22d392fd43ad5db90
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000a2d0(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char local_28 [32];
  
  if (*(char *)(param_1 + 0x65) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 0;
    iVar1 = FUN_8000a66c();
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1,local_28);
  if ((iVar1 == 0) ||
     ((iVar1 == 2 &&
      (iVar1 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1,local_28),
      iVar1 == 0)))) {
    iVar1 = 0;
    pcVar3 = local_28;
    do {
      iVar2 = param_1 + iVar1;
      iVar1 = iVar1 + 1;
      if (*(char *)(iVar2 + 0xc) != *pcVar3) {
        return 2;
      }
      pcVar3 = pcVar3 + 1;
    } while (iVar1 < 0x20);
    iVar1 = 0;
  }
  return iVar1;
}
