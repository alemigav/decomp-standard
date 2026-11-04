/* FUN_80163b6c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80163b6c  body 0x80163b6c..0x80163edb  size 880 B
 * body sha256 00a252d778eecdb8ecad5d0500e23a93472c1999918c27002bc11f5f89405191
 * provider record sha256 bcb2972c6a323b7555fbe1afe5567ec094c99e7b57db1e5d93bbb16597fc2cc0
 * callees 9 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163b6c(int param_1)

{
  short sVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar1;
  int iVar2;
  undefined4 uVar6;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (*(byte *)(param_1 + 0x2b4) + 4) * 0x1000000 + 0xf00;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar4 & 0x3f) + 0xb4;
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      uVar1 = func_0x80033604();
      uVar6 = 0xb;
      if ((uVar1 & 1) == 0) {
        uVar6 = 10;
      }
      func_0x80077d18(uVar6,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    bVar5 = func_0x80033604();
    *(byte *)(param_1 + 0x1e9) = bVar5 & 0x1f;
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar4 & 0x1f) + 0x2d;
    *(undefined1 *)(param_1 + 0x206) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (*(char *)(param_1 + 0x206) == '\0') {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
  }
  else {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                    0xfffffff0);
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
  }
  if (((*(uint *)(param_1 + 0x1ac) & 1) != 0) &&
     (sVar3 = *(short *)(param_1 + 0x1f6) + -1, *(short *)(param_1 + 0x1f6) = sVar3, sVar3 == -1)) {
    uVar4 = func_0x80033604(param_1);
    *(ushort *)(param_1 + 0x1f6) = (uVar4 & 0x1f) + 0x2d;
    bVar5 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (bVar5 & 7) + 5;
  }
  func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100);
  if ((((*(ushort *)(param_1 + 0x1aa) & 0x80) != 0) ||
      ((*(ushort *)(param_1 + 0x2b6) & 0x8000) != 0)) && ((uint)*(byte *)(param_1 + 0x1e9) % 3 == 2)
     ) {
    FUN_80162f78(param_1);
    func_0x8008aeec(param_1,*(undefined4 *)(param_1 + 0x218));
  }
  func_0x80032b5c(param_1,0);
  if (((*(ushort *)(param_1 + 0x1aa) & 0x80) != 0) || ((*(ushort *)(param_1 + 0x2b6) & 0x1000) != 0)
     ) {
    if (((*(ushort *)(param_1 + 0x2d2) & 7) == 0) &&
       (((*(ushort *)(param_1 + 0x2b6) & 0x800) != 0 &&
        (uVar4 = *(short *)(param_1 + 0x1f2) - 1, *(ushort *)(param_1 + 0x1f2) = uVar4,
        (int)((uint)uVar4 << 0x10) < 0)))) {
      *(undefined4 *)(param_1 + 4) = 0x30a0000;
      if ((*(ushort *)(param_1 + 0x2b6) & 0x1000) != 0) {
        *(undefined4 *)(param_1 + 4) = 0x30b0000;
      }
      *(undefined1 *)(param_1 + 0x26e) = 4;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x2000;
      return;
    }
    if ((*(ushort *)(param_1 + 0x2b6) & 0x1000) != 0) {
      uVar1 = func_0x80033604();
      *(short *)(param_1 + 0x66) =
           *(short *)(param_1 + 0x66) - ((short)((uVar1 & 0xff) >> 1) + -0x40);
    }
  }
  sVar3 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar3;
  if ((sVar3 == -1) || ((DAT_800e139f & 0x80) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  if (((5000 < *(uint *)(param_1 + 0x28c)) ||
      (iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400), iVar2 != 0)) &&
     (*(short *)(param_1 + 500) < 0x78)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
