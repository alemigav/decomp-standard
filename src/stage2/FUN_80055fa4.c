/* FUN_80055fa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80055fa4  body 0x80055fa4..0x80056027  size 132 B
 * body sha256 cad9d493f3364471d7e7dff3ae99c0f25754f2083ec76f9ec7e38b9a7ff101cb
 * provider record sha256 b3e428346c7fdd9e6fdc041e8bddbf36d6185bfb482611de2bee7feafdf3ce0e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80055fa4(int param_1)

{
  (*(code *)(&PTR_FUN_8010dc38)[*(byte *)(param_1 + 5)])(param_1,DAT_800df914,DAT_800df918);
  (*(code *)(&PTR_FUN_8010dc68)[*(byte *)(param_1 + 5)])
            (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
  return;
}
