/* FUN_80166ce0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80166ce0  body 0x80166ce0..0x8016724b  size 1388 B
 * body sha256 8799c2958b33b5fa7244c374dcd694c02583da77c9ae8bc2807ac16ad5bedcea
 * provider record sha256 c1b641ad888448797e617dcf97e0f76c9cd603f16a7ad3b615a119d41daa26b6
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166ce0(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  uint uVar1;
  ushort uVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  short local_50;
  short local_4e;
  short local_4c;
  short local_48;
  short local_46;
  short local_44;
  undefined1 auStack_40 [32];
  
  if (*(char *)(param_1 + 6) != '\0') goto LAB_8016721c;
  iVar4 = *(int *)(param_1 + 0x234);
  sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  if (*(short *)(param_1 + 0x1aa) == 2) {
    iVar7 = *(int *)(param_1 + 0x234);
    uVar1 = func_0x80033604(&local_50);
    local_50 = 0x40 - (short)((uVar1 & 0xff) >> 1);
    local_4e = 0;
    uVar1 = func_0x80033604();
    local_4c = 0x40 - (short)((uVar1 & 0xff) >> 1);
    uVar1 = func_0x80033604();
    iVar4 = (int)sVar2;
    iVar7 = iVar7 + 0x790;
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0 | 0x10000,iVar4,iVar7,&local_50);
    uVar3 = func_0x80033604();
    local_4e = local_4e - ((uVar3 & 0x3f) - 0x40);
    uVar1 = func_0x80033604();
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,iVar4,iVar7,&local_50);
    iVar7 = *(int *)(param_1 + 0x234);
    uVar1 = func_0x80033604();
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,iVar4,iVar7 + 0x908,&local_50);
    uVar6 = 4;
LAB_80167050:
    func_0x80077d18(uVar6,param_1);
  }
  else {
    local_50 = 0;
    local_4c = 0;
    local_4e = sVar2;
    func_0x80040e58(&local_50,auStack_40);
    local_50 = 200;
    local_4e = -200;
    local_46 = 0;
    local_44 = 0;
    local_48 = *(short *)(param_1 + 0x1e0) * 4 + 300;
    if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
      local_50 = 0x96;
      local_4e = 700;
      local_46 = 700;
      local_48 = *(short *)(param_1 + 0x1e0) * 2 + 0x96;
    }
    func_0x8004276c(auStack_40,&local_50,&local_50);
    local_50 = local_50 + *(short *)(iVar4 + 0x1c6);
    local_4e = local_4e + *(short *)(iVar4 + 0x1ca);
    local_4c = local_4c + *(short *)(iVar4 + 0x1ce);
    func_0x8004276c(auStack_40,&local_48,&local_48);
    local_48 = local_48 + *(short *)(iVar4 + 0x1c6);
    local_46 = local_46 + *(short *)(iVar4 + 0x1ca);
    local_44 = local_44 + *(short *)(iVar4 + 0x1ce);
    if ((*(char *)(param_1 + 5) != '\x10') && (*(char *)(param_1 + 5) != '\f')) {
      uVar1 = func_0x80033604();
      iVar4 = (int)sVar2;
      func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0 | 0x10000,iVar4,0x800e9028,&local_50);
      uVar3 = func_0x80033604();
      local_4e = local_4e - ((uVar3 & 0x3f) - 0x40);
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,iVar4,0x800e9028,&local_50);
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,iVar4,0x800e9028,&local_48);
      uVar3 = func_0x80033604();
      local_4e = local_4e - ((uVar3 & 0x3f) - 0x40);
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,iVar4,0x800e9028,&local_48);
      uVar6 = 2;
      if (*(char *)(param_1 + 5) != '\x01') goto LAB_80167050;
    }
  }
  *(undefined1 *)(param_1 + 700) = 1;
  *(undefined1 *)(param_1 + 0x2bd) = 0;
  if (*(byte *)(param_1 + 5) - 5 < 2) {
    *(undefined1 *)(param_1 + 0x2c5) = 1;
  }
  if (*(byte *)(param_1 + 0x26e) < 3) {
    cVar5 = *(char *)(param_1 + 5);
    if (cVar5 == '\t') {
      FUN_801674ec(param_1);
      cVar5 = *(char *)(param_1 + 5);
    }
    if (cVar5 == '\x11') {
      FUN_8016767c(param_1);
    }
    cVar5 = *(char *)(param_1 + 5);
    if (cVar5 == '\n') {
      FUN_8016724c(param_1);
      cVar5 = *(char *)(param_1 + 5);
    }
    if (cVar5 == '\v') {
      FUN_801673b4(param_1);
    }
  }
  cVar5 = *(char *)(param_1 + 5);
  if (cVar5 == '\x0e') {
    FUN_8016780c(param_1);
    cVar5 = *(char *)(param_1 + 5);
  }
  if ((cVar5 == '\x10') && (*(char *)(param_1 + 0x2ca) == '\0')) {
    FUN_8016724c(param_1);
    *(undefined1 *)(param_1 + 0x2ca) = 0x2d;
  }
  if (((*(ushort *)(param_1 + 0x2b8) & 4) == 0) && (*(short *)(param_1 + 0x1f2) < 200)) {
    *(undefined1 *)(param_1 + 0x2b5) = 0x32;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 4;
  }
  if ((*(ushort *)(param_1 + 0x2b8) & 0x200) == 0) {
    if ((*(ushort *)(param_1 + 0x2b8) & 1) == 0) {
      *(char *)(param_1 + 0x2b5) =
           *(char *)(param_1 + 0x2b5) + (&DAT_801698b3)[*(byte *)(param_1 + 5)];
      if ((*(ushort *)(param_1 + 0x2b8) & 2) == 0) {
        *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 2;
        *(undefined1 *)(param_1 + 0x2b4) = 0xf;
      }
    }
    if (((*(ushort *)(param_1 + 0x2b8) & 0x80) != 0) || (*(byte *)(param_1 + 0x2b5) < 0xc)) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
      FUN_801625b0(param_1,param_2,param_3);
      return;
    }
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 0x2b4) = 0;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffd;
  }
  else {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  }
LAB_8016721c:
  FUN_80168298(param_1,param_2,param_3);
  return;
}
