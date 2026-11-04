/* FUN_8015f298
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015f298  body 0x8015f298..0x8015f54f  size 696 B
 * body sha256 97f2800d3dabacc40266d97d4dcc1e0c580cfcd3fa2be4ba5a8be715b59262d2
 * provider record sha256 88f3e8af192c732a18f17a9d28f39d3ea5526af79e06a3c294ad60db11395014
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015f3ac) */
/* WARNING: Removing unreachable block (ram,0x8015f408) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015f298(int param_1)

{
  int iVar1;
  char cVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined *local_24;
  undefined4 local_20;
  
  uVar4 = 0;
  local_30 = 0;
  local_2c = 0xd90090;
  local_28 = 0;
  local_24 = &DAT_801614b8;
  local_20 = 0x200020;
  puVar3 = &DAT_80160c14;
  do {
    cVar2 = DAT_80160c27;
    iVar1 = (uint)*puVar3 * 0x28;
    (&DAT_80160c3a)[iVar1] = DAT_80160c27;
    (&DAT_80160c39)[iVar1] = cVar2;
    (&DAT_80160c38)[iVar1] = cVar2;
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 4);
  if (param_1 != 0) {
    *(undefined2 *)(&DAT_80160f12 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0;
  }
  else {
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_80160f12 + (uint)DAT_800dfbe8 * 0x14) = 0;
  }
  uVar4 = 0;
  iVar1 = (uint)(ushort)(&DAT_80160c14)[param_1 != 0] * 0x28;
  cVar2 = DAT_80160c27 + DAT_80160c23;
  (&DAT_80160c3a)[iVar1] = cVar2;
  (&DAT_80160c39)[iVar1] = cVar2;
  (&DAT_80160c38)[iVar1] = cVar2;
  do {
    _DAT_800df8b4 =
         func_0x80043988(_DAT_800df8b4,&DAT_80160c38 + (uint)(ushort)(&DAT_80160c14)[uVar4] * 0x28,0
                         ,0);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 2);
  local_28 = CONCAT22(local_28._0_2_,(DAT_800e9012 & 3) << 5);
  _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&local_30,0,0);
  return;
}
