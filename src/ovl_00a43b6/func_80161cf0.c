/* func_80161cf0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x801620af  size 960 B
 * body sha256 d2451384165a687e40f29dd1ddca4128dbc69cfb94a419bc46aa3ed191a45994
 * provider record sha256 d8702789960c8ba58d98d8949586488ea5bc22471587b0dea34a5c598c5e708a
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int in_a0;
  int iVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  short local_20 [4];
  ushort local_18;
  
  local_20[0] = 500;
  local_20[1] = 0;
  local_30 = _DAT_800e1158;
  local_2c = _DAT_800e115c;
  local_28 = _DAT_800e1160;
  local_24 = _DAT_800e1164;
  func_0x800653d0(in_a0,&local_30,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (((*(ushort *)(in_a0 + 0x2b8) & 2) != 0) &&
       (cVar1 = *(char *)(in_a0 + 0x2b4) + -1, *(char *)(in_a0 + 0x2b4) = cVar1, cVar1 == -1)) {
      if (*(char *)(in_a0 + 0x2b5) != '\0') {
        *(char *)(in_a0 + 0x2b5) = *(char *)(in_a0 + 0x2b5) + -1;
      }
      *(undefined1 *)(in_a0 + 0x2b4) = 0xf;
      if (*(char *)(in_a0 + 0x2b5) == '\0') {
        *(ushort *)(in_a0 + 0x2b8) = *(ushort *)(in_a0 + 0x2b8) & 0xfffd;
      }
    }
    if ((*(short *)(in_a0 + 0x1f2) < 0x1f5) && (*(short *)(in_a0 + 0x2c0) != 0)) {
      *(short *)(in_a0 + 0x2c0) = *(short *)(in_a0 + 0x2c0) + -1;
    }
    if ((((_DAT_800e10ec & 0x20) == 0) &&
        (cVar1 = *(char *)(in_a0 + 0x2b7) + -1, *(char *)(in_a0 + 0x2b7) = cVar1, cVar1 == -1)) &&
       (*(short *)(in_a0 + 0x2c0) != 0)) {
      *(undefined1 *)(in_a0 + 0x2b7) = 7;
      if ((0 < *(short *)(in_a0 + 0x1f2)) &&
         (*(short *)(in_a0 + 0x1f2) < local_20[*(ushort *)(in_a0 + 0x1aa) & 1])) {
        *(short *)(in_a0 + 0x1f2) = *(short *)(in_a0 + 0x1f2) + 1;
      }
    }
    if (*(char *)(in_a0 + 0x2b6) != '\0') {
      *(char *)(in_a0 + 0x2b6) = *(char *)(in_a0 + 0x2b6) + -1;
    }
    if (*(char *)(in_a0 + 0x2ca) != '\0') {
      *(char *)(in_a0 + 0x2ca) = *(char *)(in_a0 + 0x2ca) + -1;
    }
    if ((*(ushort *)(in_a0 + 0x2b8) & 0x20) != 0) {
      *(short *)(*(int *)(*(int *)(in_a0 + 0x234) + 0x298) + 0xc) =
           (char)(&DAT_801697a0)[*(char *)(in_a0 + 0x2ba)] * -0x10 + 0x1000;
      func_0x80066288();
      iVar3 = *(int *)(in_a0 + 0x234);
      iVar4 = *(int *)(iVar3 + 0x410);
      *(ushort *)(iVar4 + 0xc) =
           *(short *)(iVar4 + 0xc) + ((*(byte *)(in_a0 + 0x2ba) & 1) * -2 + 1) * -0x80;
      iVar3 = *(int *)(iVar3 + 0x410);
      *(ushort *)(iVar3 + 0x10) =
           *(short *)(iVar3 + 0x10) + ((*(byte *)(in_a0 + 0x2ba) & 1) * -2 + 1) * 0x80;
      func_0x80066288();
      bVar2 = *(char *)(in_a0 + 0x2ba) + 1;
      *(byte *)(in_a0 + 0x2ba) = bVar2 & 0x3f;
      if ((bVar2 & 0x10) != 0) {
        bVar2 = func_0x80033604();
        DAT_801697ea = '\a' - bVar2 % 0xf;
        bVar2 = func_0x80033604();
        DAT_801697eb = '\a' - bVar2 % 0xf;
      }
    }
    (*(code *)(&PTR_FUN_80169780)[*(byte *)(in_a0 + 4)])();
    FUN_80167c0c();
    *(undefined1 **)(in_a0 + 0x250) = &DAT_800e1130;
    func_0x800349d0();
    local_18 = local_18 & 0xfff;
    if (0x800 < local_18) {
      local_18 = local_18 - 0xfff;
    }
    iVar3 = *(int *)(in_a0 + 0x234);
    *(ushort *)(iVar3 + 0x4c2) = *(short *)(iVar3 + 0x4c2) + local_18;
    func_0x80040e58(iVar3 + 0x4c0,iVar3 + 0x470);
    *(ushort *)(iVar3 + 0x4c2) = *(short *)(iVar3 + 0x4c2) - local_18;
    FUN_80168ee8();
    FUN_801691dc();
    func_0x80033648();
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
