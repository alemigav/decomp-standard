/* FUN_80162308
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162308  body 0x80162308..0x8016248b  size 388 B
 * body sha256 3ae66c41c466836c1a1ef9020f2cad240facdc48ee6bbe9d2432cf055fafc68e
 * provider record sha256 89f966b87c1ebb60ab4dcbb11dff648a55131da8eeb6217288680691809c8c96
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162308(int param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    _DAT_800e110c = _DAT_800e110c | 0x110;
    _DAT_800e90f8 = 1;
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 2;
    if (*(char *)(param_1 + 0x1e9) == 'F') {
      func_0x80083c14(0);
    }
    iVar2 = func_0x80036c68(param_1,6,0,0);
    if (iVar2 != 0) {
      func_0x80083c14(1);
      *(undefined4 *)(param_1 + 0x30) = 0xffffad24;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (*(short *)(param_1 + 0x270) != 0)) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
  }
  else if ((bVar1 == 2) && (iVar2 = func_0x80036c68(param_1,3,0,0), iVar2 != 0)) {
    _DAT_800e90f8 = 1;
    _DAT_800e110c = _DAT_800e110c & 0xfffffeef;
    *(undefined1 *)(param_1 + 0x2d4) = 0x6e;
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) & 0xfffd;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x400;
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 4;
  }
  return;
}
