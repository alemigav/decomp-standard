/* FUN_801623f0
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x801623f0  body 0x801623f0..0x80162567  size 376 B
 * body sha256 b1ed642e12b9fad19e6603926a4e2889fb928d291e4566449820d5a09f39c8bf
 * provider record sha256 fb1e1f480bf9f686b5ee9e526e51b5d2024a3d29188e6f0f3318bebd9b06ddf5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801623f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1060300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 800;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  case 1:
    cVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
    sVar2 = *(short *)(param_1 + 0x1e0) + -0x96;
    *(short *)(param_1 + 0x1e0) = sVar2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    if (sVar2 < 300) {
      *(undefined2 *)(param_1 + 0x1e0) = 300;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    cVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
    uVar3 = *(short *)(param_1 + 0x1e0) - 0x14;
    *(ushort *)(param_1 + 0x1e0) = uVar3;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    if ((int)((uint)uVar3 << 0x10) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 4:
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
  }
  func_0x80032b5c(param_1,0x800);
  return;
}
