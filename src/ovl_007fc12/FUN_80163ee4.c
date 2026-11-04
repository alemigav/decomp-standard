/* FUN_80163ee4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80163ee4  body 0x80163ee4..0x80164827  size 2372 B
 * body sha256 5149000903249c67cf27cbb583c9a1a7a3d5ab0bf321bdfe55409818e4949873
 * provider record sha256 2318ba43498d1b1d2f1235ddd1d5df904b8c4032f68f4d4bd9d66cfc45c51a2c
 * callees 15 direct (15 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163ee4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  uint uVar3;
  char cVar5;
  uint uVar4;
  byte bVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  byte local_58 [8];
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  char local_28 [8];
  
  local_58[0] = 0xb;
  local_58[1] = 0xb;
  local_58[2] = 0xe;
  local_58[3] = 0xe;
  local_58[4] = 0xb;
  local_58[5] = 0xb;
  local_58[6] = 0xe;
  local_58[7] = 0xe;
  builtin_strncpy(local_28,"\x10\x14\x01\x05\x10\x1e\x01\n",8);
  uVar10 = *(ushort *)((int)param_1 + 0x1aa) & 1;
  if ((*(char *)(param_1 + 2) == '\x17') || (*(char *)(param_1 + 2) == '\x11')) {
    uVar10 = uVar10 + 2;
  }
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    bVar6 = local_58[uVar10 * 2];
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x7a] = (uint)bVar6 * 0x1000000 + 0xf00;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x800);
    _DAT_800e1380 = param_1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    bVar6 = func_0x80033144(param_1,&DAT_800e1130);
    _DAT_800e1134 = (uint)bVar6 << 0x10 | 0x5000000;
    if ((uVar10 & 1) != 0) {
      _DAT_800e1134 = CONCAT13(5,(uint3)(byte)(bVar6 + 2) << 0x10);
    }
    _DAT_800e1354 = param_1[0x89];
    _DAT_800e1358 = param_1[0x8a];
    DAT_800e139f = DAT_800e139f | 0x80;
    *(undefined1 *)((int)param_1 + 0x26f) = 0xf;
    *param_1 = *param_1 | 0x1000;
    _DAT_800e1130 = _DAT_800e1130 | 0x1000;
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      uVar10 = func_0x80033604(0x14);
      uVar8 = 0xb;
      if ((uVar10 & 1) != 0) {
        uVar8 = 10;
      }
      func_0x80077d18(uVar8,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
    func_0x80052d10(0x14,0,0xfa,0);
  case 1:
    func_0x8003331c(param_1,param_2,param_3,0);
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    break;
  case 2:
    bVar6 = local_58[uVar10 * 2];
    *(undefined1 *)((int)param_1 + 6) = 3;
    *(undefined2 *)(param_1 + 0x7d) = 0x94;
    param_1[0x7a] = (bVar6 + 1) * 0x1000000;
  case 3:
    func_0x8003331c(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    iVar9 = func_0x800331b8();
    iVar9 = (uint)*(ushort *)(param_1 + 0x7d) - (iVar9 * 5 + 2);
    *(short *)(param_1 + 0x7d) = (short)iVar9;
    if (iVar9 * 0x10000 < 0) {
      *(undefined1 *)((int)param_1 + 6) = 4;
      _DAT_800e1136 = CONCAT11(4,(undefined1)DAT_800e1134_1);
    }
    if (*(char *)((int)param_1 + 0x1e9) == local_28[uVar10 * 2]) {
      func_0x80052c6c(6,0xfa,0);
      func_0x80052bd0(10,0);
      func_0x80052c6c(4,0xfa,0xf);
      func_0x80052bd0(4,0xd);
      func_0x80077d18(3,param_1);
      uVar10 = func_0x80059e00(local_28[uVar10 * 2 + 1],uVar10 & 1);
      if ((uVar10 & 1) != 0) {
        *(undefined1 *)((int)param_1 + 6) = 4;
        _DAT_800e1136 = CONCAT11(4,(undefined1)DAT_800e1134_1);
        DAT_800e1336 = 1;
      }
      if ((uVar10 & 2) != 0) {
        param_1[1] = 0x1060000;
        uVar10 = func_0x80033144(param_1,&DAT_800e1130);
        _DAT_800e1134 = (uVar10 & 0xff) << 0x10 | 0x6000000;
        _DAT_800e10ec = _DAT_800e10ec | 0x100;
      }
    }
    break;
  case 4:
    bVar6 = local_58[uVar10 * 2];
    *(undefined1 *)((int)param_1 + 6) = 5;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    param_1[0x7a] = (bVar6 + 2) * 0x1000000 + 0x700;
    func_0x80052c6c(4,0xfa,10);
  case 5:
    if ((((DAT_800e9012 & 8) != 0) && ((*(ushort *)((int)param_1 + 0x2b6) & 0x60) == 0)) &&
       ((*(char *)((int)param_1 + 0x1e9) == '\x03' && ((uVar10 & 1) == 0)))) {
      uVar4 = func_0x80033604(param_1,param_2,param_3);
      uVar3 = func_0x80033604();
      if (((int)(uVar4 & 0xff) >> (uVar3 & 3) & 0xfU) == 0) {
        *(undefined1 *)(param_1 + 0xb6) = 1;
        uVar7 = func_0x80033144(param_1,&DAT_800e1130);
        *(undefined1 *)((int)param_1 + 0x2d9) = uVar7;
        bVar6 = func_0x80033604();
        *(byte *)((int)param_1 + 0x2d9) = *(byte *)((int)param_1 + 0x2d9) | bVar6 & 2;
        uVar2 = *(ushort *)((int)param_1 + 0x2b6);
        *(ushort *)((int)param_1 + 0x2b6) = uVar2 | 0x40;
        if ((*(byte *)((int)param_1 + 0x2d9) & 2) != 0) {
          *(ushort *)((int)param_1 + 0x2b6) = uVar2 & 0xffbf | 0x20;
        }
      }
    }
    func_0x8003331c(param_1,param_2,param_3,0);
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    if ((uVar10 & 1) != 0) {
      if (((((DAT_800e1138 & 1) == 0) && (DAT_800e1138 < 0xc)) || (DAT_800e1138 == 0xc)) ||
         (DAT_800e1138 == 0xd)) {
        if (*(char *)((int)param_1 + 0x1e9) == '\x16') {
          uVar3 = param_1[0x8d];
          uVar4 = *(uint *)(uVar3 + 0xbc0);
          if ((DAT_800e9012 & 8) != 0) {
            uVar4 = uVar4 | 0x4a;
          }
          *(uint *)(uVar3 + 0xbc0) = uVar4;
          uVar1 = *(undefined2 *)((int)param_1 + 0x66);
          *(undefined2 *)(uVar3 + 0xcf8) = 0;
          *(undefined2 *)(uVar3 + 0xcf4) = 0;
          *(undefined2 *)(uVar3 + 0xcf2) = 0;
          *(undefined2 *)(uVar3 + 0xcf6) = 0;
          *(undefined2 *)(uVar3 + 0xcfc) = 0;
          *(undefined4 *)(uVar3 + 0xc20) = 0x101040;
          *(undefined2 *)(uVar3 + 0xcf0) = uVar1;
          local_50 = 0;
          local_4e = 0xfda8;
          local_4c = 0;
          func_0x80037780(0x8001000,(int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0x38,
                          &local_50);
          uVar8 = 2;
          goto LAB_801644e4;
        }
      }
      else if (*(char *)((int)param_1 + 0x1e9) == '\x1b') {
        uVar8 = 8;
        if ((DAT_800e9012 & 8) != 0) {
          *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x80;
        }
LAB_801644e4:
        func_0x80077d18(uVar8,param_1);
        func_0x80052c6c(4,0xfa,0);
      }
      if ((*(byte *)((int)param_1 + 0x1e9) - 0x17 < 0x13) &&
         ((*(byte *)((int)param_1 + 0x1e9) & 1) != 0)) {
        uVar3 = param_1[0x8d];
        local_50 = 0;
        local_4e = 100;
        local_4c = 0;
        uVar4 = func_0x80033604();
        func_0x80037780(0x1000,(int)(((uint)*(ushort *)((int)param_1 + 0x66) + (uVar4 & 0xff) * 4 +
                                     -0x200) * 0x10000) >> 0x10,uVar3 + 0xbf8,&local_50);
      }
      if ((uVar10 & 1) != 0) {
        return;
      }
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\a') {
      *(undefined1 *)((int)param_1 + 6) = 7;
    }
    break;
  case 6:
    param_1[1] = 0x7000000;
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb;
    *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    break;
  case 7:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)((int)param_1 + 6) = 8;
  case 8:
    func_0x800334c8(param_1,param_2,param_3,0);
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + -0x1e;
    func_0x80032b5c(param_1,0);
    uVar10 = func_0x80033604();
    uVar4 = func_0x80033604();
    if ((((int)(uVar10 & 0xff) >> (uVar4 & 3) & 0xfU) == 2) ||
       (*(char *)((int)param_1 + 0x1e9) != '\x16')) {
      if ((((*(byte *)((int)param_1 + 0x1e9) - 7 < 0x12) &&
           (((*(char *)((int)param_1 + 0xd) != -1 &&
             (iVar9 = *(int *)((uint)*(byte *)((int)param_1 + 0xd) * 4 + -0x7ff1ec18),
             (*(byte *)(iVar9 + 8) & 0x10) != 0)) && (-1 < *(short *)(iVar9 + 0x1f2))))) &&
          ((((*(ushort *)(iVar9 + 0x1aa) & 1) == 0 && (*(char *)(iVar9 + 0x26f) == '\0')) &&
           ((*(ushort *)(iVar9 + 0x2b6) & 8) == 0)))) &&
         ((*(ushort *)(iVar9 + 0x1aa) & 0x2000) == 0)) {
        *(undefined4 *)(iVar9 + 4) = 0x1090000;
        uVar7 = func_0x80033144(param_1,iVar9);
        *(undefined1 *)(iVar9 + 0x207) = uVar7;
        func_0x80077d18(4,param_1);
      }
    }
    else {
      param_1[1] = 0x1050000;
      bVar6 = func_0x80033604();
      *(byte *)((int)param_1 + 0x2bf) = (bVar6 & 0xf) + 0x10;
      *(undefined1 *)((int)param_1 + 0x206) = 1;
      *(undefined1 *)((int)param_1 + 6) = 1;
      *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfff7;
      param_1[0x7a] = (*(char *)((int)param_1 + 0x206) * 10 + 10) * 0x10000 + 0x2000a00;
      *(undefined1 *)((int)param_1 + 0x2be) = 0;
      *(undefined1 *)((int)param_1 + 0x207) = 0;
      *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
      uVar2 = *(ushort *)((int)param_1 + 0x2b6);
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
      *(ushort *)((int)param_1 + 0x2b6) = uVar2 | 4;
      *(ushort *)((int)param_1 + 0x2b6) = uVar2 | 0x206;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
      uVar10 = func_0x80033604();
      uVar8 = 0xd;
      if ((uVar10 & 1) != 0) {
        uVar8 = 0xc;
      }
      func_0x80077d18(uVar8,param_1);
      *(undefined2 *)(param_1 + 0x7d) = 1;
    }
    break;
  case 9:
    param_1[1] = 0x1000000;
  }
  return;
}
