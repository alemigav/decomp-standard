/* FUN_80031b80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031b80  body 0x80031b80..0x80031c13  size 148 B
 * body sha256 5a3a10bba596cc6a884deb019c2344eccc64213bf2baa2a874f0289e4390da4f
 * provider record sha256 f3ed74dce72247c862c36c4d34ed0b69a768454ffdd163b7d13b0ab82987835b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80031b80(int param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = 0;
  iVar6 = 0;
  iVar8 = *(int *)(*(int *)(param_1 + 0x4c) + 4);
  piVar5 = *(int **)(*(int *)(param_1 + 0x4c) + 8);
  while (iVar8 = iVar8 + -1, iVar8 != -1) {
    if (piVar5[2] == 0) {
      piVar5 = piVar5 + 4;
    }
    else {
      iVar4 = *piVar5 + -1;
      if (iVar4 != -1) {
        psVar2 = (short *)(piVar5[2] + 0xe);
        do {
          sVar1 = *psVar2;
          psVar2[-1] = (short)iVar6;
          psVar2 = psVar2 + 8;
          iVar4 = iVar4 + -1;
          iVar7 = iVar7 + sVar1;
          iVar6 = iVar6 + sVar1;
        } while (iVar4 != -1);
      }
      piVar5 = piVar5 + 4;
    }
  }
  if (iVar7 < 1) {
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  else {
    uVar3 = param_2 + 7U & 0xfffffff8;
    *(uint *)(param_1 + 0x48) = uVar3;
    param_2 = uVar3 + iVar7 * 0x10;
  }
  return param_2;
}
