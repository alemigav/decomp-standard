/* FUN_80165a20
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165a20  body 0x80165a20..0x80165adf  size 192 B
 * body sha256 758c7ef2d1f01dffb4db5de132da9111ab67bccbcb831ba7af1e0843b0e66b0f
 * provider record sha256 74c8bf1ed5510cf5f75f537c497f4aef94e124743e17f5292b245009b30e6eb9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165a20(int param_1)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 7) = 1;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = uVar2 & 1;
  }
  cVar3 = func_0x80036c68(param_1,*(short *)(param_1 + 500) + 4,0xf,0);
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar3;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  return;
}
