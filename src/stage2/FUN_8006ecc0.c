/* FUN_8006ecc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ecc0  body 0x8006ecc0..0x8006edaf  size 240 B
 * body sha256 c6ca7b5f03da97f383b1d867a10185cf61d32f4aeb4866df5b5fbec5a14e1831
 * provider record sha256 e57260f35b4af5e0f625fea162b4d6d70b7d587e1a0a2db0d2408c49c4d9cdff
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006ecc0(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x1c) + 1);
  cVar2 = *(char *)(*(int *)(param_1 + 0x1c) + 2);
  pcVar4 = (char *)(*(int *)(DAT_800df92c + 0x28) + 2);
  if (*(char *)(*(int *)(DAT_800df92c + 0x28) + 2) != -1) {
    cVar3 = *pcVar4;
    do {
      if (cVar3 == cVar1) {
        *pcVar4 = cVar2;
      }
      else if (cVar3 == cVar2) {
        *pcVar4 = cVar1;
      }
      if (pcVar4[1] == cVar1) {
        pcVar4[1] = cVar2;
      }
      else if (pcVar4[1] == cVar2) {
        pcVar4[1] = cVar1;
      }
      pcVar4 = pcVar4 + 0x14;
      cVar3 = *pcVar4;
    } while (cVar3 != -1);
  }
  if (((DAT_800e10ec & 0x2000000) == 0) && (*(char *)(DAT_800df944 + 2) == cVar1)) {
    FUN_80083c14(cVar2);
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 3;
  return 1;
}
