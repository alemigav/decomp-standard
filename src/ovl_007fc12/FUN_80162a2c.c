/* FUN_80162a2c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162a2c  body 0x80162a2c..0x80162a63  size 56 B
 * body sha256 4654c41f794f6e997ec3af313946b316cd7da8a123ec738664e3eb77838594a6
 * provider record sha256 5dbe9976c1b58abfa15d000423c45ccaf9a18764ecf6e6799f4c22e4c9daf6ec
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162a2c(int param_1)

{
  (*(code *)(&PTR_FUN_8016e174)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
