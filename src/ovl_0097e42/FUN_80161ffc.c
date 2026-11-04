/* FUN_80161ffc
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80161ffc  body 0x80161ffc..0x801621d7  size 476 B
 * body sha256 67172bc26ae5e1edc86cd2b9c03753dda17c1c9feb2ea576506121a91a9c9d39
 * provider record sha256 84a21971a33352f9228de44b91a653d21ec065a21f9112cc892fd75831a7a27d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161ffc(uint *param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar3 = param_1[0x8d];
  _DAT_800df9ac = FUN_80163338;
  *(undefined2 *)((int)param_1 + 0x1f2) = 10;
  param_1[1] = 0x1000000;
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  DAT_80163b00 = 0;
  DAT_80163b04 = 0;
  DAT_80163b0c = 0;
  DAT_80163b08 = 0;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined2 *)(param_1 + 0xad) = 0;
  *(undefined2 *)((int)param_1 + 0x2b6) = 0;
  *(undefined2 *)(param_1 + 0xae) = 0;
  *(undefined2 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)((int)param_1 + 0x2c2) = 0;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
  *param_1 = *param_1 | 0x800000;
  *(undefined2 *)(param_1 + 0xb0) = 0;
  *(undefined2 *)((int)param_1 + 0x2be) = 0;
  *(undefined2 *)(param_1 + 0xaf) = 0;
  *(undefined1 *)((int)param_1 + 0x2c3) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  param_1[0x7a] = 0x1000000;
  func_0x80089d54();
  *(undefined4 *)(uVar3 + 0x2f0) = 0;
  *(undefined4 *)(uVar3 + 0x468) = 0;
  *(undefined2 *)((int)param_1 + 0x1da) = 0xc00;
  *(undefined2 *)(param_1 + 0x76) = 0;
  *(undefined2 *)(param_1 + 0x77) = 0;
  *param_1 = *param_1 | 0x2000000;
  uVar1 = _DAT_800e9030;
  uVar3 = _DAT_800e902c;
  param_1[0x6e] = _DAT_800e9028;
  param_1[0x6f] = uVar3;
  param_1[0x70] = uVar1;
  uVar1 = _DAT_800e903c;
  uVar3 = _DAT_800e9038;
  param_1[0x71] = _DAT_800e9034;
  param_1[0x72] = uVar3;
  param_1[0x73] = uVar1;
  uVar3 = _DAT_800e9044;
  param_1[0x74] = _DAT_800e9040;
  param_1[0x75] = uVar3;
  *(undefined2 *)((int)param_1 + 0x13a) = 100;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)(param_1 + 0x4b) = 1;
  *(undefined2 *)((int)param_1 + 0x136) = 1;
  *(undefined2 *)((int)param_1 + 0x12e) = 1;
  *(undefined2 *)(param_1 + 0x4e) = 1;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  func_0x80036e70(param_1);
  uVar2 = func_0x80033604();
  *(ushort *)((int)param_1 + 0x66) = (uVar2 & 0xff) << 4;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  FUN_801634c8(param_1);
  *param_1 = *param_1 | 0x1c000002;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  return;
}
