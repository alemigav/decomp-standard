/* FUN_80162254
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162254  body 0x80162254..0x8016233f  size 236 B
 * body sha256 e45aef97292d44c4f005378e6749b84281e6b874b69813935e4bc3125dcbf7f3
 * provider record sha256 e10072e015ed9e41221694bed632660bd5138ccfd32f049f06cbaeb2c6ac1715
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162254(int param_1)

{
  bool bVar1;
  short sVar2;
  
  if (((-1 < _DAT_800e1322) || ('\0' < *(char *)(param_1 + 0x2bd))) ||
     (0x707 < *(uint *)(param_1 + 0x28c))) {
    bVar1 = *(uint *)(param_1 + 0x28c) < 0x709;
    if (((_DAT_800e112a & 4) != 0) && (*(uint *)(param_1 + 0x28c) < 0x1519)) {
      bVar1 = true;
    }
    if ((_DAT_800e112a & 1) != 0) {
      bVar1 = true;
    }
    if (((*(ushort *)(param_1 + 0x2c6) & 1) != 0) &&
       (sVar2 = *(short *)(param_1 + 500) + -1, *(short *)(param_1 + 500) = sVar2, sVar2 == -1)) {
      bVar1 = true;
    }
    if (bVar1) {
      FUN_80165c68(param_1,1);
    }
  }
  return;
}
