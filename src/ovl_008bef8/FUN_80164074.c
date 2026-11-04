/* FUN_80164074
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80164074  body 0x80164074..0x801642d3  size 608 B
 * body sha256 ce3062e85901046496ddd1e792da25132df2f34f15bd2cccd9e1dc107ca93584
 * provider record sha256 874a5204298e2bbf51a079565f97b0d03de09c24c1b5ab93bf19a57610b70efd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164074(int param_1)

{
  short sVar2;
  int iVar1;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    _DAT_800e90f8 = 1;
    _DAT_800e110c = _DAT_800e110c | 0x110;
    _DAT_800e1110 = _DAT_800e1110 | 0x1000000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 2;
    break;
  case 1:
    if ((_DAT_800e110c & 0x80) != 0) {
      return;
    }
    _DAT_800e1130 = _DAT_800e1130 | 0x80400;
    func_0x80083c14(9);
    DAT_800e9183 = 1;
    if (*(char *)(param_1 + 0x2c1) == '\0') {
      sVar2 = *(short *)(param_1 + 0x66) + -0x400;
    }
    else {
      *(undefined4 *)(param_1 + 0x28) = 0xffffb163;
      *(undefined4 *)(param_1 + 0x30) = 0xfffffc78;
      sVar2 = 0xc00;
    }
    *(short *)(param_1 + 0x66) = sVar2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 2:
    iVar1 = func_0x80036c68(param_1,7,0,0);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x207) = 0;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      func_0x80077adc(0x20e0001,param_1 + 0x28);
    }
    break;
  case 3:
    iVar1 = func_0x80036c68(param_1,1,7,0);
    iVar1 = (uint)*(byte *)(param_1 + 0x207) + iVar1;
    *(char *)(param_1 + 0x207) = (char)iVar1;
    if (iVar1 * 0x1000000 >> 0x18 == 4) {
      *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 8;
    }
    if (*(char *)(param_1 + 0x207) == '\x05') {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      func_0x80083c14(8);
      DAT_800e9183 = 1;
      _DAT_800e110c = _DAT_800e110c & 0xfffffeef;
      _DAT_800e1110 = _DAT_800e1110 & 0xfeffffff;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
      _DAT_800e90f8 = 1;
      _DAT_800e1130 = _DAT_800e1130 & 0xfff7fbff;
      func_0x80036c68(param_1,8,0,0);
    }
  }
  return;
}
