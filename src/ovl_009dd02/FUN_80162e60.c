/* FUN_80162e60
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162e60  body 0x80162e60..0x80162f97  size 312 B
 * body sha256 007bc334cecf175e31d64e1dc072acb78a79ec3717fd5fc244e0a1518d9a8d07
 * provider record sha256 79d93f941541ef9871cd61a845fa6a4f4b0c89601d3b077102c623bb39803949
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162e60(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    param_1[0x7a] = ((uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 7) * 0x1000000 + 0x3f00;
    func_0x800334c8();
    func_0x80089d54(param_1,param_2,param_3,0x40);
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
    *param_1 = *param_1 & 0xfffffffb;
    *(undefined1 *)((int)param_1 + 0x2b6) = 1;
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
    if (iVar1 != 0) {
      FUN_80162f98(param_1);
      return;
    }
    func_0x80032b5c(param_1,0);
  }
  *(short *)(param_1 + 0x4c) = *(short *)(param_1 + 0x4c) - *(short *)(param_1 + 0x78);
  return;
}
