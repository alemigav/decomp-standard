/* FUN_8009e044
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e044  body 0x8009e044..0x8009e0eb  size 168 B
 * body sha256 f613d98b32095fa809d3fee7d4f41487d771327b325a7b8ef6f69912c21faeb5
 * provider record sha256 3896e05b7664527c0ac1923db48904a6887aa5638c9bf14ea89c501d8602e081
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e044(void)

{
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,9);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x142) {
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(0,2,&DAT_80132628);
    FUN_80025f78(1,2,&DAT_80132644);
    FUN_8009ce40();
    DAT_8013273a = 0;
    DAT_8013272e = 5;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
