/* FUN_8016489c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016489c  body 0x8016489c..0x80164d03  size 1128 B
 * body sha256 b2aac450fe15c91ac518a0145e9c9b8a5418a127c5b9badeb4a46194cfd247a1
 * provider record sha256 d1b6682eb85c43fa54b865dd02eadcfd0e95306fc228f59677f158c768df3619
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016489c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  
  bVar1 = *(byte *)((int)param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x80032bd8(param_1,(int)*(short *)((int)param_1 + 0x2b6) -
                                (int)*(short *)((int)param_1 + 0x66),0);
        if ((*(char *)((int)param_1 + 0x207) == '\0') &&
           (iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100), iVar3 != 0)) {
          *(undefined1 *)((int)param_1 + 0x207) = 1;
        }
        sVar5 = *(short *)((int)param_1 + 0x1e2) + 0x50;
        *(short *)((int)param_1 + 0x1e2) = sVar5;
        *(char *)((int)param_1 + 0x1a2) = (char)((int)param_1[0xb] / 0x708);
        if ((0x353 < sVar5) && (*(short *)(param_1 + 0x78) != 0)) {
          *(undefined2 *)(param_1 + 0x78) = 0;
          *param_1 = *param_1 & 0xfffffbf3;
          uVar4 = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),
                                  (int)*(short *)((int)param_1 + 0x32),(int)_DAT_800e115a,
                                  (int)_DAT_800e1162);
          *(undefined2 *)((int)param_1 + 0x66) = uVar4;
          *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbbff;
        }
        if ((int)(param_1[0xb] + 200) < (int)*(short *)((int)param_1 + 0x25e)) {
          return;
        }
        *(undefined1 *)((int)param_1 + 7) = 3;
        param_1[0x7a] = 0xe000300;
        *(undefined1 *)((int)param_1 + 0x206) = 1;
        *(undefined1 *)((int)param_1 + 0x2bd) = 0;
        func_0x80089d54(param_1,param_2,param_3,0x400);
        param_1[10] = (int)*(short *)(param_1 + 0x98);
        param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
        *(undefined1 *)((int)param_1 + 0x1a2) = 0;
        *(undefined1 *)((int)param_1 + 0x207) = 0;
        param_1[0xc] = (int)*(short *)((int)param_1 + 0x262);
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
        *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbbff;
        func_0x80052c6c(8,0x8c,0);
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      iVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
      if (iVar3 != 0) {
        *(undefined1 *)((int)param_1 + 0x2bd) = 0;
        *(undefined1 *)((int)param_1 + 5) = 2;
        *(undefined2 *)((int)param_1 + 6) = 0;
        *(undefined1 *)((int)param_1 + 0x2c7) = 0x3c;
        uVar2 = func_0x80033604();
        if ((0x57ea >> (uVar2 & 0xf) & 1U) != 0) {
          *(char *)((int)param_1 + 0x2c7) = *(char *)((int)param_1 + 0x2c7) + '<';
        }
        FUN_80163824(param_1);
      }
      func_0x80033648(param_1);
      if ((((*(uint *)param_1[0x85] & 0x10000) != 0) && (*(char *)((int)param_1 + 0x206) == '\0'))
         && (iVar3 = FUN_801676cc(param_1,0), iVar3 != 0)) {
        *(undefined1 *)((int)param_1 + 0x206) = 1;
        *(undefined1 *)((int)param_1 + 0x207) = 3;
        func_0x80077d18(3,param_1);
        FUN_80167374(&DAT_800e1130,8,0);
      }
      if ((*(uint *)param_1[0x85] & 0x8000000) != 0) {
        *(undefined1 *)((int)param_1 + 0x2cf) = 0x1d;
        *(undefined1 *)((int)param_1 + 0x2ce) = 7;
      }
      FUN_80163620(param_1,0xe);
      if (*(char *)((int)param_1 + 0x207) == '\0') {
        return;
      }
      FUN_80167374(param_1,0xe,1);
      FUN_80167374(param_1,0x10,1);
      *(char *)((int)param_1 + 0x207) = *(char *)((int)param_1 + 0x207) + -1;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = 0xd000f00;
    uVar2 = func_0x8006568c((int)_DAT_800e115a,(int)_DAT_800e1162);
    iVar3 = *(int *)(_DAT_800df92c + 0x38) + (char)(&DAT_80167e4c)[uVar2 & 0xff] * 0xc;
    *(short *)(param_1 + 0x98) =
         (short)((int)*(short *)(iVar3 + 4) + (int)*(short *)(iVar3 + 8) >> 1);
    iVar6 = (int)*(short *)(iVar3 + 6) + (int)*(short *)(iVar3 + 10) >> 1;
    iVar3 = iVar6 - param_1[0xc];
    *(short *)((int)param_1 + 0x262) = (short)iVar6;
    iVar3 = func_0x80040bb4(((int)*(short *)(param_1 + 0x98) - param_1[10]) *
                            ((int)*(short *)(param_1 + 0x98) - param_1[10]) + iVar3 * iVar3);
    *(undefined2 *)((int)param_1 + 0x1e2) = 0xfcac;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(short *)(param_1 + 0x78) = (short)(iVar3 / 0x16);
    uVar4 = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32),(int)*(short *)(param_1 + 0x98),
                            (int)*(short *)((int)param_1 + 0x262));
    *(undefined2 *)((int)param_1 + 0x2b6) = uVar4;
    *(undefined2 *)((int)param_1 + 0x66) = uVar4;
    *param_1 = *param_1 | 4;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  if ((*(uint *)param_1[0x85] & 0x10000) != 0) {
    *(undefined1 *)((int)param_1 + 7) = 2;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    func_0x80077d18(6);
  }
  return;
}
