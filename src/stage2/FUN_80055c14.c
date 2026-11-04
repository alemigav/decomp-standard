/* FUN_80055c14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80055c14  body 0x80055c14..0x80055fa3  size 912 B
 * body sha256 523862ad6fa9fbe3935de2f1b6d3db36779c2e7d590ee85ceb1471c5477c1f4d
 * provider record sha256 04996b5b849ca746dbc4b1e345d9a21d31465ebe9ee699d64e8be6fc50235b5b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80055c14(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined2 *)(param_1 + 0x26c) = 0;
  *(undefined2 *)(param_1 + 0x268) = 0;
  *(undefined2 *)(param_1 + 0x264) = 0;
  *(undefined1 *)(param_1 + 0x26f) = 0;
  *(int *)(param_1 + 0x250) = param_1;
  *(int *)(param_1 + 0x254) = param_1;
  *(undefined4 *)(param_1 + 0x1e8) = 0x2000000;
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x100);
  uVar4 = 500;
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined1 *)(param_1 + 0x25d) = 8;
  *(undefined1 *)(param_1 + 0x25c) = 0;
  *(undefined2 *)(iVar1 + 0xcf4) = 0x60;
  *(undefined2 *)(iVar1 + 0xcf6) = 0x60;
  *(undefined2 *)(iVar1 + 0xcf8) = 0x200;
  *(undefined2 *)(iVar1 + 0xcf0) = 0;
  *(undefined2 *)(iVar1 + 0xcf2) = 0;
  *(undefined2 *)(iVar1 + 0xcfa) = 0x138;
  cVar2 = *(char *)(param_1 + 8);
  iVar1 = 600;
  if ((((cVar2 == '\x01') || (cVar2 == '\x03')) || (cVar2 == '\x05')) ||
     ((cVar2 == '\a' || (cVar2 == '\t')))) {
    uVar4 = 0x1a4;
    iVar1 = 0x208;
    *(undefined2 *)(param_1 + 0x134) = 0xfaba;
    *(undefined2 *)(param_1 + 0x136) = 0x15e;
    *(undefined2 *)(param_1 + 0x13a) = 0x546;
    *(undefined2 *)(param_1 + 0x138) = 0x15e;
    *(undefined2 *)(param_1 + 300) = 0x15e;
    *(undefined2 *)(param_1 + 0x12e) = 0x15e;
    cVar2 = *(char *)(param_1 + 8);
  }
  if (cVar2 == '\x0e') {
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined2 *)(param_1 + 0x134) = 0xfaba;
    *(undefined2 *)(param_1 + 0x136) = 0x15e;
    *(undefined2 *)(param_1 + 0x13a) = 0x546;
    *(undefined2 *)(param_1 + 0x138) = 0x15e;
    *(undefined2 *)(param_1 + 300) = 0x15e;
    *(undefined2 *)(param_1 + 0x12e) = 0x15e;
    *(undefined4 *)(iVar3 + 0x1608) = 0;
    iVar1 = FUN_800837ac(&DAT_800e8cc0,0x50);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar3 + 0x1608) = 1;
    }
    uVar4 = 0x1a4;
    iVar1 = 0x208;
    *(int *)(iVar3 + 0x166c) = iVar3 + 0x38;
    *(undefined4 *)(iVar3 + 0x1624) = 0x42;
    *(int *)(iVar3 + 0x1734) = iVar3;
    *(undefined4 *)(iVar3 + 0x1628) = 0xfffffd72;
    *(undefined4 *)(iVar3 + 0x162c) = 0;
    *(undefined2 *)(iVar3 + 0x1660) = 0;
    *(undefined2 *)(iVar3 + 0x1662) = 0;
    *(undefined2 *)(iVar3 + 0x1664) = 0;
    *(undefined2 *)(iVar3 + 0x1738) = 0;
    *(undefined2 *)(iVar3 + 0x173a) = 0;
  }
  cVar2 = *(char *)(param_1 + 8);
  if (cVar2 == '\x0f') {
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined2 *)(param_1 + 0x134) = 0xfcd6;
    *(undefined2 *)(param_1 + 0x136) = 0xfa;
    *(undefined2 *)(param_1 + 0x13a) = 0x32a;
    *(undefined2 *)(param_1 + 0x138) = 0xfa;
    *(undefined2 *)(param_1 + 300) = 0xfa;
    *(undefined2 *)(param_1 + 0x12e) = 0xfa;
    *(undefined4 *)(iVar3 + 0x1608) = 0;
    *(int *)(iVar3 + 0x166c) = iVar3 + 0x38;
    *(undefined4 *)(iVar3 + 0x1624) = 8;
    *(int *)(iVar3 + 0x1734) = iVar3;
    *(undefined4 *)(iVar3 + 0x1628) = 0xfffffe53;
    *(undefined4 *)(iVar3 + 0x162c) = 0;
    *(undefined2 *)(iVar3 + 0x1660) = 0;
    *(undefined2 *)(iVar3 + 0x1662) = 0;
    *(undefined2 *)(iVar3 + 0x1664) = 0;
    *(undefined2 *)(iVar3 + 0x1738) = 0;
    *(undefined2 *)(iVar3 + 0x173a) = 0;
    *(uint *)(iVar3 + 0x1608) = *(uint *)(iVar3 + 0x1608) | 0x40;
    iVar1 = FUN_800837ac(&DAT_800e8ce0,0xff);
    uVar4 = 0x172;
    if (iVar1 != 0) {
      *(uint *)(iVar3 + 0x1608) = *(uint *)(iVar3 + 0x1608) | 1;
    }
    iVar1 = 0x1cc;
    cVar2 = *(char *)(param_1 + 8);
  }
  if (((cVar2 == '\x01') || (cVar2 == '\x03')) ||
     ((cVar2 == '\x05' || ((cVar2 == '\a' || (cVar2 == '\t')))))) {
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar3 + 0x1624) = 0xffffffd8;
    *(undefined4 *)(iVar3 + 0x1628) = 0xfffffe90;
    *(undefined4 *)(iVar3 + 0x162c) = 0;
    *(undefined2 *)(iVar3 + 0x1738) = 0;
    *(undefined2 *)(iVar3 + 0x173a) = 0;
    *(undefined2 *)(iVar3 + 0x1662) = 0;
    *(uint *)(iVar3 + 0x1608) = *(uint *)(iVar3 + 0x1608) | 0x41;
    *(undefined4 *)(iVar3 + 0x179c) = 0xffffffd0;
    *(undefined4 *)(iVar3 + 0x17a0) = 0xffffffe0;
    *(undefined4 *)(iVar3 + 0x1914) = 0xffffffa5;
    *(undefined4 *)(iVar3 + 0x1918) = 0x61;
    *(undefined4 *)(iVar3 + 0x1a8c) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x1a90) = 0x7f;
    *(undefined4 *)(iVar3 + 0x17a4) = 0;
    *(undefined2 *)(iVar3 + 0x18b0) = 0;
    *(undefined2 *)(iVar3 + 0x18b2) = 0;
    *(undefined2 *)(iVar3 + 0x17da) = 0;
    *(undefined4 *)(iVar3 + 0x191c) = 0;
    *(undefined2 *)(iVar3 + 0x1a28) = 0;
    *(undefined2 *)(iVar3 + 0x1a2a) = 0;
    *(undefined2 *)(iVar3 + 0x1952) = 0;
    *(undefined4 *)(iVar3 + 0x1a94) = 0;
    *(undefined2 *)(iVar3 + 0x1ba0) = 0;
    *(undefined2 *)(iVar3 + 0x1ba2) = 0;
    *(undefined2 *)(iVar3 + 0x1aca) = 0;
    *(uint *)(iVar3 + 0x1780) = *(uint *)(iVar3 + 0x1780) | 0x41;
    *(uint *)(iVar3 + 0x18f8) = *(uint *)(iVar3 + 0x18f8) | 0x41;
    *(uint *)(iVar3 + 0x1a70) = *(uint *)(iVar3 + 0x1a70) | 0x41;
  }
  if ((DAT_800dfc22 & 1) == 0) {
    FUN_800339dc(param_1 + 0x208,0,uVar4 | iVar1 << 0x10,0,*(int *)(param_1 + 0x234) + 0x4c);
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0xc) {
    FUN_8005fa54(param_1);
  }
  return;
}
