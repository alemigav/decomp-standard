/* FUN_80164e10
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164e10  body 0x80164e10..0x80165757  size 2376 B
 * body sha256 0e6c2e5339e537cead232ed1bb06d271572e33dcac398ecdb7b7d56234fe4f49
 * provider record sha256 c9b9aea1d0c71f064acb4682b15c7d7e12c2c0f592b317476df7cd44a0e7694a
 * callees 18 direct (18 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164e10(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar3 = _DAT_800e1364;
  puVar4 = (undefined4 *)param_1[0x8d];
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[10] = 0xffffc72d;
    param_1[0xc] = 0xffffc6d4;
    *(undefined2 *)((int)param_1 + 0x66) = 0x598;
    param_1[0x7a] = 0x50a0000;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    *param_1 = *param_1 | 10;
    *(undefined2 *)(param_1 + 0xb3) = *(undefined2 *)((int)param_1 + 0x2a);
    *(undefined2 *)((int)param_1 + 0x2ce) = *(undefined2 *)((int)param_1 + 0x32);
    *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) | 4;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80089d54(param_1,param_2,param_3,0x1000);
    DAT_801666a4 = _DAT_800e1196;
    DAT_801666a0 = _DAT_800e115a;
    DAT_801666a2 = _DAT_800e1162;
    _DAT_800e90f8 = 1;
    _DAT_800e1158 = -0x4a51;
    _DAT_800e115c = 200;
    _DAT_800e1160 = -0x517d;
    _DAT_800e1196 = 0x1151;
    _DAT_800e1110 = _DAT_800e1110 | 0x81000000;
    _DAT_800e110c = _DAT_800e110c | 0x110;
    DAT_801666a6 = _DAT_800e8cac;
    func_0x80083c14(0xb);
    DAT_800e9183 = 1;
    *(undefined2 *)((int)param_1 + 0x272) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
switchD_80164e68_caseD_1:
    if (*(short *)((int)param_1 + 0x1f6) == 0) {
      _DAT_800df914 = _DAT_800df914 | 0x140;
      *(undefined1 *)((int)param_1 + 0x206) = 1;
    }
    else {
      _DAT_800df914 = _DAT_800df914 | 0x100;
    }
    if (*(char *)((int)param_1 + 0x206) == '\b') {
      func_0x80038e98(2,0xd,0);
    }
    if ('\0' < *(char *)((int)param_1 + 0x206)) {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + '\x01';
    }
    sVar2 = *(short *)((int)param_1 + 0x272);
    if (sVar2 == 2) {
      *(undefined2 *)((int)param_1 + 0x1f6) = 1;
      _DAT_800e1110 = _DAT_800e1110 & 0x7fffffff;
      sVar2 = *(short *)((int)param_1 + 0x272);
    }
    if (sVar2 == 3) {
      _DAT_800e1110 = _DAT_800e1110 | 0x80000000;
      func_0x80083c14(8);
      DAT_800e9183 = 1;
      _DAT_800e1130 = _DAT_800e1130 | 0x80400;
      FUN_801630b0(param_1,10000);
      *(undefined2 *)(param_1 + 0x7d) = 0;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
switchD_80164e68_caseD_2:
      local_20 = 600;
      local_1c = 400;
      local_1e = 0;
      sVar2 = *(short *)(param_1 + 0x7d);
      if (sVar2 == 1) {
        func_0x800385a4(0x20d1000,0x80,iVar3 + 0x1060,&local_20);
        func_0x80077adc(0x1000001,&DAT_800e1158);
        sVar2 = *(short *)(param_1 + 0x7d);
      }
      if (sVar2 == 0xf) {
        _DAT_800e1110 = _DAT_800e1110 | 0x10000000;
      }
      sVar2 = *(short *)(param_1 + 0x7d);
      *(short *)(param_1 + 0x7d) = sVar2 + 1;
      if ((short)(sVar2 + 1) == 0x28) {
LAB_80165730:
        cVar1 = *(char *)((int)param_1 + 6);
LAB_80165734:
        *(char *)((int)param_1 + 6) = cVar1 + '\x01';
      }
    }
switchD_80164e68_default:
    return;
  case 1:
    goto switchD_80164e68_caseD_1;
  case 2:
    goto switchD_80164e68_caseD_2;
  case 3:
    _DAT_800e1110 = _DAT_800e1110 & 0xefffffff;
    func_0x80038e98(3,10,0);
    func_0x80038f40(0x80);
    func_0x80083c14(9);
    DAT_800e9183 = 1;
    FUN_801630b0(param_1,5000);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 4:
    local_20 = 600;
    local_1c = 400;
    local_1e = 0;
    sVar2 = *(short *)(param_1 + 0x7d);
    if (sVar2 == 1) {
      func_0x800385a4(0x20d1000,0x81,iVar3 + 0x1060,&local_20);
      func_0x80077adc(0x1000001,&DAT_800e1158);
      sVar2 = *(short *)(param_1 + 0x7d);
    }
    if (sVar2 == 7) {
      _DAT_800e1110 = _DAT_800e1110 | 0x10000000;
    }
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + 1;
    if ((short)(sVar2 + 1) != 0x20) {
      return;
    }
    goto LAB_80165730;
  case 5:
    _DAT_800e1110 = _DAT_800e1110 & 0xefffffff;
    func_0x80038e98(3,10,0);
    func_0x80038f40(0x81);
    func_0x80083c14(10);
    DAT_800e9183 = 1;
    FUN_801630b0(param_1,3000);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 6:
    local_20 = 600;
    local_1c = 400;
    local_1e = 0;
    if (*(short *)(param_1 + 0x7d) == 1) {
      func_0x800385a4(0x270a1000,0x82,iVar3 + 0x1060,&local_20);
      func_0x80077adc(0x1000001,&DAT_800e1158);
    }
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + 1;
    if ((short)(sVar2 + 1) == 10) {
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      func_0x80038f40(0x82);
      func_0x80052bd0(6,3);
      func_0x80052d10(0x3c,0xfa,0,0);
      return;
    }
    return;
  case 7:
    func_0x80038f40(0x82);
    DAT_800e9182 = 5;
    _DAT_800e110c = _DAT_800e110c | 4;
    local_20 = *(short *)((int)param_1 + 0x2a);
    *param_1 = *param_1 | 0x400;
    local_1e = -0x708;
    local_1c = *(short *)((int)param_1 + 0x32);
    func_0x80037780(0x31f5000,0,0x800e9028,&local_20);
    func_0x80077adc(0x10a0001,param_1 + 10);
    func_0x80077adc(0x20f0001,param_1 + 10);
    func_0x80038f40(0x90);
    func_0x80038f40(0x91);
    func_0x80038f40(0x92);
    func_0x80038f40(0x93);
    func_0x80038f40(0x94);
    func_0x80038f40(0x95);
    func_0x80038f40(0x96);
    func_0x80038f40(0x97);
    func_0x80038f40(0x98);
    func_0x80038f40(0x99);
    func_0x80038f40(0x9a);
    func_0x80038f40(0x9b);
    func_0x80038f40(0x9c);
    func_0x80038f40(0x9d);
    func_0x80038f40(0x9e);
    func_0x80004a6c(0,3);
    _DAT_800e110c = _DAT_800e110c | 0x20;
    entry();
    FUN_80162f84(param_1,0);
    FUN_80162f84(param_1,3);
    FUN_80162f84(param_1,5);
    FUN_80162f84(param_1,7);
    FUN_80162f84(param_1,0xd);
    FUN_80162f84(param_1,0x14);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 8:
    FUN_80161e28(param_1);
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + 1;
    if (sVar2 < 0xe) {
      cVar1 = func_0x80033604();
      local_20 = *(short *)((int)param_1 + 0x2a) + cVar1 * 0x14;
      cVar1 = func_0x80033604();
      local_1e = cVar1 * 0x14 + -0x9c4;
      cVar1 = func_0x80033604();
      local_1c = *(short *)((int)param_1 + 0x32) + cVar1 * 0x14;
      func_0x80037780(0x31f5000,0,0x800e9028,&local_20);
    }
    if (*(short *)(param_1 + 0x7d) == 0x10) {
      _DAT_800e110c = _DAT_800e110c & 0xfffffffb;
      *puVar4 = 0;
      puVar4[0x11a] = 0;
      puVar4[0x1d6] = 0;
      puVar4[0x292] = 0;
      puVar4[0x4c6] = 0;
      puVar4[0x758] = 0;
      FUN_80162140(param_1);
    }
    if ((_DAT_800e110c & 0x20) != 0) {
      return;
    }
    func_0x80035b84(param_1);
    _DAT_800e1158 = (int)DAT_801666a0;
    _DAT_800e1160 = (int)DAT_801666a2;
    _DAT_800e115c = 0;
    _DAT_800e1196 = DAT_801666a4;
    cVar1 = *(char *)((int)param_1 + 6);
    *(undefined1 *)((int)param_1 + 0x2d2) = 0;
    goto LAB_80165734;
  case 9:
    if (*(short *)((int)param_1 + 0x272) != 4) {
      return;
    }
    DAT_800e9182 = 2;
    FUN_801621e8(param_1,(int)*(short *)(param_1 + 0xb3),(int)*(short *)((int)param_1 + 0x2ce));
    iVar3 = (int)DAT_801666a6;
    param_1[10] = (int)*(short *)(param_1 + 0xb3);
    param_1[0xc] = (int)*(short *)((int)param_1 + 0x2ce);
    func_0x80083c14(iVar3);
    DAT_800e9183 = 1;
    _DAT_800e1110 = _DAT_800e1110 & 0x7effffff;
    _DAT_800e1130 = _DAT_800e1130 & 0xfff7fbff;
    goto LAB_80165730;
  default:
    goto switchD_80164e68_default;
  }
}
