/* FUN_80161e0c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80161e0c  body 0x80161e0c..0x80162147  size 828 B
 * body sha256 fa4493e6598e7efdd5fdda5fcbe8bafc6016aba1bceb58b8ab0d1a18f63e41fd
 * provider record sha256 6a8c1612eb442b24de4199743f5fe7316d23536ef83c088cac6632a136581379
 * callees 6 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161e0c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar3;
  uint uVar1;
  int iVar2;
  undefined *puVar4;
  uint *puVar5;
  uint uVar6;
  
  param_1[1] = 0x1000000;
  *param_1 = *param_1 | 0xc00000;
  uVar3 = func_0x80033604();
  if ((_DAT_800e10ec & 0x20) == 0) {
    uVar1 = func_0x80033604();
    puVar4 = &DAT_80167ca4;
  }
  else {
    uVar1 = func_0x80033604();
    puVar4 = &DAT_80167cc4;
  }
  uVar6 = 0;
  *(ushort *)((int)param_1 + 0x1f2) = *(short *)(puVar4 + (uVar1 & 0xf) * 2) + (uVar3 & 3);
  *(undefined1 *)((int)param_1 + 0x1ed) = 6;
  *(undefined1 *)((int)param_1 + 0x1ee) = 6;
  *(undefined1 *)((int)param_1 + 0x1ef) = 6;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  puVar5 = param_1;
  do {
    puVar5[0xad] = 0;
    uVar6 = uVar6 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar6 < 0xc);
  param_1[0x7a] = 0x1000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  uVar1 = param_1[0x8d];
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined1 *)((int)param_1 + 0x25d) = 8;
  *(undefined2 *)(uVar1 + 0xcf4) = 0x60;
  *(undefined2 *)(uVar1 + 0xcf6) = 0x60;
  *(undefined2 *)(uVar1 + 0xcf8) = 0x200;
  *(undefined2 *)(uVar1 + 0xcf0) = 0;
  *(undefined2 *)(uVar1 + 0xcf2) = 0;
  *(undefined2 *)(uVar1 + 0xcfa) = 0x138;
  func_0x800339dc(param_1 + 0x82,0,0x3200320,0,param_1 + 10);
  *(undefined1 *)((int)param_1 + 0x2bd) = 8;
  param_1[0xa1] = 1;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0x3200320;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0xfa8803e8;
  param_1[0x4e] = 0x3e80578;
  param_1[0x4f] = 0;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  iVar2 = func_0x80036ed8(param_1,param_1 + 0xb7,0x25);
  if (iVar2 == 0) {
    param_1[0xb7] = 0;
  }
  switch(*(ushort *)((int)param_1 + 0x1aa) & 0xf) {
  case 0:
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    *(undefined2 *)((int)param_1 + 0x2b6) = 0;
    *param_1 = *param_1 | 0xc000000;
    break;
  case 2:
  case 3:
    *(undefined1 *)((int)param_1 + 0x2be) = 1;
    *(undefined2 *)((int)param_1 + 0x2b6) = 0x800;
    *(undefined2 *)(param_1 + 0x1a) = 0x800;
    *(undefined2 *)(param_1 + 0x4d) = 0;
    *param_1 = *param_1 | 0x10000000;
    param_1[0xb2] = param_1[0xb] + 0x4e2;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    *(undefined1 *)((int)param_1 + 0x2be) = 3;
    *(undefined2 *)((int)param_1 + 0x2b6) = 0x800;
    uVar1 = (int)(*(byte *)((int)param_1 + 0x1ab) - 4) >> 1;
    *(char *)(param_1 + 0xb3) = (char)uVar1;
    *(short *)((int)param_1 + 0x66) = (short)((uVar1 & 0xff) << 10);
    param_1[0x48] = 0;
    param_1[0x49] = 0;
    param_1[0x4a] = 0;
    param_1[0x4b] = 0x1e001e;
    param_1[0x4c] = 0;
    param_1[0x4d] = 1000;
    param_1[0x4e] = 0x3e80578;
    param_1[0x4f] = 0;
    func_0x800667d4(param_1 + 10,800,1 << (*(byte *)((int)param_1 + 0x1a2) & 0x1f),0x400);
    FUN_80166b94(param_1);
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0xf0) == 0) {
      uVar1 = 0xfffff088;
    }
    else {
      uVar1 = ((*(ushort *)((int)param_1 + 0x1aa) & 0xf0) >> 4) * -0x708 + 0x4e2;
    }
    param_1[0xb2] = uVar1;
    *(undefined1 *)((int)param_1 + 0x2c1) = 1;
  }
  return;
}
