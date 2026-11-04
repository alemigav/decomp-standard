/* FUN_8016b1f4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016b1f4  body 0x8016b1f4..0x8016b4ef  size 764 B
 * body sha256 a9206e3c92903cca40639d824bbfbb04f0986b5cd690aa3855ca48f2aa6c57ac
 * provider record sha256 6ac22ba324f27c6464a341888ed7a8a66133282a02f91b86d16ec740729e2019
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b1f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined4 uVar6;
  byte local_28 [16];
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  
  local_28[0] = 0x37;
  local_28[1] = 0x16;
  local_28[2] = 1;
  local_28[3] = 0x28;
  local_28[4] = 0x17;
  local_28[5] = 1;
  local_28[6] = 0;
  local_28[7] = 1;
  local_28[8] = 1;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        if (bVar1 == 3) {
          *(undefined4 *)(param_1 + 4) = 0x7000000;
          return;
        }
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x80);
      if (*(char *)(param_1 + 0x1ea) != '\0') {
        return;
      }
      goto LAB_8016b4cc;
    }
    if (bVar1 != 0) {
      return;
    }
    uVar2 = *(ushort *)(param_1 + 0x2b6);
    *(ushort *)(param_1 + 0x2b6) = uVar2 | 4;
    if (*(char *)(param_1 + 0x2d0) == '\x01') {
      *(ushort *)(param_1 + 0x2b6) = uVar2 & 0xfffb;
    }
    iVar3 = (uint)*(byte *)(param_1 + 0x2d0) * 3;
    if (*(byte *)(param_1 + 0x1e9) < local_28[iVar3]) {
      bVar1 = local_28[iVar3 + 1];
      *(undefined1 *)(param_1 + 0x207) = 0;
      iVar3 = (uint)bVar1 * 0x1000000 + 0x1f00;
    }
    else {
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
      bVar1 = local_28[(uint)*(byte *)(param_1 + 0x2d0) * 3 + 2];
      *(undefined1 *)(param_1 + 0x207) = 1;
      iVar3 = (uint)bVar1 * 0x1000000 + 0x1e1f00;
    }
    *(int *)(param_1 + 0x1e8) = iVar3;
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    local_18 = *(undefined2 *)(iVar3 + 0xbde);
    local_16 = *(short *)(iVar3 + 0xbe2) + 300;
    local_14 = *(undefined2 *)(iVar3 + 0xbe6);
    func_0x80037780(0x1fa0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,
                    &local_18);
    uVar4 = func_0x80033604();
    uVar6 = 0xb;
    if ((uVar4 & 1) != 0) {
      uVar6 = 0xd;
    }
    func_0x80077d18(uVar6,param_1);
    func_0x80035b84(param_1);
    cVar5 = *(char *)(param_1 + 5);
    if ((cVar5 == '\n') && ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0)) {
      FUN_80167910(param_1);
      cVar5 = *(char *)(param_1 + 5);
    }
    if (cVar5 == '\v') {
      FUN_80167abc(param_1);
      iVar3 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar3 + 0xbc0) = *(uint *)(iVar3 + 0xbc0) | 0x10;
      *(undefined2 *)(iVar3 + 0xcf6) = 0x801e;
      *(undefined2 *)(iVar3 + 0xcf0) = 0;
      *(undefined2 *)(iVar3 + 0xcf2) = 0;
      *(undefined1 *)(iVar3 + 0xcf4) = 10;
      *(undefined1 *)(iVar3 + 0xcf5) = 10;
      *(undefined4 *)(iVar3 + 0xc20) = 0x304040;
      func_0x80037780(0x40f0fa0,(int)*(short *)(param_1 + 0x66),iVar3 + 0xbf8,0);
    }
    cVar5 = *(char *)(param_1 + 5);
    if ((cVar5 == '\t') || (cVar5 == '\x11')) {
      if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
        FUN_80167ba4(param_1);
      }
      cVar5 = *(char *)(param_1 + 5);
    }
    if (cVar5 == '\x0e') {
      FUN_80167c88(param_1);
    }
    *(undefined2 *)(param_1 + 0x1e0) = 0xb;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar3 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x207) == '\0') {
    *(undefined1 *)(param_1 + 6) = 2;
    return;
  }
LAB_8016b4cc:
  *(undefined1 *)(param_1 + 6) = 3;
  return;
}
