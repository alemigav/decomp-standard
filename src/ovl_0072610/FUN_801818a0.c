/* FUN_801818a0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801818a0  body 0x801818a0..0x801822e3  size 2628 B
 * body sha256 256313b2ff6c6e2433e50147eca017c21ea00e95f4a20d889466ed0643bcde49
 * provider record sha256 5fa1808948ffe6a5314f1e2e7862dc798d4f6e812b5177059017564ce43888ca
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801818a0(undefined4 param_1,int param_2,uint param_3,int param_4,undefined4 *param_5,
                 uint *param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
  iVar7 = param_8 / 3;
  param_8 = param_8 % 3;
  iVar2 = param_2 >> 1;
  if (((param_3 & 8) == 0) && (DAT_8018576c != 2)) goto LAB_80181f9c;
  iVar1 = param_2;
  if (DAT_801857a0 == 3) {
    if ((param_4 == 2) || ((param_3 & 8) == 0)) {
      if (param_8 < 2) {
        FUN_801822e4(&DAT_8018571c,0,&DAT_80185734,0,DAT_80185754,DAT_80185754 << 1,0x10,8,param_1,
                     param_2,*param_5,param_5[1],param_8);
      }
      if (iVar7 < 2) {
        puVar3 = &DAT_8018571c;
        uVar4 = 1;
        uVar10 = 8;
        local_30 = *param_5;
        local_2c = param_5[1];
        uVar5 = 1;
        iVar9 = DAT_80185754;
        iVar8 = DAT_80185754 << 1;
        param_8 = iVar7;
        goto LAB_80181f8c;
      }
    }
    else {
      iVar1 = iVar2;
      if (param_4 == 1) {
        if (param_8 < 2) {
          FUN_801822e4(&DAT_8018571c,*param_6,&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,
                       0x10,8,param_1,iVar2,*param_5,(int)param_5[1] >> 1,param_8);
        }
        if (iVar7 < 2) {
          uVar10 = 8;
          puVar3 = &DAT_8018571c;
          iVar9 = DAT_80185754 << 1;
          local_30 = param_5[4];
          local_2c = (int)param_5[5] >> 1;
          uVar4 = param_6[2];
          uVar5 = 1;
          iVar8 = iVar9;
          param_8 = iVar7;
          goto LAB_80181f8c;
        }
      }
      else if (param_4 == 3) {
        FUN_8018046c(&local_38,param_7,*param_5,(int)param_5[1] >> 1);
        if (param_8 < 2) {
          FUN_801822e4(&DAT_8018571c,0,&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,0x10,8,
                       param_1,iVar2,*param_5,(int)param_5[1] >> 1,0);
          FUN_801822e4(&DAT_8018571c,1,&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,0x10,8,
                       param_1,iVar2,local_38,local_34,1);
        }
        if (iVar7 < 2) {
          FUN_801822e4(&DAT_8018571c,1,&DAT_80185734,1,DAT_80185754 << 1,DAT_80185754 << 1,0x10,8,
                       param_1,iVar2,*param_5,(int)param_5[1] >> 1,0);
          puVar3 = &DAT_8018571c;
          uVar4 = 0;
          uVar10 = 8;
          iVar9 = DAT_80185754 << 1;
          uVar5 = 1;
          param_8 = 1;
          iVar8 = iVar9;
          goto LAB_80181f8c;
        }
      }
    }
  }
  else {
    uVar4 = (uint)(DAT_801857a0 == 2);
    if (((DAT_8018576c == 2) && (DAT_801857bc != 0)) && (uVar4 != *param_6)) {
      puVar3 = &DAT_80185710;
    }
    else {
      puVar3 = &DAT_8018571c;
    }
    if ((param_4 == 1) || ((param_3 & 8) == 0)) {
      if (param_8 < 2) {
        uVar10 = 0x10;
        iVar9 = DAT_80185754 << 1;
        local_30 = *param_5;
        local_2c = param_5[1];
        uVar4 = *param_6;
        uVar5 = 0;
        iVar8 = iVar9;
        goto LAB_80181f8c;
      }
    }
    else if (param_4 == 2) {
      if (param_8 < 2) {
        FUN_801822e4(puVar3,*param_6,&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,0x10,8,
                     param_1,param_2,*param_5,param_5[1],param_8);
        if (((DAT_8018576c == 2) && (DAT_801857bc != 0)) && (uVar4 != param_6[2])) {
          puVar3 = &DAT_80185710;
        }
        else {
          puVar3 = &DAT_8018571c;
        }
        uVar10 = 8;
        iVar1 = param_2 + 8;
        iVar9 = DAT_80185754 << 1;
        local_30 = param_5[4];
        local_2c = param_5[5];
        uVar4 = param_6[2];
        uVar5 = 0;
        iVar8 = iVar9;
LAB_80181f8c:
        FUN_801822e4(puVar3,uVar4,&DAT_80185734,uVar5,iVar9,iVar8,0x10,uVar10,param_1,iVar1,local_30
                     ,local_2c,param_8);
      }
    }
    else if (param_4 == 3) {
      if (DAT_801857bc == 0) {
        puVar3 = &DAT_8018571c;
      }
      else {
        puVar3 = &DAT_80185710;
      }
      FUN_8018046c(&local_38,param_7,*param_5,param_5[1]);
      FUN_801822e4(&DAT_8018571c,uVar4,&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,0x10,0x10
                   ,param_1,param_2,*param_5,param_5[1],0);
      uVar4 = uVar4 ^ 1;
      uVar10 = 0x10;
      iVar9 = DAT_80185754 << 1;
      uVar5 = 0;
      param_8 = 1;
      iVar8 = iVar9;
      local_30 = local_38;
      local_2c = local_34;
      goto LAB_80181f8c;
    }
  }
  param_8 = 1;
  iVar7 = param_8;
LAB_80181f9c:
  if ((param_3 & 4) == 0) {
    return;
  }
  if (DAT_801857a0 == 3) {
    if (param_4 == 2) {
      if (param_8 < 2) {
        FUN_801822e4(&DAT_80185710,0,&DAT_80185734,0,DAT_80185754,DAT_80185754 << 1,0x10,8,param_1,
                     param_2,param_5[2],param_5[3],param_8);
      }
      if (1 < iVar7) {
        return;
      }
      uVar4 = 1;
      uVar10 = 8;
      uVar5 = param_5[2];
      iVar1 = param_5[3];
      uVar6 = 1;
      iVar9 = DAT_80185754;
      iVar8 = DAT_80185754 << 1;
      param_8 = iVar7;
    }
    else {
      if (param_8 < 2) {
        FUN_801822e4(&DAT_80185710,param_6[1],&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,
                     0x10,8,param_1,iVar2,param_5[2],(int)param_5[3] >> 1,param_8);
      }
      if (1 < iVar7) {
        return;
      }
      uVar10 = 8;
      uVar5 = param_5[6];
      iVar1 = (int)param_5[7] >> 1;
      uVar4 = param_6[3];
      uVar6 = 1;
      iVar9 = DAT_80185754 << 1;
      iVar8 = DAT_80185754 << 1;
      param_2 = iVar2;
      param_8 = iVar7;
    }
  }
  else {
    if (param_4 == 1) {
      uVar10 = 0x10;
      uVar5 = param_5[2];
      iVar1 = param_5[3];
      uVar4 = param_6[1];
    }
    else {
      if (param_4 != 2) {
        return;
      }
      FUN_801822e4(&DAT_80185710,param_6[1],&DAT_80185734,0,DAT_80185754 << 1,DAT_80185754 << 1,0x10
                   ,8,param_1,param_2,param_5[2],param_5[3],param_8);
      uVar10 = 8;
      param_2 = param_2 + 8;
      uVar5 = param_5[6];
      iVar1 = param_5[7];
      uVar4 = param_6[3];
    }
    iVar9 = DAT_80185754 << 1;
    uVar6 = 0;
    iVar8 = iVar9;
  }
  FUN_801822e4(&DAT_80185710,uVar4,&DAT_80185734,uVar6,iVar9,iVar8,0x10,uVar10,param_1,param_2,uVar5
               ,iVar1,param_8);
  return;
}
