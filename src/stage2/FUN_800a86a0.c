/* FUN_800a86a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a86a0  body 0x800a86a0..0x800a8a03  size 868 B
 * body sha256 f2391116e0328c9ec62c1021a914b856dd9c41a5d696ca41694b0d5db31676cd
 * provider record sha256 ea0fd4c17fdc49ef980a7b1709d57a1e739d53b37a6778bc8ae7938f48511147
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800a86a0(int *param_1,short param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  short sVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  
  if ((DAT_80136310 != '\0') && (_DAT_80147fd0 < 0x80)) {
    iVar4 = *param_1;
    while (iVar4 != -1) {
      if (*(short *)(param_1 + 1) == param_2) {
        *(int **)(&DAT_80147fe0 + _DAT_80147fd0 * 4) = param_1;
        psVar6 = (short *)((int)param_1 + param_1[2] + 8);
        sVar1 = *psVar6;
        while (sVar1 != -1) {
          piVar5 = (int *)((int)param_5 + *param_5);
          iVar4 = *piVar5;
          while (iVar4 != -1) {
            if (*(short *)(piVar5 + 1) == sVar1) goto LAB_800a8794;
            piVar5 = (int *)((int)piVar5 + *piVar5);
            iVar4 = *piVar5;
          }
          piVar5 = (int *)0x0;
LAB_800a8794:
          if (piVar5 != (int *)0x0) {
            FUN_800ad62c(*psVar6,piVar5 + 2);
          }
          psVar6 = psVar6 + 1;
          sVar1 = *psVar6;
        }
        psVar6 = (short *)((int)param_1 + param_1[3] + 8);
        uVar2 = FUN_800a5c98(param_3);
        cVar3 = FUN_800ad330(param_4,uVar2);
        if (cVar3 != '\0') {
          sVar1 = *psVar6;
          while (sVar1 != -1) {
            sVar1 = *psVar6;
            psVar6 = psVar6 + 1;
            FUN_800add28(sVar1,param_4);
            sVar1 = *psVar6;
          }
        }
        psVar6 = (short *)((int)param_1 + param_1[4] + 8);
        sVar1 = *psVar6;
        while (sVar1 != -1) {
          piVar5 = (int *)((int)param_5 + param_5[1]);
          iVar4 = *piVar5;
          while (iVar4 != -1) {
            if (*(short *)(piVar5 + 1) == sVar1) goto LAB_800a8868;
            piVar5 = (int *)((int)piVar5 + *piVar5);
            iVar4 = *piVar5;
          }
          piVar5 = (int *)0x0;
LAB_800a8868:
          if (piVar5 != (int *)0x0) {
            FUN_800ad0c0(*psVar6,piVar5 + 2);
          }
          psVar6 = psVar6 + 1;
          sVar1 = *psVar6;
        }
        psVar6 = (short *)((int)param_1 + param_1[5] + 8);
        sVar1 = *psVar6;
        while (sVar1 != -1) {
          piVar5 = (int *)((int)param_5 + param_5[2]);
          iVar4 = *piVar5;
          while (iVar4 != -1) {
            if (*(short *)(piVar5 + 1) == sVar1) goto LAB_800a88e0;
            piVar5 = (int *)((int)piVar5 + *piVar5);
            iVar4 = *piVar5;
          }
          piVar5 = (int *)0x0;
LAB_800a88e0:
          if (piVar5 != (int *)0x0) {
            FUN_800acbc0(*psVar6,piVar5 + 2);
          }
          psVar6 = psVar6 + 1;
          sVar1 = *psVar6;
        }
        psVar6 = (short *)((int)param_1 + param_1[6] + 8);
        sVar1 = *psVar6;
        do {
          if (sVar1 == -1) {
            if (*(short *)((int)param_1 + 6) == 1) {
              FUN_800adb48(param_2,(int)param_1 + param_1[7] + 0xc,
                           *(undefined2 *)((int)param_1 + param_1[7] + 8));
            }
            _DAT_80147fd0 = _DAT_80147fd0 + 1;
            return 1;
          }
          piVar5 = (int *)((int)param_5 + param_5[3]);
          iVar4 = *piVar5;
          while (iVar4 != -1) {
            if (*(short *)(piVar5 + 1) == sVar1) goto LAB_800a8958;
            piVar5 = (int *)((int)piVar5 + *piVar5);
            iVar4 = *piVar5;
          }
          piVar5 = (int *)0x0;
LAB_800a8958:
          if (piVar5 != (int *)0x0) {
            FUN_800ace1c(*psVar6,piVar5 + 3,*(undefined2 *)((int)piVar5 + 10));
          }
          psVar6 = psVar6 + 1;
          sVar1 = *psVar6;
        } while( true );
      }
      param_1 = (int *)((int)param_1 + *param_1);
      iVar4 = *param_1;
    }
  }
  return 0;
}
