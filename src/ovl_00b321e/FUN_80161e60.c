/* FUN_80161e60
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80161e60  body 0x80161e60..0x801620a3  size 580 B
 * body sha256 83a06dfe20ff7e79f1aa27e536d336353f8c9799a0bea10cc530304f6d419d86
 * provider record sha256 fed2a0fc9cdee2c7e0e1c21da1af04f7e43c7cdded3857b858b75ff4c21ee533
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161e60(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *param_1 = *param_1 | 0xc00000;
  puVar3 = param_1;
  do {
    puVar3[0xad] = 0;
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 0xc);
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  iVar2 = 0xfa;
  if ((_DAT_800e10ec & 0x20) != 0) {
    iVar2 = 200;
  }
  uVar1 = (undefined1)((ulonglong)(longlong)iVar2 / 3);
  *(short *)((int)param_1 + 0x1f2) = (short)iVar2;
  *param_1 = *param_1 | 0xc000000;
  *(undefined1 *)((int)param_1 + 0x1ef) = uVar1;
  *(undefined1 *)((int)param_1 + 0x1ee) = uVar1;
  *(undefined1 *)((int)param_1 + 0x1ed) = uVar1;
  func_0x800339dc(param_1 + 0x82,0,0x57807d0,0,param_1 + 10);
  param_1[0x94] = (uint)&DAT_800e1130;
  *(undefined1 *)(param_1 + 0x97) = 1;
  uVar4 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  *(undefined2 *)(uVar4 + 0x134) = 8;
  *(undefined2 *)(uVar4 + 0x138) = 0x100;
  *(undefined2 *)(uVar4 + 0x130) = 0;
  *(undefined2 *)(uVar4 + 0x132) = 0;
  *(undefined2 *)(uVar4 + 0x136) = 0;
  *(undefined2 *)(uVar4 + 0x13a) = 0;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xfce0;
  *(undefined2 *)((int)param_1 + 0x13a) = 1000;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x136) = 800;
  *(undefined2 *)(param_1 + 0x4e) = 0x578;
  *(undefined2 *)(param_1 + 0x4b) = 800;
  *(undefined2 *)((int)param_1 + 0x12e) = 0x578;
  *(undefined2 *)((int)param_1 + 0x28a) = 900;
  FUN_801665a0(param_1,0);
  uVar4 = 0;
  puVar3 = (uint *)(param_1[0x8d] + 0x1318);
  do {
    uVar4 = uVar4 + 1;
    *puVar3 = *puVar3 | 0x4000;
    puVar3 = puVar3 + 0x5e;
  } while (uVar4 < 4);
  *(undefined1 *)((int)param_1 + 0x2c9) = 2;
  *(undefined1 *)((int)param_1 + 0x2bd) = 1;
  *(undefined1 *)((int)param_1 + 0x2cb) = 0x1e;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x10) == 0) {
    param_1[0x7a] = 0;
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  else {
    *(undefined1 *)((int)param_1 + 5) = 10;
    param_1[0x7a] = 0x8000000;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined1 *)((int)param_1 + 0x2c5) = 1;
    *(undefined1 *)(param_1 + 0xaf) = 1;
    *(undefined2 *)(param_1 + 0x9c) = 0;
  }
  _DAT_800df9f0 = FUN_8016598c;
  return;
}
