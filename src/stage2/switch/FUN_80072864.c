/* FUN_80072864
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072864  body 0x80072864..0x8007286f  size 12 B
 * body sha256 084f272dedbf466843c94ba85f097574712aa9213c1a2fe83d2c60381003391f
 * provider record sha256 09bcc4208fdc8a13756d460c7db6f21f4f75d8e46fd5617b0aada05dc1725faa
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool switchD_8007281c::caseD_6(uint param_1,uint param_2)

{
  return (param_2 & param_1) != 0;
}
