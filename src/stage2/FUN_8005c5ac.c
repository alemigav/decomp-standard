/* FUN_8005c5ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c5ac  body 0x8005c5ac..0x8005cad7  size 1324 B
 * body sha256 662a3fb086178fcc28c0388d1fb47fd39f81bf736d80a1152978fa19cc4481db
 * provider record sha256 ed64a00d0f14cf351b315b30d34fd1845e164b29126453dd4e36ae0d13a7ee15
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c5ac(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  short local_58 [8];
  undefined1 auStack_48 [20];
  int local_34;
  int local_30;
  int local_2c;
  short local_28;
  short local_26;
  short local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_58[0] = 0;
  local_58[1] = 0xe;
  local_58[2] = 10;
  local_58[3] = 0;
  local_58[4] = 0xc;
  local_20 = 0xff380000;
  local_1c = 0xfa007d;
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = local_58[*(ushort *)(param_1 + 0x7c) >> 0xd] * 0x1000000 + 0x700;
    (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    uVar3 = *param_1;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    *param_1 = uVar3 & 0x1fffffff;
    *param_1 = uVar3 & 0x1fffffff | (*(ushort *)(param_1 + 0x7c) & 0xe000) << 0x10;
  }
  if (((param_4 & 0x100) == 0) &&
     (((&DAT_80110e26)[((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1) * 3] & 0x7f) <
      *(byte *)((int)param_1 + 0x1e9))) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
  }
  else {
    iVar1 = FUN_80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined2 *)((int)param_1 + 6) = 0x100;
    }
    puVar5 = param_1 + 5;
    uVar3 = param_1[0x8d];
    FUN_80040e58(param_1 + 0x19,puVar5);
    local_28 = 0;
    local_26 = 0;
    local_24 = (*(byte *)((int)param_1 + 0x1e9) - 5) * -0xf + 300;
    FUN_8004276c(puVar5,&local_28,&local_28);
    FUN_800424ec(puVar5,uVar3 + 8,auStack_48);
    FUN_800424ec(auStack_48,uVar3 + 0xd40,auStack_48);
    FUN_800424ec(auStack_48,uVar3 + 0xeb8,auStack_48);
    FUN_800424ec(auStack_48,uVar3 + 0x1030,auStack_48);
    if (*(short *)(param_1 + 0x6a) != 0) {
      if (((*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e)) &&
          (*(byte *)((int)param_1 + 0x1e9) < 6)) && ((*(byte *)((int)param_1 + 0x1e9) & 1) != 0)) {
        FUN_8005c3e8(param_1);
      }
      if (*(short *)(param_1 + 0x6a) < local_30) {
        uVar3 = FUN_80033604();
        FUN_80037780((uVar3 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)((int)param_1 + 0x66),
                     auStack_48,0);
        if (*(char *)((int)param_1 + 0x206) == '\0') {
          *(undefined1 *)((int)param_1 + 0x206) = 1;
          FUN_80077adc(0x1070001,param_1 + 10);
        }
      }
    }
    uVar3 = 0;
    if (*(byte *)((int)param_1 + 0x1e9) - 7 < 5) {
      local_30 = local_30 + 200;
      uVar4 = 0x20001;
      if ((param_1[0x7c] & 0x20000000) != 0) {
        uVar4 = 0x60001;
      }
      uVar3 = FUN_800609e0(&local_34,(int)*(short *)((int)param_1 + 0x66),&local_20,uVar4);
      if (uVar3 != 0) {
        param_1[0x9d] = uVar3;
      }
      local_30 = local_30 + -200;
    }
    local_34 = local_34 + local_28;
    local_2c = local_2c + local_24;
    FUN_80069f1c(&local_34,10,0x2080,0);
    if ((*(byte *)((int)param_1 + 0x1e9) - 7 < 6) && (DAT_8011270c != 0)) {
      *(undefined2 *)((int)param_1 + 6) = 0x600;
      param_1[0x7a] = 0x10000300;
      FUN_80089d54(param_1,param_2,param_3,0x400);
      FUN_80077adc(0x1000001,param_1 + 10);
      FUN_80052bd0(6,0);
      FUN_80052c6c(3,200,0);
    }
    else {
      if ((uVar3 != 0) && (uVar3 != 0xff)) {
        FUN_80077adc(0x1060001,param_1 + 10);
        *(undefined1 *)((int)param_1 + 0x207) = 2;
        FUN_80052c6c(8,0xa0,0);
      }
      if ((*(char *)((int)param_1 + 0x207) != '\0') && (param_1[0x9d] != 0)) {
        local_28 = 0x32;
        local_26 = 100;
        local_24 = 0;
        FUN_80037780((*(uint *)param_1[0x9d] >> 0x13 & 0x18) << 0x10 | 0xb50,
                     (int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0x1060,&local_28);
        *(char *)((int)param_1 + 0x207) = *(char *)((int)param_1 + 0x207) + -1;
      }
      if ((*(char *)(param_1 + 2) == '\r') && ((*(byte *)((int)param_1 + 0x1e9) & 7) == 0)) {
        uVar6 = param_1[0x8d];
        uVar2 = FUN_80033604();
        local_28 = (uVar2 & 0xff) * -2 + 0x100;
        uVar2 = FUN_80033604();
        local_26 = (uVar2 & 0xff) * -2 + -0x2e8;
        uVar2 = FUN_80033604();
        local_24 = (uVar2 & 0xff) * -2 + 0x100;
        uVar3 = FUN_80033604();
        FUN_80037780(0x1262000,
                     (int)(((uint)*(ushort *)((int)param_1 + 0x66) - ((uVar3 & 0xff) * 2 + -0x900))
                          * 0x10000) >> 0x10,uVar6 + 0x38,&local_28);
      }
      (*(code *)(&PTR_FUN_80111078)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    }
  }
  return;
}
