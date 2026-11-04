/* FUN_8004d79c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d79c  body 0x8004d79c..0x8004d917  size 380 B
 * body sha256 7e535530f71d8f56c7f25bf73f26a2eff210aaf3fafd20e56c9a2848ada61cf9
 * provider record sha256 a8bbdd495d22e9041d8eed29183356b8870ac527a5937fdaac28066e09186c45
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8004d79c(short *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  
  piVar6 = &DAT_800e13e8;
  if (DAT_800df93c != &DAT_800e13e8) {
    do {
      puVar1 = (uint *)*piVar6;
      if (((*puVar1 & 1) != 0) && (puVar5 = puVar1 + 0x48, (*puVar1 & 2) == 0)) {
        _DAT_80139ba0 = puVar1[0xa1];
        while (_DAT_80139ba0 = _DAT_80139ba0 - 1, -1 < (int)_DAT_80139ba0) {
          iVar4 = param_2 + (uint)*(ushort *)((int)puVar5 + 0x16);
          iVar3 = *puVar5 - (int)*param_1;
          if ((uint)(iVar4 * 2) < (uint)(iVar3 + iVar4)) {
            puVar5 = puVar5 + 8;
          }
          else {
            iVar2 = puVar5[2] - (int)param_1[2];
            if ((uint)(iVar4 * 2) < (uint)(iVar2 + iVar4)) {
              puVar5 = puVar5 + 8;
            }
            else {
              iVar3 = FUN_80040bb4(iVar3 * iVar3 + iVar2 * iVar2);
              if (iVar4 - iVar3 < 1) {
                puVar5 = puVar5 + 8;
              }
              else {
                iVar3 = (uint)*(ushort *)((int)puVar5 + 0x1a) + param_3;
                if ((-iVar3 < (int)(puVar5[1] - (int)param_1[1])) &&
                   ((int)(puVar5[1] - (int)param_1[1]) < iVar3)) {
                  return 1;
                }
                puVar5 = puVar5 + 8;
              }
            }
          }
        }
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != DAT_800df93c);
  }
  return 0;
}
