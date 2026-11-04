/* FUN_800099d0
 * image   boot (boot), base 0x80000480
 * address 0x800099d0  body 0x800099d0..0x80009b9b  size 460 B
 * body sha256 8522a29a21d22b29b7b65fd7064cd798e69433e26975b2402b341e9f93af322e
 * provider record sha256 c1c008f8da5ddb66c98fc3fae38bc8afd05d26825dcba9cb4cfde10314db221f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800099d0(int param_1,int param_2,int param_3,int *param_4,char param_5,int *param_6,
                int *param_7)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_50 [31];
  undefined1 local_31 [5];
  int *local_2c;
  
  iVar1 = 1;
  if (param_5 == '\0') {
    iVar1 = *(int *)(param_1 + 0x60);
  }
  if (iVar1 < 0x80) {
    psVar4 = (short *)(iVar1 * 2 + param_2);
    do {
      if (*psVar4 == 3) break;
      iVar1 = iVar1 + 1;
      psVar4 = psVar4 + 1;
    } while (iVar1 < 0x80);
  }
  iVar5 = 0x1f;
  if (iVar1 == 0x80) {
    *param_4 = -1;
  }
  else {
    puVar2 = local_31;
    do {
      *puVar2 = 0;
      iVar5 = iVar5 + -1;
      puVar2 = puVar2 + -1;
    } while (-1 < iVar5);
    *param_6 = 1;
    iVar6 = iVar1 + 1;
    iVar5 = iVar1;
    local_2c = param_4;
    if (1 < param_3 && iVar6 < 0x80) {
      psVar4 = (short *)(iVar6 * 2 + param_2);
      do {
        if (*psVar4 == 3) {
          pcVar3 = (char *)(param_2 + iVar5 * 2);
          *pcVar3 = param_5;
          pcVar3[1] = (char)iVar6;
          iVar5 = FUN_80009b9c(param_1,iVar5,auStack_50,param_5);
          if (iVar5 != 0) {
            return iVar5;
          }
          *param_6 = *param_6 + 1;
          iVar5 = iVar6;
        }
        iVar6 = iVar6 + 1;
        psVar4 = psVar4 + 1;
      } while (*param_6 < param_3 && iVar6 < 0x80);
    }
    *local_2c = iVar1;
    if ((iVar6 != 0x80) || (param_3 <= *param_6)) {
      *(undefined2 *)(param_2 + iVar5 * 2) = 1;
      iVar1 = FUN_80009b9c(param_1,iVar5,auStack_50,param_5);
      *param_7 = 0;
      return iVar1;
    }
    *param_7 = iVar5;
  }
  return 0;
}
