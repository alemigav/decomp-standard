/* FUN_80162f14
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80162f14  body 0x80162f14..0x80163d9f  size 3724 B
 * body sha256 e23df7f036fa169d68f493667f887b8c937d3f227be875734b946eb3234049b3
 * provider record sha256 7d691d0fd397b62aa070ac40c4ef2816144ed31c85d9a90a3a5ea5b7299495b9
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8016374c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162f14(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint3 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar6;
  char cVar9;
  byte bVar10;
  ushort uVar7;
  ushort uVar8;
  uint uVar4;
  uint uVar5;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_20 [2];
  
  local_20[0] = 0x80a0b;
  if (*(byte *)((int)param_1 + 6) < 9) {
    if ((_DAT_800e1128 & 1) != 0) {
      *(undefined1 *)((int)param_1 + 6) = 9;
    }
    if ((*(byte *)((int)param_1 + 6) < 9) && ((DAT_800e139f & 0x80) != 0)) {
      *(undefined1 *)((int)param_1 + 6) = 9;
    }
  }
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x7000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    sVar6 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,
                            (int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32));
    *(short *)(param_1 + 0xb1) = sVar6;
    *(ushort *)(param_1 + 0xb1) = sVar6 - _DAT_800e1196 & 0xfff;
    uVar7 = func_0x80033604();
    *(ushort *)(param_1 + 0x7d) = (uVar7 & 1) * -0x80 + 0x40;
    uVar7 = func_0x80033604();
    *(ushort *)((int)param_1 + 0x2c6) = (uVar7 & 0x3f) + 0x186;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xfffe;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80052c6c(8,0x50,0);
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    FUN_80164980(param_1,300,
                 (int)(((uint)*(ushort *)(param_1 + 0xb1) + (uint)_DAT_800e1196) * 0x10000) >> 0x10)
    ;
    *(short *)(param_1 + 0xb1) = *(short *)(param_1 + 0xb1) + *(short *)(param_1 + 0x7d);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
    uVar4 = param_1[0xb];
    param_1[0xb] = uVar4 - 0x96;
    uVar4 = *(int *)(_DAT_800e1364 + 0x50) - (uVar4 - 0x1c2);
    if ((int)uVar4 < 0) {
      uVar4 = -uVar4;
    }
    if ((uVar4 & 0xffff) < 300) {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
    break;
  case 2:
    *(undefined1 *)((int)param_1 + 6) = 3;
    uVar7 = func_0x80033604();
    *(ushort *)(param_1 + 0x7d) = (uVar7 & 0x1f) + 0x3c;
    *(undefined2 *)((int)param_1 + 0x1f6) = 4;
    *(undefined1 *)((int)param_1 + 0x206) = 7;
    *(undefined1 *)((int)param_1 + 0x207) = 8;
  case 3:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    FUN_80164980(param_1,300,
                 (int)(((uint)*(ushort *)(param_1 + 0xb1) + (uint)_DAT_800e1196) * 0x10000) >> 0x10)
    ;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
    sVar6 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar6 + -1;
    if ((short)(sVar6 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 4;
    }
    *(short *)(param_1 + 0xb1) = *(short *)(param_1 + 0xb1) + *(short *)((int)param_1 + 0x1f6);
    param_1[0xb] = param_1[0xb] - 3;
    *(short *)((int)param_1 + 0x1f6) =
         *(short *)((int)param_1 + 0x1f6) + (short)*(char *)((int)param_1 + 0x207);
    cVar9 = *(char *)((int)param_1 + 0x206) + -1;
    *(char *)((int)param_1 + 0x206) = cVar9;
    if (cVar9 == -1) {
      *(undefined1 *)((int)param_1 + 0x206) = 0xf;
      *(char *)((int)param_1 + 0x207) = -*(char *)((int)param_1 + 0x207);
    }
    goto LAB_8016340c;
  case 4:
    uVar7 = func_0x80033604();
    *(ushort *)(param_1 + 0x7d) = (uVar7 & 0xf) + 0xf;
    *(undefined1 *)((int)param_1 + 6) = 5;
    uVar4 = func_0x80033604();
    if ((uVar4 & 1) != 0) {
      func_0x80077d18(1,param_1);
    }
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    func_0x80052c6c(8,100,0);
  case 5:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    sVar6 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar6 + -1;
    if ((short)(sVar6 + -1) == -1) {
      if (DAT_800e1134 != '\x05') {
        _DAT_800e1135 = _DAT_800e1135 & 0xffff;
        uVar1 = _DAT_800e1135;
        _DAT_800e1134 = CONCAT13(5,_DAT_800e1135);
        DAT_800e1134_1._2_1_ = (byte)uVar1;
        _DAT_800e1136 = (ushort)(byte)DAT_800e1134_1;
      }
      _DAT_800e1354 = param_1[0x89];
      _DAT_800e1358 = param_1[0x8a];
      _DAT_800e1380 = param_1;
      *(undefined1 *)((int)param_1 + 0x207) = 0x84;
    }
    bVar10 = *(char *)((int)param_1 + 0x207) - 1;
    if ((((int)*(char *)((int)param_1 + 0x207) & 0x80U) != 0) &&
       (*(byte *)((int)param_1 + 0x207) = bVar10, (bVar10 & 0x7f) == 0)) {
      *(undefined1 *)((int)param_1 + 6) = 6;
    }
    goto LAB_801633dc;
  case 6:
    *(undefined2 *)((int)param_1 + 0x1f6) = 0x140;
    uVar7 = 0x340U - *(short *)(param_1 + 0xb1) & 0xfff;
    if (uVar7 < 0x280) {
      *(undefined2 *)((int)param_1 + 0x1f6) = 0;
      *(undefined2 *)(param_1 + 0xb1) = 0x200;
    }
    sVar6 = *(short *)(param_1 + 0xb1) - *(short *)((int)param_1 + 0x1f6);
    *(short *)(param_1 + 0xb1) = sVar6;
    if (uVar7 < 0x801) {
      *(short *)(param_1 + 0xb1) = sVar6 + *(short *)((int)param_1 + 0x1f6) * 2;
    }
    uVar4 = param_1[0xb];
    param_1[0xb] = uVar4 - 200;
    uVar4 = *(int *)(_DAT_800e1364 + 0xc10) - (uVar4 - 200);
    if ((int)uVar4 < 0) {
      uVar4 = -uVar4;
    }
    if ((uVar4 & 0xffff) < 200) {
      *(undefined1 *)((int)param_1 + 6) = 7;
    }
LAB_801633dc:
    FUN_80164980(param_1,300,
                 (int)(((uint)*(ushort *)(param_1 + 0xb1) + (uint)_DAT_800e1196) * 0x10000) >> 0x10)
    ;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
LAB_8016340c:
    iVar13 = FUN_80163da0();
    iVar13 = (uint)*(ushort *)((int)param_1 + 0x2c6) + iVar13 * -0x10;
    *(short *)((int)param_1 + 0x2c6) = (short)iVar13;
    if (iVar13 * 0x10000 < 0) {
      *(undefined1 *)((int)param_1 + 6) = 9;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
    }
    break;
  case 7:
    param_1[0x7a] = 0x8000700;
    *(undefined1 *)((int)param_1 + 6) = 8;
    uVar7 = func_0x80033604();
    *(ushort *)(param_1 + 0x7d) = (uVar7 & 0xf) + 0x2d;
    uVar7 = *(short *)((int)param_1 + 0x1f2) - 1;
    *(ushort *)((int)param_1 + 0x1f2) = uVar7;
    if ((int)((uint)uVar7 << 0x10) < 0) {
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 1;
    }
    iVar13 = func_0x80059e00(10,0);
    if (iVar13 == 2) {
      *(undefined1 *)((int)param_1 + 6) = 0xb;
      _DAT_800e10ec = _DAT_800e10ec | 0x100;
      DAT_800e139f = DAT_800e139f | 0x80;
      return;
    }
    goto LAB_801634dc;
  case 8:
LAB_801634dc:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    uVar3 = _DAT_800e1160;
    uVar2 = _DAT_800e1158;
    _DAT_800e1158 = *(undefined4 *)(_DAT_800e1364 + 0xc0c);
    _DAT_800e1160 = *(undefined4 *)(_DAT_800e1364 + 0xc14);
    FUN_80164980(param_1,0x15e,
                 (int)(((uint)*(ushort *)(param_1 + 0xb1) + (uint)_DAT_800e1196) * 0x10000) >> 0x10)
    ;
    _DAT_800e1158 = uVar2;
    _DAT_800e1160 = uVar3;
    func_0x80032dbc(param_1,uVar2,uVar3,0x400);
    sVar6 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar6 + -1;
    if ((short)(sVar6 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 9;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
    }
    if (((*(ushort *)(param_1 + 0x7d) & 3) == 0) && (10 < (short)*(ushort *)(param_1 + 0x7d))) {
      uVar12 = param_1[0x8d];
      local_48 = 100;
      local_46 = 200;
      local_44 = 0;
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 2 + 0x5f4 | 0x10000,
                      (int)(((uint)*(ushort *)((int)param_1 + 0x66) - ((uVar5 & 0xff) * 4 + -0xa00))
                           * 0x10000) >> 0x10,uVar12 + 0x4a0,&local_48);
    }
    if ((param_1[0x7d] & 0x70000) == 0) {
      uVar4 = func_0x80033604();
      func_0x80077d18(*(undefined1 *)((int)local_20 + (uVar4 & 3)),param_1);
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      func_0x80052bd0((uVar4 & 1) + 1,uVar5 & 3);
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      func_0x80052c6c((uVar4 & 3) + 2,0x96,uVar5 & 3);
      return;
    }
    return;
  case 9:
    *(undefined2 *)((int)param_1 + 0x1e2) = 100;
    *(undefined2 *)(param_1 + 0x78) = 0x78;
    *(undefined1 *)((int)param_1 + 6) = 10;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    param_1[0x7a] = 0x3000000;
    uVar7 = func_0x80033604();
    *(ushort *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x900 + (uVar7 & 0xff) * -2
    ;
    if ((param_1[0xb2] & 0x10000) != 0) {
      uVar8 = func_0x80033604();
      uVar7 = _DAT_800e1196;
      *(undefined2 *)((int)param_1 + 0x1e2) = 300;
      *(undefined2 *)(param_1 + 0x78) = 200;
      *(ushort *)((int)param_1 + 0x66) = uVar7 - ((uVar8 & 0xff) * 2 + 0x100);
    }
    if ((DAT_800e139f & 0x80) == 0) {
      if (DAT_800e1134 == '\x05') {
        _DAT_800e1136 = CONCAT11(2,(byte)DAT_800e1134_1);
      }
      else {
        _DAT_800e1135 = _DAT_800e1135 & 0xffff;
        uVar1 = _DAT_800e1135;
        _DAT_800e1134 = CONCAT13(5,_DAT_800e1135);
        DAT_800e1134_1._2_1_ = (byte)uVar1;
        _DAT_800e1136 = CONCAT11(2,(byte)DAT_800e1134_1);
        _DAT_800e1354 = param_1[0x89];
        _DAT_800e1358 = param_1[0x8a];
        _DAT_800e1380 = param_1;
      }
    }
    _DAT_800e1128 = _DAT_800e1128 | 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
  case 10:
    if (*(char *)((int)param_1 + 0x1e9) == '\x01') {
      _DAT_800e1128 = _DAT_800e1128 & 0xfffe;
    }
    func_0x80089d54(param_1,param_2,param_3,0x200);
    func_0x80032bd8(param_1,0,0);
    *(short *)((int)param_1 + 0x1e2) =
         *(short *)((int)param_1 + 0x1e2) + *(short *)(param_1 + 0x7d) * 0xf;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 1;
    if ((int)param_1[0xb] <= (int)*(short *)((int)param_1 + 0x25e)) {
      return;
    }
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    param_1[1] = 0x1010000;
    if ((param_1[0xb2] & 0x10000) == 0) {
      return;
    }
    param_1[1] = 0x3010000;
    *(undefined1 *)((int)param_1 + 0x26e) = 0;
    return;
  case 0xb:
    param_1[0x7a] = 0xf000f00;
    *(undefined1 *)((int)param_1 + 6) = 0xc;
    *(undefined2 *)(param_1 + 0x7d) = 0x78;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0xfa;
    _DAT_800e1322 = 0xffff;
    _DAT_800e1136 = CONCAT11(4,(byte)DAT_800e1134_1);
    DAT_800e139f = DAT_800e139f | 0x80;
    param_1[0xb] = param_1[0xb] - 100;
    *(uint *)(param_1[0x8d] + 0x2f0) = *(uint *)(param_1[0x8d] + 0x2f0) | 0x4000;
    *(uint *)(param_1[0x8d] + 0x468) = *(uint *)(param_1[0x8d] + 0x468) | 0x4000;
    *(undefined2 *)((int)param_1 + 0x212) = 0x1000;
    *param_1 = *param_1 | 0x800;
    func_0x80052bd0(2,0);
    func_0x80052c6c(3,0x96,0);
    func_0x80052bd0(1,3);
    func_0x80052c6c(2,0x96,5);
    func_0x80052bd0(2,7);
    func_0x80052c6c(4,0x96,9);
    func_0x80052bd0(3,0xc);
    func_0x80052c6c(2,0x96,0x10);
    func_0x80052bd0(2,0x12);
    func_0x80052c6c(4,0x96,0x14);
    func_0x80052bd0(1,0x16);
    func_0x80052c6c(3,0x96,0x1a);
    func_0x80052bd0(3,0x16);
    func_0x80052c6c(3,0x96,0x1f);
    func_0x80052bd0(3,0x1d);
    func_0x80052d10(0x14,200,100,0x25);
    func_0x80052bd0(2,0x25);
    func_0x80052bd0(3,0x29);
    func_0x80052bd0(3,0x30);
    func_0x80052bd0(2,0x37);
    func_0x80052c6c(0x50,0x8c,0x37);
    func_0x80052bd0(5,0x46);
    func_0x80052c6c(0xf,0xfa,0x4b);
    func_0x80052bd0(3,0x5a);
    func_0x80052c6c(10,0xfa,0x5f);
    func_0x80052d10(0x5a,200,0,0x87);
  case 0xc:
    *(short *)((int)param_1 + 0x212) = *(short *)((int)param_1 + 0x212) + -0xf;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    uVar3 = _DAT_800e1160;
    uVar2 = _DAT_800e1158;
    _DAT_800e1158 = *(undefined4 *)(_DAT_800e1364 + 0xc0c);
    _DAT_800e1160 = *(undefined4 *)(_DAT_800e1364 + 0xc14);
    FUN_80164980(param_1,(int)*(short *)((int)param_1 + 0x1f6),
                 (int)(((uint)*(ushort *)(param_1 + 0xb1) + (uint)_DAT_800e1196) * 0x10000) >> 0x10)
    ;
    _DAT_800e1158 = uVar2;
    _DAT_800e1160 = uVar3;
    func_0x80032dbc(param_1,uVar2,uVar3,0x400);
    sVar6 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar6 + -1;
    if ((short)(sVar6 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 0xd;
    }
    if ((param_1[0x7d] & 0x30000) == 0) {
      uVar12 = param_1[0x8d];
      local_48 = 100;
      local_46 = 200;
      local_44 = 0;
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      iVar13 = uVar12 + 0x4a0;
      func_0x80037780((uVar4 & 0xff) * 2 + 0xdc4 | 0x10000,
                      (int)(((uint)*(ushort *)((int)param_1 + 0x66) - ((uVar5 & 0xff) * 4 + -0xa00))
                           * 0x10000) >> 0x10,iVar13,&local_48);
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 2 + 0x5f4 | 0x10000,
                      (int)(((uint)*(ushort *)((int)param_1 + 0x66) - ((uVar5 & 0xff) * 4 + -0xa00))
                           * 0x10000) >> 0x10,iVar13,&local_48);
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 2 + 0x5f4 | 0x10000,
                      (int)(((uint)*(ushort *)((int)param_1 + 0x66) - ((uVar5 & 0xff) * 4 + -0xa00))
                           * 0x10000) >> 0x10,iVar13,&local_48);
      if (*(short *)(param_1 + 0x7d) < 0x1e) {
        uVar4 = func_0x80033604();
        uVar5 = func_0x80033604();
        func_0x80037780((uVar4 & 0xff) * 2 + 0x9dc | 0x30000,
                        (int)(((uint)*(ushort *)((int)param_1 + 0x66) -
                              ((uVar5 & 0xff) * 4 + -0xa00)) * 0x10000) >> 0x10,iVar13,&local_48);
      }
    }
    if ((param_1[0x7d] & 0x70000) == 0) {
      uVar4 = func_0x80033604();
      func_0x80077d18(*(undefined1 *)((int)local_20 + (uVar4 & 3)),param_1);
    }
    if (*(short *)(param_1 + 0x7d) == 0x3c) {
      _DAT_800e1136 = CONCAT11(6,(byte)DAT_800e1134_1);
      *(uint *)(param_1[0x8d] + 0x178) = *(uint *)(param_1[0x8d] + 0x178) | 0x4000;
      func_0x80077d18(4,param_1);
    }
    if (*(short *)(param_1 + 0x7d) < 0x3c) {
      *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + -2;
      param_1[0xb] = param_1[0xb] + 5;
    }
    if (*(short *)(param_1 + 0x7d) != 5) {
      return;
    }
    local_48 = 100;
    local_46 = 200;
    local_44 = 0;
    func_0x80037780(0x11f40,(int)((*(ushort *)((int)param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,
                    param_1[0x8d] + 0x4a0,&local_48);
    iVar13 = 10;
    puVar11 = (uint *)param_1[0x8d];
    do {
      iVar13 = iVar13 + -1;
      *puVar11 = *puVar11 | 0x4000;
      puVar11 = puVar11 + 0x5e;
    } while (iVar13 != 0);
    func_0x80077d18(4,param_1);
    return;
  case 0xd:
    *(undefined1 *)((int)param_1 + 6) = 0xe;
    _DAT_800e1134 = 0x5000800;
  }
  return;
}
