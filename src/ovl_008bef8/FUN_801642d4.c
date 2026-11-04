/* FUN_801642d4
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801642d4  body 0x801642d4..0x80164587  size 692 B
 * body sha256 4b7392993d7b6ee8abd3e316821567e9f4bba2b8b82e6eced8c244a8900891d2
 * provider record sha256 037f640c47c70e7f72338540426e3e1f7228502d569d41af9641d4b829bfb845
 * callees 5 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801642d4(int param_1)

{
  byte bVar1;
  undefined1 uVar3;
  int iVar2;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      goto LAB_80164458;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80035b84(param_1);
    _DAT_800e90f8 = 1;
    _DAT_800e110c = _DAT_800e110c | 0x110;
    _DAT_800e1110 = _DAT_800e1110 | 0x1000000;
    *(undefined2 *)(param_1 + 0x20c) = 0xdbe0;
    *(undefined2 *)(param_1 + 0x20e) = 0xf8f8;
    *(undefined2 *)(param_1 + 0x210) = 0x3ca;
    *(undefined1 *)(param_1 + 7) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 2;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 4;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  if ((_DAT_800e110c & 0x80) != 0) {
    return;
  }
  if (*(char *)(param_1 + 0x2c1) != '\0') {
    *(undefined4 *)(param_1 + 0x28) = 0xffffb163;
    *(undefined4 *)(param_1 + 0x30) = 0xfffffc78;
    *(undefined2 *)(param_1 + 0x66) = 0x1000;
  }
  _DAT_800e1130 = _DAT_800e1130 | 0x80400;
  if ((_DAT_800e110c & 0x40000000) == 0) {
LAB_80164434:
    uVar4 = 7;
  }
  else {
    iVar2 = func_0x800837ac(0x800e8eb8,0x10);
    uVar4 = 0xe;
    if (iVar2 == 0) goto LAB_80164434;
  }
  func_0x80083c14(uVar4);
  DAT_800e9183 = 1;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
LAB_80164458:
  if (*(char *)(param_1 + 7) == '\0') {
    uVar3 = func_0x80036b2c(param_1 + 0x30,0,0x14);
    *(undefined1 *)(param_1 + 7) = uVar3;
  }
  iVar2 = func_0x80036c68(param_1,8,0,0);
  if (iVar2 != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
    func_0x80083c14(8);
    DAT_800e9183 = 1;
    _DAT_800e90f8 = 1;
    _DAT_800e110c = _DAT_800e110c & 0xfffffeef;
    _DAT_800e1110 = _DAT_800e1110 & 0xfeffffff;
    _DAT_800e1130 = _DAT_800e1130 & 0xfff7fbff;
    *(undefined4 *)(param_1 + 4) = 0x1060000;
    *(undefined2 *)(param_1 + 400) = 0xf830;
    *(undefined2 *)(param_1 + 0x192) = 7000;
    *(undefined2 *)(param_1 + 0x18c) = 0x1bee;
    *(undefined2 *)(param_1 + 0x196) = 0x1bee;
    *(undefined2 *)(param_1 + 0x18e) = 0x1bee;
    *(undefined2 *)(param_1 + 0x198) = 0x1bee;
    *(undefined2 *)(param_1 + 0x150) = 0xff6a;
    *(undefined2 *)(param_1 + 0x152) = 0x12c0;
    *(undefined2 *)(param_1 + 0x194) = 0;
    *(undefined2 *)(param_1 + 0x19a) = 2000;
    *(undefined2 *)(param_1 + 0x154) = 0;
    *(undefined2 *)(param_1 + 0x14c) = 0x157c;
    *(undefined2 *)(param_1 + 0x156) = 0x157c;
    *(undefined2 *)(param_1 + 0x15a) = 2000;
    *(undefined2 *)(param_1 + 0x14e) = 0x157c;
    *(undefined2 *)(param_1 + 0x158) = 0x157c;
  }
  return;
}
