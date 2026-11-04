/* FUN_8002857c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002857c  body 0x8002857c..0x8002877f  size 516 B
 * body sha256 14f0897b23cdb610f468d19e457489291f11a46910f6666d0a89645c4b8a0f5e
 * provider record sha256 6f98597e4bb2dfae2a86d8f7a75183b75622f38ed3f6c89b3343bacbe6924961
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002857c(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = param_1[8];
  if (iVar4 != 3) {
    if (iVar4 < 4) {
      if (iVar4 == 1) {
        param_1[9] = 1;
        param_1[10] = 1;
        goto LAB_80028730;
      }
      param_1[9] = 0;
    }
    else {
      if (iVar4 == 4) {
        if (param_1[0x3e] == 0) {
          param_1[9] = 4;
        }
        else if (*(char *)(param_1 + 0x3f) == '\0') {
          param_1[9] = 4;
        }
        else {
          if (*(char *)(param_1 + 0x3f) != '\x02') {
            *(undefined4 *)(*param_1 + 0x14) = 0x66;
            *(uint *)(*param_1 + 0x18) = (uint)*(byte *)(param_1 + 0x3f);
            (**(code **)(*param_1 + 4))(param_1,0xffffffff);
          }
          param_1[9] = 5;
        }
        param_1[10] = 4;
        goto LAB_80028730;
      }
      param_1[9] = 0;
    }
    param_1[10] = 0;
    goto LAB_80028730;
  }
  if (param_1[0x3b] == 0) {
    if (param_1[0x3e] == 0) {
      piVar2 = (int *)param_1[0x2c];
      iVar4 = *piVar2;
      iVar6 = piVar2[0x14];
      iVar7 = piVar2[0x28];
      if (((iVar4 == 1) && (iVar6 == 2)) && (iVar7 == 3)) {
LAB_8002865c:
        param_1[9] = 3;
        goto LAB_800286bc;
      }
      if (((iVar4 != 0x52) || (iVar6 != 0x47)) || (iVar3 = 2, iVar7 != 0x42)) {
        iVar3 = *param_1;
        *(int *)(iVar3 + 0x18) = iVar4;
        *(int *)(iVar3 + 0x1c) = iVar6;
        *(int *)(iVar3 + 0x20) = iVar7;
        *(undefined4 *)(*param_1 + 0x14) = 99;
        pcVar1 = *(code **)(*param_1 + 4);
        uVar5 = 1;
        goto LAB_800286ac;
      }
    }
    else if (*(char *)(param_1 + 0x3f) == '\0') {
      iVar3 = 2;
    }
    else {
      if (*(char *)(param_1 + 0x3f) == '\x01') goto LAB_8002865c;
      *(undefined4 *)(*param_1 + 0x14) = 0x66;
      *(uint *)(*param_1 + 0x18) = (uint)*(byte *)(param_1 + 0x3f);
      pcVar1 = *(code **)(*param_1 + 4);
      uVar5 = 0xffffffff;
LAB_800286ac:
      (*pcVar1)(param_1,uVar5);
      iVar3 = 3;
    }
    param_1[9] = iVar3;
  }
  else {
    param_1[9] = 3;
  }
LAB_800286bc:
  param_1[10] = 2;
LAB_80028730:
  param_1[0x13] = 2;
  param_1[0xb] = 1;
  param_1[0xc] = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  param_1[0x14] = 0x100;
  param_1[0x1d] = 0;
  param_1[0x15] = 1;
  param_1[0x16] = 0;
  param_1[0xe] = 0x3ff00000;
  param_1[0xf] = 0;
  return;
}
