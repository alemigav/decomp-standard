/* FUN_8016738c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016738c  body 0x8016738c..0x8016790f  size 1412 B
 * body sha256 0c4a73c07bb5a42e074d777c1c8acc6de44ed4019f5b043a963e5547a1bed009
 * provider record sha256 64155fe1bf4b4defe8ae70f395199c53e8344a28c781c9fb9b6c02778d2100c5
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016738c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  char cVar9;
  byte bVar10;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar11;
  undefined2 local_30 [4];
  short local_28;
  short local_26;
  undefined2 local_24;
  
  local_30[0] = 0xfe3e;
  local_30[1] = 0;
  bVar10 = *(byte *)(param_1 + 6);
  if (bVar10 != 1) {
    if (1 < bVar10) {
      if (bVar10 != 2) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      if (*(char *)(param_1 + 0x2bf) < '\x01') {
        bVar10 = func_0x80033604();
        *(byte *)(param_1 + 0x2bf) = (bVar10 & 0x10) + 0xf;
        *(undefined1 *)(param_1 + 0x2be) = 0;
      }
      bVar3 = false;
      iVar6 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
      if (((iVar6 == 0) && (*(uint *)(param_1 + 0x28c) < 4000)) && ((DAT_800e139f & 0x80) == 0)) {
        uVar7 = func_0x80033604();
        bVar3 = (uVar7 & 3) == 0;
      }
      uVar8 = 0x10b0000;
      if (!bVar3) {
        uVar7 = 0;
        if ((*(uint *)(param_1 + 0x28c) < 3000) &&
           (iVar6 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,900), iVar6 != 0)) {
          uVar7 = func_0x80033604();
          uVar7 = uVar7 & 1;
        }
        uVar8 = 0x10c0000;
        if (uVar7 == 0) {
          uVar7 = func_0x80033604();
          uVar8 = 0x1020000;
          if ((uVar7 & 1) == 0) {
            return;
          }
        }
      }
      *(undefined4 *)(param_1 + 4) = uVar8;
      return;
    }
    if (bVar10 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1f6) = 10;
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) =
         (4 - (uint)((*(ushort *)(param_1 + 0x26c) & 0x20) != 0)) * 0x1000000 + 0x300;
    uVar1 = *(undefined2 *)((int)local_30 + (*(ushort *)(param_1 + 0x26c) >> 4 & 2));
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = uVar1;
    func_0x80032b5c(param_1,0);
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      uVar7 = func_0x80033604();
      uVar8 = 0xd;
      if ((uVar7 & 1) != 0) {
        uVar8 = 0xc;
      }
      func_0x80077d18(uVar8,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    iVar6 = 0;
    *(undefined1 *)(param_1 + 0x206) = 1;
    if ((*(ushort *)(param_1 + 0x26c) & 0x20) != 0) {
      iVar6 = 0x800;
      *(undefined1 *)(param_1 + 0x206) = 0xff;
    }
    if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
      local_28 = 0;
      local_26 = 800;
      local_24 = 0;
      func_0x80037780(0x17d0,(int)(((uint)*(ushort *)(param_1 + 0x66) - iVar6) * 0x10000) >> 0x10,
                      *(int *)(param_1 + 0x234) + 0x1b0,&local_28);
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x234);
      local_28 = *(short *)(iVar4 + 0xbde) + *(char *)(param_1 + 0x206) * -100;
      local_26 = *(short *)(iVar4 + 0xbe2) + 300;
      local_24 = *(undefined2 *)(iVar4 + 0xbe6);
      func_0x80037780(0x17d0,(int)(((uint)*(ushort *)(param_1 + 0x66) - iVar6) * 0x10000) >> 0x10,
                      *(int *)(param_1 + 0x234) + 0x38,&local_28);
    }
    cVar9 = *(char *)(param_1 + 5);
    if ((cVar9 == '\n') && ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0)) {
      FUN_80167910(param_1);
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x800;
      cVar9 = *(char *)(param_1 + 5);
    }
    if (cVar9 == '\v') {
      if (((*(ushort *)(param_1 + 0x2b6) & 0x1000) == 0) &&
         (uVar7 = func_0x80033604(param_1), (uVar7 & 1) == 0)) {
        uVar7 = func_0x80033604();
        uVar5 = func_0x80033604();
        uVar2 = *(ushort *)(param_1 + 0x2b6);
        uVar7 = (int)(uVar7 & 0xff) >> (uVar5 & 3) & 1;
        *(ushort *)(param_1 + 0x2b6) = uVar2 | 0x20;
        if (uVar7 != 0) {
          *(ushort *)(param_1 + 0x2b6) = uVar2 & 0xffdf | 0x40;
        }
        puVar11 = (uint *)(*(int *)(param_1 + 0x234) + uVar7 * 0x468 + 0xeb0);
        *(undefined2 *)(puVar11 + 0x4c) = 0;
        *(undefined2 *)((int)puVar11 + 0x132) = 0;
        *(undefined2 *)((int)puVar11 + 0x136) = 0x8032;
        *(undefined1 *)(puVar11 + 0x4d) = 5;
        *(undefined1 *)((int)puVar11 + 0x135) = 5;
        puVar11[0x18] = 0x304040;
        *puVar11 = *puVar11 | 0x10;
        func_0x80037780(0x40f0bb8,(int)*(short *)(param_1 + 0x66),puVar11 + 0xe,0);
        *(undefined2 *)(puVar11 + 0xaa) = 0;
        *(undefined2 *)((int)puVar11 + 0x2aa) = 0;
        *(undefined2 *)((int)puVar11 + 0x2ae) = 0x8032;
        *(undefined1 *)(puVar11 + 0xab) = 5;
        *(undefined1 *)((int)puVar11 + 0x2ad) = 5;
        puVar11[0x76] = 0x304040;
        puVar11[0x5e] = puVar11[0x5e] | 0x10;
        func_0x80037780(0x40f07d0,(int)*(short *)(param_1 + 0x66),puVar11 + 0x6c,0);
      }
      FUN_80167abc(param_1);
    }
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  cVar9 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar9;
  func_0x80032b5c(param_1,0);
  if ((*(short *)(param_1 + 0x1f6) != 0) && (*(char *)(param_1 + 0x206) != '\0')) {
    if ((*(ushort *)(param_1 + 0x1f6) & 1) == 0) {
      iVar6 = *(int *)(param_1 + 0x234);
      if (*(char *)(param_1 + 0x2be) == '\0') {
        uVar7 = func_0x80033604();
        uVar5 = func_0x80033604();
        uVar8 = 8000;
        uVar2 = *(ushort *)(param_1 + 0x66);
      }
      else {
        *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + -500;
        uVar7 = func_0x80033604();
        uVar5 = func_0x80033604();
        uVar8 = 0x13e8;
        uVar2 = *(ushort *)(param_1 + 0x66);
      }
      func_0x80037780(uVar8,(int)(((uint)uVar2 + (uVar7 & 0xff) * 0x10 + (uVar5 & 0xff) * -0x10) *
                                 0x10000) >> 0x10,iVar6 + 0x38,param_1 + 0x1e0);
    }
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -1;
  }
  return;
}
