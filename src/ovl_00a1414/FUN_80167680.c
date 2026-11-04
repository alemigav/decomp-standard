/* FUN_80167680
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80167680  body 0x80167680..0x8016798f  size 784 B
 * body sha256 4264731527de8897a40f7d4f4039bb0137e3082aa9fccf24b1b16236d4359581
 * provider record sha256 8defa32354faccd9c5e806b41489796dcd6b2a975f4c863284177ef9c557db56
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167680(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  ushort uVar3;
  uint uVar1;
  int iVar4;
  char cVar5;
  short local_48;
  short local_46;
  short local_44;
  undefined1 auStack_40 [32];
  
  if (((*(ushort *)(param_1 + 0x2b8) & 0x10) != 0) && (*(char *)(param_1 + 6) == '\0')) {
    iVar4 = *(int *)(param_1 + 0x234);
    sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    local_48 = 0;
    local_44 = 0;
    local_46 = sVar2;
    func_0x80040e58(&local_48,auStack_40);
    local_48 = 100;
    uVar3 = func_0x80033604();
    local_46 = (uVar3 & 0xff) * -2 + 0x100;
    uVar3 = func_0x80033604();
    local_44 = 0x80 - (uVar3 & 0xff);
    if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
      local_48 = 100;
      uVar3 = func_0x80033604(auStack_40);
      local_46 = (uVar3 & 0xff) * -2 + 0x3bc;
    }
    func_0x8004276c(auStack_40,&local_48,&local_48);
    local_48 = local_48 + *(short *)(iVar4 + 0x1c6);
    local_46 = local_46 + *(short *)(iVar4 + 0x1ca);
    local_44 = local_44 + *(short *)(iVar4 + 0x1ce);
    if (*(char *)(param_1 + 5) != '\x10') {
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0 | 0x10000,(int)sVar2,0x800e9028,&local_48);
      uVar3 = func_0x80033604();
      local_46 = local_46 - ((uVar3 & 0x3f) - 0x40);
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,(int)sVar2,0x800e9028,&local_48);
      if (*(char *)(param_1 + 5) != '\x01') {
        func_0x80077d18(8,param_1);
      }
    }
    if (*(byte *)(param_1 + 0x26e) < 3) {
      cVar5 = *(char *)(param_1 + 5);
      if (cVar5 == '\t') {
        FUN_801669dc(param_1);
        cVar5 = *(char *)(param_1 + 5);
      }
      if (cVar5 == '\x11') {
        FUN_80166b14(param_1);
      }
      cVar5 = *(char *)(param_1 + 5);
      if (cVar5 == '\n') {
        FUN_8016676c(param_1);
        cVar5 = *(char *)(param_1 + 5);
      }
      if (cVar5 == '\v') {
        FUN_8016684c(param_1);
      }
    }
    if (*(char *)(param_1 + 5) == '\x0e') {
      FUN_80166ca4(param_1);
    }
    if (*(byte *)(param_1 + 5) - 5 < 2) {
      *(undefined1 *)(param_1 + 0x2c3) = 1;
    }
    if (*(char *)(param_1 + 5) == '\x10') {
      FUN_8016676c(param_1);
    }
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    if (*(short *)(param_1 + 4) == 0x109) {
      FUN_8016435c(param_1,param_2,param_3);
      return;
    }
  }
  FUN_80167990(param_1,param_2,param_3);
  return;
}
