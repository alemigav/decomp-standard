/* FUN_80165e90
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165e90  body 0x80165e90..0x801664bb  size 1580 B
 * body sha256 ce81340b249ff8800ad09b13b4310937f18375d8f5e6d1d7d030bdefe7d01974
 * provider record sha256 50dce0487e71acb244a91d35a1a384bf14a8477c9a457357a9557a4d1ee88861
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e90(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  ushort uVar4;
  int iVar2;
  uint uVar3;
  undefined1 uVar5;
  undefined4 uVar6;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x7a] = 0x4000f00;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    uVar3 = func_0x8006568c((int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32));
    uVar4 = *(ushort *)(&DAT_80167d80 + (uVar3 & 0xff) * 2);
    *(undefined2 *)(param_1 + 0x7d) = 0x2d;
    *(undefined1 *)((int)param_1 + 0x207) = 2;
    *(ushort *)((int)param_1 + 0x2b6) = uVar4;
    *(bool *)((int)param_1 + 0x206) = (uVar4 & 0x3ff) != 0;
    (*(code *)(&PTR_LAB_80167f4c)[*(byte *)((int)param_1 + 5) - 1])(param_1,param_2,param_3);
    *(undefined1 *)((int)param_1 + 0x2bd) = 0;
    func_0x80077d18(10,param_1);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
    break;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 == 0) goto LAB_801660d0;
    *(undefined1 *)((int)param_1 + 6) = 2;
    param_1[0x7a] = 0x2000f00;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *param_1 = *param_1 | 4;
    break;
  case 2:
    FUN_80165e14(param_1,0x10);
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    iVar2 = (int)*(short *)((int)param_1 + 0x2b6) - (*(ushort *)((int)param_1 + 0x66) & 0xfff);
    if ((param_1[0x6b] & 1) != 0) {
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 < 0x400) {
        *(undefined1 *)((int)param_1 + 6) = 3;
        param_1[0x7a] = 0x11000f00;
        func_0x800334c8(param_1,param_2,param_3,0);
        func_0x80089d54(param_1,param_2,param_3,0x100);
        uVar6 = 0xc;
        goto LAB_80166360;
      }
    }
    func_0x80033648(param_1);
LAB_801660d0:
    func_0x80032b5c(param_1,0);
    break;
  case 3:
    FUN_80165e14(param_1,0x18);
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80032b5c(param_1,0);
    if ((*(uint *)param_1[0x85] & 0x10000) != 0) {
      *(undefined1 *)((int)param_1 + 6) = 4;
      param_1[0x7a] = 0x12000f00;
    }
    break;
  case 4:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_1 + 0x1ea) = 0xf;
    }
    if (((*(uint *)param_1[0x85] & 0x10000) != 0) &&
       (cVar1 = *(char *)((int)param_1 + 0x207), *(char *)((int)param_1 + 0x207) = cVar1 + -1,
       cVar1 == '\x01')) {
      *(undefined1 *)((int)param_1 + 6) = 5;
      param_1[0x7a] = 0x13000f00;
      *param_1 = *param_1 | 0x4a;
    }
    break;
  case 5:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((*(uint *)param_1[0x85] & 0x10000) != 0) {
      *(undefined1 *)((int)param_1 + 6) = 6;
      *(undefined2 *)(param_1 + 0x78) = 0xdc;
      *(undefined2 *)((int)param_1 + 0x1e2) = 0xfc18;
      *(undefined1 *)((int)param_1 + 0x207) = 0;
      *(undefined1 *)((int)param_1 + 0x2bd) = 1;
      *param_1 = *param_1 | 0x400;
    }
    break;
  case 6:
    if ((*(char *)((int)param_1 + 0x207) == '\0') &&
       (iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100), iVar2 != 0)) {
      *(undefined1 *)((int)param_1 + 0x207) = 1;
    }
    func_0x80032bd8(param_1,0,0);
    uVar3 = 0xfffff9c0;
    uVar4 = *(short *)((int)param_1 + 0x1e2) + 0xa0;
    *(ushort *)((int)param_1 + 0x1e2) = uVar4;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      uVar3 = 0xfffffa24;
    }
    if ((0 < (int)((uint)uVar4 << 0x10)) && ((int)uVar3 < (int)param_1[0xb])) {
      uVar6 = 8;
      *(undefined1 *)((int)param_1 + 6) = 7;
      param_1[0xb] = uVar3;
      param_1[0x7a] = 0xf000100;
      if (*(char *)((int)param_1 + 0x206) != '\0') {
        uVar6 = 9;
      }
LAB_80166360:
      func_0x80077d18(uVar6,param_1);
    }
    break;
  case 7:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x800);
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 8;
      *(undefined2 *)((int)param_1 + 0x1e2) = 0xfc7c;
      param_1[0x7a] = 0x14000300;
      func_0x80077d18(6,param_1);
      func_0x80035b84(param_1);
    }
    break;
  case 8:
    func_0x80089d54(param_1,param_2,param_3,0x400);
    func_0x80032bd8(param_1,0,0);
    uVar4 = *(short *)((int)param_1 + 0x1e2) + 0xa0;
    *(ushort *)((int)param_1 + 0x1e2) = uVar4;
    if (-1 < (int)((uint)uVar4 << 0x10)) {
      *(undefined1 *)((int)param_1 + 6) = 9;
      uVar6 = 0xe;
      goto LAB_80166360;
    }
    break;
  case 9:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 10;
    }
    break;
  case 10:
    uVar3 = param_1[0xb];
    param_1[0xb] = uVar3 - 0xb4;
    if ((int)(uVar3 - 0xb4) < -13000) {
      *(undefined1 *)((int)param_1 + 6) = 0xb;
    }
    break;
  case 0xb:
    *(undefined1 *)((int)param_1 + 6) = 0xc;
  }
  if (0xb < *(byte *)((int)param_1 + 6)) goto LAB_8016649c;
  if (*(char *)((int)param_1 + 0x2bd) == '\0') {
    uVar3 = func_0x80033604();
    if ((0x8000 >> (uVar3 & 0xf) & 1U) == 0) goto LAB_8016649c;
    uVar5 = (&DAT_80167dac)[(uint)*(byte *)((int)param_1 + 0x26e) % 3];
    uVar6 = 0;
  }
  else {
    if (((int)param_1[0xb] < -9999) ||
       (uVar3 = func_0x80033604(), (0x17e4 >> (uVar3 & 0xf) & 1U) == 0)) goto LAB_8016649c;
    FUN_80167374(param_1,1,9);
    uVar3 = func_0x80033604();
    if ((0x17e4 >> (uVar3 & 0xf) & 1U) == 0) goto LAB_8016649c;
    uVar5 = 2;
    uVar6 = 9;
  }
  FUN_80167374(param_1,uVar5,uVar6);
LAB_8016649c:
  FUN_80167c1c(param_1);
  return;
}
