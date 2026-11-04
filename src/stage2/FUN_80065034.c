/* FUN_80065034
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80065034  body 0x80065034..0x8006521f  size 492 B
 * body sha256 020642734c3efb302974051f4d0ce412b43e6d7e8ba95204c18059bade94afb9
 * provider record sha256 a36ac87cbd05965d6e17b5955ec660e0f39913df6e93aacbd359daeaffc96ef2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80065034(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  piVar1 = *(int **)(DAT_800df92c + 0x60);
  uVar6 = 0;
  if (piVar1 != (int *)0x0) {
    iVar7 = 0;
    iVar5 = 0;
    uVar9 = piVar1[1];
    uVar8 = uVar9 - 1;
    iVar4 = *(int *)((int)piVar1 + *piVar1);
    for (; uVar6 < uVar9; uVar6 = uVar6 + 1) {
      iVar2 = **(int **)(DAT_800df92c + 0x60);
      piVar1 = (int *)((int)*(int **)(DAT_800df92c + 0x60) + iVar2 + iVar5);
      iVar3 = *piVar1;
      if (-1 < DAT_800e10e8) {
        if (iVar4 != iVar3) {
          iVar2 = iVar2 - iVar3;
          if (uVar6 != uVar8) {
            iVar2 = piVar1[3] - iVar3;
          }
          FUN_80082474(*(int *)(DAT_800df92c + 0x60) + iVar4,*(int *)(DAT_800df92c + 0x60) + iVar3,
                       iVar2);
          piVar1 = *(int **)(DAT_800df92c + 0x60);
          *(int *)((int)piVar1 + *piVar1 + iVar7 * 8) =
               *(int *)((int)piVar1 + *piVar1 + iVar5) - (iVar3 - iVar4);
          piVar1 = *(int **)(DAT_800df92c + 0x60);
          *(int *)((int)piVar1 + *piVar1 + iVar7 * 8 + 4) =
               *(int *)((int)piVar1 + *piVar1 + iVar5 + 4) - (iVar3 - iVar4);
        }
        if (uVar6 == uVar8) {
          iVar3 = **(int **)(DAT_800df92c + 0x60) - iVar3;
        }
        else {
          iVar3 = *(int *)((int)*(int **)(DAT_800df92c + 0x60) +
                          **(int **)(DAT_800df92c + 0x60) + iVar5 + 8) - iVar3;
        }
        iVar4 = iVar4 + iVar3;
        iVar7 = iVar7 + 1;
      }
      iVar5 = iVar5 + 8;
      DAT_800e10e8 = DAT_800e10e8 << 1;
    }
    piVar1 = *(int **)(DAT_800df92c + 0x60);
    FUN_80082474((int)piVar1 + iVar4,(int)piVar1 + *piVar1,iVar7 << 3);
    **(int **)(DAT_800df92c + 0x60) = iVar4;
    *(int *)(*(int *)(DAT_800df92c + 0x60) + 4) = iVar7;
    FUN_8007659c();
  }
  return;
}
