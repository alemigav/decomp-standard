/* vector_installer
 * image   boot (boot), base 0x80000480
 * address 0x800070c0  body 0x800070c0..0x800072cf  size 528 B
 * body sha256 5e733eff7e1914894c251edf9e9ba4f70968fd49cb1d729318bf00f6908abffd
 * provider record sha256 170e86d760c6e2da4db5caf5437258b79a81083adcfd645ae026d3bbf5ca730a
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vector_installer(void)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  _DAT_80014ff0 = 1;
  uVar2 = FUN_800072d0();
  FUN_8000cde0(uVar2 | 0x20000000);
  FUN_8000ccf0(0x1000800);
  do {
    iVar3 = FUN_8000d2d0(0x1fc007fc,&local_10);
  } while (iVar3 != 0);
  do {
    iVar3 = FUN_8000d360(0x1fc007fc,local_10 | 8);
  } while (iVar3 != 0);
  _DAT_80000000 = 0x3c1a8000;
  _DAT_80000004 = 0x275a06d0;
  _DAT_80000008 = 0x3400008;
  _DAT_8000000c = 0;
  _DAT_80000080 = 0x3c1a8000;
  _DAT_80000084 = 0x275a06d0;
  _DAT_80000088 = 0x3400008;
  _DAT_8000008c = 0;
  _DAT_80000100 = 0x3c1a8000;
  _DAT_80000104 = 0x275a06d0;
  _DAT_80000108 = 0x3400008;
  _DAT_8000010c = 0;
  _DAT_80000180 = 0x3c1a8000;
  _DAT_80000184 = 0x275a06d0;
  _DAT_80000188 = 0x3400008;
  _DAT_8000018c = 0;
  FUN_8000efa0(0x80000000,400);
  FUN_800073d0(0x80000000,400);
  FUN_80007ef0();
  FUN_8000c940(4,&local_c);
  local_c = local_c & 0xfffffff0;
  if (local_c != 0) {
    _DAT_800128c0 = 0;
    _DAT_800128c4 = local_c;
  }
  _DAT_800128c0 =
       FUN_80006100((_DAT_800128c0 << 1 | _DAT_800128c4 >> 0x1f) + _DAT_800128c0 +
                    (uint)(_DAT_800128c4 * 3 < _DAT_800128c4),_DAT_800128c4 * 3,0,4);
  uVar1 = _DAT_800128c0;
  if (_DAT_8000030c == 0) {
    FUN_80006650(0x8000031c,0x40);
    uVar1 = _DAT_800128c0;
  }
  _DAT_800128c0 = (int)((ulonglong)uVar1 >> 0x20);
  _DAT_800128c4 = (uint)uVar1;
  if (_DAT_80000300 == 0) {
    _DAT_800128c8 = 0x2f5b2d2;
  }
  else if (_DAT_80000300 == 2) {
    _DAT_800128c8 = 0x2e6025c;
  }
  else {
    _DAT_800128c8 = 0x2e6d354;
  }
  return;
}
