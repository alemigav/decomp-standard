/* FUN_80161db8
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80161db8  body 0x80161db8..0x80161f73  size 444 B
 * body sha256 5a9ab74b19cb164b81ff8510ef9cf6593e6359333c289023987005526142db35
 * provider record sha256 f61f57b704e77b064dbb3a58db113f5a60816be7f577f5991a84faacf20b6d2b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161db8(uint *param_1)

{
  ushort uVar2;
  int iVar1;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  *(undefined2 *)((int)param_1 + 0x1f2) = 1;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  puVar3 = param_1;
  do {
    puVar3[0xad] = 0;
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 0xc);
  param_1[0x7a] = 0xf00;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0x78;
  *param_1 = *param_1 | 0x4c00000;
  uVar2 = func_0x80033604();
  *(ushort *)(param_1 + 0xae) = uVar2 & 0x1f;
  param_1[0xad] = 0x800e1130;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xfff6;
  *(undefined2 *)((int)param_1 + 0x136) = 10;
  *(undefined2 *)((int)param_1 + 0x13a) = 10;
  *(undefined2 *)(param_1 + 0x4e) = 10;
  *(undefined2 *)(param_1 + 0x4b) = 10;
  *(undefined2 *)((int)param_1 + 0x12e) = 10;
  *(undefined2 *)((int)param_1 + 0x28a) = 0x14;
  *(undefined1 *)((int)param_1 + 0x26f) = 6;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  *(undefined2 *)(param_1 + 0x19) = 0;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  *(undefined2 *)(param_1 + 0x7d) = 0;
  param_1[1] = (uint)(byte)(&DAT_80162d30)[*(byte *)((int)param_1 + 0x1ab)] * 0x10000 + 0x1000000;
  switch(*(undefined1 *)((int)param_1 + 0x1ab)) {
  case 0:
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
    *param_1 = *param_1 | 0x8044a;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
    break;
  case 4:
  case 5:
    *(undefined2 *)(param_1 + 0x78) = 200;
    *param_1 = *param_1 & 0xe3ffffff | 2;
  }
  func_0x800339dc(param_1 + 0x82,0,0xc800c8,0,param_1 + 10);
  iVar1 = func_0x80074d64(param_1[10],param_1[0xc]);
  if (iVar1 != 0) {
    *param_1 = *param_1 | 0x400;
  }
  return;
}
