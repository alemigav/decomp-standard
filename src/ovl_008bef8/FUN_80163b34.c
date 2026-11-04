/* FUN_80163b34
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163b34  body 0x80163b34..0x80164073  size 1344 B
 * body sha256 6570a50c7aef6ca25fed61c252ae6369f3f8eab3e5bb9b39d3f93a0f01304e42
 * provider record sha256 c62eb282fb7d36445aa98f8010a8e2bf051d996ae349ce42abb8aaf6d5979482
 * callees 18 direct (16 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163b34(uint *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  undefined1 auStack_28 [16];
  
  uVar7 = param_1[0x8d];
  func_0x80082200(auStack_28,0,8);
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) & 0xfffb;
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
        return;
      }
      if (bVar1 == 3) {
        *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
        func_0x80083758(0x800e8d00,0x1e);
        *(undefined2 *)((int)param_1 + 0x2c6) = 0;
        *(undefined2 *)(param_1 + 0xb1) = 0;
        *(undefined1 *)(param_1 + 0xb0) = 0;
        _DAT_800e110c = _DAT_800e110c & 0xfffffeff;
        DAT_800e9182 = 2;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80077d18(4,param_1);
    func_0x80035b84(param_1);
    _DAT_800e110c = _DAT_800e110c | 0x100;
    if (((_DAT_800e8cac == 6) || (_DAT_800e8cac == 0xd)) && ((int)param_1[0xc] < -0x33f4)) {
      *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) | 0x40;
      _DAT_800e1130 = _DAT_800e1130 | 0x80400;
      func_0x80083c14(5);
      DAT_800e9183 = 1;
    }
    else {
      *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) & 0xffbf;
    }
    _DAT_800e110c = _DAT_800e110c | 4;
    *(undefined1 *)((int)param_1 + 0x2c2) = 0xd;
    *(undefined2 *)((int)param_1 + 0x212) = 0xe5e;
    *(undefined1 *)((int)param_1 + 0x2c3) = 1;
    *(undefined2 *)((int)param_1 + 0x2c6) = 0;
    *(undefined2 *)(param_1 + 0xb1) = 0;
    *(undefined1 *)(param_1 + 0xb0) = 0;
    *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) | 2;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 0x80a;
    _DAT_800e1cd0 = 0x800e9028;
    _DAT_800e1c88 = _DAT_800e1cb8;
    _DAT_800e1c8c = _DAT_800e1cbc;
    _DAT_800e1c90 = _DAT_800e1cc0;
    func_0x800838c0(&DAT_800e1c88,0x800e1cc4,&DAT_800e1ca4,auStack_28);
    func_0x80052bd0(8,3);
    func_0x80052d10(0x32,0xff,0,0);
    func_0x80050f38(&DAT_800e1c60);
    FUN_80165c54(param_1,uVar7 + 0xa48);
    DAT_800e9182 = 4;
    FUN_80165814(param_1);
    FUN_80164d08(param_1,0);
    func_0x80077adc(0x20f0001,param_1 + 10);
    *(undefined1 *)((int)param_1 + 0x207) = 9;
    *(undefined1 *)((int)param_1 + 0x2c9) = 1;
    DAT_80166350 = *(short *)((int)param_1 + 0x66) + 0xa0;
    if (*(short *)((int)param_1 + 0x66) == 0xc00) {
      if (-3000 < (int)param_1[0xc]) {
        param_1[0xc] = 0xfffff448;
      }
      cVar4 = *(char *)(param_1 + 0x7a);
      if (cVar4 == '\x02') {
        *(short *)((int)param_1 + 0x66) =
             *(short *)((int)param_1 + 0x66) +
             (short)(((uint)*(byte *)((int)param_1 + 0x1e9) << 9) / 0x96);
        cVar4 = *(char *)(param_1 + 0x7a);
      }
      if (cVar4 == '\x03') {
        *(short *)((int)param_1 + 0x66) =
             (short)(((uint)*(byte *)((int)param_1 + 0x1e9) << 9) / 0x96) +
             *(short *)((int)param_1 + 0x66) + 0x200;
      }
    }
    if (-0x5aff < (int)param_1[10]) {
      param_1[0xc] = param_1[0xc] - 1000;
    }
    *(undefined2 *)(param_1 + 0x78) = 0xfe0c;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    DAT_80166354 = 0x28;
  }
  iVar3 = func_0x80036c68(param_1,9,0,0);
  if (iVar3 != 0) {
    if ((*(ushort *)(param_1 + 0xad) & 0x40) != 0) {
      *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) & 0xffbf;
      if ((_DAT_800e110c & 0x40000000) == 0) {
LAB_80163ea4:
        uVar5 = 6;
      }
      else {
        iVar3 = func_0x800837ac(0x800e8eb8,0x10);
        uVar5 = 0xd;
        if (iVar3 == 0) goto LAB_80163ea4;
      }
      func_0x80083c14(uVar5);
      DAT_800e9183 = 1;
      _DAT_800e1130 = _DAT_800e1130 & 0xfff7fbff;
    }
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  if (*(char *)((int)param_1 + 0x1e9) == '\x1f') {
    _DAT_800e110c = _DAT_800e110c | 4;
    *(undefined1 *)((int)param_1 + 0x2c3) = 1;
  }
  if (*(char *)((int)param_1 + 0x207) < '\x01') {
    _DAT_800e1c60 = 0;
  }
  else {
    *(char *)((int)param_1 + 0x207) = *(char *)((int)param_1 + 0x207) + -1;
  }
  sVar2 = DAT_80166354;
  *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + DAT_80166354;
  if (sVar2 != 0) {
    DAT_80166354 = sVar2 + -2;
  }
  func_0x80032b5c(param_1,0x800);
  if (DAT_80166350 == 0xca0) {
    puVar6 = param_1 + 10;
    if (param_1[10] == 0xffff9b38) goto LAB_80163fb4;
    uVar5 = 0xffff9b38;
  }
  else {
    puVar6 = param_1 + 0xc;
    if (param_1[0xc] == 600) goto LAB_80163fb4;
    uVar5 = 600;
  }
  func_0x80036b2c(puVar6,uVar5,200);
LAB_80163fb4:
  func_0x80032ef4(param_1,(int)DAT_80166350._2_2_,0x4b);
  if (*(short *)((int)param_1 + 0x212) < 0xd97) {
    *(undefined2 *)((int)param_1 + 0x212) = 0xd96;
  }
  else {
    *(short *)((int)param_1 + 0x212) = *(short *)((int)param_1 + 0x212) + -0x14;
  }
  return;
}
