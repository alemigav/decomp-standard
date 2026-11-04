/* FUN_80164a60
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80164a60  body 0x80164a60..0x80164e7b  size 1052 B
 * body sha256 20873dd8561bd81f8e902bc39202913d05b40b360cec115517fd07b2a40862c2
 * provider record sha256 42037396378e01189683d990c239577df5cd0f3096095906ebef496f90560f93
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164a60(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  char cVar7;
  uint *puVar5;
  int *piVar6;
  short *psVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  short local_28 [4];
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar12 = *(int *)(param_1 + 0x208);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if ((*(short *)(param_1 + 500) == 0x1e) || (*(short *)(param_1 + 500) == 0x3c)) {
          *(undefined1 *)(param_1 + 0x1ea) = 7;
          *(char *)(param_1 + 0x1e8) = *(char *)(param_1 + 0x1e8) + '\x01';
        }
        uVar4 = *(short *)(param_1 + 500) + 1;
        *(ushort *)(param_1 + 500) = uVar4;
        if (((uVar4 & 0x1f) == 0) && (*(char *)(param_1 + 0x207) == '\0')) {
          iVar10 = *(int *)(param_1 + 0x234);
          uVar3 = func_0x80033604();
          local_28[0] = (short)((uVar3 & 0xff) >> 1) + 0x40;
          local_28[1] = 200;
          uVar3 = func_0x80033604();
          local_28[2] = 0x40 - (short)((uVar3 & 0xff) >> 1);
          uVar3 = func_0x80033604();
          func_0x80037780(0x805f4,(uVar3 & 0xff) << 4,iVar10 + 0x38,local_28);
        }
        iVar10 = 10;
        psVar8 = (short *)(*(int *)(param_1 + 0x234) + 0x128);
        do {
          iVar10 = iVar10 + -1;
          psVar8[-2] = psVar8[-2] + 10;
          *psVar8 = *psVar8 + 10;
          psVar8[-1] = psVar8[-1] + -0x28;
          psVar8 = psVar8 + 0xbc;
        } while (iVar10 != 0);
        iVar11 = *(int *)(param_1 + 0x234);
        iVar10 = 10;
        if (*(char *)(iVar11 + 99) != ' ') {
          piVar6 = (int *)(iVar11 + 0x60);
          iVar2 = iVar11;
          do {
            iVar11 = iVar2;
            iVar10 = iVar10 + -1;
            *piVar6 = *piVar6 + -0x10001;
            piVar6 = piVar6 + 0x5e;
            iVar2 = iVar11 + 0x178;
          } while (iVar10 != 0);
        }
        if ((*(uint *)(iVar12 + 0x18) & 0xff0000) != 0x200000) {
          *(uint *)(iVar12 + 0x18) = *(uint *)(iVar12 + 0x18) + 0x2fc0300;
          *(undefined1 *)(iVar12 + 0x1b) = 1;
          *(short *)(iVar12 + 4) = *(short *)(iVar12 + 4) + 10;
          *(short *)(iVar12 + 6) = *(short *)(iVar12 + 6) + 10;
        }
        if (*(short *)(iVar11 + 0x126) < 0) {
          *(undefined1 *)(param_1 + 6) = 3;
        }
        func_0x80089d54(param_1,param_2,param_3,0x100);
      }
      else if (bVar1 == 3) {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
      }
      goto LAB_80164e30;
    }
    if (bVar1 != 0) goto LAB_80164e30;
    uVar3 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar3 & 7) * 0x10000 + 0x9000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    func_0x80037780(0x817d0,0,*(int *)(param_1 + 0x234) + 0x38,0);
    uVar3 = (uint)*(byte *)(param_1 + 5);
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    *(undefined1 *)(param_1 + 0x207) = 0;
    if (((uVar3 - 9 < 2) || (uVar3 == 0x10)) || (uVar3 == 0x11)) {
      uVar3 = func_0x80033604();
      func_0x80037780((uVar3 & 0xff) * 4 + 0xc18 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                      param_1 + 0x14,0);
      *(undefined1 *)(param_1 + 0x207) = 1;
    }
    cVar7 = *(char *)(param_1 + 5);
    if ((cVar7 == '\v') || (cVar7 == '\x0e')) {
      uVar3 = func_0x80033604();
      func_0x80037780((uVar3 & 0xff) * 4 + 0xc18 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                      param_1 + 0x14,0);
      *(undefined1 *)(param_1 + 0x207) = 1;
      cVar7 = *(char *)(param_1 + 5);
    }
    if (cVar7 == '\f') {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
    }
    func_0x80077d18(3,param_1);
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80032b5c(param_1,0);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + *(short *)(param_1 + 500) * -0x14;
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  if (*(short *)(param_1 + 0x1e0) < 0) {
    *(undefined1 *)(param_1 + 6) = 2;
    uVar4 = func_0x80033604();
    iVar12 = 10;
    puVar9 = *(uint **)(param_1 + 0x234);
    *(ushort *)(param_1 + 500) = uVar4 & 7;
    puVar5 = puVar9 + 0x4a;
    do {
      iVar12 = iVar12 + -1;
      *puVar9 = *puVar9 | 0x2000;
      *(undefined2 *)(puVar5 + -1) = 0x1000;
      *(undefined2 *)((int)puVar5 + -2) = 0x1000;
      *(undefined2 *)puVar5 = 0x1000;
      puVar5 = puVar5 + 0x5e;
      puVar9 = puVar9 + 0x5e;
    } while (iVar12 != 0);
  }
LAB_80164e30:
  iVar12 = *(int *)(param_1 + 0x2c) + 100;
  if (*(int *)(param_1 + 0x2c) < (int)*(short *)(param_1 + 0x25e)) {
    *(int *)(param_1 + 0x2c) = iVar12;
    if (*(short *)(param_1 + 0x25e) <= iVar12) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    }
  }
  return;
}
