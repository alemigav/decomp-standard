/* FUN_80162cbc
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162cbc  body 0x80162cbc..0x80162d83  size 200 B
 * body sha256 aec833dbb02afd21d9c73d202dd6798a7f4996d47e2ea1da198da8b196244b00
 * provider record sha256 3c01795de47ea66d332d6dbaba498635c0860b962ae79eeb728d83961b58f7c9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162cbc(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80162d84(param_1);
    *(undefined1 *)(param_1 + 0x2ca) = 0xff;
    func_0x80036c68(param_1,0,0x20,0);
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 0x10;
    if (0x42 < *(byte *)(param_1 + 0x1e9)) {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
  }
  else if (*(char *)(param_1 + 6) == '\x01') {
    uVar1 = *(ushort *)(param_1 + 0x2b4) & 0xffef;
    *(ushort *)(param_1 + 0x2b4) = uVar1 | 2;
    if (_DAT_800e1322 < 0) {
      uVar2 = 0x1060000;
    }
    else {
      *(ushort *)(param_1 + 0x2b4) = uVar1 | 6;
      uVar2 = 0x1040000;
    }
    *(undefined4 *)(param_1 + 4) = uVar2;
  }
  return;
}
