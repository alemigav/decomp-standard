/* FUN_8006b220
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b220  body 0x8006b220..0x8006b263  size 68 B
 * body sha256 f82962b82b64e87cc47d149727b37a3581ebc7d7410617cfe7adf02e4a052d8b
 * provider record sha256 e875037a534e8e329d68c0ac7d8b72d2bcc5896f7426dc636d7c814c91677f03
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8006b220(int param_1)

{
  return (uint)(*(ushort *)(param_1 + 10) >> 0xb) * -100 +
         (*(ushort *)(param_1 + 10) >> 6 & 0x1f) * -0x708;
}
