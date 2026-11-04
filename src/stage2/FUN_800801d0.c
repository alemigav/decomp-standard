/* FUN_800801d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800801d0  body 0x800801d0..0x800802ab  size 220 B
 * body sha256 f9d310a979dab004720562677e54ac9784a0d17eeacf66b95889fc8d60364f01
 * provider record sha256 4f473db2219c482220f04f825fe4a43295079a0581263d6c5f88fe63f17f232c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800801d0(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_8011b560;
  iVar2 = DAT_8011b54c;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined2 *)(param_1 + 500) = 0x32;
  }
  if (*(short *)(param_1 + 500) != 0) {
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
  }
  if (*(ushort *)(param_1 + 0x2ba) < 100) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
  }
  else if ((*(short *)(param_1 + 500) < 0x1e) && (1000 < *(ushort *)(param_1 + 0x2ba))) {
    *(undefined4 *)(param_1 + 4) = 0x10d0000;
  }
  else {
    if (*(short *)(param_1 + 500) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x10d0000;
    }
    if ((uVar1 < 0x5dc) && ((*(uint *)(param_1 + 0x1ac) & 1) == 0)) {
      uVar4 = 0x30;
      if (iVar2 == 0) {
        return;
      }
      iVar2 = *(int *)(iVar2 + 0x28);
      iVar3 = *(int *)(param_1 + 0x30);
    }
    else {
      iVar2 = (int)*(short *)(param_1 + 0x260);
      iVar3 = (int)*(short *)(param_1 + 0x262);
      uVar4 = 0xffffffd0;
    }
    FUN_80032dbc(param_1,iVar2,iVar3,uVar4);
  }
  return;
}
