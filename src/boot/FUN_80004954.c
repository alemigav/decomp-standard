/* FUN_80004954
 * image   boot (boot), base 0x80000480
 * address 0x80004954  body 0x80004954..0x80004a1f  size 204 B
 * body sha256 ad95da0219db90d1273ce9c180b2bc24fcda0bea0f927a671784b47778c874f8
 * provider record sha256 ff8c78d89c5e6486a5c47f5f4f5c36b0d5e2f62b8319d22423c7ba7994888d2d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004954(void)

{
  undefined4 *puVar1;
  int iVar2;
  int local_110 [64];
  
  puVar1 = (undefined4 *)cart_record(0x43);
  _DAT_800128a8 = *puVar1;
  func_0x800888ec(_DAT_800128a8,local_110,0x28);
  iVar2 = local_110[0] * 8 + 0x28;
  _DAT_80012868 = local_110[0];
  _DAT_80012864 = iVar2;
  _DAT_80012860 = func_0x8008af80(iVar2);
  func_0x800888ec(_DAT_800128a8,_DAT_80012860,iVar2);
  _DAT_80012870 = 0;
  _DAT_80012874 = _DAT_80012860 + 0x28;
  _DAT_8001286c = _DAT_80012860 + 8;
  _DAT_800e110c = _DAT_800e110c & 0xffffffdf;
  return;
}
