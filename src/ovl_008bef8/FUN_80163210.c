/* FUN_80163210
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163210  body 0x80163210..0x801635cf  size 960 B
 * body sha256 4ae5765a40847bbb194e4aefb261244d253fcefab968c443a8939433af96b458
 * provider record sha256 77ba0978defef453e8669238a6893b0271997d12d7173dd0c7c3759fcdedd7fc
 * callees 7 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163210(int param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined1 auStack_20 [16];
  
  iVar5 = *(int *)(param_1 + 0x234);
  func_0x80082200(auStack_20,0,8);
  switch(*(undefined1 *)(param_1 + 0x2c2)) {
  default:
    goto switchD_80163264_caseD_0;
  case 1:
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    func_0x80083758(0x800e8d00,0x1d);
    *(char *)(param_1 + 0x2c2) = *(char *)(param_1 + 0x2c2) + '\x01';
  case 2:
    sVar2 = FUN_801635d0(0xd,(int)*(short *)(param_1 + 0x1f6),0xf0);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar2;
    sVar2 = FUN_801635d0(0xd,(int)*(short *)(param_1 + 0x1f6),0xfffffec0);
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar2;
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 1;
    if (_DAT_800e1c90 - *(int *)(param_1 + 0x30) < 0x1fa4) {
      _DAT_800e1c90 = *(int *)(param_1 + 0x30) + 0x1fa4;
    }
    iVar5 = iVar5 + 0x908;
    if (*(short *)(param_1 + 0x1f6) != 0xd) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    _DAT_800e1cd0 = iVar5;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfb;
    func_0x80049ff8(iVar5,&DAT_800e1ca4,&local_50);
    _DAT_800e1c90 = local_34;
    _DAT_800e1c88 = local_3c;
    _DAT_800e1c8c = local_38;
    _DAT_800e1ca4 = local_50;
    _DAT_800e1ca8 = local_4c;
    _DAT_800e1cac = local_48;
    _DAT_800e1cb0 = local_44;
    _DAT_800e1cb4 = local_40;
    _DAT_800e1cb8 = local_3c;
    _DAT_800e1cbc = local_38;
    _DAT_800e1cc0 = local_34;
    func_0x800838c0(&DAT_800e1c88,0x800e1cc4,&DAT_800e1ca4,auStack_20);
    cVar1 = *(char *)(param_1 + 0x2c2);
    goto LAB_80163578;
  case 3:
    sVar2 = FUN_801635d0(6,(int)*(short *)(param_1 + 0x1f6),0xffffff74);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar2;
    sVar2 = FUN_801635d0(6,(int)*(short *)(param_1 + 0x1f6),0xffffffc4);
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar2;
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 1;
    if (_DAT_800e1c88 != 0x6d6) {
      func_0x80036b2c(&DAT_800e1c88,0x6d6,0x46);
    }
    sVar2 = *(short *)(param_1 + 0x1f6);
    sVar4 = 6;
    break;
  case 4:
    sVar2 = FUN_80163698(6,(int)*(short *)(param_1 + 0x1f6),0xffffff74);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar2;
    sVar2 = FUN_80163698(6,(int)*(short *)(param_1 + 0x1f6),0xffffffc4);
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar2;
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 1;
    if (_DAT_800e1c88 != 0x6d6) {
      func_0x80036b2c(&DAT_800e1c88,0x6d6,0x91);
    }
    if (_DAT_800e1c8c != -0xd2) {
      func_0x80036b2c(&DAT_800e1c8c,0xffffff2e,0x19);
    }
    sVar2 = *(short *)(param_1 + 0x1f6);
    sVar4 = 6;
    break;
  case 5:
    sVar2 = FUN_801635d0(7,(int)*(short *)(param_1 + 0x1f6),0x4b);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar2;
    sVar2 = FUN_801635d0(7,(int)*(short *)(param_1 + 0x1f6),100);
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar2;
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 1;
    if (_DAT_800e1c88 != 0x6d6) {
      func_0x80036b2c(&DAT_800e1c88,0x6d6,100);
    }
    if (_DAT_800e1c8c != -0xd2) {
      func_0x80036b2c(&DAT_800e1c8c,0xffffff2e,0x37);
    }
    sVar2 = *(short *)(param_1 + 0x1f6);
    sVar4 = 7;
    break;
  case 6:
    sVar2 = FUN_80163698(7,(int)*(short *)(param_1 + 0x1f6),0x4b);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar2;
    sVar3 = FUN_80163698(7,(int)*(short *)(param_1 + 0x1f6),100);
    sVar2 = *(short *)(param_1 + 0x1f6) + 1;
    *(short *)(param_1 + 0x1f6) = sVar2;
    sVar4 = 7;
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar3;
    break;
  case 7:
    if (_DAT_800e1c88 != 0x6d6) {
      func_0x80036b2c(&DAT_800e1c88,0x6d6,100);
    }
    if (_DAT_800e1c8c != -0xd2) {
      func_0x80036b2c(&DAT_800e1c8c,0xffffff2e,0x1e);
    }
    goto switchD_80163264_caseD_0;
  }
  if (sVar2 == sVar4) {
    cVar1 = *(char *)(param_1 + 0x2c2);
    *(undefined2 *)(param_1 + 0x1f6) = 0;
LAB_80163578:
    *(char *)(param_1 + 0x2c2) = cVar1 + '\x01';
  }
switchD_80163264_caseD_0:
  return;
}
