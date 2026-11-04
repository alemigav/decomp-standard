/* FUN_80161ea0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80161ea0  body 0x80161ea0..0x80162097  size 504 B
 * body sha256 e3a08f49420ce1db4598d4253f8856cee79b6577b3ec561869f94ce917bce11e
 * provider record sha256 b790ce42c211f5f5b54eefc5faff05a7bb9ab0917abbf2457cb97394cce61748
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161ea0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined2 uVar2;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  *(undefined2 *)((int)param_1 + 0x1f2) = 10;
  param_1[0xad] = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = 0;
  param_1[0xb0] = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  *(undefined2 *)(param_1 + 0x9c) = 0;
  *(undefined2 *)((int)param_1 + 0x272) = 0;
  *(undefined2 *)(param_1 + 0x9d) = 0;
  *(undefined2 *)((int)param_1 + 0x276) = 0;
  param_1[0x7a] = 0;
  func_0x80089d54();
  uVar1 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x25d) = 8;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar1 + 0x424) = 0x60;
  *(undefined2 *)(uVar1 + 0x426) = 0x60;
  *(undefined2 *)(uVar1 + 0x428) = 0x200;
  *(undefined2 *)(uVar1 + 0x420) = 0;
  *(undefined2 *)(uVar1 + 0x422) = 0;
  *(undefined2 *)(uVar1 + 0x42a) = 0x138;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x212;
  FUN_80166294(param_1,0x15e);
  *(undefined2 *)((int)param_1 + 0x28a) = 300;
  uVar2 = func_0x80069f1c(param_1 + 10,0xfa,0x400,0);
  *(undefined2 *)((int)param_1 + 0x25e) = uVar2;
  func_0x800339dc(param_1 + 0x82,0,0xc800c8,0,param_1 + 10);
  *param_1 = *param_1 | 0x8000000;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x4000) != 0) {
    *(undefined1 *)(param_1 + 1) = 4;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
    *(byte *)((int)param_1 + 5) = *(byte *)((int)param_1 + 0x1ab) & 0xf;
    *(ushort *)((int)param_1 + 0x2c6) = *(ushort *)((int)param_1 + 0x2c6) | 1;
    (*(code *)(&PTR_FUN_80166570)[*(byte *)(param_1 + 1)])(param_1,param_2,param_3);
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x40) != 0) {
    *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
    *param_1 = *param_1 | 8;
  }
  _DAT_800df98c = FUN_801662a8;
  return;
}
