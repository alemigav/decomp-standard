/* FUN_80164b98
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164b98  body 0x80164b98..0x80164c63  size 204 B
 * body sha256 b0964fee13436854d0559824ef58c6f4072629b6e723f759a6443e39ce1dde07
 * provider record sha256 38c0c004d5d4414d9156d10b78d19800bfa96c7099b98845f7da79c62b12dd55
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164b98(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = ((uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 0xb) * 0x1000000 + 0x3f00;
    *(undefined1 *)(param_1 + 0xae) = *(undefined1 *)(param_1 + 0xb0);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    *(undefined1 *)((int)param_1 + 5) = 1;
    *(undefined2 *)((int)param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0xaf) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x2be) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x2bd) = 0x2d;
    _DAT_800e1128 = _DAT_800e1128 & 0xff7f;
    *(undefined1 *)((int)param_1 + 0x2b6) = 0;
    *param_1 = *param_1 & 0xffffffbd;
  }
  return;
}
