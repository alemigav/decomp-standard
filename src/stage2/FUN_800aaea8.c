/* FUN_800aaea8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aaea8  body 0x800aaea8..0x800aaf6f  size 200 B
 * body sha256 0ec9759e4ce228fcc3c308a36323c3da71541b73809ba7b5c45db9aa43ff41bf
 * provider record sha256 f9d58e2e0620b9509e7124ad10368edca78d391fa53c547f4b4c719f0060f975
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800aaea8(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)_DAT_80148bd4;
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    if (DAT_80136310 != '\0') {
      FUN_800a5678();
      if (*piVar1 != 0) {
        *(int *)(*piVar1 + 4) = piVar1[1];
      }
      if ((undefined4 *)piVar1[1] == (undefined4 *)0x0) {
        _DAT_80148bd4 = *piVar1;
      }
      else {
        *(undefined4 *)piVar1[1] = *piVar1;
      }
      piVar1[2] = (uint)*(ushort *)((int)piVar1 + 10);
      if (piVar1[0xd] != -1) {
        FUN_800a8248();
      }
      FUN_800a56c0();
    }
  }
  return;
}
