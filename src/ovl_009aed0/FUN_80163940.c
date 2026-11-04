/* FUN_80163940
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163940  body 0x80163940..0x80163be3  size 676 B
 * body sha256 4e7d32f003d2fcb28d73be08ee1e88c7ecc67c5aa28bf8cafb893c4e9229134c
 * provider record sha256 0e40206e6e5f462cedcfc567082019965060491a92b397a08a9076e9d20757d0
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163940(int param_1)

{
  byte bVar1;
  short sVar4;
  undefined4 uVar2;
  int iVar3;
  char cVar5;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [2];
  int local_18;
  
  local_28 = 0x640000;
  local_24 = 0xc80000;
  sVar4 = FUN_80162544();
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      uVar2 = 0x1010000;
      if (bVar1 != 2) {
        return;
      }
      goto LAB_80163bc8;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  iVar3 = FUN_801622f4(param_1,10,0xe,0x13,200,_DAT_800e1266);
  if (iVar3 != 0) {
    func_0x80052bd0(8,0);
    func_0x80052d10(0xd,200,0x28,2);
    FUN_80162cf8(param_1);
    func_0x80077d18(5,param_1);
    *(undefined1 *)(param_1 + 0x2c6) = 0x1e;
    if ((*(ushort *)(param_1 + 0x2b8) & 8) == 0) {
      *(undefined2 *)(param_1 + 0x2d0) = 0;
      FUN_80162694(0xf);
    }
  }
  cVar5 = func_0x80036c68(param_1,2,0xf,0);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
  if ((*(ushort *)(param_1 + 0x2b8) & 8) != 0) {
    _DAT_800e1110 = _DAT_800e1110 | 0x1000000;
    if (((*(short *)(param_1 + 500) != 0) && ((ushort)(sVar4 + 0x95U) < 0x1c1)) &&
       (*(uint *)(param_1 + 0x28c) < 0x708)) {
      func_0x80032dbc(&DAT_800e1130,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30),
                      0x80);
      func_0x800837d0((int)*(short *)(param_1 + 0x66),&local_28,&local_28);
      local_20[0] = *(int *)(param_1 + 0x28) + (int)local_28._0_2_;
      local_18 = *(int *)(param_1 + 0x30) + (int)local_24._0_2_;
      func_0x80036a30(&DAT_800e1158,local_20,0x96);
    }
  }
  if (*(char *)(param_1 + 0x1e9) != '\x14') {
    return;
  }
  cVar5 = '\x14';
  if (*(short *)(param_1 + 500) != 0) {
    if (((-1 < _DAT_800e1322) && ((ushort)(sVar4 + 0x95U) < 0x1c1)) &&
       (*(uint *)(param_1 + 0x28c) < 0x708)) {
      *(undefined4 *)(param_1 + 4) = 0x1050000;
    }
    cVar5 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar5 != '\x14') {
    return;
  }
  uVar2 = 0x1050000;
  if ((*(ushort *)(param_1 + 0x2b8) & 8) == 0) {
    return;
  }
LAB_80163bc8:
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
