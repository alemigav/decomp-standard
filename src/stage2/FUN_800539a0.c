/* FUN_800539a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800539a0  body 0x800539a0..0x80053c4b  size 684 B
 * body sha256 80d37d07651864f4547fcc04a30babf46a76a554ea58ffce1d494ef9ac1e361e
 * provider record sha256 d198e352611c2998cec77a7089a5edf9c7c0f30d610640d5df75d91051f5b372
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800539a0(int param_1,int param_2,int *param_3)

{
  bool bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  
  pbVar2 = DAT_8010d940;
  uVar3 = 0;
  if (*param_3 == 0) {
    if (*(int *)(DAT_8010d940 + 0x2f8) != param_2) {
      *(int *)(DAT_8010d940 + 0x2f8) = param_2;
      *(int *)(pbVar2 + 0x2fc) = param_2;
      pbVar2[0x2d6] = 1;
    }
    bVar6 = pbVar2[0x2d6];
    pbVar2[0x2d6] = bVar6 - 1;
    uVar3 = 0;
    if ((byte)(bVar6 - 1) == 0) {
      pbVar5 = *(byte **)(pbVar2 + 0x2fc);
      pbVar2[0x2d6] = (byte)param_1;
      bVar1 = false;
      bVar6 = *pbVar5;
      while (bVar6 != 0) {
        bVar6 = *pbVar5;
        if (bVar6 == 0x5d) {
          *pbVar2 = 0;
          pbVar2[1] = pbVar2[1] + 1;
        }
        else if (bVar6 < 0x5e) {
          if (bVar6 == 0x5b) {
            *(byte **)(pbVar2 + 0x2fc) = pbVar5 + 1;
            iVar4 = *(int *)(pbVar2 + 0x2fc);
            pbVar2[0x2d6] = (pbVar5[1] - 0x30) * 'd';
            *(int *)(pbVar2 + 0x2fc) = iVar4 + 1;
            iVar7 = *(int *)(pbVar2 + 0x2fc);
            bVar6 = pbVar2[0x2d6] + (*(char *)(iVar4 + 1) + -0x30) * '\n';
            pbVar2[0x2d6] = bVar6;
            *(int *)(pbVar2 + 0x2fc) = iVar7 + 1;
            pbVar2[0x2d6] = *(char *)(iVar7 + 1) + (bVar6 - 0x30);
            *(int *)(pbVar2 + 0x2fc) = *(int *)(pbVar2 + 0x2fc) + 1;
            return 0;
          }
LAB_80053b48:
          bVar1 = true;
          pbVar2[(uint)*pbVar2 + (uint)pbVar2[1] * 0x1e + 4] = **(byte **)(pbVar2 + 0x2fc);
          pbVar2[(uint)*pbVar2 + (uint)pbVar2[1] * 0x1e + 0x16c] = pbVar2[0x2d7];
          pbVar2[0x2d5] = 0x10;
          *pbVar2 = *pbVar2 + 1;
        }
        else if (bVar6 == 0x5e) {
          *(byte **)(pbVar2 + 0x2fc) = pbVar5 + 1;
          bVar6 = pbVar5[1];
          *(byte **)(pbVar2 + 0x2fc) = pbVar5 + 2;
          *pbVar2 = *pbVar2 - (pbVar5[2] + (bVar6 - 0x30) * '\n' + -0x30);
        }
        else {
          if (bVar6 != 0x7c) goto LAB_80053b48;
          *(byte **)(pbVar2 + 0x2fc) = pbVar5 + 1;
          pbVar2[0x2d7] = pbVar5[1] - 0x30;
        }
        if (0x1d < *pbVar2) {
          *pbVar2 = 0;
          pbVar2[1] = pbVar2[1] + 1;
        }
        if (0xb < pbVar2[1]) {
          pbVar2[1] = pbVar2[1] - 1;
          FUN_80053c78(0x2100000);
        }
        FUN_80077adc(0x2100000,0);
        iVar4 = *(int *)(pbVar2 + 0x2fc);
        pbVar5 = (byte *)(iVar4 + 1);
        *(byte **)(pbVar2 + 0x2fc) = pbVar5;
        if ((param_1 != 0) && (bVar1)) {
          return 0;
        }
        bVar6 = *(byte *)(iVar4 + 1);
      }
      uVar3 = 1;
      pbVar2[0x2f8] = 0;
      pbVar2[0x2f9] = 0;
      pbVar2[0x2fa] = 0;
      pbVar2[0x2fb] = 0;
      *param_3 = 1;
    }
  }
  return uVar3;
}
