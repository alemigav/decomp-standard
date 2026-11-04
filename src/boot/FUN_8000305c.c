/* FUN_8000305c
 * image   boot (boot), base 0x80000480
 * address 0x8000305c  body 0x8000305c..0x8000319b  size 320 B
 * body sha256 050cf9f0d67502374cbf706c701ea937e9c37518a676778f95444e7ef2dea627
 * provider record sha256 935d0b3d0b6584b42d64c447f7dd691f3ab0d9119270d08b12c28d2e5f303f1d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8000305c(int param_1,uint param_2,char *param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  
  if (param_3 != (char *)0x0) {
    if (*param_3 != '1') {
      return 0xfffffffa;
    }
    if (param_4 == 0x38) {
      if (param_1 == 0) {
        return 0xfffffffe;
      }
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (*(int *)(param_1 + 0x20) == 0) {
        *(code **)(param_1 + 0x20) = FUN_800048e8;
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(code **)(param_1 + 0x24) = FUN_8000490c;
      }
      iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x18);
      *(int *)(param_1 + 0x1c) = iVar1;
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x14) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 0;
        if ((int)param_2 < 0) {
          param_2 = -param_2;
          *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 1;
        }
        if (7 < param_2 - 8) {
          FUN_80002fe8(param_1);
          return 0xfffffffe;
        }
        *(uint *)(*(int *)(param_1 + 0x1c) + 0x10) = param_2;
        pcVar2 = (code *)0x0;
        if (*(int *)(*(int *)(param_1 + 0x1c) + 0xc) == 0) {
          pcVar2 = FUN_800011a0;
        }
        iVar1 = FUN_800015e0(param_1,pcVar2,1 << (param_2 & 0x1f));
        *(int *)(*(int *)(param_1 + 0x1c) + 0x14) = iVar1;
        if (iVar1 != 0) {
          FUN_80002f80(param_1);
          return 0;
        }
        FUN_80002fe8(param_1);
      }
      return 0xfffffffc;
    }
  }
  return 0xfffffffa;
}
