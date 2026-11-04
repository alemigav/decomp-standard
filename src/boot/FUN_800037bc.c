/* FUN_800037bc
 * image   boot (boot), base 0x80000480
 * address 0x800037bc  body 0x800037bc..0x800038ef  size 308 B
 * body sha256 35e1ccf99b4d1afcb650327e70bb802b72a6e36b80e9a066a4cd714725d288b8
 * provider record sha256 9bb6d5a01b4af20f229e420c3fed164cc7b9aa5baeb297f4b50f54987905110a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800037bc(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_1 == (int *)0x0) || (piVar2 = (int *)param_1[7], piVar2 == (int *)0x0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    if (*piVar2 != 0xd) {
      *piVar2 = 0xd;
      *(undefined4 *)(param_1[7] + 4) = 0;
    }
    iVar6 = param_1[1];
    if (iVar6 == 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      pcVar4 = (char *)*param_1;
      uVar5 = *(uint *)(param_1[7] + 4);
      do {
        if (3 < uVar5) break;
        if (uVar5 < 2) {
          if (*pcVar4 != '\0') goto LAB_80003860;
          uVar5 = uVar5 + 1;
        }
        else if (*pcVar4 == -1) {
          uVar5 = uVar5 + 1;
        }
        else {
LAB_80003860:
          uVar5 = 4 - uVar5;
          if (*pcVar4 != '\0') {
            uVar5 = 0;
          }
        }
        iVar6 = iVar6 + -1;
        pcVar4 = pcVar4 + 1;
      } while (iVar6 != 0);
      iVar3 = *param_1;
      *param_1 = (int)pcVar4;
      param_1[1] = iVar6;
      param_1[2] = (int)(pcVar4 + (param_1[2] - iVar3));
      *(uint *)(param_1[7] + 4) = uVar5;
      if (uVar5 == 4) {
        iVar6 = param_1[2];
        iVar3 = param_1[5];
        FUN_80002f80(param_1);
        uVar1 = 0;
        param_1[2] = iVar6;
        param_1[5] = iVar3;
        *(undefined4 *)param_1[7] = 7;
      }
      else {
        uVar1 = 0xfffffffd;
      }
    }
  }
  return uVar1;
}
