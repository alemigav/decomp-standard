/* FUN_801658cc
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801658cc  body 0x801658cc..0x80165a13  size 328 B
 * body sha256 1a7fc8b3bdd22e1496fc290e2ae6ed2fe4b4972279a82c1201ba96cecbf3b9cb
 * provider record sha256 0d1890787be03b989abf78bef142d37725a0a71849606f67551554bd1eb43dbe
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801658cc(int param_1)

{
  char cVar1;
  undefined4 local_30 [8];
  
  local_30[0] = 0x15efe70;
  local_30[1] = 0x1900000;
  local_30[2] = 0x15efed4;
  local_30[3] = 0xfa0000;
  local_30[4] = 0x15eff38;
  local_30[5] = 0x640000;
  local_30[6] = 0x15eff9c;
  local_30[7] = 0xffce0000;
  if ((*(byte *)(param_1 + 0x2cf) & 1) == 0) {
    func_0x800837d0(((int)_DAT_800e1324 << 0x1b) >> 0x10,
                    local_30 + (uint)(*(byte *)(param_1 + 0x2cf) >> 1) * 2,
                    local_30 + (uint)(*(byte *)(param_1 + 0x2cf) >> 1) * 2);
    FUN_80168600(0x800e1130,0,2,0x2400,0,0,local_30 + (uint)(*(byte *)(param_1 + 0x2cf) >> 1) * 2);
  }
  cVar1 = *(char *)(param_1 + 0x2cf) + '\x01';
  *(char *)(param_1 + 0x2cf) = cVar1;
  if (cVar1 == '\a') {
    *(undefined4 *)(param_1 + 0x2d8) = 0;
  }
  return;
}
