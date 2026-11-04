/* FUN_801625ac
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x801625ac  body 0x801625ac..0x80162b57  size 1452 B
 * body sha256 256f1b0cf3951a76c18bd1167113200baf26216f73f8ee3ac37430a1940cddc7
 * provider record sha256 1c63224c91ef8dff4e8430343d5c9891e7e2aad14a9921856abc6ad85c390a65
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801625ac(uint *param_1)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  undefined1 uVar5;
  int iVar4;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_78 [20];
  undefined4 local_64;
  undefined2 local_5e;
  undefined4 local_5c;
  undefined1 auStack_58 [20];
  int local_44;
  int local_40;
  int local_3c;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  uVar9 = param_1[0x8d];
  *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) | 8;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      func_0x80036b84(param_1,3,0,0);
      iVar8 = -0x6270 - param_1[0xc];
      iVar7 = -0x708 - param_1[0xb];
      iVar4 = func_0x80040bb4(iVar8 * iVar8 + iVar7 * iVar7);
      cVar6 = *(char *)((int)param_1 + 0x206) + '\x01';
      *(char *)((int)param_1 + 0x206) = cVar6;
      if (cVar6 == '\x10') {
        *(undefined1 *)((int)param_1 + 0x206) = 0;
        func_0x80077d18(3,param_1);
      }
      if (0x708 < iVar4) {
        if (((*(ushort *)((int)param_1 + 0x2ba) & 2) != 0) || (0x59 < *(short *)(param_1 + 0x7d))) {
          *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) & 0xfffd;
          FUN_801634c8(param_1);
          *(undefined4 *)(uVar9 + 0x2f0) = 0;
          *(undefined4 *)(uVar9 + 0x468) = 0;
          *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) & 0xfffe;
          DAT_80163b00 = DAT_80163b00 & ~(1 << (*(byte *)((int)param_1 + 0x2c2) & 0x1f));
          *param_1 = *param_1 & 0xffffdfff;
          param_1[1] = 0x1000000;
          return;
        }
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && (iVar8 * 0x708 == -0x80000000)) {
          trap(0x1800);
        }
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && (iVar7 * 0x708 == -0x80000000)) {
          trap(0x1800);
        }
        *(undefined2 *)((int)param_1 + 0x1e2) = 0;
        param_1[0xc] = -((iVar8 * 0x708) / iVar4) - 0x6270;
        param_1[0xb] = -((iVar7 * 0x708) / iVar4) - 0x708;
      }
      if (*(short *)(param_1 + 0x7d) < 0x5a) {
        *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 1;
      }
      iVar4 = _DAT_800e1364;
      iVar7 = (uint)*(byte *)((int)param_1 + 0x2c2) * 0xe;
      func_0x80040e58(&DAT_80163944 + iVar7,auStack_58);
      local_44 = (int)*(short *)(&DAT_8016393e + iVar7);
      local_40 = (int)*(short *)(&DAT_80163940 + iVar7);
      local_3c = (int)*(short *)(&DAT_80163942 + iVar7);
      func_0x800424ec(iVar4 + (uint)*(ushort *)(&DAT_8016393c + iVar7) * 0x178 + 0x38,auStack_58,
                      auStack_78);
      *(undefined2 *)(param_1 + 0xaf) = local_64._2_2_;
      *(undefined2 *)((int)param_1 + 0x2be) = local_5e;
      *(undefined2 *)(param_1 + 0xb0) = local_5c._2_2_;
      bVar3 = false;
      iVar4 = func_0x80040bb4((param_1[10] - local_64) * (param_1[10] - local_64) +
                              (param_1[0xc] - local_5c) * (param_1[0xc] - local_5c));
      if (iVar4 < 200) {
        iVar4 = param_1[0xb] - (int)*(short *)((int)param_1 + 0x2be);
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if (iVar4 < 200) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) & 0xfff7 | 2;
        DAT_80163b04 = DAT_80163b04 + 1;
        if (DAT_800e139f == '\0') {
          _DAT_800e1354 = param_1[0x89];
          _DAT_800e1358 = param_1[0x8a];
          _DAT_800e1134 = 0x5000000;
          _DAT_800e1380 = param_1;
          if (0xe1 < DAT_80163b0c) {
            _DAT_800e1134 = 0x3000000;
            _DAT_800e1322 = 0xffff;
            DAT_800e139f = -0x80;
            DAT_80163b08 = 1;
            _DAT_800e10ec = _DAT_800e10ec | 0x4000000;
          }
        }
        param_1[1] = 0x1030000;
        bVar3 = DAT_80163b10 < 0xa0;
        *param_1 = *param_1 & 0xffffdfff;
        if (bVar3) {
          func_0x80052bd0(4,0);
          func_0x80052d10(0xc,0x8c,0x32,1);
          return;
        }
        return;
      }
      if (((*(ushort *)((int)param_1 + 0x2ba) & 2) == 0) && (*(short *)(param_1 + 0x7d) < 0x5a)) {
        func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0xaf),(int)*(short *)(param_1 + 0xb0),0x40
                       );
        iVar4 = (int)*(short *)((int)param_1 + 0x2be) -
                (param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2));
        if (100 < iVar4) {
          iVar4 = 100;
        }
        if (iVar4 < -100) {
          iVar4 = -100;
        }
        *(short *)((int)param_1 + 0x1e2) = (short)iVar4;
      }
      else {
        *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 1;
      }
      param_1[0xb] = param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2);
      if (*(short *)(param_1 + 0x78) < 200) {
        sVar2 = *(short *)((int)param_1 + 0x1f6);
        *(short *)((int)param_1 + 0x1f6) = sVar2 + 1;
        *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + sVar2;
      }
      func_0x80032b5c(param_1,0);
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80077d18(3,param_1);
    *(undefined4 *)(uVar9 + 0x2f0) = 1;
    *(undefined4 *)(uVar9 + 0x468) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    uVar5 = FUN_8016358c();
    *(undefined1 *)((int)param_1 + 0x2c2) = uVar5;
    *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) | 1;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  iVar4 = func_0x80036b84(param_1,2,0,0);
  if (iVar4 != 0) {
    func_0x80036e70(param_1);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x800);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *param_1 = *param_1 | 0x2000;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  return;
}
