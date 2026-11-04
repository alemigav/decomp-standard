/* FUN_80030a3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030a3c  body 0x80030a3c..0x80030b8b  size 336 B
 * body sha256 9359670804fbe7055078083e142077bba37dcc8e9d91858c930a1296cfe640b6
 * provider record sha256 5b6d39db61650ea5009425dc145017fda0393ef7b6aa5a689dcce5dc0b7a7aca
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80030a3c(int *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  
  if (((uint)param_2[1] <= param_3) || (*param_2 == 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xf;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[6] + param_2[4]) < param_3 + param_2[3])) {
    if (param_2[8] == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x3d;
      (**(code **)*param_1)(param_1);
    }
    if (param_2[7] != 0) {
      FUN_800307c8(param_1,param_2,1);
      param_2[7] = 0;
    }
    if ((uint)param_2[6] < param_3) {
      param_2[6] = param_3;
    }
    else {
      iVar1 = (param_3 + param_2[3]) - param_2[4];
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      param_2[6] = iVar1;
    }
    if (param_4 == 0) {
      FUN_800307c8(param_1,param_2,0);
      goto LAB_80030b50;
    }
  }
  else {
LAB_80030b50:
    if (param_4 == 0) goto LAB_80030b5c;
  }
  param_2[7] = 1;
LAB_80030b5c:
  return *param_2 + (param_3 - param_2[6]) * 4;
}
