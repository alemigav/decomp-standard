/* FUN_8004e438
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004e438  body 0x8004e438..0x8004e773  size 828 B
 * body sha256 6402fb5aba079d63f312d870fe31b90f9f28943482c60b1062d4e5b07482507c
 * provider record sha256 4c9106fd0d28a8b504e42e77e8b716747af28227fcdc47be167ccd29f8629800
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004e438(int param_1)

{
  uint uVar1;
  int iVar2;
  short sVar5;
  int iVar3;
  undefined4 uVar4;
  ushort uVar6;
  uint *puVar7;
  short local_38 [2];
  short local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  
  uVar6 = DAT_800e1196 + 0x200U & 0xfc00;
  if (DAT_800e12d2 < 0x1f) {
    local_38[0] = *(short *)(&DAT_8010ba00 + param_1 * 2);
    local_34 = 0;
    FUN_800837d0((int)(short)uVar6,local_38,local_38);
    local_30 = local_38[0] + DAT_800e1158;
    local_2c = DAT_800e115c + -0x708;
    local_28 = local_34 + DAT_800e1160;
    uVar1 = FUN_800667d4(&local_30,0,1 << (DAT_800e12d2 & 0x1f),0x8000);
    iVar2 = FUN_8004eccc(&DAT_800e1130);
    if (((((uVar1 & 2) != 0) || (iVar2 != 0)) &&
        (sVar5 = FUN_80069f1c(&local_30,0,0x8000,0), sVar5 <= local_2c)) &&
       (((DAT_8011270c & 1) == 0 && (iVar3 = FUN_8004f814(&local_30,&DAT_800e1130), iVar3 == 0)))) {
      if (iVar2 == 0) {
        DAT_800e13b0 = (uint *)0x0;
      }
      else {
        DAT_800e13b0 = (uint *)iVar2;
      }
      DAT_800e1134._1_1_ = 8;
      DAT_800e1134._2_1_ = 0;
      DAT_800e1134._3_1_ = 0;
      return 1;
    }
  }
  local_38[0] = *(short *)(&DAT_8010ba28 + param_1 * 2);
  local_34 = 0;
  FUN_800837d0((int)(short)uVar6,local_38,local_38);
  local_30 = local_38[0] + DAT_800e1158;
  local_28 = local_34 + DAT_800e1160;
  local_2c = DAT_800e115c;
  local_2c = FUN_80069f1c(&local_30,0,0,0);
  if (DAT_80112710 < local_2c) {
    local_2c = DAT_80112710;
  }
  uVar1 = FUN_800667d4(&local_30,0,1 << (DAT_800e12d2 & 0x1f),0);
  if (DAT_800e115c < local_2c) {
    if (((uVar1 & 4) != 0) || (uVar4 = 0, DAT_800e13b0 != (uint *)0x0)) {
      puVar7 = &DAT_800e18f8;
      if (&DAT_800e18f8 < DAT_800e85f8) {
        do {
          if ((((*puVar7 & 1) != 0) && ((*puVar7 & 2) == 0)) && (puVar7 != DAT_800e13b0)) {
            iVar2 = FUN_8004f774(&local_30,puVar7,0,1);
            if (iVar2 != 0) goto LAB_8004e74c;
            sVar5 = local_2c._2_2_;
            local_2c = DAT_800e115c;
            iVar2 = FUN_8004f774(&local_30,puVar7,0,1);
            if (iVar2 != 0) goto LAB_8004e74c;
            local_2c = (int)sVar5;
          }
          puVar7 = puVar7 + 0xda;
        } while (puVar7 < DAT_800e85f8);
      }
      iVar2 = FUN_8004f814(&local_30,&DAT_800e1130);
      uVar4 = 0;
      if (iVar2 == 0) {
        if (DAT_800e13b0 != (uint *)0x0) {
          DAT_800e13b0 = (uint *)0x0;
        }
        uVar4 = 1;
        DAT_800e1134._1_1_ = 8;
        DAT_800e1134._2_1_ = 2;
        DAT_800e1134._3_1_ = 0;
      }
    }
  }
  else {
LAB_8004e74c:
    uVar4 = 0;
  }
  return uVar4;
}
