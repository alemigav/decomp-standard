/* FUN_80162010
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162010  body 0x80162010..0x8016226f  size 608 B
 * body sha256 77068a8b7bdb668c7584271f78598b20caf7240224d25c702938da45170c3de1
 * provider record sha256 19863d2d5549dc91c40684e1ec6312a740ee26cd9ed3c03e80f0a5fe6b73f828
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162010(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)param_1[0x8d];
  _DAT_800df994 = FUN_801646a8;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined2 *)((int)param_1 + 0x1f2) = 0x6298;
  uVar3 = 0;
  *(undefined1 *)((int)param_1 + 0x25d) = 5;
  uVar1 = param_1[0x8d];
  param_1[0x95] = (uint)&DAT_800e1130;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar1 + 0x88c) = 0x14;
  *(undefined2 *)(uVar1 + 0x88e) = 0x14;
  *(undefined2 *)(uVar1 + 0x890) = 0x230;
  *(undefined2 *)(uVar1 + 0x888) = 0;
  *(undefined2 *)(uVar1 + 0x88a) = 0;
  *(undefined2 *)(uVar1 + 0x892) = 0x138;
  do {
    uVar3 = uVar3 + 1;
    *puVar2 = *puVar2 | 0x9000;
    puVar2 = puVar2 + 0x5e;
  } while (uVar3 < 0x16);
  _DAT_800e1354 = param_1[0x89];
  _DAT_800e1358 = param_1[0x8a];
  param_1[0x7a] = 0x1000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  param_1[0xa1] = 3;
  *(undefined2 *)(param_1 + 0x54) = 0x1c2;
  *(undefined2 *)(param_1 + 0x53) = 0x5aa;
  *(undefined2 *)((int)param_1 + 0x156) = 0x5aa;
  *(undefined2 *)((int)param_1 + 0x14e) = 0x5aa;
  *(undefined2 *)(param_1 + 0x56) = 0x5aa;
  *(undefined2 *)(param_1 + 0xad) = 0;
  *(undefined1 *)((int)param_1 + 0x2b6) = 0;
  *(undefined2 *)((int)param_1 + 0x2ba) = 0;
  *(undefined2 *)(param_1 + 0xae) = 0;
  param_1[0xaf] = 0;
  *(undefined1 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)((int)param_1 + 0x2c1) = 0;
  *(undefined1 *)((int)param_1 + 0x2c2) = 0;
  *(undefined1 *)((int)param_1 + 0x2c3) = 0;
  *(undefined2 *)(param_1 + 0xb1) = 0;
  *(undefined2 *)((int)param_1 + 0x2c6) = 0;
  *(undefined1 *)(param_1 + 0xb2) = 0;
  *(undefined1 *)((int)param_1 + 0x2c9) = 0;
  *(undefined1 *)((int)param_1 + 0x2ca) = 0;
  *(undefined1 *)((int)param_1 + 0x2cb) = 0;
  *(undefined1 *)(param_1 + 0xb3) = 0;
  *(undefined1 *)((int)param_1 + 0x2cd) = 0;
  param_1[0xb4] = 0;
  *(undefined1 *)((int)param_1 + 0x2cf) = 0;
  *(undefined1 *)(param_1 + 0xb5) = 0;
  *(undefined2 *)(param_1 + 0x9c) = 0;
  *(undefined2 *)(param_1 + 0x55) = 0;
  *(undefined2 *)((int)param_1 + 0x152) = 0;
  *(undefined2 *)((int)param_1 + 0x15a) = 2000;
  *(undefined2 *)(param_1 + 100) = 0xf768;
  *param_1 = *param_1 | 0x4c;
  *(undefined2 *)(param_1 + 0x65) = 0;
  *(undefined2 *)(param_1 + 99) = 0xaf0;
  *(undefined2 *)((int)param_1 + 0x196) = 0xaf0;
  *(undefined2 *)((int)param_1 + 0x18e) = 0xaf0;
  *(undefined2 *)(param_1 + 0x66) = 0xaf0;
  *(undefined2 *)(param_1 + 0x5c) = 0x76c;
  *(undefined2 *)(param_1 + 0x5b) = 0x3b6;
  *(undefined2 *)((int)param_1 + 0x176) = 0x3b6;
  *(undefined2 *)((int)param_1 + 0x16e) = 0x3b6;
  *(undefined2 *)(param_1 + 0x5e) = 0x3b6;
  *(undefined2 *)(param_1 + 0x4c) = 3000;
  *(undefined2 *)(param_1 + 0x4b) = 600;
  *(undefined2 *)((int)param_1 + 0x136) = 600;
  *(undefined2 *)((int)param_1 + 0x12e) = 600;
  *(undefined2 *)(param_1 + 0x4e) = 600;
  *(undefined2 *)((int)param_1 + 0x28a) = 0x44c;
  *(undefined2 *)((int)param_1 + 0x192) = 0;
  *(undefined2 *)((int)param_1 + 0x19a) = 2000;
  *(undefined2 *)(param_1 + 0x5d) = 0;
  *(undefined2 *)((int)param_1 + 0x172) = 0;
  *(undefined2 *)((int)param_1 + 0x17a) = 2000;
  *(undefined2 *)(param_1 + 0x4d) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x13a) = 2000;
  *param_1 = *param_1 | 0x1c000000;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  return;
}
