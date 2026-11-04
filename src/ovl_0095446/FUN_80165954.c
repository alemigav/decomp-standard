/* FUN_80165954
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80165954  body 0x80165954..0x80165e1b  size 1224 B
 * body sha256 af311b0d44135b5f67c4e8c4e371df528acaaaf3dba26dadf175512665659e07
 * provider record sha256 117af0fbc772ef3e7ac1cbaeeaddd9c637d4a0c156a9b53849f26b678d23e437
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165954(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar5;
  int iVar1;
  ushort uVar3;
  uint uVar2;
  short sVar4;
  int iVar6;
  char cVar7;
  short local_48;
  short local_46;
  short local_44;
  undefined1 auStack_40 [32];
  
  if (*(char *)(param_1 + 6) == '\0') {
    bVar5 = func_0x80033604();
    DAT_80167fca = '\x03' - bVar5 % 6;
    bVar5 = func_0x80033604();
    DAT_80167fcb = '\x0f' - bVar5 % 0x1e;
    if (*(char *)(param_1 + 5) != '\x10') {
      iVar6 = *(int *)(param_1 + 0x234);
      iVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      local_48 = 0;
      local_46 = (short)iVar1;
      uVar3 = func_0x80033604();
      local_44 = 0x80 - (uVar3 & 0xff);
      func_0x80040e58(&local_48,auStack_40);
      local_48 = 800;
      local_46 = 0;
      if (*(char *)(param_1 + 0x26e) == '\0') {
        local_48 = 500;
        local_46 = 200;
      }
      func_0x8004276c(auStack_40,&local_48,&local_48);
      local_48 = local_48 + *(short *)(iVar6 + 0x1c6);
      local_46 = local_46 + *(short *)(iVar6 + 0x1ca);
      local_44 = local_44 + *(short *)(iVar6 + 0x1ce);
      uVar2 = func_0x80033604();
      iVar6 = (int)(short)iVar1;
      func_0x80037780((uVar2 & 0xff) * 8 + 0x1fa0 | 0x90000,iVar6,0x800e9028,&local_48);
      if (3 < (byte)(&DAT_801682ac)[(*(byte *)(param_1 + 5) - 1) * 2]) {
        uVar3 = func_0x80033604();
        local_46 = local_46 - ((uVar3 & 0x3f) - 0x40);
        uVar2 = func_0x80033604();
        func_0x80037780((uVar2 & 0xff) * 8 + 0x1fa0 | 0x80000,iVar6,0x800e9028,&local_48);
      }
      uVar2 = func_0x80033604();
      if ((uVar2 & 3) == 0) {
        func_0x80037780(0x1017d0,iVar6,0x800e9028,&local_48);
        uVar2 = func_0x80033604();
        func_0x80037780(0x1f0817d0,(int)((iVar1 - ((uVar2 & 0xff) * 4 + -0x200)) * 0x10000) >> 0x10,
                        0x800e9028,&local_48);
      }
    }
    if (*(char *)(param_1 + 700) != '\0') {
      iVar1 = (uint)*(byte *)(param_1 + 700) -
              (uint)(byte)(&DAT_801682ad)[(*(byte *)(param_1 + 5) - 1) * 2];
      *(char *)(param_1 + 700) = (char)iVar1;
      if (iVar1 * 0x1000000 < 1) {
        *(undefined1 *)(param_1 + 700) = 1;
      }
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x23e;
      sVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x1c2);
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x23e;
      if ((sVar4 == 0) && (*(char *)(param_1 + 700) == '\x01')) {
        *(undefined1 *)(param_1 + 700) = 0;
      }
    }
    cVar7 = *(char *)(param_1 + 5);
    if (cVar7 == '\t') {
      FUN_80164f00(param_1);
      cVar7 = *(char *)(param_1 + 5);
    }
    if (cVar7 == '\x11') {
      FUN_80165038(param_1);
    }
    cVar7 = *(char *)(param_1 + 5);
    if (cVar7 == '\n') {
      FUN_80164d40(param_1);
      cVar7 = *(char *)(param_1 + 5);
    }
    if (cVar7 == '\v') {
      FUN_80164e20(param_1);
    }
    cVar7 = *(char *)(param_1 + 5);
    if (cVar7 == '\x0e') {
      FUN_8016524c(param_1,1);
      cVar7 = *(char *)(param_1 + 5);
    }
    if ((cVar7 == '\x10') && (*(char *)(param_1 + 0x2c4) == '\0')) {
      FUN_80164d40(param_1);
      *(undefined1 *)(param_1 + 0x2c4) = 0x2d;
    }
    if ((*(byte *)(param_1 + 5) - 5 < 2) && (*(char *)(param_1 + 0x2bf) == '\0')) {
      *(undefined1 *)(param_1 + 0x2bf) = 1;
    }
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) & 0xdfff;
    if (*(char *)(param_1 + 0x2be) != '\0') {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
      if (*(char *)(param_1 + 4) != '\x02') {
        FUN_801626f4(param_1,param_2,param_3);
        return;
      }
      if ((*(ushort *)(param_1 + 0x2ba) & 0x1000) != 0) {
        if (*(char *)(param_1 + 700) != '\0') goto LAB_80165dc0;
        *(undefined1 *)(param_1 + 700) = 1;
      }
    }
  }
  if (*(char *)(param_1 + 700) == '\0') {
    FUN_80165e1c(param_1,param_2,param_3);
    return;
  }
LAB_80165dc0:
  (*(code *)(&PTR_FUN_80168024)[(*(byte *)(param_1 + 5) - 1) * 9 + (uint)*(byte *)(param_1 + 0x26e)]
  )(param_1,param_2,param_3);
  return;
}
