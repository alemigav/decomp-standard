/* FUN_8007a7e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a7e4  body 0x8007a7e4..0x8007a8df  size 252 B
 * body sha256 729eb28f7297060e58e67a65a51c6f89014ece1225261f26616853d18197ca82
 * provider record sha256 f9cffb03894d8dc7858d08ae65dffb0f691f3b57bfa4a59f3f2e761db50e3b0f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a7e4(int param_1)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 7;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    iVar4 = 0xc;
    do {
      iVar3 = *(int *)(param_1 + 0x234) + (uint)(byte)(&UNK_8011a860)[iVar4] * 0x178;
      sVar2 = *(short *)(iVar3 + 0x11c);
      if (sVar2 == 0) {
        uVar1 = *(int *)(iVar3 + 0x60) + 0x10101;
        *(uint *)(iVar3 + 0x60) = uVar1;
        if ((uVar1 & 0xffffff) == 0x404040) {
          *(undefined2 *)(iVar3 + 0x11c) = 1;
        }
        sVar2 = *(short *)(iVar3 + 0x11c);
      }
      iVar5 = iVar5 + -1;
      if ((sVar2 == 1) &&
         (uVar1 = *(int *)(iVar3 + 0x60) - 0x10101, *(uint *)(iVar3 + 0x60) = uVar1,
         (uVar1 & 0xffffff) == 0)) {
        *(undefined2 *)(iVar3 + 0x11c) = 2;
        *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfdff;
        *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) & 0xfffffffd;
      }
      iVar4 = iVar4 + -2;
    } while (iVar5 != 0);
    DAT_80124838 = DAT_80124838 + -2;
    if (DAT_80124838 < 0) {
      DAT_80124838 = 0;
    }
  }
  return;
}
