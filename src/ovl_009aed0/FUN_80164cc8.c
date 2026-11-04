/* FUN_80164cc8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164cc8  body 0x80164cc8..0x80164d87  size 192 B
 * body sha256 78b5022063ee96ebaeb5dc008c375296643336d19e036eba5d6c20b84d9df404
 * provider record sha256 638349cb777fdd81b9a828c38a4ea6cb7d43ca662dbfd7b07d1c4ad29dd9c5fe
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164cc8(int param_1)

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
  cVar3 = func_0x80036c68(param_1,*(short *)(param_1 + 500) + 6,3,0);
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar3;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  return;
}
