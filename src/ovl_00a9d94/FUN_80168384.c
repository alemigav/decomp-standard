/* FUN_80168384
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80168384  body 0x80168384..0x801687d7  size 1108 B
 * body sha256 0a61ec7c619ce2930181352945ac9870ed016ad94a73d649dd5a9ac4610ab022
 * provider record sha256 18009bc75671e385276ca9e3ac4f8e2f4fdb221a47debad80388b59c5488cd16
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80168384(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  uint uVar1;
  ushort uVar3;
  int iVar4;
  char cVar5;
  short local_50;
  short local_4e;
  short local_4c;
  short local_48;
  short local_46;
  short local_44;
  undefined1 auStack_40 [32];
  
  if (*(char *)(param_1 + 6) == '\0') {
    iVar4 = *(int *)(param_1 + 0x234);
    sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
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
      local_4e = 800;
      local_46 = 700;
      local_48 = *(short *)(param_1 + 0x1e0) * 2 + 0x96;
    }
    if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 2) {
      local_50 = 200;
      local_4e = -700;
      local_46 = -700;
      local_48 = *(short *)(param_1 + 0x1e0) * 2 + 200;
    }
    func_0x8004276c(auStack_40,&local_50,&local_50);
    local_50 = local_50 + *(short *)(iVar4 + 0xd86);
    local_4e = local_4e + *(short *)(iVar4 + 0xd8a);
    local_4c = local_4c + *(short *)(iVar4 + 0xd8e);
    func_0x8004276c(auStack_40,&local_48,&local_48);
    local_48 = local_48 + *(short *)(iVar4 + 0xd86);
    local_46 = local_46 + *(short *)(iVar4 + 0xd8a);
    local_44 = local_44 + *(short *)(iVar4 + 0xd8e);
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
      if (*(char *)(param_1 + 5) != '\x01') {
        func_0x80077d18(2,param_1);
      }
    }
    if (*(byte *)(param_1 + 5) - 5 < 2) {
      *(undefined1 *)(param_1 + 700) = 1;
    }
    if (*(byte *)(param_1 + 0x26e) < 3) {
      cVar5 = *(char *)(param_1 + 5);
      if (cVar5 == '\t') {
        FUN_80167498(param_1);
        cVar5 = *(char *)(param_1 + 5);
      }
      if (cVar5 == '\x11') {
        FUN_80167628(param_1);
      }
      cVar5 = *(char *)(param_1 + 5);
      if (cVar5 == '\n') {
        FUN_80167228(param_1);
        cVar5 = *(char *)(param_1 + 5);
      }
      if (cVar5 == '\v') {
        FUN_80167360(param_1);
      }
    }
    if (*(char *)(param_1 + 5) == '\x0e') {
      FUN_801678c0(param_1);
    }
    if ((*(ushort *)(param_1 + 0x2b6) & 0x400) == 0) {
      *(char *)(param_1 + 0x2b9) =
           *(char *)(param_1 + 0x2b9) + (&DAT_8016c4e3)[*(byte *)(param_1 + 5)];
      if ((*(ushort *)(param_1 + 0x2b6) & 1) == 0) {
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 1;
        *(undefined1 *)(param_1 + 0x2b8) = 0xf;
      }
      if (*(byte *)(param_1 + 0x2b9) < 0xc) {
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
        FUN_8016250c(param_1,param_2,param_3);
        return;
      }
      *(undefined1 *)(param_1 + 0x2b9) = 0;
      *(undefined1 *)(param_1 + 0x2b8) = 0;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffe;
    }
    else {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    }
  }
  FUN_801687d8(param_1,param_2,param_3);
  return;
}
