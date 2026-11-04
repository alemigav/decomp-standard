/* FUN_8009ec1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ec1c  body 0x8009ec1c..0x8009ec97  size 124 B
 * body sha256 160326ee807fd0dce462020ff3ab6fecf0fffa81e28cdd571b0c7e3ac04c5d87
 * provider record sha256 9575c20c5a37c2fc9d4c828fc2b7d5dfaab65534b41b47480d21697cb0273f66
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ec1c(uint *param_1,int param_2)

{
  DAT_801344f4 = 1;
  DAT_80134298 = *param_1 & 0xfffffff;
  DAT_8013429c = param_1[1] & 0xfffffff;
  DAT_801342a4 = param_2 + DAT_80134420 & 0xfffffff;
  DAT_801342a0 = param_1[2] & 0xfffffff;
  func_0x8000f020();
  FUN_8006c044(&DAT_80134428,0);
  return;
}
