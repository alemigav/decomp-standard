/* FUN_80057f74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057f74  body 0x80057f74..0x80057fc7  size 84 B
 * body sha256 65102d7ea4a4d1ee21678f2087cf030414dc6feefa62243b72fe1c1f6153f698
 * provider record sha256 dcfbf533de7c30940d3e052a9edc936de993d648409e62cb92d7ced4e2fab9cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80057f74(uint *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  byte local_18 [8];
  short local_10;
  short local_e;
  short local_c;
  undefined2 local_a;
  
  local_18[0] = 0;
  local_18[1] = 3;
  local_a = 0;
  local_c = 0;
  local_e = 0;
  local_10 = 0;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    DAT_800e110c = DAT_800e110c | 0x40;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 4;
  case 1:
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 0x7d),0x50);
    iVar3 = FUN_80032f64(param_1,(int)*(short *)(param_1 + 0x7d),0x28);
    if (iVar3 == 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      FUN_80032ef4(param_1,(int)*(short *)(param_1 + 0x7d),0x50);
    }
    FUN_80089d54(param_1,param_1[0x87],param_1[0x88],0x200);
    break;
  case 2:
    bVar1 = local_18[*(char *)((int)param_1 + 0x206)];
    *(undefined1 *)((int)param_1 + 6) = 3;
    cVar4 = *(char *)((int)param_1 + 0x1a2) + *(char *)((int)param_1 + 0x1f7);
    *(char *)((int)param_1 + 0x1a2) = cVar4;
    param_1[0x7a] = (uint)bVar1 * 0x1000000 + 0x300;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x1a2) = cVar4 + *(char *)((int)param_1 + 0x1f7) * -2;
    }
    *(int **)(param_1[0x82] + 0x14) = &DAT_8010dcb8;
    *(undefined2 *)(param_1 + 0x7d) = 0;
  case 3:
    FUN_800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar3 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x400);
    if (iVar3 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 4;
      sVar2 = *(short *)((int)param_1 + 0x1f6);
      bVar1 = local_18[*(char *)((int)param_1 + 0x206)];
      *(short *)((int)param_1 + 0x1f6) = sVar2 + -1;
      param_1[0x7a] = (bVar1 + 1) * 0x1000000;
      if (sVar2 == 1) {
        *(undefined1 *)((int)param_1 + 6) = 5;
        param_1[0x7a] = (local_18[*(char *)((int)param_1 + 0x206)] + 2) * 0x1000000;
      }
    }
    FUN_80032bd8(param_1,0,0);
    if (*(char *)((int)param_1 + 0x206) == '\0') {
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -0x14;
      *(short *)((int)param_1 + 0x2ae) = *(short *)((int)param_1 + 0x2ae) + 0x14;
      if (*(short *)(param_1 + 0x7d) < -200) {
        *(undefined2 *)(param_1 + 0x7d) = 0xff38;
LAB_800581c4:
        *(undefined2 *)((int)param_1 + 0x2ae) = 200;
      }
    }
    else {
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x14;
      *(short *)((int)param_1 + 0x2ae) = *(short *)((int)param_1 + 0x2ae) + 0x14;
      if (200 < *(short *)(param_1 + 0x7d)) {
        *(undefined2 *)(param_1 + 0x7d) = 200;
        goto LAB_800581c4;
      }
    }
    local_10 = *(short *)(param_1 + 0x7d);
LAB_800582a4:
    FUN_8004276c(param_1 + 5,&local_10,&local_10);
    uVar5 = param_1[0x8d];
    DAT_8010dcb8 = (int)local_10 + *(int *)(uVar5 + 0x4c);
    DAT_8010dcbc = (int)local_e + *(int *)(uVar5 + 0x50);
    DAT_8010dcc0 = (int)local_c + *(int *)(uVar5 + 0x54);
    break;
  case 4:
    FUN_800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar3 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if ((iVar3 != 0) &&
       (sVar2 = *(short *)((int)param_1 + 0x1f6), *(short *)((int)param_1 + 0x1f6) = sVar2 + -1,
       sVar2 == 1)) {
      *(undefined1 *)((int)param_1 + 6) = 5;
      param_1[0x7a] = (local_18[*(char *)((int)param_1 + 0x206)] + 2) * 0x1000000;
    }
    goto LAB_8005827c;
  case 5:
    FUN_800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar3 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if (iVar3 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 6;
    }
LAB_8005827c:
    FUN_80032bd8(param_1,0,0);
    local_10 = 200;
    if (*(char *)((int)param_1 + 0x206) == '\0') {
      local_10 = -200;
    }
    goto LAB_800582a4;
  case 6:
    param_1[0x7a] = 0x700;
    *(undefined1 *)((int)param_1 + 6) = 7;
    *(undefined2 *)(param_1 + 0x7d) = 200;
    if (*(char *)((int)param_1 + 0x206) == '\0') {
      *(undefined2 *)(param_1 + 0x7d) = 0xff38;
      goto switchD_80057fc0_caseD_7;
    }
LAB_80058324:
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -0x32;
    *(short *)((int)param_1 + 0x2ae) = *(short *)((int)param_1 + 0x2ae) + -0x32;
    if (*(short *)(param_1 + 0x7d) < 0) {
      *(undefined2 *)(param_1 + 0x7d) = 0;
LAB_80058370:
      *(undefined2 *)((int)param_1 + 0x2ae) = 0;
    }
    goto LAB_80058374;
  case 7:
switchD_80057fc0_caseD_7:
    if (*(char *)((int)param_1 + 0x206) != '\0') goto LAB_80058324;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x32;
    *(short *)((int)param_1 + 0x2ae) = *(short *)((int)param_1 + 0x2ae) + -0x32;
    if (0 < *(short *)(param_1 + 0x7d)) {
      *(undefined2 *)(param_1 + 0x7d) = 0;
      goto LAB_80058370;
    }
LAB_80058374:
    local_10 = *(short *)(param_1 + 0x7d);
    FUN_8004276c(param_1 + 5,&local_10,&local_10);
    uVar5 = param_1[0x8d];
    DAT_8010dcb8 = (int)local_10 + *(int *)(uVar5 + 0x4c);
    DAT_8010dcbc = (int)local_e + *(int *)(uVar5 + 0x50);
    DAT_8010dcc0 = (int)local_c + *(int *)(uVar5 + 0x54);
    FUN_800334c8(param_1,param_1[0x87],param_1[0x88],0);
    FUN_80089d54(param_1,param_1[0x87],param_1[0x88],0x200);
    FUN_80032b5c(param_1,0);
    if (9 < *(byte *)((int)param_1 + 0x1e9)) {
      *param_1 = *param_1 & 0xfffffff7;
      FUN_800551e0();
      param_1[1] = 0x1000000;
      DAT_800e110c = DAT_800e110c & 0xffffffbf;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xfffffffb;
      *(uint *)(param_1[0x82] + 0x14) = param_1[0x8d] + 0x4c;
    }
  default:
    break;
  }
  if ((*(uint *)param_1[0x85] & 0x4000) != 0) {
    FUN_80077f30(0,((*(uint *)param_1[0x85] & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
