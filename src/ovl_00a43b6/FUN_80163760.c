/* FUN_80163760
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80163760  body 0x80163760..0x801642f7  size 2968 B
 * body sha256 af423221fac4ef0d9aef5f6ba24adb3c53c564765a9171cad4ce32a42732953b
 * provider record sha256 b018d6f06f710701e6dfac83b44d270aed00efd9e64e8c4c9530de46fb687d72
 * callees 18 direct (18 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163760(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar4;
  ushort uVar3;
  uint uVar5;
  uint uVar6;
  short local_48;
  short local_46;
  short local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) | 0x80;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    break;
  case 1:
    goto switchD_801637b0_caseD_1;
  case 2:
    param_1[0x7a] = 0x9000700;
    *(undefined1 *)((int)param_1 + 6) = 3;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x800);
    _DAT_800e1380 = param_1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    _DAT_800e1354 = param_1[0x89];
    _DAT_800e1134 = 0x6000000;
    _DAT_800e1358 = param_1[0x8a];
    DAT_800e139f = DAT_800e139f | 0x80;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 0x1000;
    _DAT_800e1130 = _DAT_800e1130 | 0x1000;
    _DAT_800e10ec = _DAT_800e10ec | 0x100;
    _DAT_800e1196 = *(short *)((int)param_1 + 0x66) + 0x800;
    func_0x80059e00(500,0);
  case 3:
    func_0x8003331c(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      param_1[0x7a] = 0x17000f00;
      *(undefined1 *)((int)param_1 + 6) = 4;
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\x06') {
      func_0x80077d18(5,param_1);
      FUN_80166c64(param_1);
    }
    FUN_80169528(param_1,&local_38);
    uVar5 = param_1[0x8d];
    *(undefined4 *)(uVar5 + 0x908) = local_38;
    *(undefined4 *)(uVar5 + 0x90c) = local_34;
    *(undefined4 *)(uVar5 + 0x910) = local_30;
    *(undefined4 *)(uVar5 + 0x914) = local_2c;
    *(undefined4 *)(uVar5 + 0x918) = local_28;
    *(int *)(uVar5 + 0x91c) = local_24;
    *(int *)(uVar5 + 0x920) = local_20;
    *(int *)(uVar5 + 0x924) = local_1c;
    if (*(byte *)((int)param_1 + 0x1e9) < 7) {
      return;
    }
    if ((*(byte *)((int)param_1 + 0x1e9) & 3) == 0) {
      uVar3 = func_0x80033604();
      local_48 = (uVar3 & 0xff) * -2 + 0x100;
      uVar3 = func_0x80033604();
      local_46 = 0x148 - (uVar3 & 0xff);
      uVar3 = func_0x80033604();
      local_44 = (uVar3 & 0xff) * -2 + 0x100;
      uVar6 = func_0x80033604();
      func_0x80037780((uVar6 & 0xff) << 2 | 0x1000,(int)*(short *)((int)param_1 + 0x66),
                      uVar5 + 0x908,&local_48);
      return;
    }
    return;
  case 4:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 == 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x1ea) = 0xf;
    return;
  case 5:
    param_1[0x7a] = 0x9010700;
    *(undefined1 *)((int)param_1 + 6) = 6;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  case 6:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      param_1[1] = 0x1010000;
      *(undefined1 *)((int)param_1 + 0x2b6) = 0x1e;
      *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) & 0xff7f;
      if (*(char *)((int)param_1 + 0x207) != '\0') {
        bVar4 = func_0x80033604();
        *(byte *)((int)param_1 + 0x2b6) = (bVar4 & 7) + 10;
      }
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    }
    func_0x80032b5c(param_1,0);
    FUN_80169528(param_1,&local_38);
    if ((*(uint *)param_1[0x85] & 0x30000) != 0) {
      bVar1 = false;
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
      local_48 = 0;
      local_46 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3e = 500;
      local_3c = 0;
      iVar2 = func_0x8003307c(&local_38,&DAT_800e1158,800,&local_48);
      if (iVar2 == 0) {
        iVar2 = func_0x8003307c(&local_38,&DAT_800e1158,800,&local_40);
        if (iVar2 != 0) {
          bVar1 = true;
        }
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (DAT_800e139f == 0)) {
        func_0x80059e00(0xf,1);
        DAT_800e138c = DAT_800e138c | 0x12;
        DAT_800e139f = DAT_800e139f | 0x80;
        _DAT_800e1354 = param_1[0x89];
        _DAT_800e1358 = param_1[0x8a];
        _DAT_800e1134 = 0x2020000;
        _DAT_800e1380 = param_1;
        *(undefined1 *)((int)param_1 + 0x206) = 5;
        *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) & 0xfffe;
        func_0x80077d18(4,param_1);
        FUN_80166c64(param_1);
        *(undefined1 *)((int)param_1 + 0x207) = 1;
        func_0x80052bd0(8,0);
        func_0x80052c6c(8,0xfa,4);
      }
      local_48 = 0;
      local_46 = 1000;
      local_44 = 0;
      func_0x8004276c(&local_38,&local_48,&local_48);
      local_24 = local_24 + local_48;
      local_20 = local_20 + local_46;
      local_1c = local_1c + local_44;
      func_0x80069f1c(&local_24,600,0x8000,1);
      if (_DAT_8011270c != 0) {
        uVar5 = param_1[0x8d];
        local_48 = 0;
        local_46 = 1000;
        local_44 = 0;
        *(undefined4 *)(uVar5 + 0x908) = local_38;
        *(undefined4 *)(uVar5 + 0x90c) = local_34;
        *(undefined4 *)(uVar5 + 0x910) = local_30;
        *(undefined4 *)(uVar5 + 0x914) = local_2c;
        *(undefined4 *)(uVar5 + 0x918) = local_28;
        *(int *)(uVar5 + 0x91c) = local_24;
        *(int *)(uVar5 + 0x920) = local_20;
        *(int *)(uVar5 + 0x924) = local_1c;
        iVar2 = uVar5 + 0x908;
        func_0x80037780(0x1061fa0,(int)*(short *)((int)param_1 + 0x66),iVar2,&local_48);
        uVar3 = func_0x80033604();
        local_48 = local_48 - ((uVar3 & 0x7f) - 0x40);
        func_0x80037780(0x1061fa0,(int)*(short *)((int)param_1 + 0x66),iVar2,&local_48);
        uVar3 = func_0x80033604();
        local_46 = local_46 - ((uVar3 & 0xff) - 0x80);
        func_0x80037780(0x1061fa0,(int)*(short *)((int)param_1 + 0x66),iVar2,&local_48);
        uVar3 = func_0x80033604();
        local_44 = local_44 - ((uVar3 & 0x7f) - 0x40);
        func_0x80037780(0x1061fa0,(int)*(short *)((int)param_1 + 0x66),iVar2,&local_48);
        if (*(short *)((int)param_1 + 0x1f6) == 0) {
          func_0x80077d18(7,param_1);
          *(undefined2 *)((int)param_1 + 0x1f6) = 7;
        }
      }
    }
    _DAT_800e110c = _DAT_800e110c & 0xfffffff7;
    if (*(short *)((int)param_1 + 0x1f6) != 0) {
      *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + -1;
      _DAT_800e110c = _DAT_800e110c | 8;
    }
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
      FUN_80169528(param_1,&local_38);
      uVar3 = func_0x80033604();
      local_48 = (uVar3 & 0xff) * -2 + 0x100;
      uVar3 = func_0x80033604();
      local_46 = (uVar3 & 0xff) * -2 + 0x4e8;
      uVar3 = func_0x80033604();
      local_44 = (uVar3 & 0xff) * -2 + 0x100;
      uVar6 = param_1[0x8d];
      *(undefined4 *)(uVar6 + 0x908) = local_38;
      *(undefined4 *)(uVar6 + 0x90c) = local_34;
      *(undefined4 *)(uVar6 + 0x910) = local_30;
      *(undefined4 *)(uVar6 + 0x914) = local_2c;
      *(undefined4 *)(uVar6 + 0x918) = local_28;
      *(int *)(uVar6 + 0x91c) = local_24;
      *(int *)(uVar6 + 0x920) = local_20;
      *(int *)(uVar6 + 0x924) = local_1c;
      uVar5 = func_0x80033604();
      func_0x80037780((uVar5 & 0xff) << 2 | 0x1000,(int)*(short *)((int)param_1 + 0x66),
                      uVar6 + 0x908,&local_48);
      iVar2 = _DAT_800e1364;
      uVar3 = func_0x80033604();
      local_48 = (uVar3 & 0xff) * -2 + 0x100;
      local_46 = 0;
      uVar3 = func_0x80033604();
      local_44 = (uVar3 & 0xff) * -2 + 0x100;
      uVar5 = func_0x80033604();
      func_0x80037780((uVar5 & 0xff) << 2 | 0x1000,0,iVar2 + 0x38,&local_48);
    }
    if ((*(char *)((int)param_1 + 0x1e9) == '\n') && (*(char *)((int)param_1 + 0x207) == '\0')) {
      param_1[0x7a] = 0xb000700;
      *(undefined1 *)((int)param_1 + 0x207) = 1;
    }
  default:
    goto switchD_801637b0_default;
  }
  param_1[0x7a] = 0x5000f00;
  func_0x800334c8(param_1,param_2,param_3,0);
  *(undefined1 *)((int)param_1 + 6) = 1;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  *(undefined1 *)((int)param_1 + 0x207) = 0;
  *(undefined1 *)((int)param_1 + 0x206) = 0;
switchD_801637b0_caseD_1:
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    DAT_800e139f = DAT_800e139f & 0x7f;
    *(undefined1 *)((int)param_1 + 6) = 2;
    if (0x14 < _DAT_800e1322) {
      *(undefined1 *)((int)param_1 + 6) = 5;
      *(undefined1 *)((int)param_1 + 0x206) = 0;
      uVar5 = func_0x80033604();
      uVar6 = func_0x80033604();
      if (((int)(uVar5 & 0xff) >> (uVar6 & 3) & 3U) == 0) {
        param_1[1] = 0x1020000;
      }
    }
    if (*(char *)((int)param_1 + 0x207) == '\0') {
      param_1[1] = 0x1010000;
      *(undefined1 *)((int)param_1 + 0x2b6) = 0xf;
    }
  }
  func_0x80032b5c(param_1,0);
  FUN_801695d0(param_1,&local_38);
  uVar5 = param_1[0x8d];
  *(undefined4 *)(uVar5 + 0xd70) = local_38;
  *(undefined4 *)(uVar5 + 0xd74) = local_34;
  *(undefined4 *)(uVar5 + 0xd78) = local_30;
  *(undefined4 *)(uVar5 + 0xd7c) = local_2c;
  *(undefined4 *)(uVar5 + 0xd80) = local_28;
  *(int *)(uVar5 + 0xd84) = local_24;
  *(int *)(uVar5 + 0xd88) = local_20;
  *(int *)(uVar5 + 0xd8c) = local_1c;
  if ((*(uint *)param_1[0x85] & 0x30000) == 0) {
LAB_80163a0c:
    if (*(char *)((int)param_1 + 0x207) != '\0') goto LAB_80163a18;
LAB_80163a94:
    if ((*(uint *)param_1[0x85] & 0x30000) != 0) {
      return;
    }
  }
  else {
    if (*(char *)((int)param_1 + 0x207) == '\0') {
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
      local_48 = 0;
      local_46 = 0;
      local_44 = 0;
      iVar2 = func_0x8003307c(&local_38,&DAT_800e1158,800,&local_48);
      if ((iVar2 != 0) && (DAT_800e139f == 0)) {
        DAT_800e139f = 0x80;
        DAT_800e138c = DAT_800e138c | 0x12;
        _DAT_800e1354 = param_1[0x89];
        _DAT_800e1358 = param_1[0x8a];
        _DAT_800e1134 = 0x5000000;
        _DAT_800e1380 = param_1;
        *(undefined1 *)((int)param_1 + 0x207) = 1;
        *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) & 0xfffe;
        func_0x80077d18(8,param_1);
        func_0x80052bd0(2,0);
        func_0x80052c6c(0xf,0x78,0);
      }
      goto LAB_80163a0c;
    }
LAB_80163a18:
    if ((*(uint *)param_1[0x85] & 0x30000) != 0) {
      _DAT_800e1158 = local_24;
      _DAT_800e1160 = local_1c;
      if ((*(byte *)((int)param_1 + 0x1e9) & 3) == 0) {
        func_0x80037780(0x30b17d0,(int)*(short *)((int)param_1 + 0x66),_DAT_800e1364 + 0x618,0);
        func_0x80037780(0x30b17d0,(int)*(short *)((int)param_1 + 0x66),_DAT_800e1364 + 0xa80,0);
      }
      goto LAB_80163a94;
    }
  }
  if ((*(char *)((int)param_1 + 0x207) != '\0') && (*(char *)((int)param_1 + 0x206) == '\0')) {
    DAT_800e139f = DAT_800e139f & 0x7f;
    *param_1 = *param_1 & 0xffffefff;
    _DAT_800e1134 = 0x1000000;
    _DAT_800e1130 = _DAT_800e1130 & 0xffffefff;
  }
  if (((*(uint *)param_1[0x85] & 0x30000) == 0) && (*(char *)((int)param_1 + 0x207) != '\0')) {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
  }
switchD_801637b0_default:
  return;
}
