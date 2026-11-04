/* FUN_8017db90
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017db90  body 0x8017db90..0x8017dc47  size 184 B
 * body sha256 6e186fc06dbd22bbb473a0e0ee58d24cb57f12da12cb1794f00c5bf99021354d
 * provider record sha256 864de29778006e2c16be80533dda281e50ec072a5709c6f255daa3ef1e6669c8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017db90(void)

{
  int iVar1;
  undefined2 local_18 [4];
  
  local_18[0] = 0x14ca;
  local_18[1] = 0x14c9;
  iVar1 = func_0x80004cfc(local_18[DAT_8017e5bc],_DAT_8010b6e8,0x80000000,"CONF_LD");
  func_0x8002607c(_DAT_8010b6e8);
  if (DAT_8017e5bc == 0) {
    iVar1 = func_0x800479c8(DAT_8017e5b0,&DAT_8017e594,0x14cb,1);
  }
  if (iVar1 == -1) {
    DAT_8017e5be = DAT_8017e5be | 1;
  }
  DAT_8017e5c9 = 0;
  return;
}
