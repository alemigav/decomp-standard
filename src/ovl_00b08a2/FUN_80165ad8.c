/* FUN_80165ad8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80165ad8  body 0x80165ad8..0x80165b1f  size 72 B
 * body sha256 63555d697c0489b07b7292d82d04829b3ba0df6c1a7d1a1e6f097d03ecd86695
 * provider record sha256 9efcc3343facdf70eb35b850199a2e9c444ee48293f47a4011e65366baf0f6c0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ad8(int param_1)

{
  (**(code **)(&DAT_80167290 +
              ((*(byte *)(param_1 + 5) - 1) * 9 + (uint)*(byte *)(param_1 + 0x26e)) * 4))();
  return;
}
