/* FUN_80036d14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036d14  body 0x80036d14..0x80036dc3  size 176 B
 * body sha256 3e81893ceb77c7f2639c2a33a23cff5930d7706a7ace77824d2b892dcf85bee5
 * provider record sha256 780ffdbf8e2fd5cf53de092358839159b17be7a727f60efac834bbc7e673e122
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036d14(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x1e8) != param_2) {
    *(char *)(param_1 + 0x1e8) = (char)param_2;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 0x1ea) = (char)param_3;
  }
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  if (param_3 + 1U == 0) {
    trap(0x1c00);
  }
  iVar1 = FUN_8008a994(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                       0x1000 / (param_3 + 1U) | param_4 << 0x10);
  if (iVar1 == 0) {
    FUN_80032c6c(param_1,0,0);
  }
  return iVar1 != 0;
}
