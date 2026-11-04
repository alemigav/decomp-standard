/* FUN_80161ef4
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161ef4  body 0x80161ef4..0x80161f6f  size 124 B
 * body sha256 9391bc673c331e5661dfe78644790a50bdf4ae27cc4ede555afbd5a9915bd7de
 * provider record sha256 910e033132eae96b41422ecdf17f8e16edd595901b735bfe08ea20ac41a27cbc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161ef4(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80162618)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80162620)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
