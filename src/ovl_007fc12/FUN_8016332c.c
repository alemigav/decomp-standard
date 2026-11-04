/* FUN_8016332c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016332c  body 0x8016332c..0x8016384b  size 1312 B
 * body sha256 f987f7ada042042e83fb5e0f598aa8342aaabcd77825e88a2f500b72e04ee48a
 * provider record sha256 6677da60ec1eac0228e0d72c216ac7038b94ca70993cc908ea4bd3a29c0285b7
 * callees 9 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016332c(int param_1)

{
  char cVar5;
  ushort uVar4;
  byte bVar6;
  uint uVar1;
  uint uVar2;
  int iVar3;
  short sVar7;
  undefined4 uVar8;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
    bVar6 = func_0x80033604();
    *(byte *)(param_1 + 0x207) = (bVar6 & 0xf) << 1;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 500) =
         (uVar4 & 0xff) + (*(ushort *)(&DAT_8016e244 + *(char *)(param_1 + 0x207) * 2) & 0x7fff);
    bVar6 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (bVar6 & 0x1f) + 0x1e;
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    bVar6 = func_0x80033604();
    *(byte *)(param_1 + 0x1e9) = bVar6 & 0x1f;
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    uVar1 = func_0x80033604();
    *(short *)(param_1 + 0x1f6) = (short)((uVar1 & 0xff) >> 3) + 100;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  sVar7 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar7;
  if (sVar7 == -1) {
    cVar5 = *(char *)(param_1 + 0x207) + '\x01';
    *(char *)(param_1 + 0x207) = cVar5;
    if ('\x1f' < cVar5) {
      *(undefined1 *)(param_1 + 0x207) = 0;
    }
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 500) =
         (uVar4 & 0x1f) + (*(ushort *)(&DAT_8016e244 + *(char *)(param_1 + 0x207) * 2) & 0x7fff);
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x10 + (uVar4 & 1) * 0x20;
  }
  if (*(uint *)(param_1 + 0x28c) < 0x1389) {
    sVar7 = 8;
  }
  else {
    sVar7 = (*(short *)(&DAT_8016e244 + *(char *)(param_1 + 0x207) * 2) >> 0xf) * 0x10 + 8;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                  (int)sVar7);
  cVar5 = *(char *)(param_1 + 0x206) + -1;
  *(char *)(param_1 + 0x206) = cVar5;
  if (cVar5 == -1) {
    bVar6 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (bVar6 & 0xf) + 0x1e;
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      uVar1 = func_0x80033604();
      uVar8 = 10;
      if ((uVar1 & 0x1f) != 0) {
        uVar1 = func_0x80033604(10);
        uVar8 = 0xb;
        if ((uVar1 & 0x1f) != 0) goto LAB_80163578;
      }
      func_0x80077d18(uVar8,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
  }
LAB_80163578:
  if (*(uint *)(param_1 + 0x28c) < 3000) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
  }
  func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100);
  if ((((*(ushort *)(param_1 + 0x1aa) & 0x80) != 0) ||
      ((*(ushort *)(param_1 + 0x2b6) & 0x8000) != 0)) && ((uint)*(byte *)(param_1 + 0x1e9) % 3 == 2)
     ) {
    FUN_80162f78(param_1);
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
    func_0x8008aeec(param_1,*(undefined4 *)(param_1 + 0x218));
  }
  func_0x80032b5c(param_1,0);
  sVar7 = *(short *)(param_1 + 0x1f6);
  *(short *)(param_1 + 0x1f6) = sVar7 + -1;
  if (sVar7 == 1) {
    uVar1 = func_0x80033604();
    *(short *)(param_1 + 0x1f6) = (short)((uVar1 & 0xff) >> 3) + 100;
    uVar1 = func_0x80033604();
    if (((uVar1 & 3) == 0) && (*(uint *)(param_1 + 0x28c) < 5000)) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
    }
  }
  if (((*(ushort *)(param_1 + 0x1aa) & 0x80) != 0) || ((*(ushort *)(param_1 + 0x2b6) & 0x1000) != 0)
     ) {
    if (((*(ushort *)(param_1 + 0x2d2) & 7) == 0) && ((*(ushort *)(param_1 + 0x2b6) & 0x800) != 0))
    {
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      uVar4 = *(short *)(param_1 + 0x1f2) - 1;
      *(ushort *)(param_1 + 0x1f2) = uVar4;
      *(ushort *)(param_1 + 0x66) =
           *(short *)(param_1 + 0x66) + 0x40 +
           ((ushort)((int)(uVar1 & 0xff) >> (uVar2 & 3)) & 1) * -0x80;
      if ((int)((uint)uVar4 << 0x10) < 0) {
        *(undefined4 *)(param_1 + 4) = 0x30a0000;
        if ((*(ushort *)(param_1 + 0x2b6) & 0x1000) != 0) {
          *(undefined4 *)(param_1 + 4) = 0x30b0000;
        }
        *(undefined1 *)(param_1 + 0x26e) = 4;
        *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x2000;
        return;
      }
    }
    if ((*(ushort *)(param_1 + 0x2b6) & 0x1000) != 0) {
      uVar1 = func_0x80033604();
      *(short *)(param_1 + 0x66) =
           *(short *)(param_1 + 0x66) - ((short)((uVar1 & 0xff) >> 1) + -0x40);
    }
  }
  if (((*(uint *)(param_1 + 0x28c) < 2000) &&
      (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200), iVar3 == 0)) &&
     ((DAT_800e139f & 0x80) == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  if ((((_DAT_800e112a & 4) != 0) && (*(uint *)(param_1 + 0x28c) < 0x9c4)) &&
     (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x52c), iVar3 == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
