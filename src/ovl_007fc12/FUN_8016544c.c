/* FUN_8016544c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016544c  body 0x8016544c..0x8016571b  size 720 B
 * body sha256 da1a9506e38c97fe2aa4dc5c2e257dd0022a7ff2f5fb203e84d1ab54658e6d4a
 * provider record sha256 f30603c4d6cdd1b5600e9e223f53f88afc4c0fce9e5f1eed9a065bf721da7b0e
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016544c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  byte local_20 [8];
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  local_20[0] = 0x12;
  local_20[1] = 0x13;
  local_20[2] = 0x14;
  local_20[3] = 0x12;
  local_20[4] = 0x13;
  local_20[5] = 0x14;
  local_20[6] = 0x12;
  local_20[7] = 0x13;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    uVar3 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uint)local_20[uVar3 & 7] * 0x1000000 + 0x700;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  case 1:
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      func_0x80033680(param_1,0,1);
    }
    if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
      iVar2 = *(int *)(param_1 + 0x234);
      local_18 = 200;
      local_16 = 0;
      local_14 = 0;
      uVar3 = func_0x80033604();
      func_0x80037780(0x13d0,(uVar3 & 0xff) << 4,iVar2 + 0xbf8,&local_18);
    }
    if ((*(ushort *)(param_1 + 0x1aa) & 0x4000) == 0) {
      *(undefined1 *)(param_1 + 6) = 3;
    }
    break;
  case 2:
    uVar3 = func_0x80033604();
    bVar1 = local_20[uVar3 & 7];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x30000;
    break;
  case 3:
    *(undefined1 *)(param_1 + 6) = 4;
    *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
    *(undefined1 *)(param_1 + 0x2d0) = 2;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x10;
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      uVar3 = func_0x80033604();
      if ((uVar3 & 1) == 0) {
        uVar3 = func_0x80033604();
        uVar5 = 0xb;
        if ((uVar3 & 1) == 0) {
          uVar3 = func_0x80033604(0xb);
          uVar5 = 10;
          if ((uVar3 & 1) == 0) goto LAB_80165634;
        }
        func_0x80077d18(uVar5,param_1);
      }
LAB_80165634:
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
  case 4:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 5;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xffef;
    }
    break;
  case 5:
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xffef;
    break;
  case 6:
    *(undefined1 *)(param_1 + 6) = 7;
    uVar3 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar3 & 7) * 0x10000 + 0x15000f00;
  case 7:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x10100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    break;
  case 8:
    *(undefined1 *)(param_1 + 6) = 0;
  }
  return;
}
