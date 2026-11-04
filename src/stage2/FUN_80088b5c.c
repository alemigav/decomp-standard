/* FUN_80088b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088b5c  body 0x80088b5c..0x80088e33  size 728 B
 * body sha256 b56eba0ff0c62a4b57f47562f3fbebb53c0e33a27c2c5768457214c3d4beaa49
 * provider record sha256 16b8758bb40360601c9f4269cf87fc62276fa9c47b0c18f2c9161413d2b57192
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088b5c(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  uVar9 = param_2[0x19];
  if ((((uint *)param_2[0x4b] == (uint *)0x0) || (uVar2 = *(uint *)param_2[0x4b], (uVar2 & 1) != 0))
     || ((uVar2 & 0x20) == 0)) {
    if ((param_3 & 0x40) == 0) {
      FUN_800424ec(uVar9,param_2 + 2,param_4);
    }
    if ((param_3 & 0x800) != 0) {
      local_48 = param_2[2];
      local_44 = param_2[3];
      local_40 = param_2[4];
      local_3c = param_2[5];
      local_38 = param_2[6];
      local_34 = param_2[7] * (int)*(short *)(param_2[0x4b] + 0x124) >> 0xc;
      local_30 = param_2[8] * (int)*(short *)(param_2[0x4b] + 0x126) >> 0xc;
      local_2c = param_2[9] * (int)*(short *)(param_2[0x4b] + 0x128) >> 0xc;
      FUN_800424ec(uVar9,&local_48,param_4);
    }
    if ((param_3 & 0x20) != 0) {
      FUN_800897d4(param_2,param_4);
    }
    FUN_80042454(param_4,&local_48);
    if ((param_3 & 0x400) != 0) {
      local_28 = (int)*(short *)(param_2 + 0x49);
      local_24 = (int)*(short *)((int)param_2 + 0x126);
      local_20 = (int)*(short *)(param_2 + 0x4a);
      FUN_80040d2c(&local_48,&local_28);
    }
    puVar8 = &local_48;
    if ((param_3 & 0x2000) != 0) {
      local_28 = (int)*(short *)(param_2 + 0x49);
      iVar7 = 2;
      local_24 = (int)*(short *)((int)param_2 + 0x126);
      puVar6 = &DAT_800e9048;
      local_20 = (int)*(short *)(param_2 + 0x4a);
      do {
        iVar4 = 2;
        puVar3 = puVar6;
        puVar5 = puVar8;
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
          *(undefined2 *)puVar5 = uVar1;
          puVar5 = (undefined4 *)((int)puVar5 + 2);
        } while (iVar4 != -1);
        puVar8 = (undefined4 *)((int)puVar8 + 6);
        iVar7 = iVar7 + -1;
        puVar6 = puVar6 + 3;
      } while (iVar7 != -1);
      FUN_80040d2c(&local_48,&local_28);
      FUN_8004226c(&local_48,param_4,&local_48);
      local_34 = *(int *)(param_4 + 0x14);
      local_30 = *(int *)(param_4 + 0x18);
      local_2c = *(int *)(param_4 + 0x1c);
      local_28 = *(int *)(param_4 + 0x20);
    }
    iVar7 = FUN_80083d2c(param_2 + 0x13,DAT_800df940);
    if (iVar7 == 0) {
      param_3 = param_3 | 0x4000;
    }
    if ((param_3 & 0x4000) == 0) {
      if ((param_3 & 0x18) == 0) {
        FUN_800411b8(&local_48,param_2 + 0x34);
        FUN_8008548c(param_2,param_1 + 0x78,param_1);
        return;
      }
      if ((param_3 & 8) != 0) {
        FUN_8004a5bc(param_1 + 0x78,param_2);
      }
      FUN_800411b8(&local_48,param_2 + 0x34);
      FUN_8008548c(param_2,param_1 + 0x78,param_1);
    }
    if ((param_3 & 8) == 0) {
      if ((param_3 & 0x10) != 0) {
        FUN_80089b7c(param_2);
      }
    }
    else {
      FUN_80089a98(param_2);
    }
  }
  else {
    *param_2 = 0x20;
  }
  return;
}
